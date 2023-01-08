			 OPTi 82C924 LATEST INFORMATION
             Windows31/DOS (Version 1.03f )
             Windows95/DOS (Version 4.00.10)
       				  10/15/95

Important note:
----------------

  !! Please check the package you get first !!

  Win95/DOS Package:
    For the users of the Windows 95, please Install Windows 95
    Driver first. Read the README.W95 for the installation guide.

  Win31/DOS Package:
    For the users of the Windows 3.1x and DOS, please install
    this package from a Real DOS prompt. Do not run it in a 
    Windows' DOS session.

---------------------------------------------------------------------

0.  What's NEW in this release

    - When DOS CM (Config Manager) isn't present, the program 
	  uses PnP test mode of 82c924 device to setup the hardware 
	  resource in stead of using old-version MC registers.

	- DOS package now supports both old DOS 6.xx and Win95 DOS

	  For Win31/DOS package, it works as before. The DOS
	  Installer will also install Windows 3.1 Drivers.

	  For Win95/DOS package (a single floppy), it starts
	  from Win95 installation then brings up DOS Installer.

    - Windows 95 Real DOS Support 
	  Add program and functions to integrate with 82C924 Windows 
      95 driver. SNDINIT program puts SETSOUND in DOSSTART.BAT 
      when it detects that "winbootdir" is present, so every time
      the user leave Windows 95 to real mode dos, the SETSOUND
      program will be invoked to setup the sound card. This is
	  necessary because Win95 may reset PNP devices H/W resource
	  at Win95 exit time.
        
    - Add/Update COMM interface and MODEM resource in SYSTEM.INI
      of Windows 3.1 when the sound card supports modem.


1.  SOFTWARE PACKAGE CONTENTS

	Package 1) DOS/Windows 3.1 installation package:
	------------------------------------------------

	  The 82C924 software package contains (1) 3.5" 1.44M diskette.
	  - This is the DOS plus Windows installation diskette

	  The Installation diskette has the following subdirectories and 
	  files:

	  a.)  Installation files
			 - INSTALL.COM  - installation program
			 - INSTALL.DAT  - on-line help text file
			 - CDROM.CFG    - CDROM Config File
			 - README.TXT   - This file
			 - SOUND16.CFG  - Device Configuration File
			 - LOGO.BMP     - Company Logo BMP File

	  b.)  DOS Drivers & Files
			 - SNDINIT.COM  - SNDINIT1.exe or SNDINIT2.exe loader 
			 - SNDINIT1.EXE - hardware config and test program in PNP
							  environment
			 - SNDINIT2.EXE - hardware config and test program in Non 
							  PNP environment
			 - VOLUME.BAT   - DOS volume setup program
			 - VOLTSR.EXE   - Volume memory resident program
			 - KARAOKE.EXE  - Karaoke Program
			 - CDSETUP.SYS  - CD-ROM setup device driver
			 - DEMO8.WAV    - 8-bit Wave audio file
			 - DEMO16.WAV   - 16-bit Wave audio file
			 - SOUND16.CFG  - Device configuration file
			 - xxxx.SYS     - CD-ROM drivers

	  c.)  Windows Drivers & Files (sub Directory: WINDRV)
			 - SND924.DRV   - Base audio device driver
			 - OPTIKB.DLL   - MPU-401 PNP-aware Device Driver
			 - VSND924D.386 - Virtual device driver
			 - MSMIXMGR.DLL - Microsoft mixer manager
			 - MIDIMAP.CFG  - Configuration file for Midimapper
			 - OEMSETUP.INF - For Windows drivers re-installation
			
	  d.)  Windows Audio Application Programs  (sub Directory: WINAPP)
			 - MIXER_IX.EXE - Audio volume mixer control program
			 - APLAYER.EXE  - Wave audio playback and recording 
							  demo application
			 - README.WRI   - Readme file for APLAYER.

			 Besides, you may get other audio applications from your 
			 sound card manufacturer. Most likely, they will install 
			 their audio applications through this INSTALL package 
			 as well.

    Package 2) Windows 95/DOS drivers installation package:
	-------------------------------------------------------

	  The 82C924 Windows 95/DOS installation package contains (1) 3.5" 
	  1.44M diskette.
	  - This is the Windows 95/DOS installation diskette

	  The Installation diskette has the following subdirectories and 
	  files:

	  a.)  Windows 95 Installation files
			 - INS.INF
			 - SND924P.INF

	  b.)  Windows 95 drivers and files:
			 - SND924P.DRV
			 - SND924P.VXD
			 - SNDM401P.DRV
			 - SNDM401P.VXD
			 - SNDOPL3P.DRV
			 - OPTJOY.IN_
			 - README.W95

	  c.)  Installation files
			 - SND4DOS.EXE  - Win95 DOS installation loader
			 - INSTALL.COM  - DOS installation program, invoked 
			                  by SND4DOS.
			 - INSTALL.DAT  - on-line help text file
			 - CDROM.CFG    - CDROM configuration file
			 - README.TXT   - This file
			 - SOUND16.CFG  - Device fonfiguration file
			 - LOGO.BMP     - Company logo BMP file

	  d.)  DOS Drivers & Files
			 - SNDINIT.COM  - SNDINIT1.exe or SNDINIT2.exe loader 
			 - SNDINIT1.EXE - hardware Config and Test Program in PNP
					          environment (with CM)
			 - SNDINIT2.EXE - hardware config and test program in Non 
					          PNP environment (without CM)
			 - SETSOUND.EXE - invoked to configure the hardware when 
					          Windows 95 exits to real mode DOS
			 - VOLUME.BAT   - DOS volume setup program
			 - VOLTSR.EXE   - Volume memory resident program
			 - CDSETUP.SYS  - CD-ROM setup device driver
			 - DEMO8.WAV    - 8-bit Wave audio file
			 - DEMO16.WAV   - 16-bit Wave audio file
			 - SOUND16.CFG  - Device configuration file
			 - xxxx.SYS     - CD-ROM drivers

			
