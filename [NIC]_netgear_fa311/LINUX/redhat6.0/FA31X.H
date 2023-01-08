
/* fa31x.h - NETGEAr FA311/FA312 PCI Adapter */
/* This is the Rev 3 of the driver and the changes for the Rev C of FA311/FA312 
 * have been included */ 

#ifndef __FA31x_H__
#define __FA31x_H__

#ifdef __KERNEL__
#include <linux/types.h>
#endif

#define DP_DEV_NAME        "NETGEAR FA311/FA312 PCI Adapter"
#define DP_DRV_NAME        "fa311/fa312"

/* PCI Confiugration Registers */

#undef  PCI_VENDOR_ID_NS_83815
#define PCI_VENDOR_ID_NS_83815  0x0020 /* FA311/FA312 */

#define	FA31x_PCI_IO_SIZE		256

/*
 * Operational Registers:
 * These registers mapped either into PCI memory space or I/O space.
 */

/* MAC/BIU Registers */

#define DP_CR               0x00 /* Command Register */
#define DP_CFG              0x04 /* Configuration Register */
#define DP_MEAR             0x08 /* EEPROM Access Register */
#define DP_PTSCR            0x0C /* PCI Test Control Register */
#define DP_ISR              0x10 /* Intr Status Register */
#define DP_IMR              0x14 /* Intr Mask Register */
#define DP_IER              0x18 /* Intr Enable Register */
#define DP_TXDP             0x20 /* Tx Descriptor Pointer Register */
#define DP_TXCFG            0x24 /* Tx Configuration Register */
#define DP_RXDP             0x30 /* Rx Descriptor Pointer Register */
#define DP_RXCFG            0x34 /* Rx Configuration Register */
#define DP_CCSR             0x3C
#define DP_WCSR             0x40 /* Wake on LAN Control/Status Register */
#define DP_PCR              0x44 /* Pause Control/Status Register */
#define DP_RFCR             0x48 /* Rx Filter/Match Control Register */
#define DP_RFDR             0x4C /* Rx Filter/Match Data Register */
#define DP_BRAR             0x50 /* Boot ROM Address */
#define DP_BRDR             0x54 /* Boot ROM Data */
#define DP_SRR              0x58 /* Silicon Revision Register (RO) */
#define DP_MIBC             0x5C /* MIB Control Registor */
#define DP_MIB              0x60 /* MIB Data Register Base (RO) */

/* MIB Registers */

#define DP_MIB_RX_PKT_ERR   0x60 /* Pkts recvd with errors */
#define DP_MIB_RX_FCS_ERR   0x64 /* Pkts recvd with frame check seq errs */
#define DP_MIB_RX_MISS_PKT  0x68 /* Pkts missed due to FIFO  overruns*/
#define DP_MIB_RX_FA_ERR    0x6C /* Pkts recvd with frame alignment errs */
#define DP_MIB_RX_SYM_ERR   0x70 /* Pkts recvd with symbol errs */
#define DP_MIB_RX_LONG_FRM  0x74 /* Pkts > 1518 bytes */
#define DP_MIB_TXSQE_ERR    0x78 /* Loss of coll. heartbeat on Tx */

/* Internal Phy Registers */

#define DP_BMCR             0x80 /* Basic Mode Control Register */
#define DP_BMSR             0x84 /* Basic Mode Status Register (RO) */
#define DP_PHYIDR1          0x88 /* PHY Identifier Register #1 (RO) */
#define DP_PHYIDR2          0x8C /* PHY Identifier Register #2 (RO) */
#define DP_ANAR             0x90 /* Auto-Nego Advertisment Reg */
#define DP_ANLPAR           0x94 /* Auto-Nego Link Partner Ability Reg */
#define DP_ANER             0x98 /* Auto-Negotiation Expansion Reg */
#define DP_ANNPTR           0x9C /* Auto-Negotiation Next Page TX */
#define DP_PHYSTS           0xC0 /* PHY Status Register (RO) */
#define DP_FCSCR            0xD0 /* False Carrier Sense Counter Reg */
#define DP_RECR             0xD4 /* Recv Error Counter Register */  
#define DP_PHYCR            0xE4 /* PHY Control Register */  
#define DP_10BTSCR          0xE8 /* 10Base-TStatus/Control Reg */ 

/* New Phy registers and their bit mask values for Rev 3 */    

#define DP_PHY_PAGE        0xCC /* */
#define DP_PHY_EXTCFG      0xF0 /*2000*/     
#define DP_PHY_DSPCFG      0xF4 /* */
#define DP_PHY_SDCFG       0xF8 /* */
#define DP_PHY_TDATA       0xFC /* */

#define DP_PHY_PAGE_VAL        (u16)0x0001 /* */
#define DP_PHY_DSPCFG_VAL      (u16)0x5040 /* Load/Kill C2 */
#define DP_PHY_SDCFG_VAL       (u16)0x008C /* Raise SD off, from 4 to C */
#define DP_PHY_TDATA_VAL       (u16)0x0000 /* Set value for C2 */
#define DP_PHYCR_PMDCSR_VAL    (u16)0x189C /* DC Speed = 01 */

/*
 * Command Register Bit Masks (DP_CR)
 *
 * This register is used for issuing commands to FA311. A global software
 * reset along with individual reset and enable/disable switches for
 * transmitter and receiver are provided here.
 */

