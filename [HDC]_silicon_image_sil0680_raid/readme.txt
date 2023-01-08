Silicon Image Ultra-133 Medley ATA Raid Controller OS Driver Installation
-------------------------------------------------------------------------

Table of Contents
-----------------

 1) Windows NT 4.0 and Windows 2000/XP Fresh Installation.

 2) Adding the SiI RAID controller to an existing Windows NT installation.

 3) Adding the SiI RAID controller to an existing Windows 2000/XP installation.

 4) Verifying controller installation under Windows NT, 2000 and XP.

 5) Update SiI RAID driver on Windows NT 4.0 with existing Silicon Image driver.

 6) Update SiI RAID driver on Windows 2000/XP with existing Silicon Image driver.

 7) Windows 98SE and Windows ME Fresh Installation Instructions.

 8) First time installing SiI RAID driver with existing Windows 98SE/ME.

 9) Update SiI RAID driver on Windows 98SE/ME with existing Silicon Image driver.

 

--------------------------------------------------------
1) Windows NT 4.0 and Windows 2000/XP Fresh Installation
--------------------------------------------------------
Follow the instructions in this section if you are performing a new
installation of Windows NT 4.0 or Windows 2000/XP, and you wish to
boot from a device attached to the SiI 680 controller.


1. Power off the system.  Connect the hard drives to the PCI-680
   controller and insert the controller into a PCI slot. Power up
   the system.

2. Put your Windows NT/2000/XP CD into the CD-ROM/DVD drive, or
   the NT/2000/XP boot diskette #1 in the floppy drive if your 
   system cannot boot from the CD.

3. Press F6 for third party SCSI or driver installation at the beginning
   of text mode installation.  Press 's' when setup asks if you want to
   specify an additional device, and insert the diskette labeled
   'Silicon Image Ultra-133 Medley ATA Raid Driver Installation Disk' .

   Press 'Enter' and select 
   'Silicon Image Ultra-133 Medley ATA Raid Controller'

4. Press 'Enter' to continue on with text mode setup.

5. Follow the setup instructions to select your choice for
   partition and file system.

6. After setup examines your disks, it will copy files to 
   Windows 2000 installation folders and restart the system.  
   The setup program will continue and finish the installation
   after restart.

7. Wait until Windows 2000 finishes installing devices, regional
   settings, networking settings, components, and final set of 
   tasks, reboot the system if it is required.  

8. See instructions in section 4 to verify controller was installed
   correctly.



---------------------------------------------------------------------------
2) Adding the SiI RAID controller to an existing Windows NT 4.0 installation
---------------------------------------------------------------------------
Follow the instructions in this section to install the Silicon Image
SiI 680 driver on a system already running Windows NT 4.0.


1. Power off the system.  Connect the hard drives to the PCI-680
   controller and insert the controller into a PCI slot. Power up
   the system.  

2. After OS boots up, Click 'Start' 

3. Under 'Settings', click 'Control Panel'.

4. Select 'SCSI Adapters' from the Control Panel.

5. Select the 'Drivers' tab and click 'Add'.

6. Click 'Have Disk'.

7. Insert the diskette labeled ' Silicon Image Ultra-133 Medley ATA Raid
   Driver Installation Disk' into A: and press 'Enter'.

8. Choose 'Silicon Image Ultra-133 Medley ATA Raid Controller' and 
   click 'OK'.

9. See instructions in section 4 to verify controller was installed
   correctly.



---------------------------------------------------------------------------
3)Adding the SiI RAID controller to an existing Windows 2000/XP installation
---------------------------------------------------------------------------
Follow the instructions in this section to install the Silicon Image
SiI 680 driver on a system already running Windows 2000.


1.  Power off the system.  Connect the hard drives to the PCI-680
    controller and insert the controller into a PCI slot.  Power up
    the system.  

2.  During OS boot up, Windows 2000 will display the 
    'Found New Hardware Wizard'. Click 'Next'.

