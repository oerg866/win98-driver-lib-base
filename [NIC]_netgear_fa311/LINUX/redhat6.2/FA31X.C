/* fa31x.c -- NETGEAR FA311/FA312 PCI Adapter Driver */
/* fa31x.c: Version 2.20       07/16/2001
 *     
 *       NETGEAR FA311/FA312 PCI Adaper Driver for Linux 
 *       Copyright(C) 2000,2001 by Pam Tu
 *
 *       This program is free software; you can redistribute it and/or
 *       modify it under the terms of the GNU General Public License
 *       as published by the Free Software Foundation; either version 2
 *       of the License, or (at your option) any later version.
 *
 *       This program is distributed in the hope that it will be useful,
 *       but WITHOUT ANY WARRANTY; without even the implied warranty of
 *       MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *       GNU General Public License for more details.
 */
static const char *version = "fa31x.c: NETGEAR FA311/FA312 PCI Adapter v2.20\n";

/* Generic Kernel Module/Driver Headers */

#ifdef MODVERSIONS
#include <linux/modversions.h>
#endif

#include <linux/module.h>
#include <linux/kernel.h>

#include <linux/pci.h>

#include <linux/ioport.h>
#include <asm/io.h>         /* IO stuff */
#include <asm/byteorder.h>
#include <linux/delay.h>

/* Ethernet Driver Specific Headers */

#include <linux/netdevice.h>
#include <linux/etherdevice.h>
#include <linux/skbuff.h>
#include <linux/malloc.h>
#include <linux/if_ether.h>

#include "fa31x.h"

/* Macros */

/*
 * SWAP_BUS_TO_CPU_XX and SWAP_CPU_TO_BUS_XX macros swap 16 and 32 bit values
 * between the PCI bus' little endian byte-order and the CPU's native
 * byte-order.
 */
#ifdef __BIG_ENDIAN
#define BUS_TO_CPU_SWAP_16(X)    swap_16(X)
#define BUS_TO_CPU_SWAP_32(X)    swap_32(X)
#define CPU_TO_BUS_SWAP_16(X)    swap_16(X)
#define CPU_TO_BUS_SWAP_32(X)    swap_32(X)
#define CPU_TO_NET_SWAP_16(X)    ((u16)(X))
#define CPU_TO_NET_SWAP_32(X)    ((u32)(X))
#define NET_TO_CPU_SWAP_16(X)    ((u16)(X))
#define NET_TO_CPU_SWAP_32(X)    ((u32)(X))
#else
#define BUS_TO_CPU_SWAP_32(X)    ((u32)(X))
#define BUS_TO_CPU_SWAP_16(X)    ((u16)(X))
#define CPU_TO_BUS_SWAP_32(X)    ((u32)(X))
#define CPU_TO_BUS_SWAP_16(X)    ((u16)(X))
#define CPU_TO_NET_SWAP_16(X)    swap_16(X)
#define CPU_TO_NET_SWAP_32(X)    swap_32(X)
#define NET_TO_CPU_SWAP_16(X)    swap_16(X)
#define NET_TO_CPU_SWAP_32(X)    swap_32(X)
#endif

/* Macros translate addresses between PCI bus and CPU */
#define BUS_TO_CPU_ADDR_XLATE(X)  BUS_TO_CPU_SWAP_32(bus_to_virt(X))
#define CPU_TO_BUS_ADDR_XLATE(X)  CPU_TO_BUS_SWAP_32(virt_to_bus(X))

/* Macros to read/write 32/16 bit data to/from FA311/FA312 device registers. */
#define DP_REG32_WRITE(reg, val)  io_write_32 (iobase+(reg),            \
                                               CPU_TO_BUS_SWAP_32(val))
#define DP_REG32_READ(reg)        BUS_TO_CPU_SWAP_32(io_read_32 (iobase+(reg)))
#define DP_REG16_WRITE(reg, val)  io_write_16 (iobase+(reg),            \
                                               CPU_TO_BUS_SWAP_16(val))
#define DP_REG16_READ(reg)        BUS_TO_CPU_SWAP_16(io_read_16 (iobase+(reg)))
#define DP_REG32_SET(reg, val)    DP_REG32_WRITE(reg,DP_REG32_READ(reg)|(val))
#define DP_REG32_CLR(reg, val)    DP_REG32_WRITE(reg,DP_REG32_READ(reg)&~(val))
#define DP_REG16_SET(reg, val)    DP_REG16_WRITE(reg,DP_REG16_READ(reg)|(val))
#define DP_REG16_CLR(reg, val)    DP_REG16_WRITE(reg,DP_REG16_READ(reg)&~(val))

/* Debug Macros */
#define DP_DEBUG_PROBE            0x00000001
#define DP_DEBUG_OPEN             0x00000002
#define DP_DEBUG_CLOSE            0x00000004
#define DP_DEBUG_IOCTL            0x00000008
#define DP_DEBUG_TX               0x00000010
#define DP_DEBUG_RX               0x00000020
#define DP_DEBUG_MC               0x00000040
#define DP_DEBUG_ANEG             0x00000080
#define DP_DEBUG_INTR             0x00000100
#define DP_DEBUG_LOAD             0x00000200
#define DP_DEBUG_UNLOAD           0x00000400

#ifdef DEBUG
u32     dp_debug_level=DEBUG;
#define DP_DEBUG(level, X)  if (level & dp_debug_level) printk X
#else
#define DP_DEBUG(level, X)
#endif

/* data types */
typedef u32    status;                /* return status */
typedef volatile u8 * virt_addr;      /* CPU virtual address */
typedef volatile u8 * bus_addr;       /* BUS physical address */
typedef u8     bool;

#define OK        0                   /* status: OK */
#define ERROR    -1                   /* status: ERROR */
#define	TRUE      1
#define FALSE     0

/* Default Driver Parameters */
#define DP_DEFAULT_TXQ_SIZE         10
#define DP_DEFAULT_RXQ_SIZE         30
#define DP_RX_COPY_THRESHOLD        128 /* upper limit for rx packet copy */
#define DP_POLYNOMIAL               0x04C11DB6

/* Alignment and packet sizes */
#define ETH_CRC_LEN                 4
#define ETH_MAX_PKT_SIZE            (ETH_FRAME_LEN + ETH_CRC_LEN)
#define DP_ALIGN                    4     /* word alignment */

/* Driver private descriptor macros */
#define DP_DESC_SKBPTR              0x0c  /* SKB pointer offset */
#define DP_QUEUE_ELE_SIZE           (DP_DESC_SIZE + 4)
#define DP_QUEUE_ELE_NEXT(q)											\
        q->cur_desc_addr = DP_QUEUE_ELE_NEXT_GET(q, q->cur_desc_addr)
#define DP_QUEUE_ELE_NEXT_GET(q, desc_addr)									\
        ((desc_addr) == (q)->last_desc_addr) ? (q)->first_desc_addr :		\
		                                   (desc_addr) + DP_QUEUE_ELE_SIZE