#define DP_CR_TXE           0x00000001 /* Transmit Enable */
#define DP_CR_TXD           0x00000002 /* Transmit Disable */
#define DP_CR_RXE           0x00000004 /* Receiver Enable */
#define DP_CR_RXD           0x00000008 /* Receiver Disable */
#define DP_CR_TXR           0x00000010 /* Transmit Reset */
#define DP_CR_RXR           0x00000020 /* Receiver Reset */
#define DP_CR_SWI           0x00000080 /* Software Interrupt */
#define DP_CR_RST           0x00000100 /* Reset */

/*
 * Configuration and Media Status Register Bit Masks (DP_CFG)
 *
 * This register allows configuration of a various device and phy options,
 * and provide phy status information.
 */

#define DP_CFG_BEM              (u32)0x00000001 /* Big Endian Mode (BM xfers) */
#define DP_CFG_BROM_DIS         (u32)0x00000004 /* Disable Boot ROM interface */
#define DP_CFG_PESEL            (u32)0x00000008 /* Parity Err Det (BM xfer) */
#define DP_CFG_EXD              (u32)0x00000010 /* Excessv Deferl Tmr disbl */ 
#define DP_CFG_POW              (u32)0x00000020 /* Prog Out of Window Timer */
#define DP_CFG_SB               (u32)0x00000040 /* Single Back-off */
#define DP_CFG_REQALG           (u32)0x00000080 /* PCI Bus Request Algorithm */
#define DP_CFG_EUPHCOMP         (u32)0x00000100 /* DP83810 Descriptor Compat */ 
#define DP_CFG_PHY_DIS          (u32)0x00000200 /* Disable internal Phy */
#define DP_CFG_PHY_RST          (u32)0x00000400 /* Reset internal Phy */
#define DP_CFG_ANEG_SEL         (u32)0x0000E000 /* Auto-nego Sel - Mask */
#define DP_CFG_ANEG_SEL_10_HD   (u32)0x00000000 /*  Force 10Mb Half duplex */
#define DP_CFG_ANEG_SEL_100_HD  (u32)0x00004000 /*  Force 100Mb Half duplex */
#define DP_CFG_ANEG_SEL_10_FD   (u32)0x00002000 /*  Force 10Mb Full duplex */
#define DP_CFG_ANEG_SEL_100_FD  (u32)0x0000A000 /*  Force 100Mb Full duplex */
#define DP_CFG_ANEG_SEL_AUTO    (u32)0x0000E000 /*  Nego 10/100 Half/Full dplx*/
#define DP_CFG_PAUSE_ADV        (u32)0x00010000 /* Strap for pause capable */
#define DP_CFG_PINT_ACEN        (u32)0x00020000 /* Phy Intr Auto Clr Enable */ 
#define DP_CFG_PHY_CFG          (u32)0x00FC0000 /* Phy Configuration */
#define DP_CFG_ANEG_DN          (u32)0x08000000 /* Auto-negotiation Done */
#define DP_CFG_POL              (u32)0x10000000 /* 10Mb Polarity Indication */
#define DP_CFG_FDUP             (u32)0x20000000 /* Full Duplex */
#define DP_CFG_SPEED100         (u32)0x40000000 /* Speed 100Mb */
#define DP_CFG_LNKSTS           (u32)0x80000000 /* Link status */

/*
 * EEPROM Access Register Bit Masks (DP_MEAR)
 *
 * Provides an interface for software access to the NMC9306 style EEPROM.  The
 * default values given assume that the EEDO line has a pullup resistor to
 * VDD.
 */

#define DP_MEAR_EEDI            (u32)0x00000001 /* EEPROM data in */
#define DP_MEAR_EEDO            (u32)0x00000002 /* EEPROM data out */
#define DP_MEAR_EECLK           (u32)0x00000004 /* EEPROM Serial Clock */
#define DP_MEAR_EESEL           (u32)0x00000008 /* EEPROM Chip Select */

/* PCI Test Control Register Bit Masks (DP_PTSCR) */

#define DP_PTSCR_EEBIST_FAIL    (u32)0x00000001 /* EE BIST Fail Indication */
#define DP_PTSCR_EEBIST_EN      (u32)0x00000002 /* Enable  EEPROM BIST */
#define DP_PTSCR_EELOAD_EN      (u32)0x00000004 /* Enable EEPROM Load */
#define DP_PTSCR_RBIST_RXFFAIL  (u32)0x00000008 /* RX Filter RAM BIST Fail */
#define DP_PTSCR_RBIST_TXFAIL   (u32)0x00000010 /* TX FiFO Fail */
#define DP_PTSCR_RBIST_RXFAIL   (u32)0x00000020 /* RX FIFO BIST Fail */
#define DP_PTSCR_RBIST_ACT      (u32)0x00000040 /* SRAM BIST Active*/
#define DP_PTSCR_RBIST_EN       (u32)0x00000080 /* SRAM BIST Enable */
#define DP_PTSCR_RBIST_MODE     (u32)0x00000100 /* SRAM BIST Mode */
#define DP_PTSCR_RBIST_CLKD     (u32)0x00000200 /* SRAM BIST Clock */
#define DP_PTSCR_RBIST_RST      (u32)0x00000400 /* SRAM BIST Reset */
#define DP_PTSCR_RESVD          (u32)0x00001000 /* Reserved -- Must be 1 */

/*
 * Interrupt Status Register Bit Masks (DP_ISR)
 *
 * Indicates the source of an interrupt when the INTA pin goes active.
 * Enabling the corresponding bit in the IMR allows bits in this reg to produce
 * an interrupt. ISR reflects all pending iterrupts regardless of the status
 * of the corresponding mask bit in the IMR.
 */