3.  DOS/WINDOWS 3.1 DRIVER INSTALLATION PROCESS

  !!! Note: For Windows users, please exit from Windows and run
                    the installation from DOS. !!!

	  The hard disk installation program, INSTALL.EXE, will copy 
	  the necessary files from OPTi Installation disk into your hard 
	  disk. Follow the following procedure to install the software:

	  (Assuming you are using floppy drive A, and you wish to install
		to hard disk drive C)

	  1. Place the disk labeled "OPTi 82C924 Installation" in 
		  Drive A.

	  2. Type a: and press ENTER to change to Drive A.

	  3. Type install and press ENTER to begin the installation.

	  INSTALL.EXE will do the followings for you: 
	 
	  a.) Create the directory \OPTI924 in your hard disk drive. 

	  b.) Prompt you for CD-ROM and sound card options so that after
			you have finished the installation and have rebooted your 
			machine, you will be ready to use the sound card.

	  c.) Copy the files in your floppy disk to the OPTI924 directory 
			and Windows directory respectively.

	  d.) Update your CONFIG.SYS, AUTOEXEC.BAT and SYSTEM.INI files
			In CONFIG.SYS, the following will be added:

			- DEVICE=C:\OPTI924\CDSETUP.SYS /T:S /P:340 
			  (assuming SONY CD-ROM)
			  DEVICE=C:\OPTI924\SLCD.SYS /D:MSCD000 /B:340

			In AUTOEXEC.BAT:
 
			- PATH=C:\OPTI924 (appended)
			  SET SOUND16=C:\OPTI924
			  C:\OPTI924\SNDINIT /B
			  SET BLASTER=A220 I5 D1 T4

			In SYSTEM.INI:

			- [drivers]
			  WAVE=SND924.DRV
			  AUX=SND924.DRV
			  MIDI=SND924.DRV
			  MIXER=SND924.DRV
 
			  [386Enh]
     		  ;OPTi924 COMM interface. Please do not delete/modify  
			  COMxBase=modem IO Port
			  COMxIrq=modem IRQ

 			  DEVICE=VSND924D.386

			  [snd16.drv]
			  SingleModeDMA=YES
		      CodecType=AD1848
			  
			  MPU401=YES
			  MPU401IP=330
			  MPU401Int=9

		      IOAddress=530
			  Interrupt=5
			  DMADAC=1
			  DMAADC=1

			  ModemIO=2E8
			  ModemIrq=3
			 	

			  * SND924.DRV is the Base driver comprising WAVE, MIDI,
			    MIXER and AUXILIARY audio services.

		      * The program only add/update the lines related to modem
			    when the sound card supports modem. 

			  * VSND924D.386 is the Virtual Device driver for Windows 
			    Enhanced Mode.
			  * x in the COMxIrq, COMxBase is the COMM number (0-4, 
			    0 means that modem is disabled).   	

