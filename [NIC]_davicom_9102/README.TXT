*****************************************************************************
*                                                                           *
*                DAVICOM 9102(A) PCI Fast Ethernet Based Adapter            *
*                                                                           *
*                           NDIS 3/4/5 Driver                               *
*                                                                           *
*                             June 21, 2001                                 *
*                                                                           *
*****************************************************************************




Introduction:
=============

  This document shows you how to setup the driver and how to use the enhanced
  functions by setting the custom keywords.


Contents of the Subdirectory:
=============================

    DM9PCI3.SYS   The NDIS3 driver for Windows 95(OSR1)/NT 3.51 or later.
    DM9PCI4.SYS   The NDIS4 driver for Windows 95(OSR2)/NT 4.0 or later.
    DM9PCI5.SYS   The NDIS5 driver for Windows 98/2000.
    DM9NDI.DLL    The network installer for Windows 95/98.
    DM9INST.DLL   The network co-installer for Windows NT.
    NETDM.INF     The installation information file for Windows 95/98/2000.
    OEMSETUP.INF  The installation information file for Windows NT 3.51/4.0
    README.TXT    This file.



Contents:
=========

    (A) Installing the driver for Microsoft Windows 95 (OSR1)
    (B) Installing the driver for Microsoft Windows 95 (OSR2) or later
    (C) Installing the driver for Microsoft Windows 98 or later
    (D) Installing the driver for Microsoft Windows NT 3.51/4.0
    (E) Installing the driver for Microsoft Windows 2000 series



NOTE: Before starting with the installation process, make sure that the adapter
      is properly installed and configured. You can use the diagnostic program
      (A:\DIAG9102.EXE) in DOS mode to make sure your connection with the network
      is correct.


(A) Installing the driver for Microsoft Windows 95 (OSR1)
=========================================================

    1. Turn the power of your PC on to boot from Windows 95(OSR1). Windows 95(OSR1)
       auto-detects your new adapter installed, and the "New Hardware Found"
       dialogue box will appear. Select "Driver from disk provided by hardware
       manufacturer" to install driver from the diskette that come with your
       lan adapter.

       Note: If your new adapter is not detected by Windows 95(OSR1), you can
       open "My Computer" -> "Control Panel" -> "Networks" after Windows 95(OSR1)
       comes up, and select "Add adapter" -> "Have disk" to install driver from
       the diskette that come with your lan adapter.

    2. Insert the driver diskette into your floppy drive, enter the driver
       path, i.e. A:\, and then click the OK button in the "Install from Disk"
       dialog box.

    3. Select "DAVICOM 9102/A PCI Fast Ethernet Adapter", and start to copy the
       files to your system.

    4. When the driver installation is completed, restart Windows 95(OSR1).

    5. "PME" parameter has no function in the device properties.


(B) Installing the driver for Microsoft Windows 95 (OSR2) or later
==================================================================

    1. Turn the power of your PC on to boot from Windows 95(OSR2 or later).
       The system auto-detects your new adapter installed, and the "New Hardware
       Found" dialogue box will appear. Select "Driver from disk provided by
       hardware manufacturer" to install driver from the diskette that come with
       your lan adapter.

    2. Insert the driver diskette into your floppy drive, and specify the
       path of the driver in the diskette(i.e. A:\) to copy the driver
       files to your system.

    3. Select "DAVICOM 9102/A PCI Fast Ethernet Adapter", and start to copy the
       files to your system.

    4. When the driver installation is completed, restart Windows 95 system.

    5. "PME" parameter has no function in the device properties.


(C) Installing the driver for Microsoft Windows 98 or later
===========================================================

    1. Turn the power of your PC on to boot from Windows 98. The system
       auto-detects your new adapter installed, and the "New Hardware Found"
       dialogue box will appear. Select "Driver from disk provided by hardware
       manufacturer" to install driver from the diskette that come with your
       lan adapter.

    2. Insert the driver diskette into your floppy drive, and specify the
       path of the driver in the diskette(i.e. A:\) to copy the driver
       files to your system.

    3. Select "DAVICOM 9102/A PCI Fast Ethernet Adapter", and start to copy the
       files to your system.

    4. When the driver installation is completed, restart Windows 98.



(D) Installing the driver for Microsoft Windows NT 3.51/4.0
===========================================================

    1. Open "Control Panel" -> "Networks", and choose the "Add Adapter" button.
       The Add Noetwork Adapter dialog box appears.  Select "<other> Requires
       disk from manufacturer" in the list of Network Adapters, and then press
       <Enter>.

    2. Insert the driver diskette into your floppy drive, and specify the
       path of the driver in the diskette(i.e. A:\) if necessary.

    3. Select "DAVICOM 9102/A Based Adapter", and start to copy the files to
       your system.

    4. After all the driver files have been copied to your system, a property
       dialog box appears in the screen. You can enable the special properties
       if you want to.

    5. When the driver installation is completed, restart your PC.


(E) Installing the driver for Microsoft Windows 2000 series
===========================================================

    1. Turn the power of your PC on to boot from Windows 2000. The system
       auto-detects your new adapter installed, and the "New Hardware Found"
       dialogue box will appear. Click the Next button in the "Found New
       Hardware Wizard" dialogue box. Then select the option "Search for a
       suitable driver for my device (recommended)" and click the Next button.

    2. Insert the driver diskette into your floppy drive, and select the option
       "Floppy disk drives", and then click the Next button to start to copy the
       files to your system. After finishing the files copied, click the Finish
       button in the "Found New Hardware Wizard" dialogue box.

    3. Move the cursor onto 'My Network Place', and then click the right button
       of the mouse to open its properties. After clicking, the "Network and Dial-up
       Connections" diaglogue box appears, and then open the properties of the
       "Local Area Connection" of this adapter.

    4. Click the "Install" Button in the "Local Area Connection Properties" dialogue
       box. Select the "Protocol" in the list box of "Select Network Component Type",
       and then push the "Add" button. Insert the driver diskette into your floppy
       drive, click the "Have Disk" button. Input the correct path of the source,
       and push the "OK" push to fire the installation.

    5. In the "Select Network Protocol" dialogue box, select "DAVICOM 9102/A Network
       Diagnostic" and push the OK to finish the installation. After all, click the
       "Close" button to close the "Local Area Connection Properties" dialogue box.

NOTE:
    Step 3, 4, and 5 are for installing the diagnostic program.


Trademarks:
===========

Microsoft Windows NT 3.51/4.0, Windows 95/98, and Windows 2000 are the trademarks of
Microsoft Corporation.