#define DP_ISR_RXOK             (u32)0x00000001 /* Rx OK */
#define DP_ISR_RXDESC           (u32)0x00000002 /* Rx Descriptor */
#define DP_ISR_RXERR            (u32)0x00000004 /* Rx packet Error */
#define DP_ISR_RXEARLY          (u32)0x00000008 /* Rx Early Threshold */
#define DP_ISR_RXIDLE           (u32)0x00000010 /* Rx Idle */
#define DP_ISR_RXORN            (u32)0x00000020 /* Rx Overrun */
#define DP_ISR_TXOK             (u32)0x00000040 /* Tx Packet OK */
#define DP_ISR_TXDESC           (u32)0x00000080 /* Tx Descriptor */
#define DP_ISR_TXERR            (u32)0x00000100 /* Tx Packet Error */
#define DP_ISR_TXIDLE           (u32)0x00000200 /* Tx Idle */
#define DP_ISR_TXURN            (u32)0x00000400 /* Tx Underrun */
#define DP_ISR_MIB              (u32)0x00000800 /* MIB Service */
#define DP_ISR_SWI              (u32)0x00001000 /* Software Interrupt */
#define DP_ISR_PME              (u32)0x00002000 /* Power Management Event */
#define DP_ISR_PHY              (u32)0x00004000 /* Phy Interrupt */
#define DP_ISR_HIBERR           (u32)0x00008000 /* High Bits error set */
#define DP_ISR_RXSOVR           (u32)0x00010000 /* Rx Status FIFO Overrun */
#define DP_ISR_RTABT            (u32)0x00100000 /* Recieved Target Abort */
#define DP_ISR_RMABT            (u32)0x00200000 /* Recieved Master Abort */
#define DP_ISR_SSERR            (u32)0x00400000 /* Signaled System Error */
#define DP_ISR_DPERR            (u32)0x00800000 /* Detected Parity Error */
#define DP_ISR_RXRCMP           (u32)0x01000000 /* Receive Reset Complete */
#define DP_ISR_TXRCMP           (u32)0x02000000 /* Transmit Reset Complete */

/*
 * Interrupt Mask Register Bit Masks (DP_IMR)
 *
 * Interrupts are enabled by setting the appropriate bit-mask.
 */

#define DP_IMR_RXOK              (u32)0x00000001 /* Rx ok */
#define DP_IMR_RXDESC            (u32)0x00000002 /* Rx Descriptor */
#define DP_IMR_RXERR             (u32)0x00000004 /* Rx packet Error */
#define DP_IMR_RXEARLY           (u32)0x00000008 /* Rx Early Threshold */
#define DP_IMR_RXIDLE            (u32)0x00000010 /* Rx Idle */
#define DP_IMR_RXORN             (u32)0x00000020 /* Rx Overrun */
#define DP_IMR_TXOK              (u32)0x00000040 /* Tx Packet Ok */
#define DP_IMR_TXDESC            (u32)0x00000080 /* Tx Descriptor */
#define DP_IMR_TXERR             (u32)0x00000100 /* Tx Packet Error */
#define DP_IMR_TXIDLE            (u32)0x00000200 /* Tx Idle */
#define DP_IMR_TXURN             (u32)0x00000400 /* Tx Underrun */
#define DP_IMR_MIB               (u32)0x00000800 /* MIB Service */
#define DP_IMR_SWI               (u32)0x00001000 /* Software Interrupt */
#define DP_IMR_PME               (u32)0x00002000 /* Power Management Event */
#define DP_IMR_PHY               (u32)0x00004000 /* Phy Interrupt */
#define DP_IMR_HIERR             (u32)0x00008000 /* High Bits error set */
#define DP_IMR_RXSOVR            (u32)0x00010000 /* Rx Status FIFO Overrun */
#define DP_IMR_RTABT             (u32)0x00100000 /* Recieved Target Abort */
#define DP_IMR_RMABT             (u32)0x00200000 /* Recieved Master Abort */
#define DP_IMR_SSERR             (u32)0x00400000 /* Signaled System Error */
#define DP_IMR_DPERR             (u32)0x00800000 /* Detected Parity Error */
#define DP_IMR_RXRCMP            (u32)0x01000000 /* Receive Reset Complete */
#define DP_IMR_TXRCMP            (u32)0x02000000 /* Transmit Reset Complete */

/*
 * Interrupt Enable Register Bit Masks (DP_IER)
 *
 * Enable or disable DP chip interrupts
 */

#define DP_IER_IE               (u32)0x00000001 /* Interrupt Enable */
#define DP_IER_ID               (u32)0x00000000 /* Interrupt Disable */

/* Transmit descriptor Pointer Register Bit Mask (DP_TXDP) */

#define DP_TXDP_MSK             (u32)0xFFFFFFFE /* Transmit Descriptor Ptr */

/* Transmit Configuration Register Bit Masks (DP_TXCFG) */

