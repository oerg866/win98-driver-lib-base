
                QLA1080 -- QLogic LVD SCSI Adapter

                Miniport Driver for Windows 95/98

=============
Release Notes
=============

This release has been tested with the following:

    a.  Windows 95 Retail Version.

    b.  Windows 95 OEM Service Release 2 (Build 950b).

    c.  Windows 98 Retail Version.


This document is divided into 4 Sections:

    Section 1:  Windows 95/98 files on this diskette.

    Section 2:  Installation of Windows 95/98 onto a SCSI disk.

    Section 3:  Adding a QLogic Adapter to an existing system.

    Section 4:  Miniport Driver Adapter Settings.

================================================
Section 1:  Windows 95/98 files on this diskette
================================================

The Win9x directory on this diskette contains the following files:

    QL1080.INF  Driver installation script for Windows 95/98.

    QL1080.MPD  Windows 95/98 miniport driver for the QLogic
                QLA1080 LVD SCSI host adapter.

    QL1080.CAT  Digital Signature Catalog file.

    README.TXT  This text file.

==========================================================
Section 2:  Installation of Windows 95/98 onto a SCSI disk
==========================================================

  To initially install Windows 95/98 on a SCSI disk and/or from
  a CD-ROM attached to the QLogic PCI SCSI adapter:

2.1  For Windows 95 Retail Pack (General distribution, Build 950)
-----------------------------------------------------------------

  1. Install QLogic SCSI Adapter and attach SCSI device(s).
  2. Install DOS onto system boot disk.
  3. If installing from CD-ROM attached to QLogic adapter,
     install QLogic DOS drivers for supporting CD-ROM device and
     the MSCDEX.EXE driver.  (Refer to the README file in the root
     directory of the "QLogic Software Drivers" diskette).
  4. Boot to DOS, loading CD-ROM driver, then run the Windows 95 SETUP
     program from the CD.
  5. Once Win95 is loaded and operational, open the "My Computer"
     icon, then open the "Control Panel" icon.
  6. From the Control Panel window, open the "System" icon and
     select "Device Manager" tab.
  7. Listed under "Other devices", select "PCI SCSI Bus Controller"
     and click on "Properties".
  8. Select the "Driver" tab and click on "Change Driver".
  9. Select "SCSI controllers" and click on "OK".
 10. Insert the "QLogic Software Drivers" diskette and click on "Have Disk".
 11. Enter "A:\Win9x" for path to QLogic driver and click "OK".
 12. Select "QLogic QLA1080 LVD PCI SCSI Adapter" and click "OK".
 13. Click "OK" again to proceed with installing miniport driver.
 14. Click "Cancel" in the dialog box that may say, "Windows cannot
     determine if it can remove this device safely" (DO NOT "Test").

 CAUTION: Clicking "TEST" may cause the system to hang.  However,
          restarting the system will result in normal operation.

 15. When prompted to restart your computer, click "No".
 16. Edit the CONFIG.SYS file to remove any QLogic drivers that may
     have been added for DOS support.  These are not required for
     Windows 95.
 17. Remove diskette from drive A:, shut down system and reboot.
     The system will now utilize the miniport driver for all operations.


2.2  For Windows 95 OEM Service Release (Build 950b)
----------------------------------------------------

  1. Install QLogic SCSI Adapter and attach SCSI device(s).
  2. Install DOS onto system boot disk.
  3. If installing from CD-ROM attached to QLogic adapter,
     install QLogic DOS drivers for supporting CD-ROM device and
     the MSCDEX.EXE driver.  (Refer to the README file in the root
     directory of the "QLogic Software Drivers" diskette).
  4. Boot to DOS, loading CD-ROM driver, then run the Windows 95 SETUP
     program from the CD.
  5. Click "No" if Windows restarts and asks if you want to see
     more about your computer not being configured for optimal
     performance.
  6. Once Win95 is loaded and operational, open the "My Computer" icon,
     then open the "Control Panel".
  7. From the Control Panel, open the "System" icon and select
     "Device Manager" tab.
  8. Listed under "Other devices", select "PCI SCSI Bus Controller"
     and click on "Properties".
  9. Select the "Driver" tab and click on "Update Driver".
 10. Insert the "QLogic Software Drivers" diskette and click on "Yes"
     in the 'Update Device Driver Wizard' dialog box to have Windows 95
     search for an updated driver.
 11. Click on "Other Locations" when the 'Update Device Driver
     Wizard' dialog box returns.
 12. Enter "A:\Win9x" for path to QLogic driver and click "OK".
 13. Click "Finish" when the 'Update Device Driver Wizard' finds
     the updated driver for the "QLogic QLA1080 LVD PCI SCSI Adapter".
 14. Click "OK" when prompted to insert the "QLogic Software Drivers" diskette.
 15. Enter "A:\Win9x" for path to QLogic driver in the 'Copying
     Files' dialog box.
 16. Click "OK" to proceed with installing miniport driver.
 17. Click "Cancel" in the dialog box that may say, "Windows cannot
     determine if it can remove this device safely" (DO NOT "Test").

 CAUTION: Clicking "TEST" may cause the system to hang.  However,
          restarting the system will result in normal operation.

 18. Remove diskette from drive A:, shut down system and reboot. The system
     will now utilize the Windows 95 miniport driver for all operations.


