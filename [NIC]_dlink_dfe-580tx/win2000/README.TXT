
	D-Link DL10050-based FAST Ethernet Adapter
	D-Link DFE-550TX FAST Ethernet 10/100 Adapter
	D-Link DFE-550FX 100Mbps Fiber-optics Adapter
	D-Link DFE-580TX 4 Port Server Adapter
	D-Link DFE-530TXS PCI Fast Ethernet Adapter
		Installation for Windows 2000

 Getting Started
 ---------------

    The Windows 2000 installation CD is needed to complete this
    installation.

    Windows 2000 Installation Procedure
    -----------------------------------

    Windows 2000 had supported this adapter, and the driver version is
    v1.0.5. To use the bundled driver ...

    1. Make sure your computer is power-off.

    2. Plug the adapter into one PCI slot of your computer.

    3. Turn on the power. Windows 2000 will find and install
       the driver automatically.

    Update driver from diskette
    ---------------------------
    The following steps can help you update the bundled driver to
    the one in the Adapter Drivers Diskette/CD-ROM.

     1. Open Control Panel, double click "System" icon to open System
        Properties.

     2. In the "Hardware" sheet, you can see the "Device Manager" button.
        Click to open Device Manager.

     3. Use the tool bar to make sure you "View" "Devices by type".
        Then you will able to find

        D-Link DFE-550TX 10/100 Adapter, or
        D-Link DL10050 based 10/100 Adapter

        in "Network Adapters" group. Double click it to open its property.

     4. In the "Driver" sheet of the adapter's properties, there is a button
        named "Update Driver". Click it, the Upgrade Device Driver Wizard
        will show up to help updating the driver.

     The following steps will lead you through the wizard ...

     1. The first page is the welcome messages, click "Next" to continue.

     2. Select "Display a list of the known drivers of this device so that 
	I can choose a specific driver.", and click "Next".

     3. Click "Have Disk".

     4. Specify the path.
        (A:\ , assume A: is floppy drive)
        (D:\ , assume D: is CD drive) 
        
     5. Choose the appropriat driver model from list.
        Click "Next" to continue.

     7. The wizard will copy and load the driver, than you will see "Finish"
        button. Click it and it's done.

 Driver keywords
 ---------------
     - Open 'Device Manager' in "My Computer" -> "Control Pannel" -> "System".
       Double click the adapter, like "D-Link DFE-550TX ..." etc.
       Select "Advanced" tag.

	802.1Q/1P VLAN	You can enable it for VLAN group.
	tagging		Default: Disabled

	Connection Type	Specify the connection type for the adapter.
			Default: Auto-Negotiation
			(for DFE-550FX default setting is 100Base-FX
				Full Duplex)

	GVRP		Support GVRP and will active after 802.1Q/1P
			VLAN tagging enable.
			default: Enabled

	Network Address	You can set the Ethernet address for your
			adapter. It is not recommended to use this
			keyword. As you know two or more adapter in
			the same network with same Ethernet address
			will cause a little problem.

			When using this keyword you need to input
			exactly 6 bytes of Ethernet address using
			one of the following format:

			xx-xx-xx-xx-xx-xx
			OR
			xxxxxxxxxxxx

			Default: read address from adapter ROM.

	VLAN ID		This value will active after 802.1Q/1P VLAN
			tagging enable.
       
	Working Mode	User can switch between Server Mode and 
			Bridge Mode for the purpose.
			Default: Server Mode