#define DP_TXCFG_DRTH           (u32)0x0000003F /* Tx Drain Threshold */
#define DP_TXCFG_FLTH           (u32)0x00003F00 /* Tx Fill Threshold */
#define DP_TXCFG_MXDMA          (u32)0x00700000 /* Max DMA Burst Size */ 
#define DP_TXCFG_MXDMA_1        (u32)0x00100000 /* 1 32-bit word */
#define DP_TXCFG_MXDMA_2        (u32)0x00200000 /* 2 32-bit words */
#define DP_TXCFG_MXDMA_4        (u32)0x00300000 /* 4 32-bit words */
#define DP_TXCFG_MXDMA_8        (u32)0x00400000 /* 8 32-bit words */
#define DP_TXCFG_MXDMA_16       (u32)0x00500000 /* 16 32-bit words */
#define DP_TXCFG_MXDMA_32       (u32)0x00600000 /* 32 32-bit words */
#define DP_TXCFG_MXDMA_64       (u32)0x00700000 /* 64 32-bit words */
#define DP_TXCFG_MXDMA_128      (u32)0x00000000 /* 128 32-bit words */
#define DP_TXCFG_IFG            (u32)0x0C000000 /* Interframe gap Time */ 
#define DP_TXCFG_ATP            (u32)0x10000000 /* Automatic Transmit Pad */ 
#define DP_TXCFG_MLB            (u32)0x20000000 /* MAC Loopback */
#define DP_TXCFG_HBI            (u32)0x40000000 /* HeartBeat Ignore */
#define DP_TXCFG_CSI            (u32)0x80000000 /* Carrier Sense Ignore */

#define	DP_TXCFG_DRTH_SET(X)	((X) & DP_TXCFG_DRTH)
#define DP_TXCFG_FLTH_SET(X)	(((X) << 8) & DP_TXCFG_FLTH)

/* Recieve Descriptor Pointer Register Bit Mask (DP_RXDP) */

#define DP_RXDP_MSK             (u32)0xFFFFFFFC /* Receive Descriptor Ptr */

/* Recieve Configuration Register Bit Masks (DP_RXCFG) */

#define DP_RXCFG_DRTH           (u32)0x0000003E /* Rx Drain Threshold */
#define DP_RXCFG_MXDMA          (u32)0x00700000 /* Max DMA Burst size */
#define DP_RXCFG_MXDMA_1        (u32)0x00100000 /* 1 32-bit words */
#define DP_RXCFG_MXDMA_2        (u32)0x00200000 /* 2 32-bit words */
#define DP_RXCFG_MXDMA_4        (u32)0x00300000 /* 4 32-bit words */
#define DP_RXCFG_MXDMA_8        (u32)0x00400000 /* 8 32-bit words */
#define DP_RXCFG_MXDMA_16       (u32)0x00500000 /* 16 32-bit words */
#define DP_RXCFG_MXDMA_32       (u32)0x00600000 /* 32 32-bit words */
#define DP_RXCFG_MXDMA_64       (u32)0x00700000 /* 64 32-bit words */
#define DP_RXCFG_MXDMA_128      (u32)0x00000000 /* 128 32-bit words */
#define DP_RXCFG_ALP            (u32)0x08000000 /* Accept Long Packets */
#define DP_RXCFG_ATX            (u32)0x10000000 /* Accept transmit packets */
#define DP_RXCFG_ARP            (u32)0x40000000 /* Accept Runt Packets */
#define DP_RXCFG_AEP            (u32)0x80000000 /* Accept Errored Packets */

#define	DP_RXCFG_DRTH_SET(X)	((X) & DP_RXCFG_DRTH)

/*
 * Wake Command/status Register Bit Masks (DP_WCSR)
 *
 * It is used to configure/control and monitor FA311 Wake Od LAN Logic
 * The Wake On LAN logic is used to monitor the incoming packet stream while
 * in a low-power state, and provide a wake event to the system if desired
 * packet type, contents, or Link change are detected. 
 */

#define DP_WCSR_WKPHY           (u32)0x00000001 /* Wake on Phy Interrupt */
#define DP_WCSR_WKUCP           (u32)0x00000002 /* Wake on unicast */
#define DP_WCSR_WKMCP           (u32)0x00000004 /* Wake on Multicast */
#define DP_WCSR_WKBCP           (u32)0x00000008 /* Wake on Broadcast */
#define DP_WCSR_WKARP           (u32)0x00000010 /* Wake on ARP */
#define DP_WCSR_WKPAT0          (u32)0x00000020 /* Wake on Pattern 0 match */
#define DP_WCSR_WKPAT1          (u32)0x00000040 /* Wake on Pattern 1 match */
#define DP_WCSR_WKPAT2          (u32)0x00000080 /* Wake on Pattern 2 match */
#define DP_WCSR_WKPAT3          (u32)0x00000100 /* Wake on Pattern 3 match */
#define DP_WCSR_WKMAG           (u32)0x00000200 /* Wake on Magic Packet */
#define DP_WCSR_MPSOE           (u32)0x00000400 /* Magic Packet SecureOn Enbl */
#define DP_WCSR_SOHACK          (u32)0x00200000 /* SecureOn Hack Attempt */
#define DP_WCSR_PHYINT          (u32)0x00400000 /* Phy Interrupt */
#define DP_WCSR_UCASTR          (u32)0x00800000 /* Unicast Recieved */
#define DP_WCSR_MCASTR          (u32)0x01000000 /* Multicast Recieved */
#define DP_WCSR_BCASTR          (u32)0x02000000 /* Broadcast Recieved */
#define DP_WCSR_ARPR            (u32)0x04000000 /* ARP Recieved */
#define DP_WCSR_PATM0           (u32)0x08000000 /* Pattern 0 match */
#define DP_WCSR_PATM1           (u32)0x10000000 /* Pattern 1 match */
#define DP_WCSR_PATM2           (u32)0x20000000 /* Pattern 2 match */
#define DP_WCSR_PATM3           (u32)0x40000000 /* Pattern 3 match */
#define DP_WCSR_MPR             (u32)0x80000000 /* Magic Packet Recieved */