/* Macros to get/set the values of the descriptor fields */
#define DP_DESC_LNK_GET(ptr)     *(u32 *)((virt_addr)ptr + DP_DESC_LNK)
#define DP_DESC_CMDSTS_GET(ptr)  *(u32 *)((virt_addr)ptr + DP_DESC_CMDSTS)
#define DP_DESC_BUFPTR_GET(ptr)  *(u32 *)((virt_addr)ptr + DP_DESC_BUFPTR)
#define DP_DESC_SKBPTR_GET(ptr)  *(u32 *)((virt_addr)ptr + DP_DESC_SKBPTR)

#define DP_DESC_LNK_SET(ptr, val)      DP_DESC_LNK_GET(ptr) = (val)
#define DP_DESC_CMDSTS_SET(ptr, val)   DP_DESC_CMDSTS_GET(ptr) = (val)
#define DP_DESC_BUFPTR_SET(ptr,val)    DP_DESC_BUFPTR_GET(ptr) = (val)
#define DP_DESC_SKBPTR_SET(ptr,val)    DP_DESC_SKBPTR_GET(ptr) = (val)

/*
 * Macros to get/set the values of descriptor fields with
 * appropriate address and byte order translations
 */
#define DP_DESC_LNK_XLATE_GET(p)    BUS_TO_CPU_ADDR_XLATE(DP_DESC_LNK_GET(p))
#define DP_DESC_CMDSTS_XLATE_GET(p)    BUS_TO_CPU_SWAP_32(DP_DESC_CMDSTS_GET(p))
#define DP_DESC_BUFPTR_XLATE_GET(p) BUS_TO_CPU_ADDR_XLATE(DP_DESC_BUFPTR_GET(p))

#define DP_DESC_LNK_XLATE_SET(p, v)                                    \
        DP_DESC_LNK_SET(p, CPU_TO_BUS_ADDR_XLATE(v))
#define DP_DESC_CMDSTS_XLATE_SET(p, v)                                 \
        DP_DESC_CMDSTS_SET(p, CPU_TO_BUS_SWAP_32(v))
#define DP_DESC_BUFPTR_XLATE_SET(p,v)                                  \
        DP_DESC_BUFPTR_SET(p, CPU_TO_BUS_ADDR_XLATE(v))


/* Descriptor queue */
struct fa31x_queue {
	virt_addr  first_desc_addr;  /* descriptor array address */
	virt_addr  last_desc_addr;   /* last descriptor address */
	virt_addr  cur_desc_addr;    /* current descriptor address */ 
	virt_addr  qbuf;             /* allocated queue buffer */
	u16        count;            /* number of elements */
};

/* Queue types -- qtype */
#define DP_QUEUE_TYPE_TX    1    /* Transmit queue */
#define DP_QUEUE_TYPE_RX    2    /* Receive queue */

/* Device private data */
struct fa31x_priv {
	struct device *         next;        /* Next fa31xdevice */
    struct fa31x_queue    tx_queue;    /* Transmit Descriptor Queue */
    struct fa31x_queue    rx_queue;    /* Receive Descriptor Queue */
    struct enet_statistics  stats;       /* MIB data */
};

static struct device *    fa31x_dev_list;        /* List of fa31xdevices */

/* Linux Network Driver interface routines */
extern int fa31x_probe (struct device *dev);
static int fa31x_open (struct device *dev);
static int fa31x_close (struct device *dev);
static int fa31x_start_xmit (struct sk_buff *skb, struct device *dev);
static void fa31x_set_multicast_list (struct device *dev);
static int fa31x_ioctl (struct device *dev, struct ifreq *rq, int cmd);
static void fa31x_interrupt (int irq, void *dev_id, struct pt_regs *regs);
static struct enet_statistics *fa31x_get_stats (struct device *dev);

/* Support Functions */
/*static u16 swap_16 (u16 us);*/
/*static u32 swap_32 (u32 ui);*/
static u32 io_read_32 (u16 io_port);
static void io_write_32 (u16 io_port, u32 data);
static u16 io_read_16 (u16 io_port);
/*static void io_write_16 (u16 io_port, u16 data);*/

/* Driver Private Routines */
static void fa31x_mac_address_set (u32 iobase, char *mac_addr);
static void fa31x_mac_address_get (u32 iobase, char *mac_addr);
static status fa31x_dev_reset (u32 iobase);
static status fa31x_queue_create (struct fa31x_queue *q, int count, int qtype);
static status fa31x_queue_delete (struct fa31x_queue *q);
static virt_addr fa31x_tx_desc_get (struct device *dev);
static virt_addr fa31x_rx_desc_get (struct device *dev);
static status fa31x_phy_setup (struct device *dev);
static int fa31x_crc (char * mc_addr);
static void fa31x_tx_skb_reclaim (struct device *dev, virt_addr desc_addr);
static void  ReadEEWord(u16 iobase,u32 wordOffset,u16* pEeData);


/* Driver Debug Routines */
#ifdef DEBUG
static void fa31x_regs_info (u16 iobase);
#endif

/*
 * fa31x_probe - enumerate the PCI bus for instances of FA311/FA312
 *
 * This routine enumerates FA311/FA312 ethernet devices on the PCI bus, and
 * registers each FA311/FA312 device found.
 */
