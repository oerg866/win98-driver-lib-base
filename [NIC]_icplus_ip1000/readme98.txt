

     		IC Plus IP1000 Gigabit Ethernet Adapter
                 Windows NDIS 98 First edition driver 


Contents:
---------

1. File Description
2. Driver Installation for Windows 98A
3. Parameters Description


1. File Description
-------------------

Filename              Description
=================     =====================================================
readme.txt            Presents a summary of the contents for Windows NDIS
                      driver installation.

netipg.inf	      Windows installation INFormation file for install

ipgnd4.sys            Windows 98A NDIS 5 driver

2. Driver Installation for Windows 98A
------------------------------------------------

    The Windows installation floppy or CD is needed to complete this
    installation.

    Adapter Installation Procedure
    --------------------------------------------
    a. Make sure your computer is power-off.
    
    b. Plug the adapter into one PCI 33MHz slot of your computer.
    
    c. Turn on the power. 

    Install and/or Update driver from diskette
    ------------------------------------------
    The following steps can help you install or update the driver to
    the one in the Adapter Drivers Diskette/CD-ROM.
     
     a. Open Control Panel, double click "System" icon to open System
        Properties.
     
     b. In the "Hardware" sheet, you can see the "Device Manager" button.
        Click to open Device Manager.
     
     c. Use the tool bar to make sure you "View" "Devices by type".
        Then you will able to find Ethernet Controller in "Network Adapters"
        group. Double click it to open its property.
     
     d. In the "Driver" sheet of the adapter's properties, there is a button
        named "Update Driver". Click it, the Upgrade Device Driver Wizard
        will show up to help updating the driver.

     The following steps will lead you through the wizard ...
     
     a. The first page is the welcome messages, click "Next" to continue.
     
     b. Select "Display a list of the known drivers of this device so that 
        I can choose a specific driver.", and click "Next".
     
     c. Click "Have Disk".
     
     d. Specify the path.
        (A:\ , assume A: is floppy drive)
        (D:\ , assume D: is CD drive) 
     
     e. Choose the driver.
        IC Plus IP1000 Gigabit Ethernet Adapter
        Click "Next" to continue.

     f. When the wizard can not find the required driver files, it pops
        a windows asking for its path. Browse to the path of the driver.

     g. The wizard will copy and load the driver, then you will see "Finish"
        button. Click it and it's done.

3. Parameter Description
------------------------
   - Open 'Device Manager' in "My Computer" -> "Control Pannel" ->
     "System"  Select "Hardware" and click "Device Manager".
     Double click "IC Plus IP1000 Gigabit Ethernet Adapter", Select 
     "Advanced" item.

	802.1Q/1P VLAN   You can enable it for VLAN group.
       	tagging          Default: Disabled

	Connection Type  Specify the connection type for the adapter.
                         Default: Auto-Sense

	Flow Control	 Enabled/Disabled for Transmit/Receive Flow Control.
                         Default : Enabled

	Network Address  Set the Ethernet address for your adapter. 
                         It is not recommended to use this. 
                         Default: read address from adapter ROM.

	Receive Buffers	 Set the number of Receive Buffers Descriptors
                         Default : 128

	Task Offloading	 Set the desired methof of TCP/IP/UDP Offloading.
                         Default : Disabled

	TCP/IP Jumbo     You can enable this for Jumbo frame support.
	Frame            Default: Disabled  
                         (The device or link partner should also support
                         Jumbo frame for this function to take effect.) 

	Transmit BUffers Set the number of Transmit Buffers Descriptors
                         Default : 128

	VLAN ID          This value will active after 802.1Q/1P VLAN
                         tagging enable.
                         Default : Not active.

        Wake on Lan      Enabled/Disabled Wake up from Lan.
                         Default : Enabled

 