/*
 * Pause Control/Status Register Bit Masks (DP_PCR)
 *
 * It is used to control and monitor the DP 83815 Pause Frame reception logic
 * The Pause frame reception logic is used to accept 802.3x Pause frames,
 * extract the pause length value, and initiate a TXMAV pause interval of the 
 * specified number of slot times.
 */

#define DP_PCR_PAUSE_CNT        (u32)0x0000FFFF /* Pause Counter value */
#define DP_PCR_MLD_EN           (u32)0x00010000 /* Manual Load Enable */
#define DP_PCR_PSNEG            (u32)0x00200000 /* Pause negotiated */
#define DP_PCR_PS_RCVD          (u32)0x00400000 /* Pause frame recieved */
#define DP_PCR_PS_ACT           (u32)0x00800000 /* Pause Active */
#define DP_PCR_PS_DA            (u32)0x20000000 /* Pause on DA */
#define DP_PCR_PS_MCAST         (u32)0x40000000 /* Pause on Multicast */
#define DP_PCR_PSEN             (u32)0x80000000 /* Pause Enable */

/* 
 * Recieve Filter/Match Control Register Bit Masks (DP_RFCR)
 *
 * It is used to control and configure the FA311 Recieve Filter Control logic
 * The RFC logic is used to configure destination address filtering of incoming
 * packets.
 */

#define DP_RFCR_RFADDR          (u32)0x000003FF /* Rx Filter Extended RegAdd */ 
#define DP_RFCR_RFADDR_PMATCH1  (u32)0x00000000 /* Perfect Match octets 1-0 */
#define DP_RFCR_RFADDR_PMATCH2  (u32)0x00000002 /* Perfect Match octets 3-2 */
#define DP_RFCR_RFADDR_PMATCH3  (u32)0x00000004 /* Perfect Match octets 5-4 */ 
#define DP_RFCR_RFADDR_PCOUNT1  (u32)0x00000006 /* Pattern Count 1-0 */
#define DP_RFCR_RFADDR_PCOUNT2  (u32)0x00000008 /* Pattern Count 3-2 */
#define DP_RFCR_RFADDR_SOPAS1   (u32)0x0000000A /* SecureOn Password 1-0 */
#define DP_RFCR_RFADDR_SOPAS2   (u32)0x0000000C /* SecureOn Password 3-2 */
#define DP_RFCR_RFADDR_SOPAS3   (u32)0x0000000E /* SecureOn Password 5-4 */
#define DP_RFCR_RFADDR_FMEM_LO  (u32)0x00000200 /* Rx filter memory start */
#define DP_RFCR_RFADDR_FMEM_HI  (u32)0x000003FE /* Rx filter memory end */
#define DP_RFCR_ULM             (u32)0x00080000 /* U/L bit Mask */
#define DP_RFCR_UHEN            (u32)0x00100000 /* Unicast Hash Enable */
#define DP_RFCR_MHEN            (u32)0x00200000 /* Multicast Hash Enable */
#define DP_RFCR_AARP            (u32)0x00400000 /* Accept ARP Packets */
#define DP_RFCR_APAT            (u32)0x07800000 /* Accept On Pattern Match */
#define DP_RFCR_APM             (u32)0x08000000 /* Accept on Perfect match */
#define DP_RFCR_AAU             (u32)0x10000000 /* Accept All Unicast */
#define DP_RFCR_AAM             (u32)0x20000000 /* Accept All Multicast */
#define DP_RFCR_AAB             (u32)0x40000000 /* Accept All Broadcast */
#define DP_RFCR_RFEN            (u32)0x80000000 /* Rx Filter Enable */

/* 
 * Recieve Filter/Match Data Register Bit Masks (DP_RFDR)
 *
 * This register is used to read and write internal recieve filter registers,
 * the pattern buffer memory and the hash table memory.
 */

#define DP_RFDR_RFDATA          (u32)0x0000FFFF /* Recieve Filter data */
#define DP_RFDR_BMASK           (u32)0x00030000 /* Byte Mask */

/* Boot ROM Address Register Bit Masks (DP_BRAR) */

#define DP_BRAR_ADDR            (u32)0x0000FFFF /* Boot ROM Address */
#define DP_BRAR_AUTOINC         (u32)0x80000000 /* Auto-Increment */

/* Boot ROM Data Register Bit Masks (DP_BRDR) */

#define DP_BRDR_DATA            (u32)0xFFFFFFFF /* Boot ROM Data */

/* Silicon Revision Register Bit Masks (DP_SRR) */

#define DP_SRR_MIN              (u32)0x000000FF /* Minor Revision Level */
#define DP_SRR_MAJ              (u32)0x0000FF00 /* Major Revision Level */
#define	DP_SRR_MAJ_SHF			8               /* Shift bits */

/*
 * Management Information Base Control Register Bit Masks (DP_MIBC)
 *
 * It is used to control access to the statistics block and the warning bits
 * and to control the collection of management info statistics.
 */

#define DP_MIBC_WRN             (u32)0x00000001 /* Warning Tst Indicator (RO) */
#define DP_MIBC_FRZ             (u32)0x00000002 /* Freeze All Counters */
#define DP_MIBC_ACLR            (u32)0x00000004 /* Clear all Counters */
#define DP_MIBC_MIBS            (u32)0x00000008 /* MIB Counter Strobe (TEST) */

