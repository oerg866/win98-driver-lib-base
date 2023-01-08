
            D-Link DFE-530TX PCI Fast Ethernet Adapter Installation
                            for Windows 2000

 Getting Started
 ---------------

    The Windows 2000 installation CD are needed to complete this
    installation. The driver of DFE-530TX rev.A adapter had been
    supported on Windows 2000 RC2 or later. If you are DFE-530TX
    rev.C user, please following the steps below.

    Windows 2000 Installation Procedure
    -----------------------------------

     1. Make sure your computer is power-off.

     2. Plug the adapter into one PCI slot of your computer.

     3. Turn on the power. Your computer should be booting.

     4. Windows 2000 will find new hardware, and
        "Found New Hardware Wizard" will appear.

     5. Insert the driver CD into the CD-ROM, and press "Next",
        and "Next" again in the following windows.

     6. Select "Specify a location" in the checkbox, and press "Next"
        to continue.

     7. In the following dialog box, specify the directory of the driver
        files. For example:

            D:\ (  assume D: is CD-ROM drive)           
            
        and then click "OK".

     8. The wizard should found the driver now. Follow the direction
        to complete installation.

     9. After finishing the installation, there should be a new
        'Local Area Connection' appearing and the LAN card should work now.


 Trouble Shooting
 ----------------

     - Everything is OK in Device Manager, but the network adapter still
       doesn't function properly. Please make sure that your Computer
       name is different from others in the same network.  You can change
       your Computer name in

       "My Computer" -> "Control Panel" -> "System"
       -> "Network Identification"

     - Everything appears to be OK but the network adapter still doesn't
       function properly. Please make sure that the adapter is properly
       connected to a network device (ex: HUB) and the "connection type"
       for this adapter is set to "AutoSense" or the correct media type.
       To check the media type setting, you should start 'Device Manager'
       in

       "My Computer" -> "Control Panel" -> "System"

       In the 'Device Manager', you can find the adapter in 'Network adapters'.
       Open the adapter's property and select "Advanced" item. You can find
       the connection type setting.


 Driver keywords
 ---------------
     - Open 'Device Manager' in "My Computer" -> "Control Pannel" -> "System".
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