int
fa31x_probe (struct device *dev)
{
    int  dev_count;
    u8   bus;
    u8   func;
    u8   irq;
    u32  iobase;
    u32  version;
    
    if (! pcibios_present())
        return -ENODEV;        /* No such device */

    dev_count=0;
    while (pcibios_find_device (PCI_VENDOR_ID_NS, PCI_VENDOR_ID_NS_83815,
                                dev_count, &bus, &func)
           == PCIBIOS_SUCCESSFUL) {

        /* Allocate, name the device and add to ethernet device list */
        dev = init_etherdev(dev, sizeof (struct fa31x_priv));

        if (dev == NULL) {
            printk (KERN_INFO "%s: Failed to create device struct\n",
                    DP_DRV_NAME);
            break;
        }
            
        /* Read PCI Configuration Registers */
        pcibios_read_config_byte (bus, func, PCI_INTERRUPT_LINE, &irq);
        pcibios_read_config_dword (bus, func, PCI_BASE_ADDRESS_0, &iobase);
        iobase &= PCI_BASE_ADDRESS_IO_MASK;

        /* Put the device in a quiescent state */
        if (fa31x_dev_reset (iobase) != OK) {
            printk (KERN_INFO "%s: Device Reset failed.\n",
                    DP_DRV_NAME);
            kfree (dev); 
            continue;             /* Try the next device */
        }
        DP_REG32_WRITE(DP_CCSR, 0x00008000);
	DP_REG32_WRITE(DP_WCSR, 0x00000000);   
        /* Get the ethernet address */
        fa31x_mac_address_get (iobase, dev->dev_addr);

        /* If address is not set, set up a default one */
        /* XXX needed only for pre-release versions of the hardware */
        if ((dev->dev_addr[0] == 0) && (dev->dev_addr[1] == 0) &&
            (dev->dev_addr[2] == 0) && (dev->dev_addr[3] == 0) &&
            (dev->dev_addr[4] == 0) && (dev->dev_addr[5] == 0)) {
            u32   random = jiffies;
            u8 *  ptr = (u8 *) &random;

            dev->dev_addr[0] = 0x08; /* National's Ethernet ID 0 */
//            dev->dev_addr[1] = 0x00; /* National's Ethernet ID 1 */
 //           dev->dev_addr[2] = 0x17; /* National's Ethernet ID 2 */
            dev->dev_addr[3] = *ptr++;
            dev->dev_addr[4] = *ptr++;
            dev->dev_addr[5] = *ptr;
        }
  
        /* initialize the device data */
        dev->base_addr = iobase;
        dev->irq       = irq;
        dev->open      = fa31x_open;
        dev->stop      = fa31x_close;
        dev->get_stats = fa31x_get_stats;
        dev->do_ioctl  = fa31x_ioctl;
        dev->hard_start_xmit    = fa31x_start_xmit;
        dev->set_multicast_list = fa31x_set_multicast_list;

        ether_setup (dev);        /* initialize generic fields */

        /* reserve IO region */
        request_region (iobase, FA31x_PCI_IO_SIZE, dev->name);

        /* Display board info */
        version = DP_REG32_READ(DP_SRR);
        printk (KERN_INFO "%s: bus=%d func=%d io=0x%x irq=%d ver=%d.%d\n",
                dev->name, bus, func, iobase, irq,
                (version & DP_SRR_MAJ) >> DP_SRR_MAJ_SHF,
                (version & DP_SRR_MIN));
	

        /* If address is not set, set up a default one */
        /* XXX needed only for pre-release versions of the hardware */
        if ((dev->dev_addr[0] == 0) && (dev->dev_addr[1] == 0) &&
            (dev->dev_addr[2] == 0) && (dev->dev_addr[3] == 0) &&
            (dev->dev_addr[4] == 0) && (dev->dev_addr[5] == 0)) {
            u32   random = jiffies;
            u8 *  ptr = (u8 *) &random;

            dev->dev_addr[0] = 0x08; /* National's Ethernet ID 0 */
            dev->dev_addr[1] = 0x00; /* National's Ethernet ID 1 */
            dev->dev_addr[2] = 0x17; /* National's Ethernet ID 2 */
            dev->dev_addr[3] = *ptr++;
            dev->dev_addr[4] = *ptr++;
            dev->dev_addr[5] = *ptr;
        }
  


        printk (KERN_INFO "%s: ethernet addr=%02x:%02x:%02x:%02x:%02x:%02x\n",
                dev->name,
                dev->dev_addr[0], dev->dev_addr[1], dev->dev_addr[2],
                dev->dev_addr[3], dev->dev_addr[4], dev->dev_addr[5]);



        /* Chain the device */
        ((struct fa31x_priv *)(dev->priv))->next = fa31x_dev_list;
        fa31x_dev_list = dev;

#ifdef DEBUG
        printk (KERN_INFO "%s: DebugInfo: dev=0x%x priv=0x%x "
                "&dp_debug_level=0x%x\n",
                dev->name, (u32)dev, (u32)dev->priv, (u32)&dp_debug_level);
#endif

        /* Update Counters */
        dev_count++;
        dev=NULL;
    }

    return dev_count ? OK : -ENODEV;
}

/* fa31x_open - open and initialize a device */
static int
fa31x_open (struct device *dev)
{
    u32     iobase = dev->base_addr;
    struct fa31x_priv* priv   = dev->priv;
    
    /* Reset the device -- paranoia! */
    if (fa31x_dev_reset (iobase) != OK)
        return -EAGAIN;

    /* Allocate Tx and Rx queues */
    if (fa31x_queue_create (&priv->tx_queue, DP_DEFAULT_TXQ_SIZE,
                              DP_QUEUE_TYPE_TX) != OK) {
        printk (KERN_INFO "%s: Failed to create tx queue\n", dev->name);
        return -EAGAIN;
    }

    if (fa31x_queue_create (&priv->rx_queue, DP_DEFAULT_RXQ_SIZE,
                              DP_QUEUE_TYPE_RX) != OK) {
        fa31x_queue_delete (&priv->tx_queue);
        printk (KERN_INFO "%s: Failed to create rx queue\n", dev->name);
        return -EAGAIN;
    }

    /* Install the Tx and Rx queues on the device */
    DP_REG32_WRITE (DP_TXDP, virt_to_bus(priv->tx_queue.first_desc_addr));
    DP_REG32_WRITE (DP_RXDP, virt_to_bus(priv->rx_queue.first_desc_addr));

    DP_DEBUG (DP_DEBUG_OPEN,
              (KERN_INFO "dp: setting TXDP=0x%x RXDP=0x%x\n",
               (u32)virt_to_bus (priv->tx_queue.first_desc_addr),
               (u32)virt_to_bus (priv->rx_queue.first_desc_addr)));

    /* Install interrupt vector */
    if (request_irq (dev->irq, &fa31x_interrupt, SA_SHIRQ,
                     dev->name, dev) != OK) {
        fa31x_queue_delete (&priv->tx_queue);
        fa31x_queue_delete (&priv->rx_queue);
        return -EAGAIN;
    }

    /* Setup phy capabilities */
    if (fa31x_phy_setup (dev) != OK) {
        printk (KERN_INFO "%s: Warning PHY setup did not complete. Check cable.\n",
                dev->name);
    }
    
    /* Setup transmit control */
    DP_REG32_WRITE (DP_TXCFG, (DP_TXCFG_DRTH_SET(0x30) | 
                               DP_TXCFG_FLTH_SET(0x10) |
                               DP_TXCFG_MXDMA_32       |
                               DP_TXCFG_ATP));

    DP_DEBUG (DP_DEBUG_OPEN,
              (KERN_INFO "dp: TXCFG set to 0x%x\n",
               (DP_TXCFG_DRTH_SET(0x30) | DP_TXCFG_FLTH_SET(0x10) |
                DP_TXCFG_MXDMA_32       | DP_TXCFG_ATP)));
    
    /* Setup receive control */
    DP_REG32_WRITE (DP_RXCFG, (DP_RXCFG_DRTH_SET(0x08) |
                               DP_RXCFG_MXDMA_32));

    DP_DEBUG (DP_DEBUG_OPEN,
              (KERN_INFO "dp: RXCFG set to 0x%x\n",
               (DP_RXCFG_DRTH_SET(0x08) | DP_RXCFG_MXDMA_32)));

    /* Setup the ethernet address */
    fa31x_mac_address_set (iobase, dev->dev_addr);

    /* Receive perfect match and broadcast packets */
    DP_REG32_WRITE (DP_RFCR, 0);
    DP_REG32_WRITE (DP_RFCR, (DP_RFCR_AAB  | /* all broadcast pkts */
                              DP_RFCR_APM  | /* perfect match pkts */
                              DP_RFCR_RFEN));

    DP_DEBUG (DP_DEBUG_OPEN,
              (KERN_INFO "dp: RFCR set to 0x%x\n",
               DP_RFCR_RFEN | DP_RFCR_APM | DP_RFCR_AAB));
                    
    /* Turn on device interrupts */
    DP_REG32_WRITE (DP_IMR, (DP_IMR_RXOK  | DP_IMR_MIB   |
                             DP_IMR_RTABT | DP_IMR_RMABT |
                             DP_IMR_SSERR | DP_IMR_PHY));
    DP_REG32_WRITE (DP_IER, DP_IER_IE);

    /* Enable Tx/Rx */
    DP_REG32_WRITE (DP_CR, DP_CR_TXE | DP_CR_RXE);

    /* Increment module reference count */
    MOD_INC_USE_COUNT;

    return OK;
}