/* BMCR - (Internal Phy) Basic Mode Control Register */

#define DP_BMCR_COL_TST         (u16)0x0080 /* Collision Test */
#define DP_BMCR_HDX             (u16)0x0000 /* Half duplex mode */
#define DP_BMCR_FDX             (u16)0x0100 /* Full duplex mode */
#define DP_BMCR_ANEG_RES        (u16)0x0200 /* Restart Auto negotiation */
#define DP_BMCR_ISOLATE         (u16)0x0400 /* Isolate */
#define DP_BMCR_PWRDWN          (u16)0x0800 /* Power Down */
#define DP_BMCR_ANEG_EN         (u16)0x3100 /* Auto Negotiation Enable */
#define DP_BMCR_SPD_100         (u16)0x2000 /* Speed Select 100Mbps */
#define DP_BMCR_SPD_10          (u16)0x0000 /* Speed Select 100Mbps */
#define DP_BMCR_LOOP            (u16)0x4000 /* Loopback */
#define DP_BMCR_RESET           (u16)0xB100 /* Reset */

/* BMSR - (Internal Phy) Basic Mode Status Register */

#define DP_BMSR_XREG_ABLE       (u16)0x0001 /* Extended Register Capability */
#define DP_BMSR_JABR_DET        (u16)0x0002 /* Jabber Detected */
#define DP_BMSR_LNK_VALID       (u16)0x0004 /* Valid Link Status */
#define DP_BMSR_AN_ABLE         (u16)0x0008 /* Auto-Neg Ability */
#define DP_BMSR_REM_FLT         (u16)0x0010 /* Remote Fault Detected */
#define DP_BMSR_AN_DONE         (u16)0x0020 /* Auto Nego Complete */
#define DP_BMSR_PRS_ABLE        (u16)0x0040 /* Preamble Supr Capable */
#define DP_BMSR_10_HD_ABLE      (u16)0x0800 /* 10BASE-T Half Duplex Capable */
#define DP_BMSR_10_FD_ABLE      (u16)0x1000 /* 10BASE-T Full Duplex Capable */
#define DP_BMSR_100_HD_ABLE     (u16)0x2000 /* 100BASE-TX Half Duplex Capable */
#define DP_BMSR_100_FD_ABLE     (u16)0x4000 /* 100BASE-TX Full Duplex Capable */
#define DP_BMSR_100T4_ABLE      (u16)0x8000 /* 100BASE -T4 Capable */

/* PHY Identifier Register #1 */

#define DP_PHYIDR1_OUI_MSB      (u16)0xFFFF /* OUI Most significant Bits */

/* PHY Identifier Register #2 */

#define DP_PHYIDR2_MDL_REV      (u16)0x000F /* Model Revision number */
#define DP_PHYIDR2_VNDR_MDL     (u16)0x03F0 /* Vendor Model Number */
#define DP_PHYIDR2_OUI_LSB      (u16)0xFC00 /* OUI Last Significant Bits */

/*
 * Auto-Negotiation Advertisement Register
 *
 * Contains the advertised abilities of this device as they will be transmitted
 * to its link partner during Auto-Negotiation.
 */

#define DP_ANAR_SEL             (u16)0x001F /* Protocol Selection Bits */
#define DP_ANAR_10T             (u16)0x0020 /* 10BASE-T Support */
#define DP_ANAR_10_FD           (u16)0x0040 /* 10BASE-T Full Duplex Support */
#define DP_ANAR_TX              (u16)0x0080 /* 100BASE-TX Support */
#define DP_ANAR_TX_FD           (u16)0x0100 /* 100BASE-TX Full Duplex Support */
#define DP_ANAR_T4              (u16)0x0200 /* 100BASE-T4 Support */
#define DP_ANAR_PAUSE           (u16)0x0400 /* Pause */
#define DP_ANAR_RF              (u16)0x2000 /* Remote Fault */
#define DP_ANAR_NP              (u16)0x8000 /* Next Page Indication */

/*
 * Auto-Negotiation Link Partner Ability Register
 *
 * Contains the advertised abilities of the Link Partner as recieved during
 * Auto Negotiation. The content changes after the successful autonegotiation
 * if Next-Pages are supported.
 */

#define DP_ANLPAR_SEL           (u16)0x001F /* Protocol Selection Bits */
#define DP_ANLPAR_10T           (u16)0x0020 /* 10BASE-T Support */
#define DP_ANLPAR_10_FD         (u16)0x0040 /* 10BASE-T Full Duplex */
#define DP_ANLPAR_TX            (u16)0x0080 /* 100BASE-TX Support */
#define DP_ANLPAR_TX_FD         (u16)0x0100 /* 100BASE-TX Full Duplex */
#define DP_ANLPAR_T4            (u16)0x0200 /* 100BASE-T4 Support */
#define DP_ANLPAR_RF            (u16)0x2000 /* Remote Fault */
#define DP_ANLPAR_ACK           (u16)0x4000 /* Acknowledge */
#define DP_ANLPAR_NP            (u16)0x8000 /* Next Page Indication */

/*
 * Auto-Negotiation Expansion Register
 *
 * contains additional Local device and Link Partner status info
 */

#define DP_ANER_LP_AN_ABLE      (u16)0x0001 /* Link Partner Auto Neg Able */
#define DP_ANER_PAGE_RX         (u16)0x0002 /* Link Code Word Page Recvd */
#define DP_ANER_NP_ABLE         (u16)0x0004 /* Next Page Able */
#define DP_ANER_LP_NP_ABLE      (u16)0x0008 /* Link Partner NextPage Able */
#define DP_ANER_PDF             (u16)0x0010 /* Parallel Detection Fault */

