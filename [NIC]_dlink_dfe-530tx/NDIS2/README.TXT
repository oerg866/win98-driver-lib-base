
           D-Link DFE-530TX PCI Fast Ethernet Adapter NDIS Driver
                    Installation Overview

 Contents
 ---------------------------------------------------------------------------
     Introduction
     User's Guide

 Introduction
 ----------------------------------------------------------------------------
    The PCI Family NDIS driver programs included in the driver
    diskette. These driver programs comply with Microsoft's NDIS v2.0.1
    specification. The following text files describe the installation
    procedure for some of the most popular operating systems supporting
    NDIS drivers.

    NDIS driver program for DOS follows the Microsoft's NDIS spec v2.0.1.
    The following document files detail the installation procedure for
    some of the most popular operating systems supporting NDIS drivers:

 User's Guide
 ----------------------------------------------------------------------------
    This guide lists the available PROTOCOL.INI keywords for all NDIS
    device drivers. Most of the keywords are optional and come with their
    respective default values. 
    
    DRIVERNAME     - This keyword specifies the driver name for the
                     adapter.
       
    CONNECTIONTYPE - This parameter specifies the configuration of data
                     rate of the network adapter. If CONNECTIONTYPE does not
                     specified, it will auto detect the data rate.

                     Parameters List:
                       AUTOSENSE     -- Auto-select media type and line speed.
                       _10BASET      -- Force to 10Mbps half duplex mode.
                       _10BASETFD    -- Force to 10Mbps full duplex mode.
                       _100BASETX    -- Force to 100Mbps half duplex mode.
                       _100BASETXFD  -- Force to 100Mbps full duplex mode.

        
    FLOW_CONTROL  - This keyword is used to specify flow contro
                    ability. The strings are :
                       
                       HARDWARE_DEFAULT (HD)
                       ENABLE
                       DISABLE
		    (Not supported in force mode)
	
    SLOT          - This parameter specifies the slot number used for
                    notifications. For PCI slot, you can specify from
                    1 to 16.