/* fa31x_close - close a device, and reclaim resources */
static int
fa31x_close (struct device *dev)
{
    u32                     iobase = dev->base_addr;
    struct fa31x_priv* priv   = dev->priv;

    /* Stop the Tx/Rx */
    /* XXX Do we need to do this ??? */
    DP_REG32_WRITE (DP_CR, (DP_CR_TXD | DP_CR_RXD)); 

    /* Reset the device */
    fa31x_dev_reset (iobase);
    
    /* Uninstall the interrupt vector */
    free_irq (dev->irq, dev);

    /* Free the Tx and Rx queues */
    fa31x_queue_delete (&priv->tx_queue);
    fa31x_queue_delete (&priv->rx_queue);

    /* Decrement module reference count */
    MOD_DEC_USE_COUNT;
    
    return OK;
}

/*
 * fa31x_start_xmit - transmit an ethernet packet.
 *
 * This routine writes to a tx descriptor, sets the ownership bit of the
 * CMDSTS, and signals the chip
 */
static int
fa31x_start_xmit (struct sk_buff *skb, struct device *dev)
{
    u32        iobase = dev->base_addr;
	u32        cmdsts;
    virt_addr  tx_desc;
    struct enet_statistics *stats_p;

    if (skb->len > ETH_MAX_PKT_SIZE)
        return ERROR;

	tx_desc = fa31x_tx_desc_get(dev);
    if (tx_desc == NULL) {
        set_bit (0, &dev->tbusy);
        DP_REG32_SET (DP_IMR, DP_IMR_TXOK | DP_IMR_TXIDLE);
        tx_desc = fa31x_tx_desc_get (dev);
    }

    stats_p = &((struct fa31x_priv *)(dev->priv))->stats;

    /* Update tx_desc to point to SKB data, set CMDSTS, and signal the chip */
    if (tx_desc != NULL) {

		/* Reclaim SKBs from the TX queue */
        if (DP_DESC_SKBPTR_GET (tx_desc))
			fa31x_tx_skb_reclaim (dev, tx_desc);

		/* update statistics of the previous transmit */
		cmdsts = DP_DESC_CMDSTS_XLATE_GET (tx_desc);

                if(DP_REG32_READ(DP_ISR) & DP_ISR_TXERR) {  /*modified by Pam 2001/7/16 */

		/* if (cmdsts & DP_DESC_CMDSTS_TX_ERRORS) { */

			stats_p->tx_errors++;
			
			/* Update individual counters */

			stats_p->collisions += DP_DESC_CMDSTS_TX_COLLISIONS_GET(cmdsts);

			if (cmdsts & DP_DESC_CMDSTS_TX_TXA) /* tx aborted */
				stats_p->tx_packets--;
			
			if (cmdsts & DP_DESC_CMDSTS_TX_TFU) /* fifo errors */
				stats_p->tx_fifo_errors++;

			if (cmdsts & DP_DESC_CMDSTS_TX_CRS) /* lost carrier */
				stats_p->tx_carrier_errors++;

			if (cmdsts & DP_DESC_CMDSTS_TX_OWC) /* out of window collisions */
				stats_p->tx_window_errors++;
		}
        
		/* Update the descriptor */
        DP_DESC_CMDSTS_XLATE_SET (tx_desc, DP_DESC_CMDSTS_OWN|skb->len);
        DP_DESC_BUFPTR_XLATE_SET (tx_desc, skb->data);
        DP_DESC_SKBPTR_SET (tx_desc, (u32)skb);
        
        dev->trans_start = jiffies;
        DP_REG32_SET (DP_CR, DP_CR_TXE);
        DP_DEBUG (DP_DEBUG_TX, 
                  (KERN_INFO "Tx: tx_desc=0x%x ", (u32)tx_desc));
        stats_p->tx_packets++;
    } else 
        stats_p->tx_dropped++;

    return OK;
}

/*
 * fa31x_start_receive - receive the data from a Rx Queue descriptor
 *
 * This routine receives the data from Rx queue as long as it gets a valid
 * rx_descriptor and resets the descriptor's CMDSTS field back to the Buffer
 * size, and updates the BUFPTR and SKBPTR fields to the newly allocated SKB.
 */