/*
 * Auto-Negotiation Next page Transmit Register
 *
 * contains the next page Info sent by this device to its Link Partner 
 * during Auto-Negotiation
 */

#define DP_ANNPTR_CODE          (u16)0x07FF /* Code Field */
#define DP_ANNPTR_TOG_TX        (u16)0x0800 /* Toggle */
#define DP_ANNPTR_ACK2          (u16)0x1000 /* Acknowledge2 */
#define DP_ANNPTR_MP            (u16)0x2000 /* Message Page */
#define DP_ANNPTR_NP            (u16)0x8000 /* Next Page Indication */

/*
 * PHY Status Register
 *
 * provides a single location within the register set for quick access to
 * commonly accessed information
 */

#define DP_PHYSTS_LNK_VALID     (u16)0x0001 /* Valid Link */
#define DP_PHYSTS_SPEED_10      (u16)0x0002 /* 10 Mbps Mode */
#define DP_PHYSTS_FDX           (u16)0x0004 /* Full Duplex Mode */
#define DP_PHYSTS_LOOP          (u16)0x0008 /* Loopback Enabled */
#define DP_PHYSTS_ANEG_DONE     (u16)0x0010 /* Auto-Neg Complete */
#define DP_PHYSTS_JABBER        (u16)0x0020 /* Jabbler Detected */
#define DP_PHYSTS_REM_FAULT     (u16)0x0040 /* Remote Fault Detected */
#define DP_PHYSTS_MII_INTR      (u16)0x0080 /* MII Interrupt Pending */
#define DP_PHYSTS_LCWP_RX       (u16)0x0100 /* Link Code Word Page Rx'd */
#define DP_PHYSTS_DSCRMBL_LCK   (u16)0x0200 /* 100TX Descrambler Lock */
#define DP_PHYSTS_SIG_DET       (u16)0x0400 /* 100TX Uncond Signal Detect */
#define DP_PHYSTS_FCSL          (u16)0x0800 /* False Carrier Sense Latch */
#define DP_PHYSTS_POL_INV       (u16)0x1000 /* Polarity status */
#define DP_PHYSTS_RX_ERR_LATCH  (u16)0x2000 /* Received error latch */

/*
 * False carrier Sense Counter Register
 *
 * provides info required to implement the "FalseCarriers" attribute within
 * the MAJ managed object class of Clause 30 of the IEEE 802.3u specification.
 */

#define DP_FCSCR_FCSCNT         (u16)0x00FF /* False Carrier Event Counter */

/*
 * Receiver Error Counter Register
 *
 * provides info required to implement the "SymbolErrorDuringCarrier" attribute
 * within  the PHY managed object class of Clause 30 of the IEEE 802.3u
 * specification.  
 */

#define DP_RECR_RXERCNT         (u16)0x00FF /* RX_ER Counter*/

/* 100Mb/s PCS Configuration and Status Register */

#define DP_PCSR_NRZI_BYP        (u16)0x0004 /* NRZI Bypass Enable */
#define DP_PCSR_FRC_100_OK      (u16)0x0020 /* Force 100Mb/s Good Link */
#define DP_PCSR_SD_OPT          (u16)0x0100 /* Signal Detect Option */
#define DP_PCSR_SD_F_B          (u16)0x0200 /* Signal Detect Force */
#define DP_PCSR_TQ_EN           (u16)0x0400 /* 100Mbs True Quite Mode En */
#define DP_PCSR_FREE_CLK        (u16)0x0800 /* Receive Clock */
#define DP_PCSR_BYP_4B5B        (u16)0x1000 /* Bypass 4B/5B Encoding */

/* PHY Control Register */

#define DP_PHYCR_PHYADDR        (u16)0x001F /* PHY Address */
#define DP_PHYCR_LED_CFG        (u16)0x0060 /* LED Configuration */
#define DP_PHYCR_LED_CFG_10_HI  (u16)0x0000 /* Speed10 HIGH */
#define DP_PHYCR_LED_CFG_10     (u16)0x0020 /* Speed10 selected */
#define DP_PHYCR_LED_CFG_DPLXHI (u16)0x0040 /* DPLX active HIGH */
#define DP_PHYCR_LED_CFG_DPLX   (u16)0x0060 /* DPLX selected */
#define DP_PHYCR_PAUSE_PASS     (u16)0x0080 /* Pause Compare Pass */
#define DP_PHYCR_BP_STRETCH     (u16)0x0100 /* Bypass LED Stretch*/
#define DP_PHYCR_BIST_START     (u16)0x0200 /* BIST Start */
#define DP_PHYCR_BIST_PASS      (u16)0x0400 /* BIST Pass */
#define DP_PHYCR_PSR_15         (u16)0x0800 /* BIST Sequence Sel PSR15 (PSR9) */

/* 10Base-T Status/Control Register(10BTSCR) */