4.  WINDOWS 95/DOS DRIVERS PACKAGE INSTALLATION PROCESS

	  During the installation of 82C924 Windows 95 driver, 
	  the installation program will insert a line in AUTOEXEC.BAT to 
	  invoke the SND4DOS program to install the 924 DOS driver.  
	  After installed the Windows 95 driver, the Windows 95 asks for 
	  a reboot to make the new hardware (in this case, sound device) 
	  to work properly.	After reboot, the SND4DOS will be invoked and 
	  bring up the DOS driver installation program (install.com on the 
	  installation disk ) to install the DOS driver and remove the line 
	  SND4DOS inserted in AUTOEXEC.BAT.	
	 
	  Please follow the following procedure to install the software:

	  1. Follow the installation guideline provided with 924 Windows 95 
	     driver to install the Windows 95 driver.  
	
	  2. During the first reboot after installed the 924 Windows 95
	     driver, the program SND4DOS will take over. Just follow the 
		 instrution of SND4DOS to bring OPTi DOS Installer to setup 
		 the Sound Card for your Windows 95 real DOS environment.

		 !! If you decide not to install at current time, you always
		    have a chance to re-setup your sound card support for DOS
			later. Just type C:\SND4DOS at your Real Mode DOS Prompt.

	  3. DOS Installer actually is the same one as DOS/Win31.
	 	 The differences are 
		     a. it won't install Win31 Drivers and applications.
			 b. it inserts a line into DOSSTART.BAT in Windows 95
			    Home Directory. 

		 DOS Installer will modify Windows 95 system files:

			In CONFIG.SYS

			  DEVICE=C:\OPTI924\CDSETUP.SYS /T:S /P:340 
			  (assuming SONY CD-ROM)
			  DEVICE=C:\OPTI924\SLCD.SYS /D:MSCD000 /B:340

			In AUTOEXEC.BAT:
 
			  PATH=C:\OPTI924 (appended)
			  SET SOUND16=C:\OPTI924
			  C:\OPTI924\SNDINIT /B
			  SET BLASTER=A220 I5 D1 T4

			In DOSSTART.BAT:
 
			  C:\OPTI924\SETSOUND
			
		
5.  GETTING HELP ABOUT SNDINIT.EXE
 
	  You can issue the following command to get information 
	  about sndinit.exe:

	  - SNDINIT /?




6.  CD-ROM Interface Setup Device Driver

	  The CD-ROM Setup Device Driver is called CDSETUP.SYS. This 
	  driver sets up the interface of your CD-ROM to the 82C924 sound
	  card. Each time you change or add a CD-ROM to your sound card. 
	  The line "DEVICE=CDSETUP.SYS..." will be added to the first line 
	  of your CONFIG.SYS file before the CD-ROM device driver line. 
	  CDSETUP.SYS is defined as follows:
	  
	  DEVICE=[drive:]\[directory]\CDSETUP.SYS /T:[M/S/P/I/X] /P:[addr] 
				/I:[IRQ] /D:[DMA]  

	  [drive] = drive where you have the driver installed
	  [directory] = directory where the driver is located
	  [M/S/P/I/X] = M stands for Mitsumi
						 S stands for SONY
						 P stands for PANASONIC
						 I stands for IDE drive
						 X stands for disabled

	  [address] = Port address for CD-ROM (320, 330, 340, 360)

	  [IRQ] = Interrupt number (5,7,9,10,11)

	  [DMA] = DMA channel (0, 1, 3)

	  For example, the following line sets up the interface for a 
	  Mitsumi CD-ROM:

	  DEVICE=C:\OPTI924\CDSETUP.SYS /T:M /P:340 /I:10

	  If you did not specify the /I or /D options, CDSETUP will 
	  automatically choose the default setting for the CD-ROM type 
	  your have specified.

	  - For Mitsumi, the IRQ is 10 and DMA is disabled.
	  - For SONY, they are both disabled.
	  - FOR PANASONIC, they are both disabled.

	  For IDE drive, you need to just specify the /T:I option. 
	  Specifying any other option in addition to this will be ignored.
	  The I/O Port and Interrupt for IDE is located at 170H and Int 15.


7) Run DOS games in Windows 3.1

   a) Sometimes, the Setup of the PIF file of a DOS game is crucial. 
	  To make a game work effectively under Windows, you probably 
	  have to try a few alternative options through PIF editor.

   b) Not all the DOS games can run in Windows' DOS BOX. Some of 
	  them just don't run because of system restrictions.
	 