static int
fa31x_start_receive (struct device *dev)
{
    u32         cmdsts;
	int         len;
	bool        do_copy;
    virt_addr   rx_desc;
    struct sk_buff *cur_skb;
    struct sk_buff *new_skb;
	struct sk_buff *rx_skb;
    struct enet_statistics *stats_p;
    
    stats_p = &((struct fa31x_priv *)(dev->priv))->stats;
    
    for (rx_desc = fa31x_rx_desc_get(dev);
         (rx_desc != NULL);
		 rx_desc = fa31x_rx_desc_get(dev)) {
        
        DP_DEBUG (DP_DEBUG_RX, 
                  (KERN_INFO "Rx: rx_desc=0x%x, CMDSTS = 0x%x",
                   (u32)rx_desc, DP_DESC_CMDSTS_XLATE_GET(rx_desc)));

        cmdsts = DP_DESC_CMDSTS_XLATE_GET (rx_desc);

        /* Send the packet to the stack if no errors */
        if ((cmdsts & DP_DESC_CMDSTS_RX_ERRORS) == 0) {

			len = (cmdsts & DP_DESC_CMDSTS_SIZE) - ETH_CRC_LEN;

			/*
			 * Allocate a new SKB
			 * small data packets less than DP_RX_COPY_THRESHOLD are copied
			 * into the new SKB, other allocate one to replace the current SKB.
			 */
			if (len < DP_RX_COPY_THRESHOLD) {
				do_copy = TRUE;
				new_skb = alloc_skb (len + 2, GFP_ATOMIC);
			} else {
				do_copy = FALSE;
				new_skb = alloc_skb (ETH_MAX_PKT_SIZE, GFP_ATOMIC);
			}
		
            if (new_skb) {
                cur_skb = (struct sk_buff *) DP_DESC_SKBPTR_GET (rx_desc);

				if (do_copy) {
					/* Copy data from current SKB and send the new SKB up */
					rx_skb = new_skb;
					skb_reserve (rx_skb, 2);
					memcpy (skb_put(rx_skb, len), cur_skb->data, len);
				} else {
					/* Replace the the current SKB with the new SKB */
					rx_skb = cur_skb;
					DP_DESC_BUFPTR_XLATE_SET (rx_desc, new_skb->data);
					DP_DESC_SKBPTR_SET (rx_desc, (u32) new_skb);
					(void) skb_put(rx_skb, len);
				}

				/* update the SKB and set it up */
				rx_skb->dev = dev;
				rx_skb->protocol = eth_type_trans (rx_skb, dev);

				netif_rx (rx_skb);

				dev->last_rx = jiffies;
				stats_p->rx_packets++; 
            } else 
                stats_p->rx_dropped++; /* no resources */
			if (cmdsts & DP_DESC_CMDSTS_RX_DEST_MC)
				stats_p->multicast++;
        }
        else {
            stats_p->rx_errors++; /* bad packet */

			/* Update individual counters */
			if (cmdsts & (DP_DESC_CMDSTS_RX_RUNT |
						  DP_DESC_CMDSTS_RX_LONG))
				stats_p->rx_length_errors++;

			if (cmdsts & DP_DESC_CMDSTS_RX_CRCE)
				stats_p->rx_crc_errors++;

			if (cmdsts & DP_DESC_CMDSTS_RX_FAE)
				stats_p->rx_frame_errors++;

			if (cmdsts & DP_DESC_CMDSTS_RX_RXO)
				stats_p->rx_fifo_errors++;
		}

        /* Cleanup the descriptor and make available for reception */
        DP_DESC_CMDSTS_XLATE_SET (rx_desc, ETH_MAX_PKT_SIZE);
    }
    return OK;
}

/* fa31x_get_stats - get current device statistics */
static struct enet_statistics *
fa31x_get_stats (struct device *dev)
{
    return &((struct fa31x_priv *)(dev->priv))->stats;
}

/* fa31x_set_multicast_list - sets multicast, & promiscuous mode */
static void
fa31x_set_multicast_list (struct device *dev)
{
    u32      iobase = dev->base_addr;
    u16   hash_table[32];
    u32      rfcr_flags;
    int   i;
    struct dev_mc_list * mc_list;
    

    /* default RFCR mode */
    rfcr_flags = DP_RFCR_APM | DP_RFCR_AAB | DP_RFCR_RFEN;

    /* Setup promiscuous mode */
    if (dev->flags & IFF_PROMISC) {
        DP_DEBUG (DP_DEBUG_OPEN,
                  (KERN_INFO "IFF_PROMISC\n"));
        rfcr_flags = (DP_RFCR_AAU | DP_RFCR_AAM | DP_RFCR_AAB |
                      DP_RFCR_RFEN);
            
    } else if (dev->flags & IFF_ALLMULTI) {

        /* Receive all multicast packets */
        DP_DEBUG (DP_DEBUG_OPEN,
                  (KERN_INFO "IFF_ALLMULTI\n"));
        rfcr_flags |= DP_RFCR_AAM;
    } else {

        /* Setup to receive programmed multicast packets */
        memset (hash_table, 0, 32);
        for (i=0, mc_list=dev->mc_list; mc_list && i < dev->mc_count;
             i++, mc_list = mc_list->next) {
			DP_DEBUG (DP_DEBUG_OPEN,
					  (KERN_INFO "mc_addr=%p\n", mc_list->dmi_addr));
            set_bit (fa31x_crc((char *)mc_list->dmi_addr) & 0x1ff, hash_table);
        }

        /* install the hash table */
        for (i=0; i<32; i++) {
            DP_REG32_WRITE (DP_RFCR, DP_RFCR_RFADDR_FMEM_LO + i*2);
            DP_REG32_WRITE (DP_RFDR, (u32) hash_table[i]);
        }

        rfcr_flags |= DP_RFCR_MHEN;
    }

    DP_REG32_WRITE (DP_RFCR, 0);
    DP_REG32_WRITE (DP_RFCR, rfcr_flags);
    DP_DEBUG (DP_DEBUG_OPEN,
              (KERN_INFO "MC Setup RFCR flags=0x%x\n", rfcr_flags));

    return;
}

/* fa31x_crc - computer CRC for hash table entries */
static int
fa31x_crc (char * mc_addr)
{
    u32    crc;
    u8    cur_byte;
    u8    msb;
    u8    byte, bit;

    crc = ~0;
    for (byte=0; byte<6; byte++) {
        cur_byte = *mc_addr++;
        for (bit=0; bit<8; bit++) {
            msb = crc >> 31;
            crc <<= 1;
            if (msb ^ (cur_byte & 1)) {
                crc ^= DP_POLYNOMIAL;
                crc |= 1;
            }
            cur_byte >>= 1;
        }
    }
    crc >>= 23;

    return (crc);
}

/* fa31x_interrupt - handle driver specific ioctls */
static int
fa31x_ioctl (struct device *dev, struct ifreq *rq, int cmd)
{
    return -EOPNOTSUPP;
}

/* 02/15/2000 */
static u32 PreviousLinkStatus=0;
/* fa31x_interrupt - handle the interrupts */
static void
fa31x_interrupt (int irq, void *dev_id, struct pt_regs *regs)
{
    struct device * dev = dev_id;
    u16  iobase = dev->base_addr;
    u32  reg_isr;
    u32  CurrentLinkStatus;
    
    CurrentLinkStatus= DP_REG32_READ(DP_PHYSTS);
#define HAL_PHY_SPEED10   0x00000002
    if(PreviousLinkStatus!=CurrentLinkStatus)
	{
		if(CurrentLinkStatus & HAL_PHY_SPEED10)
		{
			DP_REG32_WRITE(DP_PHY_PAGE,0x0001);
			DP_REG32_WRITE(DP_PHY_EXTCFG,0x0000);
			DP_REG32_WRITE(DP_PHY_PAGE,0x0000);
		}
               else
               {
			DP_REG32_WRITE(DP_PHY_PAGE,0x0001);
                        DP_REG32_WRITE(DP_PHY_EXTCFG,0x0010);
                        DP_REG32_WRITE(DP_PHY_PAGE,0x0000);
 
		}
		PreviousLinkStatus=CurrentLinkStatus;
	}

    reg_isr = DP_REG32_READ (DP_ISR);
    
    DP_DEBUG (DP_DEBUG_IOCTL,
              (KERN_INFO "%s: intr_status=0x%x\n", dev->name,
               reg_isr));
    if (reg_isr & DP_ISR_RXOK)
        fa31x_start_receive (dev);

    if (reg_isr & (DP_ISR_TXOK | DP_ISR_TXIDLE)) {
        DP_REG32_CLR (DP_IMR, (DP_IMR_TXOK|DP_IMR_TXIDLE));
        clear_bit (0, &dev->tbusy);
        mark_bh (NET_BH);
    }
}

