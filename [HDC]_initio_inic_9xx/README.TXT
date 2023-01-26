


    /*******************************************************************
                   Initio INI-9XXXU/UW                            

                  Windows 95\98 device driver                        
    ********************************************************************/

   FILES YOU NEED:
   -------------------------------------------------------------------------
      Information script files for installation: ini910u.inf.
      Miniport device driver: ini910u.mpd.

   INSTALLATION:
   -------------------------------------------------------------------------
   A: New Windows 95 installation:
   B. New Windows 98 installation
   C. Adding to an existing Win 95 system
   D. Adding to an existing Win 98 system


A Window 95 new Installation
-------------------------------
Complete the installation as described in the Window 95
users manual. When the installation has completed open 
the 'Device Manager'. There will be a listing of 
'Other Devices'. Double click on this icon to view the 
devices. Double click on 'PCI-SCSI Bus Controller'. 
Select the driver tab, and then select change driver. 
Select 'SCSI 	Controllers' for the hardware type. 
Select 'Have disk.." in the select device window. Place 
the Initio INI-9XXXU/UW Driver Disk 1 into the floppy 	
drive. Enter the path of 'A:\WIN9X', when prompted, and 
select OK. Select the 'INITIO INI-9XXX Host Adapter" and 
click OK. Click OK when prompted to re-boot the 
system.

B Windows 98 new Installation
--------------------------------

The latest revision of the Initio INI-9XXXU/UW driver is 
imbedded in Windows 98. Windows 98 will detect the SCSI 
adapter and install the appropriate drivers.

***NOTE***
Using the Installation Boot floppy with Win 98 release.
--------------------------------------------------------
To install using the Installation Boot disk from Microsoft 
some minor changes need to be made to the floppy. Make a 
copy of the Windows 98 Boot Disk included with the Windows 
98 package. Copy the following files to the root of the boot 
disk from the DOS directory of the Initio driver diskette
	ASPI910U.SYS
	INICD.SYS 
Edit the config.sys file and add the following lines at the 
end of the [SETUP_CD] header
	Device=aspi910u.sys
	Device=inicd.sys /D:oemcd001
Place the floppy into the drive and reboot the system. Install 
Windows 98 as described in the user manual.

C Windows 95 Adding SCSI adapter to an existing installation
-------------------------------------------------------------

After adding the SCSI adapter boot the system. Windows 95 will 
detect the presence of a new device and open the 'NEW HARDWARE 
FOUND' window with 'PCI SCSI BUS CONTROLLERS' highlighted. Click 
on 'DRIVER FROM DISK PROVIDED BY HARDWARE MANUFACTURER' then 
click 'OK'. Select 'SCSI CONTROLLER' and click on 'HAVE DISK'. 
A window will appear asking for the path. Place disk 1 of the 
INI-9XXXU/UW manager set in the floppy drive. Enter 'A:\WIN9X' 
for the path and click 'OK'. Select INITIO INI-9XXX HOST ADAPTER' 
and click 'OK' Reboot the system when prompted.

****NOTE***
If prompted again for the path enter 'A:\WIN9X'

D Windows 98 Adding SCSI Adapter to an existing installation
------------------------------------------------------------

After adding the SCSI adapter boot the system. Windows 98 will detect the presence of a new SCSI Controller and install the appropriate driver from the Windows 98 CD.

