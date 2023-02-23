
     		IC Plus IP100 10/100 Fast Ethernet Adapter
                         Windows NDIS driver 


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

netipf.inf	      Windows installation INFormation file for install

ipfnd5.sys            Windows 98A NDIS 5 driver

ipfndi.dll            Windows 98A driver install assistant file

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
        IC Plus IP100 10/100 Fast Ethernet Adapter
        Click "Next" to continue.

     f. When the wizard can not find the required driver files, it pops
        a windows asking for its path. Browse to the path of the driver.

     g. The wizard will copy and load the driver, then you will see "Finish"
        button. Click it and it's done.

3. Parameter Description
------------------------
   - Open 'Device Manager' in "My Computer" -> "Control Pannel" ->
     "System"  Select "Hardware" and click "Device Manager".
     Double click "IC Plus IP100 10/100 Fast Ethernet Adapter", Select 
     "Advanced" item.

	
	Connection Type  Specify the connection type for the adapter.
                         Default: Auto-Sense

	Network Address  Set the Ethernet address for your adapter. 
                         It is not recommended to use this. 
                         Default: read address from adapter ROM.

	No Cable         Set the indication function of "No Cable".
	Indication	 Default : Disabled

	Receive Buffers	 Set the number of Receive Buffers Descriptors
                         Default : 96

	Transmit Buffers Set the number of Transmit Buffers Descriptors
                         Default : 96


 