3.  Select 'Search for a suitable driver for my device
    (Recommended)' and Click 'Next'.

4.  Under 'Optional search locations' insure that 'Floppy disk drives'
    is checked.

5.  Insert the diskette labeled ' Silicon Image Ultra-133 Medley ATA Raid Driver
    Installation Disk'  into A: and click 'Next'.

6.  When the wizard indicates that it found a driver for the device click
    'Next'.

7.  If the 'Digital Signature Not Found' dialog appears, click 'Yes' to
    continue installing the driver.

8.  The wizard will now copy the required files to the system and start the
    driver.  After starting the driver the wizard will display a completion
    dialog, click 'Finish' to exit the wizard.

9.  See instructions in section 4 to verify controller was installed
    correctly.



------------------------------------------------------------------
4) Verifying controller installation under Windows NT, 2000 and XP
------------------------------------------------------------------
Follow the instructions in this section to verify that the controller was
installed correctly.

   For Windows 2000/XP

      1. Right click on 'My Computer' icon, select 'Properties',
         left click on 'Hardware' tab, and then on 'Device Manager' 
         button.

      2. Double click on 'SCSI and RAID Controllers', If there is no
         yellow '! ' or ' ? ' in front of
         'Silicon Image Ultra-133 Medley ATA Raid Controller', the driver
	 is started correctly.  

      3. To view information about the devices attached to the controller, use the SiICfg
         Utility and click on the device from the list. 
         

   For Windows NT 4.0

      1. Double click on 'My Computer' icon, select 'Control Panel', click
         on 'SCSI Adapters' icon, 'Silicon Image Ultra-133 Medley ATA Raid 
	 Controller' should displayed correctly under 'Device' and 'Driver' tab.

      2. To view information about the devices attached to the controller, use the SiICfg
         Utility and click on the device from the list. 

-------------------------------------------------------------------------------
5) Update SiI RAID driver on Windows NT 4.0 with existing Silicon Image driver
-------------------------------------------------------------------------------

1. After OS boots up, Click 'Start' 

2. Under 'Settings', click 'Control Panel'.

3. Select 'SCSI Adapters' from the Control Panel.

4. Select the 'Drivers' tab and click 'Add'.

5. Click 'Have Disk'.

6. Insert the diskette labeled 'Silicon Image Ultra-133 Medley ATA Raid Driver
   Installation Disk' into A: and press 'Enter'.

7. Choose 'Silicon Image Ultra-133 Medley ATA Raid Controller' and 
   click 'OK'.

8. Refer to instructions in section 4 to verify controller was installed
   correctly.


-------------------------------------------------------------------------------
6) Update SiI RAID driver on Windows 2000/XP with existing Silicon Image driver
-------------------------------------------------------------------------------

With the Silicon Image controller already plugged in and the driver already 
installed.  Follow the instructions to update SiI RAID driver.


1. Right click on 'My Computer' and select 'Properties'. Under the 'System Properties'
   section, click on 'Hardware' tab, and then on 'Device Manager'
   click 'SCSI and RAID Controller'  and right click 'Silicon Image Ultra-133 Medley
   ATA Raid Controller'.

2. Click 'Driver' ,'Update Driver'  and select 'Search for a suitable driver for my
   device[Recommended]'. Insert the driver diskette into floppy drive. 
   Click 'Next' and complete the driver installation.

3. System will go through the enumeration process and install the driver.
   At the end of the process, click 'Yes' to reboot your system when necessary.  

4. See instructions in section 4 to verify controller was installed
   correctly.


--------------------------------------------------------------
7) Windows 98SE and Windows ME Fresh Installation Instructions 
--------------------------------------------------------------
Follow the instructions in this section if you are performing a new 
installation of Windows 98SE/ME and you wish to boot from a device attached
to the SiI 680 controller.

