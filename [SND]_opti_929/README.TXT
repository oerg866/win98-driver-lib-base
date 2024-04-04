                   OPTi MAD16 Pro LATEST INFORMATION
               DOS Utility for Windows 95 (Version 2.50)
                             02/13/96

         !!! Note: For Window 95 users, please Install Windows 95
                   Driver first. Read the README.W95 for the
                   installation guide.  !!!


0.  What's NEW in this release

    DOS:
    1) this version for 929 and 924 legacy. 
    2) use VOLUMEPAGE=NO of [OPTION] in SOUND16.CFG to disable volume
       button in SNDINIT.EXE if users want to run SNDINIT.EXE and
       MIXER.EXE at the same package. 



1.  SOFTWARE PACKAGE CONTENTS

     The MAD16 Pro software package contains (1) 3.5" 1.44M diskette.
     - This is the DOS plus Win95 installation diskette

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
          - SNDINIT.EXE  - also used as hardware Config and Test 
                           Program
          - VOLUME.BAT   - DOS Volume Setup Program
          - VOLTSR.EXE   - Volume Memory Resident Program
          - KARAOKE.EXE  - Karaoke Program
          - CDSETUP.SYS  - CD-ROM setup device driver
          - DEMO8.WAV    - 8-bit Wave audio file
          - DEMO16.WAV   - 16-bit Wave audio file
          - SOUND16.CFG  - Device Configuration file
          - xxxx.SYS     - CD-ROM drivers

			
2.  INSTALLATION PROCESS

     During the installation of 82C929 Windows 95 driver, 
     the installation program will insert a line in AUTOEXEC.BAT to 
     invoke the SND4DOS program to install the 82c929 DOS driver.  
     After installed the Windows 95 driver, the Windows 95 asks for 
     a reboot to make the new hardware (in this case, sound device) 
     to work properly. After reboot, the SND4DOS will be invoked and 
     bring up the DOS driver installation program (install.com on the 
     installation disk ) to install the DOS driver and remove the line 
     SND4DOS inserted in AUTOEXEC.BAT.	
	 
     Please follow the following procedure to install the software:

     1. Follow the installation guideline provided with 929 Windows 95 
        driver to install the Windows 95 driver.  
	
     2. During the first reboot after installed the 929 Windows 95
        driver, the program SND4DOS will take over. Just follow the 
        instrution of SND4DOS to bring OPTi DOS Installer to setup 
        the Sound Card for your Windows 95 real DOS environment.

        !! If you decide not to install at current time, you always
           have a chance to re-setup your sound card support for DOS
           later. Just type C:\SND4DOS at your Real Mode DOS Prompt.


     DOS INSTALL.COM will do the followings for you: 
	 
     a.) Create the directory \SOUND16 in your hard disk drive. 

     b.) Prompt you for CD-ROM and sound card options so that after
         you have finished the installation and have rebooted your 
         machine, you will be ready to use the sound card.

     c.) Copy the files in your floppy disk to the SOUND16 directory. 

     d.) Update your CONFIG.SYS and AUTOEXEC.BAT files
         In CONFIG.SYS, the following will be added:

         - DEVICE=C:\SOUND16\CDSETUP.SYS /T:S /P:340 
           (assuming SONY CD-ROM)
           DEVICE=C:\SOUND16\SLCD.SYS /D:MSCD000 /B:340

         In AUTOEXEC.BAT:
 
         - PATH=C:\SOUND16 (appended)
           SET SOUND16=C:\SOUND16
           C:\SOUND16\SNDINIT /B
           SET BLASTER=A220 I5 D1 T4



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