/* fa31x_mac_address_set - set the ethernet address */
static void
fa31x_mac_address_set (u32 iobase, char *mac_addr)
{
    u16 *    mac_addr_ptr;
    int i;

    for (i=0, mac_addr_ptr = (u16 *)mac_addr; i<3; i++, mac_addr_ptr++) {
        DP_REG32_WRITE (DP_RFCR, DP_RFCR_RFADDR_PMATCH1 + i*2);
        DP_REG32_WRITE (DP_RFDR, CPU_TO_BUS_SWAP_16 (*mac_addr_ptr));
    }
}

/* fa31x_mac_address_get - get the ethernet address */
static void
fa31x_mac_address_get (u32 iobase, char *mac_addr)
{
    u16 *  mac_addr_ptr=(u16 *)mac_addr;
    int    i;
   u16 mask;
   u16 word1 = 0;
   u16 word2 = 0;
   u16 word3 = 0;
   u16 word4 = 0;
   u16 nicAddress[ 3 ];

   //
   // Read 16 bit words 6 - 9 from the EEProm.  They contain the hardwares MAC
   // address in a rather cryptic format.
   //
   ReadEEWord( iobase,
	       0x06,
	       &word1 );
   ReadEEWord( iobase,
	       0x07,
	       &word2 );
   ReadEEWord( iobase,
	       0x08,
	       &word3 );
   ReadEEWord( iobase,
	       0x09,
	       &word4 );

   //
   // Decode the cryptic format into what we can use a word at a time.
   //
   nicAddress[ 0 ] = word1 & 1;
   nicAddress[ 1 ] = word2 & 1;
   nicAddress[ 2 ] = word3 & 1;

   i = 15;
   mask = 0x2;
   while ( i-- ) {
      if ( word2 & 0x8000 ) {
	 nicAddress[ 0 ] |= mask;
      }
      word2 = word2 << 1;
      mask = mask << 1;
   }
//printk("word0=%x\n",nicAddress[0]);
  *mac_addr_ptr=nicAddress[0];
  mac_addr_ptr++;


   i = 15;
   mask = 0x2;
   while ( i-- ) {
      if ( word3 & 0x8000 ) {
	 nicAddress[ 1 ] |= mask;
      }
      word3 = word3 << 1;
      mask = mask << 1;
   }
//printk("word1 =%x\n",nicAddress[1]);

  *mac_addr_ptr=nicAddress[1];
 mac_addr_ptr++;

   i = 15;
   mask = 0x2;
   while ( i-- ) {
      if ( word4 & 0x8000 ) {
	 nicAddress[ 2 ] |= mask;
      }
      word4 = word4 << 1;
      mask = mask << 1;
   }
//printk("word2 =%x\n",nicAddress[2]);

  *mac_addr_ptr=nicAddress[2];

}

/* fa31x_dev_reset - soft reset FA311/FA312 */
static status
fa31x_dev_reset (u32 iobase)
{
    int  timeout = 100;     /* XXX cleanup: use macro */
    
    DP_REG32_WRITE (DP_CR, DP_CR_RST);
    while (timeout--) {
        if (DP_REG32_READ (DP_ISR) == 0x03008000) {
            return (OK);
        }
        udelay (5);
    }
    return ERROR;
}

/*
 * fa31x_queue_create - create a circular queue of descriptors
 *
 * This routine allocates a descriptor buffer array aligned  on a word
 * boundary, initializes and links the array to make a circular queue.
 */
static status
fa31x_queue_create (struct fa31x_queue *q, int count, int qtype)
{
    virt_addr     desc_addr;
    int           i;
    struct sk_buff *skb;
    
    /* allocate the desc buffer array */
    q->qbuf = (virt_addr) kmalloc (DP_QUEUE_ELE_SIZE * count + DP_ALIGN,
                                   GFP_DMA);
    if (q->qbuf == (virt_addr) NULL)
        return ERROR;

    memset ((char *)q->qbuf, 0, DP_QUEUE_ELE_SIZE * count + DP_ALIGN);

    /* Adjust alignment and Initialize queue data */
    q->cur_desc_addr =
        q->first_desc_addr =
        (virt_addr)(((u32)q->qbuf + DP_ALIGN) & ~(DP_ALIGN - 1));
    q->last_desc_addr = q->first_desc_addr + ((count -1) * DP_QUEUE_ELE_SIZE);
    q->count = count;

    /* Initialize each buffer descriptor, and link them into circular queue */
    for (i=0, desc_addr=q->first_desc_addr; i<count;
         i++, desc_addr+=DP_QUEUE_ELE_SIZE) {
        DP_DESC_LNK_XLATE_SET (desc_addr, desc_addr + DP_QUEUE_ELE_SIZE);

        /* Update the size, BUFPTR, and SKBPTR fields for RX descriptors */
        if (qtype == DP_QUEUE_TYPE_RX) {
            skb = alloc_skb (ETH_MAX_PKT_SIZE, GFP_ATOMIC);
            if (skb == NULL) {
                fa31x_queue_delete (q);
                return (ERROR);
            }
            DP_DESC_CMDSTS_XLATE_SET (desc_addr, ETH_MAX_PKT_SIZE);
            DP_DESC_BUFPTR_XLATE_SET (desc_addr, skb->data);
            DP_DESC_SKBPTR_SET (desc_addr, (u32) skb);
        }
    }
    /* Make the queue circular */
    DP_DESC_LNK_XLATE_SET (q->last_desc_addr, q->first_desc_addr);

    return OK;
}

/* fa31x_queue_delete - frees an allocated descriptor queue */
static status
fa31x_queue_delete (struct fa31x_queue *q)
{
    int       i;
    virt_addr desc_addr;
    struct sk_buff *skb;
        
    /* Free all SKBs in the queue */
    for (i=0, desc_addr=q->first_desc_addr;
         (i < q->count);
         i++, desc_addr += DP_QUEUE_ELE_SIZE) {
        skb = (struct sk_buff *) DP_DESC_SKBPTR_GET (desc_addr);
        if (skb != NULL)
            dev_kfree_skb (skb);
    }

    /* Free the queue buffer */
    kfree ((char *)q->qbuf);
    
    return (OK);
}

/*
 * fa31x_tx_desc_get - get a valid transmit descriptor
 *
 * This routine returns the current descriptor from the tx_queue if driver is 
 * the owner, else returns NULL
 */