#define DP_10BTSCR_JABR_DIS     (u16)0x0001 /* Jabber Disable */ 
#define DP_10BTSCR_HB_DIS       (u16)0x0002 /* Heartbeat Disable */ 
#define DP_10BTSCR_LOW_SQL      (u16)0x0004 /* Reduced Sqyelch Enable */ 
#define DP_10BTSCR_AUTOPOL_DIS  (u16)0x0008 /* Auto Polarity Disable */
#define DP_10BTSCR_POL          (u16)0x0010 /* 10Mb Polarity Status */ 
#define DP_10BTSCR_FRC_POL_COR  (u16)0x0020 /* Force 10Mb Polarity Correction */
#define DP_10BTSCR_FRC_10       (u16)0x0040 /* Force 10Mb Good Link */ 
#define DP_10BTSCR_LP_DIS       (u16)0x0080 /* Normal Link Pulse Disable */
#define DP_10BTSCR_LB10_DIS     (u16)0x0100 /* 10Base-T Loopback Disable */


/*
 * Transmit and receive descriptors
 *
 * FA311 uses the same descriptor layout for both transmit and receive
 * descriptors.
 */

#define DP_DESC_SIZE            0x0C /* 3 words */

/* Descriptor Layout */

#define DP_DESC_LNK             0x00 /* Link field offset */
#define DP_DESC_CMDSTS          0x04 /* Command & Status offset */
#define DP_DESC_BUFPTR          0x08 /* Buffer pointer offset */

/* DP_DESC_CMDSTS - Descriptor Command and Status Definitions */

#define DP_DESC_CMDSTS_SIZE         (u32)0x00000FFF /* Size of data in bytes */
#define DP_DESC_CMDSTS_TX_CCNT      (u32)0x000F0000 /* Collision Count */
#define DP_DESC_CMDSTS_TX_EC        (u32)0x00100000 /* Excessive Collisions */
#define DP_DESC_CMDSTS_TX_OWC       (u32)0x00200000 /* Out of window collns */
#define DP_DESC_CMDSTS_TX_ED        (u32)0x00400000 /* Excessive deferrals */
#define DP_DESC_CMDSTS_TX_TD        (u32)0x00800000 /* Transmit deferrals */
#define DP_DESC_CMDSTS_TX_CRS       (u32)0x01000000 /* Carrier sense lost */
#define DP_DESC_CMDSTS_TX_TFU       (u32)0x02000000 /* Tx FIFO underrun */
#define DP_DESC_CMDSTS_TX_TXA       (u32)0x04000000 /* Tx abort */
#define DP_DESC_CMDSTS_RX_COL       (u32)0x00010000 /* Collision */
#define DP_DESC_CMDSTS_RX_LBP       (u32)0x00020000 /* Loopback packet */
#define DP_DESC_CMDSTS_RX_FAE       (u32)0x00040000 /* Frame align error */
#define DP_DESC_CMDSTS_RX_CRCE      (u32)0x00080000 /* CRC error */
#define DP_DESC_CMDSTS_RX_ISE       (u32)0x00100000 /* Invalid symbol error */
#define DP_DESC_CMDSTS_RX_RUNT      (u32)0x00200000 /* Runt packet */
#define DP_DESC_CMDSTS_RX_LONG      (u32)0x00400000 /* Long packet */
#define DP_DESC_CMDSTS_RX_DEST      (u32)0x01800000 /* Destination Class */
#define DP_DESC_CMDSTS_RX_DEST_REJ  (u32)0x00000000 /*  Packet Rejected */
#define DP_DESC_CMDSTS_RX_DEST_UNI  (u32)0x00800000 /*  Unicast packet */
#define DP_DESC_CMDSTS_RX_DEST_MC   (u32)0x01000000 /*  Multicast packet */
#define DP_DESC_CMDSTS_RX_DEST_BC   (u32)0x01800000 /*  Broadcast packet */
#define DP_DESC_CMDSTS_RX_RXO       (u32)0x02000000 /* Receive overrun */
#define DP_DESC_CMDSTS_RX_RXA       (u32)0x04000000 /* Receive aborted */
#define DP_DESC_CMDSTS_OK           (u32)0x08000000 /* Packet OK */
#define DP_DESC_CMDSTS_TX_SUPCRC    (u32)0x10000000 /* Supress CRC */
#define DP_DESC_CMDSTS_RX_INCCRC    (u32)0x10000000 /* Include CRC */
#define DP_DESC_CMDSTS_INTR         (u32)0x20000000 /* Interrupt */
#define DP_DESC_CMDSTS_MORE         (u32)0x40000000 /* More descriptors */
#define DP_DESC_CMDSTS_OWN          (u32)0x80000000 /* Descr owner (consumer) */

#define DP_DESC_CMDSTS_TX_COLLISIONS_GET(cmdsts)								\
        (((cmdsts) & DP_DESC_CMDSTS_TX_CCNT) >> 16)

#define DP_DESC_CMDSTS_TX_ERRORS	(DP_DESC_CMDSTS_TX_CCNT |			\
                                     DP_DESC_CMDSTS_TX_EC   |			\
                                     DP_DESC_CMDSTS_TX_OWC  |			\
                                     DP_DESC_CMDSTS_TX_ED   |			\
                                     DP_DESC_CMDSTS_TX_CRS  |			\
                                     DP_DESC_CMDSTS_TX_TFU  |			\
                                     DP_DESC_CMDSTS_TX_TXA)				

#define DP_DESC_CMDSTS_RX_ERRORS    (DP_DESC_CMDSTS_RX_RXA  |			\
                                     DP_DESC_CMDSTS_RX_RXO  |			\
                                     DP_DESC_CMDSTS_RX_LONG |			\
                                     DP_DESC_CMDSTS_RX_RUNT |			\
                                     DP_DESC_CMDSTS_RX_CRCE |			\
                                     DP_DESC_CMDSTS_RX_FAE)

#endif /* __FA31x_H__ */
