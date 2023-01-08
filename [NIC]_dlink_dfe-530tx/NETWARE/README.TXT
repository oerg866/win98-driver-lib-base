
           D-Link DFE-530TX PCI Fast Ethernet Adapters NetWare Drivers
                            Installation Overview

 Contents
 --------
    - Introduction
    - User's Guide

 Introduction
 ------------
    The PCI Family NetWare driver programs provided in this driver CD.
    For installation information for various systems, please refer to the
    appropriate text file listed below.  These files are included in this
    driver CD.

        File                Description
    ------------    ------------------------------------------------
    DOSODI.TXT      NetWare DOS Client installation document
    NW3xx.TXT       NetWare 3.12/3.2 Server installation document
    NW4XX.TXT       NetWare 4.x Server installation document
    NW5.TXT	    NetWare 5 Server installation document
    NW6.TXT	    NetWare 6 Server installation document
    CLIENT32.TXT    Client32 for DOS/Windows 3.1x installation document
    
 User's Guide
 ------------
    This guide lists the available NET.CFG keywords for the ODI device
    drivers. Most of these keywords are optional and use respective
    default values.

    Parameters supported by the NET.CFG for DLKFET.COM driver
    ---------------------------------------------------------
       Protocol IPX
       Bind #1

       Link Driver DLKFET
       frame Ethernet_802.3
      ;frame Ethernet_802.2
      ;frame Ethernet_II
      ;frame Ethernet_SNAP

       Protocol IPX 00 Ethernet_802.3
      ;Protocol IPX E0 Ethernet_802.2
      ;Protocol IPX 8137 Ethernet_II
      ;Protocol IPX 8137 Ethernet_SNAP

      ;Optional driver keywords:

      ;The following keywords are for driver v4.12 or latter only.
      ;----------------------------------------------------------------
          
      ;PCISLOT                      ;This keyword is used to force slot
                                    ;number for specified NIC card.
					
	  
       CONNECTIONTYPE               ;This keyword is used to specify duplex 
                                    ;and speed mode. The strings are :
                                        
                                     AUTOSENSE
                                    ;10BaseT  
                                    ;10BaseTFD
                                    ;100BaseTX   
                                    ;100BaseTXFD 
                                        
      ;FLOW_CONTROL                 ;This keyword is used to specify flow contro
                                    ;ability. The strings are :
                                        
                                     HARDWARE_DEFAULT
                                    ;ENABLE
                                    ;DISABLE
                                    (Not supported in force mode)

      ;The following keywords are for driver v4.12 previously(v4.12 not included).
      ;----------------------------------------------------------------------------
       AUTOSENSE          ;Autosense media type
      ;10BaseT            ;Force the driver to 10Mbps half duplex mode.
      ;10BaseTFD          ;Force the driver to 10Mbps full duplex mode.
      ;100BaseTX          ;Force the driver to 100Mbps half duplex mode.
      ;100BaseTXFD        ;Force the driver to 100Mbps full duplex mode.bps full duplex mode.

