
        D-Link DFE-530TX PCI Fast Ethernet Adapter Installation
                          for Windows XP


 Getting Started
 ---------------

    The Windows XP installation CD are needed to complete this install.


    Windows XP build-in driver Installation Procedure
    (for rev.A, B card)	 
    -------------------------------------------------

     1. Plug PCI Ethernet adapter into the system.

     2. Start your PC normally.  Upon power up, the system will
        indicate to you that "new network device installed".
        Windows has detected the installation of a new networking
        device and completed installation procedure. If you want 
        to setup up a network, click the icon to run the network 
        setup wizard. 
        
        
    Windows XP update Driver Installation Procedure
    (for rev.A, B card)
    -----------------------------------------------

     1. Make sure your computer is power-off.

     2. Plug the adapter into one PCI slot of your computer.

     3. Turn on the power. Your computer should be booting.

     4. Windows XP will find new hardware, and install 
        "D-Link DFE-530TX PCI Fast Ethernet Adapter (rev.A)" or
        "D-Link DFE-530TX PCI Fast Ethernet Adapter (rev.B)" 
        automatically.
        
     5. Click "Start" --> right click "My Computer" and select 
        "Properties".
        
     6. Select "Hardware" --> "Device Manager".
     
     7. Right click "D-Link DFE-530TX PCI Fast Ethernet Adapter..." in Network Adapters
        and select "Update Driver...".
        
     8. Check "install from a list or specific location (Advance), click Next.
     
     9. Check "Don't search. I will choose the driver to install", click Next.
     
    10. Click "Have Disk..." and specific location A:\, if driver
        in floppy disk. (assum D:\ for CD-ROM) Click "OK" for next.
    
    11. Select "D-Link DFE-530TX PCI Fast Ethernet Adapter..." and click Next.
        Then will copy driver files into system.
        
    12. Please select "Continue Anyway" to finish the installation.
     
    13 After finishing the installation, there should be a new
       'Local Area Connection' will appear and the LAN card should works now.


    Windows XP new Driver Installation Procedure
    (for rev.C card)
    -----------------------------------------------
 
    The following steps helps you install driver for your adapter:

     1. Make sure your computer is power-off.

     2. Plug the adapter into one PCI slot of your computer.

     3. Turn on the power. Your computer should be booting.

     4. Windows XP will find new hardware, and
        "Add new hardware wizard" will appear.

     5. Insert the driver diskette/CD into floppy/CDROM drive.

     6. Follow the instruction and the wizard will help you
        complete the installation.


   
 Trouble Shooting
 ----------------

    1. Everything is OK in Device Manager, but the network adapter still
       doesn't function properly. Please make sure that your Computer
       name is different from others in the same network.  You can change
       your Computer name in

       "My Computer" -> Press right key of you mouse and select "Properties"->
       "Computer Name" -> "Change" icons

    2. Everything appears to be OK but the network adapter still doesn't
       function properly. Please make sure that the adapter is properly
       connected to a network device (ex: HUB) and the "connection type"
       for this adapter is set to "Auto-negotiation" or the correct
       media type. You can check it in "My Computer" -> press right key of
       your mouse and select "properties"->"Device Manager"->"Network Adapter" 
       -> "Properties" icons. Select "Advanced" item.


    Driver keywords:
    ----------------

      Open "Device Manager" -> "Network Adapter" -> "Properties" ->
      Double click "D-Link DFE-530TX ...", Select "Advanced" item.

     	Connection Type      	Specify the connection type for the adapter.
                            	Default: Auto-Negotiation

        Flow Control	    	Flow control capability advertisement.
			    	Default: Hardware Default
				(Not supported in force mode)

	Network Address      	You can set the Ethernet address for your
                            	adapter. It is not recommended to use this
                            	keyword. As you know two or more adapter in
                            	the same network with same Ethernet address
                            	will cause a little problem.

                            	When using this keyword you need to input
                            	exactly 6 bytes of Ethernet address using
                            	one of the following format:
					                                               
                              	xxxxxxxxxxxx

                            	Default: read address from adapter ROM.

	Transmit Buffers    	Internal driver buffers for packet transmit.
			    	Default: 64
				
	Receive Buffers	    	Internal driver buffers for packet receive.
			    	Default: 64

	Validate Packet Length	Enable driver to check packet length.
				If packet length is incorrect, the driver
				will drop this packet.
				Default: Disable


