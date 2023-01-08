CMD 648/649 IDE Controllers Windows 95/98/ME Driver Installation Instructions
------------------------------------------------------------------------------
Table of Contents
-----------------

I)  Windows 95/98/ME Fresh Installation Instructions.
II) First time installing CMD driver with existing Windows 95/98/ME.
III)Update CMD driver on Windows 95/98/ME system with existing CMD driver.
IV) Optimization using Configuration Utility.


I) Windows 95/98/ME Fresh Installation Instructions. 
-------------------------------------------------
Follow these instructions in this section if you are freshly installing 
Windows 95/98/ME.

Begin Windows 95/98/ME setup using installation CD. If your CD-ROM drive is
not bootable, your can start up with floppy diskettes.

1. Install Windows 95/98/ME using the onboard IDE controller. Do not plug in
   CMD PCI-IDE controller card at this time.
2. When the operating system installation is completed and system is up and 
   running, insert the CMD installation driver diskette into a 3.5" floppy 
   drive.
3. Press the "start" button on the Windows status bar.
4. Select "Run..."
5. Type "a:\win9x\setup"; where "a" is the identifying letter for the 3.5" 
   floppy drive.
6. After the Setup program copies the driver files from diskette to system
   hard drive, the system will prompt "Shutdown the system and install the 
   PCI-64X IDE controller." When this prompt appears, click "OK" and remove 
   the installation diskette from the floppy drive.
   Windows will shut down the system.
7. Inset CMD PCI-IDE controller into a PCI slot that supports bus-master DMA.
   (Your computer's manual should identify the bus-master slots.)
8. Connect your IDE drives to the CMD PCI-IDE controller card.
9. Power up the system.  The CMD PCI-IDE controller card on-board BIOS
   should automatically detect the drives connected to it once power-up is
   complete.
10. System will go through the enumeration process and detect new hardware.
   At the end of the process, Windows will prompt "to finish setting up
   your hew hardware, you must restart your computer."  Simply select "No"
   for this message and all the other messages that follow.  Do a manual
   restart from desktop instead (start -> shut down -> restart).



II) First time installing CMD driver with existing Windows 95/98/ME.
-----------------------------------------------------------------

If you have an existing Windows 95/98/ME system and just obtain a
CMD PCI-IDE controller card, you need to run the Setup program to install
CMD driver before you insert the CMD controller into you system.  
The Setup Utility is located in the CMD driver diskette or the diskette
provided by OEM vendor.

1. Place the installation files on a floppy diskette.  Make sure
   all of the files are in the same directory.

2. Press the "Start" button on the Windows 95/98/ME status bar.

3. Select "Run...".

4. Enter "Setup" with the full path of the installation files.
   for example, if the installation files are in the root directory
   of A drive, then type "A:\win9x\setup".

5. After the Setup program copies the driver files from diskette to system
   hard drive, the system will prompt "Shutdown the system and install the 
   PCI-64X IDE controller." When this prompt appears, click "OK" and remove 
   the installation diskette from the floppy drive.
   Windows will shut down the system.

6. Wait until the system power is down .  Plug in CMD PCI-IDE controller card.
   Connect the drives to the controller.  Power up the system.

7. System will go through the enumeration process and detect new hardware.
   At the end of the process, Windows will prompt "to finish setting up
   your hew hardware, you must restart your computer."  Simply select "No"
   for this message and all the other messages that follow.  Do a manual
   restart from desktop instead (start -> shut down -> restart).


III) Update CMD driver on Windows 95/98/ME with existing CMD driver.
-----------------------------------------------------------------

With the CMD controller already plugged in and CMD driver already installed.
The driver upgrade can be done by running the same Setup Utility program.

1. Follow the same steps (step 1 to 5) as shown in section (II).
2. After reboot.  The new driver will be loaded by the Windows.
     

IV) Optimization using Configuration Utility.
----------------------------------------------

CMD provides a Configuration Utility that allows advanced user to change
the controller configuration.  Utility can be accessed once CMD driver
is installed whether from a fresh installation or from an upgrade.
When CMD driver is installed using Setup Utility, the configuration will
be set to a default mode that maximizes the performance of the drives
connected to the controller.  In most cases, this means the controller
is tuned to highest transfer mode that is supported by the drives.  If
a user wishes to change this default setting, it can be done through
this Configuration Utility in "system property".

If you wish to configure the driver for optimal performance, follow
the following steps.

1. Open "System Properties" and click on the Device Manager tab.
   "System Properties" can be accessed by two ways.  The first method is
   through the Control Panel by the mouse sequence:
     "Start Button -> Settings -> Control Panel -> System".
   The second method is to right click on the "My Computer" icon and then
   select Properties.

2. Under "Hard Disk Controllers" you should see 
     "CMD PCI-0648 (may be 0649, depends on the controller is being
     used) Bus Master PCI to IDE Controller",
     "Primary CMD Bus Master IDE Controller", and 
     "Secondary CMD Bus Master IDE Controller".
   Double click on one of the latter two that corresponds to the channel
   that you wish to configure.  Select the "Settings" tab.

3. Change the "PCI Bus Speed" to match the PCI speed of your computer.
   If you have a 66MHz, 100MHz, 133MHz, 166MHz, or 200MHz system, the
   bus speed is likely to be 33MHz.  If you have a 60MHz, 90MHz, 120MHz,
   or 150MHz, then the bus speed is likely to be 30MHz.  If you have a
   75MHz system, then the bus speed is likely to be 25MHz.

4. Normally after the driver is installed, the "16-Bit PIO" and "Use LBA 
   Mode on Small Drives" options will be unchecked and "Enable DMA on 
   ATAPI Drives" option is checked. "Enable DMA" could be either checked
   or unchecked depending on the transfer mode supported by the drive.  
   Generally you want to leave them as default.  However, user can change 
   them to different setting. These option are defined as following:
	16-Bit PIO = access IDE data register in 16-bit instead of 32-bit.
                     This only applies to some older drives that do not
                     support 32-bit data access.  Newer drives should all
                     support 32-bit access nowadays.
        Use LBA Mode on Smaller Drives = use LBA mode to access smaller
					 drive.  Only apply to older drive.
                                         Newer drives support LBA mode and
                                         does not need this feature.
	Enable DMA on ATAPI Drives = set the transfer mode of the ATAPI 
                                     drive (CD-ROM, CD-R/W, and tape...) to 
                                     the highest DMA transfer mode supported
                                     by the drive. 
        Enable DMA = set the transfer mode to the highest DMA transfer mode
                     supported by the drive.

5. "Enable DMA" option indicates whether DMA mode is enabled on this drive.
   A "No Override" setting means the Controller will transfer data using 
   the highest (fastest) mode that the drive claims it supports. If 
   "Enable DMA" is checked and "No Override" setting is chosen, the drive
   will run DMA mode if the drive supports it (UDMA for most newer drives).  
   If "Enable DMA" is unchecked and "No Override" setting is chosen, the 
   drive will run PIO mode even if it supports MDMA and UDMA modes.  

   When you specify other settings other than "No Override", The "Enable DMA"
   option will be gray out indicating the drive will be forced to either PIO,
   MDMA or UDMA modes regardless of what the drive can support.  Even though
   the "Enable DMA" option is gray out. It will still be checked if a DMA 
   mode is chosen (MDMA or UDMA).

6. After you change the setting.  Click "OK".
7. System will prompt you with the following message "You must restart your 
   computer before the settings will take effect.  Do you want to restart
   your computer now?" When this message appears, select "Yes".
8. After the system is restarted, the new settings will apply.
   