static virt_addr
fa31x_tx_desc_get (struct device *dev)
{
    struct fa31x_queue *   q;
    virt_addr                desc_addr = NULL;

    q = &((struct fa31x_priv *)(dev->priv))->tx_queue;

    /* Check if we own the descriptor */
    if  ((DP_DESC_CMDSTS_XLATE_GET (q->cur_desc_addr) & DP_DESC_CMDSTS_OWN)
         == 0) {
        desc_addr = q->cur_desc_addr;
        DP_QUEUE_ELE_NEXT (q);                 /* Move to the next element */
    }

    return desc_addr;
}

/* fa31x_tx_skb_reclaim - reclaim SKBs in transmitted descriptors */
static void
fa31x_tx_skb_reclaim (struct device *dev, virt_addr desc_addr)
{
	struct sk_buff *       skb;
	struct fa31x_queue * q;
	
    /* Reclaim buffers from all descriptors we own. */
    q = &((struct fa31x_priv *)(dev->priv))->tx_queue;
    while (((DP_DESC_CMDSTS_XLATE_GET(desc_addr) & DP_DESC_CMDSTS_OWN) == 0) &&
		   ((skb=(struct sk_buff *) DP_DESC_SKBPTR_GET(desc_addr)) != NULL)) {
		dev_kfree_skb (skb);
		DP_DESC_SKBPTR_SET (desc_addr, 0);
		desc_addr = DP_QUEUE_ELE_NEXT_GET (q, desc_addr);
    }
}

/*
 * fa31x_rx_desc_get - get a valid receive descriptor
 *
 * This routine returns the current descriptor from the rx_queue if driver is 
 * the owner, else returns NULL
 */
static virt_addr
fa31x_rx_desc_get (struct device *dev)
{
    struct fa31x_queue *   q;
    virt_addr                desc_addr = NULL;

    q = &((struct fa31x_priv *)(dev->priv))->rx_queue;

    /* Check if we own the descriptor */
    if  (DP_DESC_CMDSTS_XLATE_GET (q->cur_desc_addr) & DP_DESC_CMDSTS_OWN) {
        desc_addr = q->cur_desc_addr;
        DP_QUEUE_ELE_NEXT(q);                 /* Move to the next element */
    }

    return desc_addr;
}

/* fa31x_phy_setup - reset and setup the PHY device */
int link_speed=0;

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,2,0)
MODULE_PARM(link_speed, "i");
#endif

static status
fa31x_phy_setup (struct device *dev)
{
    u32  iobase = dev->base_addr;
    u32  dp_cfg_val;
    u16  phy_status;
    u16  timeout;
    u32  lnk_status;
    u32  lnk_check = 0;

    dp_cfg_val = DP_REG32_READ(DP_CFG);
    dp_cfg_val &= 0xFFFF1FFF;               /* clear auto-negotiation select */
    dp_cfg_val |= (DP_CFG_PESEL         |   /* parity error detect */
                   DP_CFG_PAUSE_ADV     |   /* pause capable */
                   DP_CFG_PINT_ACEN     |   /* phy intr auto clear */
                   0x00040000);             /* phy config */

    switch (link_speed) {
    case 1: /* Force 10Mb Half duplex */
        dp_cfg_val |= DP_CFG_ANEG_SEL_10_HD;
        break;

    case 2: /* Force 100Mb Half duplex */
        dp_cfg_val |= DP_CFG_ANEG_SEL_100_HD;
        break;

    case 3: /* Force 10Mb Full duplex */
        dp_cfg_val |= DP_CFG_ANEG_SEL_10_FD;
        break;

    case 4: /* Force 100Mb Full duplex */
        dp_cfg_val |= DP_CFG_ANEG_SEL_100_FD;
        break;

    default:
	printk (KERN_INFO "Usage: insmod fa31x link_speed=n (n=0...4)");
        printk (KERN_INFO "Force to 10/100 full/half autonegotiate mode)");
    case 0: /* Autonegotiate 10/100 full/half */
        dp_cfg_val |= DP_CFG_ANEG_SEL_AUTO;
        break;
    }

    DP_REG32_WRITE (DP_CFG, dp_cfg_val | DP_CFG_PHY_RST);
    udelay (500);

    DP_REG32_WRITE (DP_CFG, dp_cfg_val);
    for (timeout=10000; timeout; timeout--) {

        lnk_status = DP_REG32_READ (DP_CFG);

        switch (link_speed) {
        case 1: /* Force 10Mb Half duplex */
            if (!(lnk_status & (DP_CFG_SPEED100 | DP_CFG_FDUP))) {
                lnk_check = 1;
                break;
            }
            udelay (500);
            break;

        case 2: /* Force 100Mb Half duplex */
            if ((lnk_status & (DP_CFG_SPEED100 | DP_CFG_FDUP))
                == DP_CFG_SPEED100) {
                lnk_check = 1;
                break;
            }
            udelay (500);
            break;

        case 3: /* Force 10Mb Full duplex */
            if ((lnk_status & (DP_CFG_ANEG_DN | DP_CFG_SPEED100))
                == DP_CFG_ANEG_DN) {
                lnk_check = 1;
                break;
            }
            udelay (500);
            break;

        case 4: /* Force 100Mb Full duplex */
            if ((lnk_status & (DP_CFG_ANEG_DN | DP_CFG_SPEED100))
                == (DP_CFG_ANEG_DN | DP_CFG_SPEED100)) {
                lnk_check = 1;
                break;
            }
            udelay (500);
            break;

        case 0: /* Autonegotiate 10/100 full/half */
        default:
            if (DP_REG32_READ (DP_CFG) & DP_CFG_ANEG_DN) {
                lnk_check = 1;
                break;
            }
            udelay (500);
        }

        if (lnk_check)
            break;
    }

    if (timeout == 0) {
        DP_DEBUG (DP_DEBUG_ANEG, (KERN_INFO "Phy Autonegotiate Failed\n"));
        return (ERROR);
    }
    DP_REG32_WRITE (DP_PHY_PAGE, DP_PHY_PAGE_VAL);
    DP_REG32_WRITE (DP_PHYCR, DP_PHYCR_PMDCSR_VAL);
    DP_REG32_WRITE (DP_PHY_TDATA, DP_PHY_TDATA_VAL);
    DP_REG32_WRITE (DP_PHY_DSPCFG, DP_PHY_DSPCFG_VAL);
    DP_REG32_WRITE (DP_PHY_SDCFG, DP_PHY_SDCFG_VAL);
    DP_REG32_WRITE (DP_PHY_PAGE, (u16) 0x0000);

                        
    phy_status = DP_REG16_READ (DP_PHYSTS);
    printk (KERN_INFO "%s: speed=%d duplex=%s link=%s\n",
            dev->name,
            (phy_status & DP_PHYSTS_SPEED_10) ? 10 : 100,
            (phy_status & DP_PHYSTS_FDX)? "full" : "half",
            (phy_status & DP_PHYSTS_LNK_VALID) ? "up" : "down");

    return (OK);
}

#if 0
/* swap_16 - swap a 16 bit value between little endian & big endian byteorder */
static u16 swap_16 (u16 us)
{
    return ((us << 8) & 0xff00) | ((us >> 8) & 0x00ff);
}
#endif

