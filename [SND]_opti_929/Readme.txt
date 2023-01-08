					  OPTi MAD16 Pro LATEST INFORMATION
							DOS/Windows (Version 2.20)
										12/07/94

	 !!! Note: For Windows users, please exit from Windows and run
				the installation from DOS. !!!

0.  What's NEW in this release

	 - Support OTHER CD drives which not listed in our installer's CD
		drive list. OTHER IDE, Sony compatible and Panasonic compatible
		are those which we are not aware of at the time software release
		but actually could be interfaced with our sound cards. What
		the software does, when OTHER is selected, is to setup the
		CD-ROM interface of the sound card. The CD driver installation
		then has to be taken care by you after the audio software 
		installation is done.
	 - Maintain Green PC feature after IRQ re-selection
	 - Reset FM MIDI device during INIT


1.  SOFTWARE PACKAGE CONTENTS

	 The MAD16 Pro software package contains (1) 3.5" 1.44M diskette.
	 - This is the DOS plus Windows installation diskette

	 The Installation diskette has the following subdirectories and 
	 files:

	 a.)  Installation files
			- INSTALL.COM  - Hard disk installation program
			- INSTALL.DAT  - on-line help text file
			- SNDINIT.EXE  - INSTALL Main Program
			- CDROM.CFG    - CDROM Config File
			- README.TXT   - This file
			- SOUND16.CFG  - Device Configuration File
			- LOGO.BMP     - Company Logo BMP File

	 b.)  DOS Drivers & Files
			- SNDINIT.EXE  - also used as hardware Config and Test Program
			- VOLUME.BAT   - DOS Volume Setup Program
			- VOLTSR.EXE   - Volume Memory Resident Program
			- KARAOKE.EXE  - Karaoke Program
			- CDSETUP.SYS  - CD-ROM setup device driver
			- DEMO8.WAV    - 8-bit Wave audio file
			- DEMO16.WAV   - 16-bit Wave audio file
			- SOUND16.CFG  - Device Configuration file
			- xxxx.SYS     - CD-ROM drivers

	 c.)  Windows Drivers & Files (sub Directory: WINDRV)
			- SND16.DRV    - Base Audio Device Driver
			- MPU401P.DRV  - MPU-401 Device Driver
			- VSND16D.386  - Virtual Device Driver
			- MSMIXMGR.DLL - Microsoft Mixer Manager
			- MIDIMAP.CFG  - Configuration file for Midimapper
			- OEMSETUP.INF - For Windows drivers re-installation
			
	 d.)  Windows Audio Application Programs  (sub Directory: WINAPP)
			*** You may not have Windows applications shipped with your 
				 sound card.
			
2.  INSTALLATION PROCESS

	 The hard disk installation program, INSTALL.EXE, will copy 
	 the necessary files from OPTi Installation disk into your hard 
	 disk. Follow the following procedure to install the software:

	 !!! Note: For Windows users, please exit from Windows and run
				the installation from DOS.

	 (Assuming you are using floppy drive A, and you wish to install
	  to hard disk drive C)

	 1. Place the disk labeled "OPTi MAD16 Pro Installation" in 
		 Drive A.

	 2. Type a: and press ENTER to change to Drive A.

	 3. Type install and press ENTER to begin the installation.

	 INSTALL.EXE will do the followings for you: 
	 
	 a.) Create the directory \SOUND16 in your hard disk drive. 

	 b.) Prompt you for CD-ROM and sound card options so that after
		  you have finished the installation and have rebooted your 
		  machine, you will be ready to use the sound card.

	 c.) Copy the files in your floppy disk to the SOUND16 directory and 
		  Windows directory respectively.

	 d.) Update your CONFIG.SYS, AUTOEXEC.BAT and SYSTEM.INI files
		  In CONFIG.SYS, the following will be added:

		  - DEVICE=C:\SOUND16\CDSETUP.SYS /T:S /P:340 
			 (assuming SONY CD-ROM)
			 DEVICE=C:\SOUND16\SLCD.SYS /D:MSCD000 /B:340

		  In AUTOEXEC.BAT:

		  - PATH=C:\SOUND16 (appended)
			 SET SOUND16=C:\SOUND16
			 C:\SOUND16\SNDINIT /B
			 SET BLASTER=A220 I5 D1 T4

		  In SYSTEM.INI:

		  - [drivers]
			 WAVE=SND16.DRV
			 AUX=SND16.DRV
			 MIDI=SND16.DRV
			 MIXER=SND16.DRV
			 MIDI1=MPU401P.DRV

			 [386Enh]
			 DEVICE=VSND16D.386

			 SND16.DRV is the Base driver comprising WAVE, MIDI,
			 MIXER and AUXILIARY audio services.
		
			 MPU401P.DRV is the device driver for MPU-401 Wave Table 
			 Synthesis interface which requires a MPU-401 compatible 
			 device attached to the MIDI Input/Output port or the Wave 
			 Table connector on board the sound card.

			 VSND16D.386 is the Virtual Device driver for Windows 
			 Enhanced Mode.


