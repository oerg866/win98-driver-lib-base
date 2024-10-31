
                              W940ND.SYS

                    Winbond Electronics Corporation


Description:

  1. W940ND.SYS is a NDIS 3.x driver for Windows 95, NT 4.0, Windows 98 and
     NT 5.0 Platforms.

     If there is only one 940 card, the driver will automatically get IOBASE
     and IRQ from PCI Configuration Space.

     If there is more than one 940 card, user can indicate a specified 940
     940 card by inputing IDs.

     If user does not input an ID to select a specified 940 card, this driver
     will automatically select a free 940 card to load.

  2. W940ND.INF is a Network Setup Information File.


Installation:

  1. Plug Winbond W89C940 card into one of the PCI slots of your PC.

  2. Turn power on then boot from OS.

  3. If OS prompts Ethernet Controller in New Hardware Found
     dialog box, then please follow below steps to install driver :

     3.1 Select "Specify a location" from New Hardware Found dialog box,
         then click Next button.
     3.2 Type the path name that contains W940ND.SYS and W940ND.INF files and
         click the 'Next' button.
     3.3 When the 'Winbond W89C940 PCI Ethernet Adapter' dialog box appears,
         press <Enter>.
     3.4 Follow screen instructions to complete the process.


Use:

  1. boot your computer,

  2. If you want to select another 940 card, perform the following steps:
       a. Double-click the 'Control Panel' icon in the 'Main' Program Group.
       b. Double-click the 'Network' Iron from the 'Control Panel' Window.
       c. Select the 'Winbond 940 PCI Adapter' item in the 'Installed Adapter
          Cards' Window and double-click the 'Configure' Button.
       d. When the 'Input Ethernet ID' Dialog Box appears, type the Ethernet
          IDs you want to select and then click the 'OK' button.
       e. Click the 'OK' Button in the 'Network Settings' Dialog Box.
       f. Restart your system.


Trouble Shooting:

  Note: 1. On Win98 OS, if you had ever installed the w940nd.inf file
           in drv94014.exe, the result was failed, this w940nd.inf was
           copied to the %winbootdir%\inf\other directory, and was
           renamed to be micros~1.inf (the full name was like
           Microsoftw940nd.inf).
        2. Under case 1, before you want to install the w940nd.inf
           in drv94015.exe, please delete the old w940nd.inf file
           (it is to delete below file:
              %winbootdir%\inf\other\Microsoftw940nd.inf),
           and please also remove any 940 adapter in the system icon in
           control panel, then re-start the OS and re-install 940
           cards by the new w940nd.inf in drv94015.exe.
        3. In drv94014.exe, the Win98 INF file is
              w940nd.inf    97/11/19     size : 6144 bytes.
           In drv94015.exe, the Win98 INF file is
              w940nd.inf    98/04/16     size : 4842 bytes.


Histories of Release:

    ***) 2.00,   12-17-1997
         Pass the NDISTEST.

    ***) 2.10,   06-11-1998
         Fix the driver unloaded problem.

    ***) 2.20,   08-04-1998
         Fix the bug of IRQ sharing.