#if 0 /* Not used */
/* swap_32 - swap a 32 bit value between little endian & big endian byteorder */
static u32 swap_32 (u32 ui)
{
    return ((swap_16 (ui & 0x0000ffff) << 16) | swap_16 (ui >> 16));
}
#endif

/* io_read_16 - read the 16 bit value stored at given io address */
static u16 io_read_16 (u16 io_port)
{
    return inw (io_port);
}

#if 0 /* Not used */
/* io_write_16 - write the 16 bit data at given io address */
static void io_write_16 (u16 io_port, u16 data)
{
    outw (data, io_port);
}
#endif

/* io_read_32 - read the 32 bit value stored at given io address*/
static u32 io_read_32 (u16 io_port)
{
    return inl (io_port);
}

/* io_write_32 - write the 32 bit data at given io address */
static void io_write_32 (u16 io_port, u32 data)
{
    outl (data, io_port);
}

#ifdef DEBUG
/* fa31x_desc_info - print info on descriptors
 *
 * This routine displays values of the elements of fa31x_queue;
 * if option is -1, prints info on all the descs and their field vals;
 * and in all other cases prints info on the  specified descriptor.
 */

static void fa31x_desc_info (struct fa31x_queue * q, int option)
{
    virt_addr    desc_addr;
    u32          i;

    /* Display info header */
    printk ( KERN_DEBUG "fa31x_desc_info(): q=0x%x, "
             "first_desc_addr=0x%x, last_desc_addr=0x%x cur_desc_addr=0x%x\n",
             (u32)q,  (u32)q->first_desc_addr,
             (u32)q->last_desc_addr, (u32)q->cur_desc_addr);

    /* Print requested element info */
    switch (option) {
    case -1:                                 /* all elements */
        desc_addr = q->first_desc_addr;
        for (i=0; i<q->count; i++) {
            printk (KERN_DEBUG "desc_addr=0x%x link=0x%x "
                    "cmdsts=0x%x bufptr=0x%x\n",
                    (u32)desc_addr, DP_DESC_LNK_GET (desc_addr),
                    DP_DESC_CMDSTS_GET (desc_addr),
                    DP_DESC_BUFPTR_GET (desc_addr));
            desc_addr += DP_QUEUE_ELE_SIZE;
        }
        break;
        
    default:                                 /* a specific element */
        if (option > q->count) {
            printk (KERN_DEBUG "Can't print info for ele=%d when count=%d\n",
                    option, q->count);
        }
        else {
            desc_addr = q->first_desc_addr + (DP_QUEUE_ELE_SIZE * (option - 1));
            printk (KERN_DEBUG "ele=%d desc_addr=0x%x link=0x%x "
                    "cmdsts=0x%x bufptr=0x%x\n",
                    option, (u32)desc_addr, DP_DESC_LNK_GET (desc_addr),
                    DP_DESC_CMDSTS_GET (desc_addr),
                    DP_DESC_BUFPTR_GET (desc_addr));
        }
    }
}


/* fa31x_regs_info - prints values of registers */
static void fa31x_regs_info (u16 iobase)
{
    printk (KERN_INFO "dp(0x%x): CFG=0x%x IMR=0x%x IER=0x%x\n",
            iobase, DP_REG32_READ (DP_CFG), DP_REG32_READ (DP_IMR),
            DP_REG32_READ (DP_IER));
    printk (KERN_INFO " ++ TXDP=0x%x TXCFG=0x%x RXDP=0x%x RXCFG=0x%x\n",
            DP_REG32_READ (DP_TXDP), DP_REG32_READ (DP_TXCFG),
            DP_REG32_READ (DP_RXDP), DP_REG32_READ (DP_RXCFG));
}
#endif

#ifdef MODULE

/*
 * init_module - Initialize the driver module
 *
 * This routine is called to initialize the driver when the module in
 * installed into a running kernel via insmod.
 *
 */

int
init_module (void)
{
    printk (KERN_INFO "%s", version);
    return fa31x_probe (NULL);
}

/*
 * cleanup_module - Deinstall the driver module.
 *
 * This routine is called when removing the driver module from a running
 * kernel via rmmod.
 *
 */

void
cleanup_module (void)
{
    struct device *cur_dev;

    cur_dev=fa31x_dev_list;
    while (cur_dev) {
        fa31x_dev_list = ((struct fa31x_priv *)(cur_dev->priv))->next;
        unregister_netdev (cur_dev);
        release_region (cur_dev->base_addr, FA31x_PCI_IO_SIZE);
        kfree (cur_dev);
        cur_dev = fa31x_dev_list;
    }
}
#endif /* MODULE */

static void  ReadEEWord(u16 iobase,u32 wordOffset,u16* pEeData)
{
#define DP_MEAR 0x08
#define EECLK  0x00000004
#define EECS   0x00000008
#define EEDI   0x00000001
#define EEDO   0x00000002

u32 i = 9;
u32 mask = 0x100;
u32 command = 0x180 | wordOffset;
u32 data;
u32 temp;
   //
   // Start the sequence with Chip Select 0 for a 4 microsecond cycle.
   //
   DP_REG32_WRITE (DP_MEAR, 0);
   udelay( 2 );
   DP_REG32_WRITE (DP_MEAR, EECLK );
   udelay( 2 );
   //
   // Write out the read command, one bit at a time, insuring that each transition
   // of the clock lasts at least 2 microseconds.
   //
   while ( i-- ) {
      data = ( command & mask ) ? EECS | EEDI : EECS;
      DP_REG32_WRITE(DP_MEAR, data );
      udelay( 2 );
      DP_REG32_WRITE(DP_MEAR, data | EECLK );
      udelay( 2 );
      mask = mask >> 1;
   }
   //
   // Read in the 16 bits of data, one bit at a time, insuring that each
   // transition of the clock lasts at least 2 microseconds.
   //
   i = 16;
   mask = 0x8000;
   data = 0;
   while ( i--) {
      DP_REG32_WRITE(DP_MEAR,  EECS );
      udelay( 2 );
      DP_REG32_WRITE(DP_MEAR, EECS | EECLK );
      udelay( 2 );
      temp = DP_REG32_READ(DP_MEAR);
      if ( temp & EEDO ) {
	 data |= mask;
      }
    mask = mask >> 1;
  }
  *pEeData = ( u16 )data;
}




/*
 * Local variables:
 * 
 * for Redhat 5.2/6.0/6.x
 compile-command: "gcc -D__KERNEL__ -DMODULE -Wall -Wstrict-prototypes -O -m486 -c fa31x.c"
 * for Redhat 7.0
 compile-command: "kgcc -D__KERNEL__ -DMODULE -Wall -Wstrict-prototypes -O -m486 -c fa31x.c -I/usr/src/linux/include"
 *  version-control: t
 *  kept-new-versions: 5
 * End:
 */