You may start up the Windows 98SE/ME installation from CD. If either your
Windows 98SE/ME CD or CD-ROM drive is not bootable, your can start up with
floppy diskettes.

1. Power off the system.  Connect the hard drives to the SiI RAID
   controller and insert the controller into a PCI slot. Power up
   the system.  

2. Put your Windows 98SE/ME CD into the CD-ROM/DVD drive, and
   the Windows 98SE/ME boot diskette in the floppy drive if your 
   system cannot boot from the CD.

3. Follow the normal Windows 98SE/ME setup instructions to select your choice for
   partition and file system.


4. Wait until Windows 98SE/ME finishes installing devices, regional
   settings, networking settings, components, and final set of 
   tasks, reboot the system.  

5. After the system reboot, right click on 'My Computer' and select 'Properties'.  
   From the 'System Properties' , select 'Device Manager', right click on
   the '?PCI RAID controller' and select 'Properties' from the pop-up menu.

6. Click 'Driver' ,'Update Driver'  and select 'Automatic search for a better
   driver[Recommended]'. Insert the driver diskette into floppy drive. 
   Click 'Next' and complete the driver installation.

7. System will go through the enumeration process and install the driver.
   At the end of the process, click 'Yes'  to reboot your system.  

8. See instructions in section A to verify controller was installed
   correctly.


----------------------------------------------------------------------
8) First time installing SiI RAID driver with existing Windows 98SE/ME
----------------------------------------------------------------------

If you have an existing Windows 98SE/ME system and just obtained a
Silicon Image SiI 680 controller card, you need to run the update program 
to install Silicon Image driver. The driver package is located in the 
Silicon Image driver diskette or the diskette provided by OEM vendor.

1. Power off the system.  Connect the hard drives to the SiI 680
   controller and insert the controller into a PCI slot. Power up
   the system.

2. During the system boot up, the Hardware Wizard will display that it found a 
   ' PCI RAID Controller' , click ' Next' . Select ' Search for the best
   driver for your device[Recommended]'  and click ' Next' .  

3. Check the ' Floppy disk drives'  and insert the driver diskette into floppy 
   drive.  Click ' Next' .

4. System will go through the enumeration process and install the driver.
   At the end of the process, Click ' Finish'  to complete the installation.
   Reboot the system if your Windows 98SE/ME drive is connected on the 
   SiI RAID Controller. 

5. See instructions in section A to verify controller was installed
   correctly.


-------------------------------------------------------------------------------
9) Update SiI RAID driver on Windows 98SE/ME with existing Silicon Image driver
-------------------------------------------------------------------------------

With the Silicon Image controller already plugged in and the driver already 
installed.  Follow the instructions to update SiI 680 driver.


1. Right click on 'My Computer' and select 'Properties'. Under 'System Properties',
   click 'SCSI and RAID Controller'  and right click 'Silicon Image Ultra-133 Medley
   ATA Raid Controller'.

2. Click 'Driver' ,'Update Driver'  and select 'Automatic search for a better
   driver[Recommended]'. Insert the driver diskette into floppy drive. 
   Click 'Next' and complete the driver installation.

3. System will go through the enumeration process and install the driver.
   At the end of the process, click 'Yes' to reboot your system.  

4. See instructions in section A to verify controller was installed
   correctly.


------------------------------------------------
A) Using Control Panel Utility (Windows 98SE/ME) 
------------------------------------------------
Follow the instructions in this section to verify that the controller was
installed correctly on Win98SE and Windows ME.

      1. Right click on 'My Computer' icon, select 'Properties'.
         Click on 'Device Manager' tab.

      2. Double click on 'SCSI and RAID Controllers', If there is no
         yellow '! ' or ' ? ' in front of 'Silicon Image Ultra-133 Medley ATA Raid
         Controller', the driver is started correctly.  

      3. To view information about the devices attached to the controller, use the SiICfg
         Utility and click on the device from the list. 


