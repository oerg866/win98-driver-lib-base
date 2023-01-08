
        D-Link DFE-530TX PCI Fast Ethernet Adapter Installation
                          for Windows 98, Windows 98 SE


 Getting Started
 ---------------

    The Windows 98, Windows 98 SE installation CD are need to
    complete this install.


    Windows 98, Windows 98 SE Installation Procedure
    ------------------------------------------------

     1. Plug PCI Ethernet adapter into the system.

     2. Start your PC normally.  Upon power up, the system will
        indicate to you that new "PCI Ethernet Controller" hardware has
        been found. Press "Next" to be continue.

     3. Insert the driver CD.

     4. Select "Search for the best driver for your device [Recommanded]".

     5. Check d:\ (assume d: is the CD-ROM drive) and press "Next".

     6. The system detects the necessary driver and installs it
        for the new hardware.

     7. After finishing file copying, the Windows system will ask
        you to restart the system.  Select YES to reboot.

     8. During system boot up, the operating system will automatically
        detect the PCI Fast Ethernet adapter and install the driver for
        the adapter.



 Trouble Shooting
 ----------------

    1. Everything is OK in Device Manager, but the network adapter still
       does't function properly. Please make sure that your Computer
       name is different from others in the same network.  You can change
       your Computer name in

       "My Computer" -> "Control Panel" -> "Network" -> "Identification"
       icons

    2. Everything appears to be OK but the network adapter still doesn't
       function properly. Please make sure that the adapter is properly
       connected to a network device (ex: HUB) and the "connection type"
       for this adapter is set to "Auto-negotiation" or the correct
       media type. You can check it in "My Computer" -> "Control Panel"
       -> "Network" -> "Properties" icons. Select "Advanced" item.


    Driver keywords:
    ----------------

      Open "My Computer" -> "Control Pannel" -> "Network" ->
      Double click "D-Link DFE-530TX ...", Select "Advanced" item.

     	Connection Type      	Specify the connection type for the adapter.
                            	Default: Auto-Negotiation

	Driver Initial Delay    If your PC has problem in connecting with Netware
				server, you can enable this option to solve it.
				Default: Disable

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