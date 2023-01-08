
         D-Link DFE-530TX PCI Fast Ethernet Adapter Packet Driver
                          Installation Overview


 User's Guide
 ------------

    File            Description
    ------------    ----------------------------------------------------
    PCNFS.TXT       Sun PC-NFS installation document
    PCTCP.TXT       FTP PC/TCP installation document
    PDIPX.TXT       IPX SHELL installation document
    NCSA.TXT        NCSA installation document
    WINSOCK.TXT     Winsock installation document

   The following syntax keywords are for driver v4.10 or latter only.
   -------------------------------------------------------------------

   Installation Packet Driver:
   ----------------------------
    1) Copy the Packet driver to your HardDisk, suppose you copy it to
       C:\PACKET directory.
       EX: copy  a:\packet\dlkfet.com  c:\packet\dlkfet.com

    2) Add the following line to C:\AUTOEXEC.BAT
           C:\PACKET\DLKFET -n 0x60 
           
    or

    1) Copy the Packet driver to your HardDisk, suppose you copy it to
       C:\PACKET directory.
       EX: copy  a:\packet\dlkfet.sys  c:\packet\dlkfet.sys

    2) Add the following line to C:\CONFIG.SYS
           DEVICE=C:\PACKET\DLKFET.SYS -n 0x60 

    Sample of configuration file:
    ----------------------------------------------------------------
    (Suppose PACKET driver is copied to C:\PACKET directory)

    File Name:          C:\AUTOEXEC.BAT
    ----------
        C:\PACKET\DLKFET  -n  -w  0x60   

      0x60 is software vector number this driver uses.
      -n means Novell packets can be transmitted across this driver
      -w means Window compatible.
     
     
       if you want to link to N-way Device and use auto mode, you can add parameter as follow:         
       C:\PACKET\DLKFET -a -n0x60
              
       if you want to force assigning pci slot number you can add parameter as follow:
       
       C:\PACKET\DLKFET -l10  -n 0x60  (pci slot number=10) 
       
       if you want to set up your connection type, you can add parameter as follow:
       
       C:\PACKET\DLKFET -connectiontype=autosense 0x60 (Auto mode, default value)
       C:\PACKET\DLKFET -connectiontype=10baset 0x60 (speed=10Mbs, halfduplex)
       C:\PACKET\DLKFET -connectiontype=10basetfd 0x60 (speed=10Mbs, fullduplex)
       C:\PACKET\DLKFET -connectiontype=100basetx 0x60 (speed=100Mbs, halfduplex)
       C:\PACKET\DLKFET -connectiontype=100basetxfd 0x60 (speed=100Mbs, fullduplex)
      
       if you want to set up your flow control ability, you can add parameter as follow:
       
       C:\PACKET\DLKFET -flow_control=hardware_default 0x60 (use hardware value, default)
       C:\PACKET\DLKFET -flow_control=enable 0x60 (enable flow control)
       C:\PACKET\DLKFET -flow_control=disable 0x60 (disable flow control)
       
       if you want to use installable device driver (dlkfet.sys), you should add these
       configuration in CONFIG.SYS and add "DEVICE=" before "C:\PACKET\DLKFET".
	
	
    The following syntax and keywords are for driver v4.10 previously(v4.10 not included).
    --------------------------------------------------------------------------------------
    syntax:

    DEVICE = DLKFET.SYS [/option] <packet_int_no>
    DLKFET.COM [/option] <packet_int_no>

    Parameters:	

        <packet_int_no> is the software interrupt vector number used by
                        the packet driver program, which can be from
                        96 to 128.

                        Note: <packet_int_no> can be hex or decimal
                              number.
                              hex - start with '0x'.
                                ex. >DLKFET 0x62
                              dec - start with nonzero digit.
                                ex. >DLKFET 98

        </slot=##>      is the number of assigned slot, which is from 1
                        to f.

                        Note: '##' can be hex number only.
                              ex:>DLKFET /slot=1
                                 >DLKFET /slot=2
                                 >DLKFET /slot=f

        </d>            Delay Initial - The driver program will not
                        initialize the network interface card until the
                        packet driver program is accessed by its upper
                        layer program first time.

        </w>            the /w parameter is used only in the Windows
                        environment.

        </u>            unload the driver program from memory.
                        The program will automatically search for Packet
                        driver to unload.

        </n>            NetWare conversion

     To select media type, you can use :

        </autosense>    this is the default setting. It let you be able to
                        change media without restart the driver.

        </100BaseTXFD>  Force the driver to select 100Mbps full duplex mode.

        </100BaseTX>    Force the driver to select 100Mbps half duplex mode.

        </10BaseTFD>    Force the driver to select 10Mbps full duplex mode.

        </10BaseT>      Force the driver to select 10Mbps half duplex mode.

        </flow_control> Set flow_control function.