2.3  For Windows 98
----------------------------------------------------

If using E/IDE CD-ROM:
  1. Connect E/IDE CD-ROM to E/IDE controller.
  2. Install Qlogic adapter and attach SCSI devices.
  3. Insert the "Windows 98 Boot Disk" into drive A: and turn on your
     computer.
  4. Select option 1 to install Windows 98.  Please be sure that the
     Windows 98 CD is inserted in the CD-ROM drive.

     (Continue with step 6 below)

If using SCSI CD-ROM:
  1. Install Qlogic adapter and attach SCSI devices.
  2. Create a bootable partition on your hard drive and format it.
  3. Boot to C:\.  Insert the "QLogic Software Drivers" diskette into drive A:
     and run SETUP.BAT from A:\.
  4. When the SETUP program prompts for MSCDEX.EXE, insert the "Windows 98
     Boot Disk".
  5. Reboot system and run the Windows 98 SETUP program from the CD.

     (Continue with step 6 below)


  6. Once Windows 98 is loaded and operational, open the "My Computer"
     icon, then open the "Control Panel".
  7. From the Control Panel, open the "System" icon and select
     "Device Manager" tab.
  8. Listed under "Other devices", select "PCI SCSI Bus Controller"
     and click on "Properties".
  9. Select the "Driver" tab and click on "Update Driver".
 10. Insert the "QLogic Software Drivers" diskette and click on "Next" in the
     'Update Device Driver Wizard' dialog box to have Windows 98 search
     for an updated driver.
 11. Select "Display a list of all the drivers in a specific location,
     so you can select the driver you want", then click "Next".
 12. If prompted to select the type of device, select "SCSI Controllers",
     then click "Next".
 13. Click "Have Disk" and enter "A:\Win9x" for the path to the
     QLogic driver, then click "OK".
 14. "QLogic QLA1080 LVD PCI SCSI Adapter" should be selected.  Click "Next".
 15. Windows will display a screen to confirm your QLogic adapter choice and
     path to the QLogic drivers.  Click "Next".
 16. Click "Finish" when the 'Update Device Driver Wizard' finds
     the updated driver.
 17. When prompted to restart your computer, remove the diskette from drive A:,
     then click "Yes".


=============================================================================
Section 3:  Adding a QLogic Adapter to an existing Win 95/98 Operating System
=============================================================================

To install the QLogic QLA1080 SCSI miniport driver on an
already installed Windows 95 or Windows 98 system:

3.1  For Windows 95 Retail Pack (Build 950)
-------------------------------------------

  1. Shut down Windows 95 and install QLogic adapter.
  2. During the reboot, the "New Hardware Found" window will pop up
     after detecting the "QLogic PCI SCSI Bus Controller".
  3. Insert the "QLogic Software Drivers" diskette and select option
     to load "Driver from disk provided by hardware manufacturer",
     and click "OK".
  4. Enter "A:\Win9x" for the path to the driver and click on "OK"
     to install the QLogic miniport driver.

3.2  For Windows 95 OEM Service Release (Build 950b)
----------------------------------------------------

  1. Shut down Windows 95 and install QLogic adapter.
  2. During the reboot, the "New Hardware Found" window will pop up
     after detecting a "PCI SCSI Bus Controller".
  3. Insert the "QLogic Software Drivers" diskette and click "Next".
  4. Click on "Other Locations" when the 'Update Device Driver
     Wizard' dialog box returns.
  5. Enter "A:\Win9x" for path to QLogic driver and click "OK".
  6. Click "Finish" when the 'Update Device Driver Wizard' finds the
     updated driver for "QLogic QLA1080 LVD PCI SCSI Adapter".
  7. Click "OK" when prompted to insert the 'QLogic Software Diskette'.
  8. Enter "A:\Win9x" for path to QLogic driver in the 'Copying Files'
     dialog box.
  9. Click "OK" to proceed with installing miniport driver.
 10. Shut down system and reboot.

3.3  For Windows 98 RETAIL VERSION
----------------------------------

  1. Shut down Windows 98 and install QLogic adapter.
  2. During the reboot, the "New Hardware Found" window will pop up
     after detecting a "PCI SCSI Bus Controller".
  3. Insert the "QLogic Software Drivers" diskette and click "Next".
  4. Select "Display a list of all the drivers in a specific location,
     so you can select the driver you want", then click "Next".
  5. If prompted to select the type of device, select "SCSI Controllers",
     then click "Next".
  6. Click "Have Disk" and enter "A:\Win9x" for the path to the
     QLogic driver, then click "OK".
  7. "QLogic QLA1080 LVD PCI SCSI Adapter" should be selected.  Click "Next".
  8. Windows will display a screen to confirm your SCSI adapter choice and
     path to the QLogic drivers.  Click "Next".
  9. You will notice a pause while the driver is copied and loaded.  Press
     the "Finish" button when it is displayed.
 10. If prompted to restart your computer, remove the diskette from drive A:,
     then click "Yes".


============================================
Section 4:  Miniport Driver Adapter Settings
============================================

  QLOGIC.INF initializes the value of Adapter Settings in the registry to
  configure the miniport driver settings.  The following miniport parameters
  are currently defined:

     MaximumSGList=17       This sets the maximum number of scatter/gather
                            segments to the value 17.