3.  GETTING HELP ABOUT SNDINIT.EXE
 
	 You can issue the following command to get information 
	 about sndinit.exe:

	 - SNDINIT /?


4.  VOLUME CONTROL TSR PROGRAM

	 The volume control memory resident program, VOLTSR.EXE, allows
	 you to change volume using hot keys while you are in a DOS 
	 application. The hot keys are:

		  Ctrl-Alt-U      Raises the volume
		  Ctrl-Alt-D      Lowers the volume
		  Ctrl-Alt-M      Mute

	 For example, pressing the CTRL, ALT, and U keys will raise 
	 the volume.

	 You need to load the TSR before you can use it. To load the TSR,
	 type VOLTSR at the DOS prompt.


5.  KARAOKE PROGRAM

	 The Karaoke.exe program allows user to control the input volume
	 of the microphone on the fly with "HOT KEYS." Before using 
	 Karaoke, the VOLTSR.EXE program must be successfully loaded
	 and running.

	 To enable Karaoke Mode, type: "KARAOKE ON" at the DOS prompt.

	 To increase MIC input, use: Ctrl-Alt-PageUp
	 To decrease MIC input, use: Ctrl-Alt-PageDown

	 To disable Karaoke Mode, type: "KARAOKE OFF" at the DOS prompt.


6.  CD-ROM Interface Setup Device Driver

	 The CD-ROM Setup Device Driver is called CDSETUP.SYS. This 
	 driver sets up the interface of your CD-ROM to the MAD16 sound
	 card. Each time you change or add a CD-ROM to your sound card. 
	 The line "DEVICE=CDSETUP.SYS..." will be added to the first line 
	 of your CONFIG.SYS file before the CD-ROM device driver line. 
	 CDSETUP.SYS is defined as follows:
	 
	 DEVICE=[drive:]\[directory]\CDSETUP.SYS /T:[M/S/P/I/X] /P:[address] 
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

	 DEVICE=C:\SOUND16\CDSETUP.SYS /T:M /P:340 /I:10

	 If you did not specify the /I or /D options, CDSETUP will 
	 automatically choose the default setting for the CD-ROM type 
	 your have specified.

	 - For Mitsumi, the IRQ is 10 and DMA is disabled.
	 - For SONY, they are both disabled.
	 - FOR PANASONIC, they are both disabled.

	 For IDE drive, you need to just specify the /T:I option. 
	 Specifying any other option in addition to this will be ignored.
	 The I/O Port and Interrupt for IDE is located at 170H and Int 15.


7) Run DOS games in Windows

	 Our implementation is designed for those DOS games which have
	 icons in Windows and run in full screen DOS and close after 
	 finished. When multiple DOS boxes are open, only the first 
	 DOS box owns the audio device. DOS Box support could be very 
	 complicated, we have to concentrate our implementation only on 
	 those features most useful to the general users. We recommend 
	 to run game or play audio in DOS box only one at a time. 
	 Close the DOS box which owns the device will return the device 
	 to Windows. Then you can play audio in Windows or run another 
	 DOS game.

	 !! Note !!
	 a) Sometimes, the Setup of the PIF file of a DOS game is crucial. 
		 To make a game work effectively under Windows, you probably 
		 have to try a few alternative options through PIF editor.
	 b) Not all the DOS games can run in Windows' DOS BOX. Some of 
		 them just don't run because of system restrictions.
	 
		

