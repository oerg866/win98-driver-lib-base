            SiS PCI Fast Ethernet Adapter Installation
                for Windows 98/Windows 98 SE Driver
            ==========================================

driver file:  .\sisnic.sys
INF file:     .\netoem.inf

Install The Driver
------------------

1.  Install the card in the PCI slot and connect the cable to the network;
    turn on the computer and start Windows 98. **HAVE YOUR WINDOWS 98 CD
    ROM AVAILABLE** because you will need to copy some additional system
    files.

2.  When Windows 98 starts, a "Add New Hardware Wizard" dialog box appears
    identifying the card as a "PCI Ethernet Controller".

    NOTE, if the "Add New Hardware Wizard" dialog box does not appear,
    please do the followings

    a. After entering Windows 98, double click "My Computer".
    b. Double click "Control Panel".
    c. Double click "System".
    d. Click the "Device Manager" tab.
    e. Open "Other Devices" (with a yellow "?" icon).
    f. Select "PCI Ethernet Controller" then click "Remove" button to
       remove it.

       Note, if you do not see any "PCI Ethernet Controller", Windows 98
       fails to detect your adapter. There may be problem with the adapter
       itself or with the system BIOS.

    g. Click Refresh and a "Add New Hardware Wizard" appears identifying
       the card as a "PCI Ethernet Controller";
    h. goto next step.

3.  Click Next then select "Search for the best driver for your device
    [Recommended]".

4.  Click Next then enable the "Specify a location" check box; specify the
    correct path in which SiS 900 PCI Fast Ethernet Adapter driver for Win98
    resides.

5.  Click Next then Windows 98 identifies the card as
    "SiS 900 PCI Fast Ethernet Adapter"

6.  Click Finish to let Windows 98 finishes the driver installation.


Adapter Configuration
---------------------

1. Double click "My Computer".
2. Double click "Control Panel".
3. Double click "Network" icon.
4. Select
   "SiS 900 PCI Fast Ethernet Adapter"
   then click "Properties..." button.
5. Click "Advanced" tab.
6. Here, you can set the following properties:

   <1>. MediaType

             100BaseTX
             100BaseTX Full_Duplex
             10BaseT Full_Duplex
             10BaseT
             AUTO_CONFIG   ;Default value if not set

   <2>. NetworkAddress

             Override the adapter's Ethernet address. Legal values are
             xx-xx-xx-xx-xx-xx, where xx is a hexadecimal byte value.
             Unless necessary, do NOT modify this field and let the
             system use the default Ethernet address contained in the
             serial ROM on the adapter.

7. After setting the properties, you must restart your computer to
   make the changes effective.

---End of File---


