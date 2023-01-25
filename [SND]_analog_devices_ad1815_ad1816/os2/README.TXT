   		    AD1815 and AD1816 Soundport Controller Driver for OS/2
   				Production Release 1.0 
		  	   	   Analog Devices, Inc.
---------------------------------------------------------------------------------------------------------------------------
                           

I. FILES ON THIS DISKETTE
--------------------------------------------------------------------------------------------------------------------------   

AD1816.HLP     	7,071 	09-11-96  11:05p  - AD1816 Soundport controller help file
AD1816.SCR         	3,588 	08-28-96   9:19p   - AD1816 Soundport controller file list
AD1816DD.SYM         	7,620 	09-12-96  12:42p   - AD1816 Driver symbols file
AD1816DD.SYS        	41,199 	01-08-97   2:13p    - AD1816 Soundport controller driver
AUDPLAY.ICO         	4,395 	02-10-95   5:26p    - Audio ICON
CARDINFO.DLL        	26,737 	09-11-96  11:05p   - AD1816 Soundport controller card info
CLOCK01.SYS         	4,181 	10-19-94   7:09p    - Timer driver
CLOCK02.SYS         	4,280 	10-19-94   7:10p    - Timer driver
CONTROL.SCR         	4,145 	09-12-96   9:00a    - Install script for MINSTALL
GAMEDD.SYS         	6,683 	05-06-95  12:30p   - Joystick driver
GAMEVDD.SYS         	5,296 	03-24-95   8:42a   - Joystick driver
JOYSTK.CH             	61 	05-25-95   2:17p    - Joystick install script
JOYSTK.ICO        	15,782 	05-26-95  10:58a   - Joystick ICON
MIDIPLAY.ICO         	4,395 	07-19-94   5:54p    - MIDI ICON
MPU401.SYS        	13,318 	05-13-96   8:28p    - MPU-401 driver
MPURES.DLL         	1,040 	05-22-96   2:55p    - MPU-401 resource DLL
OPL3.HLP         	2,599 	01-16-95   3:38p    - OPL3 Help File
OPL3.SYS        		23,879 	10-20-94   4:49p    - OPL3 driver
OPL3RES.DLL         	1,040 	01-16-95   3:38p    - OPL3 resource file
README.TXT        	18,830 	09-13-96   3:31p    - This file
RSTRCLK.BAT         	2,065 	08-29-96   7:51a    - Batch file for restoring timer basedevs
TIMER0.SYS        	 7,142 	09-23-94   4:31p    - Timer driver
UPDTCLK.BAT         	3,188 	08-29-96   7:43p    - Batch file for updating timer basedevs
STARWARS.MID       	107,302 05-13-96   9:55p    - Sample MIDI file
M1.MID        		17,232 	06-02-96   2:07p    - Sample MIDI file
HOTOP01.MID         	1,283 	12-29-95   2:39p    - Sample MIDI file
                        30 file(s)     

II. BEFORE YOU BEGIN
-------------------------------------------------------------------------------------------------------------------------- 
Proper operation of the Analog Devices AD1816 Soundport
Controller requires that:

     --You are using OS/2 Warp version 3.
     --The OS/2 Multimedia Extensions are installed.
     --The Analog Devices AD1816 driver is installed.

NOTE: You must have the OS/2 Multimedia Extensions installed
           BEFORE you install this driver. You will use the OS/2
           Multimedia Extensions to install and configure the Analog
           Devices AD1816 Soundport Controller driver.

If your installation fails, you may need to update some of
your OS/2 system files. See the "Troubleshooting" section
for more information.

III. CHECKING FOR THE OS/2 MULTIMEDIA EXTENSIONS
--------------------------------------------------------------------------------------------------------------------------
Check your system for the following conditions:

     --If the extensions are already installed you will see the
       "Multimedia" icon on your OS/2 desktop. If the extensions
       are already installed, skip ahead to the procedure
       "INSTALLING THE AD1816 SOUNDPORT CONTROLLER DRIVER."

     --If the "Multimedia" icon is not visible, OS/2 Multimedia
       Extensions may not yet be installed. Install the
       extensions using the following procedure.

IV. INSTALLING THE MULTIMEDIA EXTENSIONS
--------------------------------------------------------------------------------------------------------------------------     To install the Multimedia Extensions:

     1.Open the "OS/2 System" folder on the OS/2 desktop. Double-
        click the "System Setup" icon.
     2.From the "System Setup" window, double-click the
        "Selective Install" icon to display the "System
        Configuration" window. The box labeled "Multimedia Device
        Support" in the lower left corner of the "System
        Configuration" window should read "None".
     3.Click the "OK" button. The "OS/2 Setup and Installation"
        window appears.
     4.Click the box next to "Multimedia Software Support". You
        should now see a check mark in that box.
     5.Click the "Install" button. OS/2 will begin installing
        the extensions. Follow all on-screen instructions,
        including the last one that instructs you to restart your
        system. Once your system has restarted, use the following
        procedure to install the driver for the Analog Devices
        AD1816 Soundport Controller.

V. INSTALLING THE  AD1816 SOUNDPORT CONTROLLER DRIVER
--------------------------------------------------------------------------------------------------------------------------     To install the AD1816 Soundport Controller Driver:

     1.Double-click the "Multimedia" folder icon on the OS/2
       desktop. Run the "Multimedia Application Install"
       program.
     2.Insert the AD1816 Soundport Controller OS/2 Driver
        Diskette into your diskette drive.
     3.Use the drop-down "Drive" list box to select the drive
        letter, A: or B:, that contains the diskette.
     4.Click the "Analog Devices AD1816" line to place a check
        mark next to the selection. By default, the AD1816 driver
        installation does not install the MPU-401 support for
        MIDI devices (since this is not a very common installation 
        option). If you want MPU-401 support, click  the
        "IBM MPU-401" line to place a check mark next to it.
     5.Click the "Install" button. If you receive a warning that
        the program will change your CONFIG.SYS file, click the
        "Yes" button to allow the program to make the required
        changes.
     6.The "Analog Devices AD1816" window appears. This window
        displays the configuration information for the AD1816
        Soundport Controller.  Note that the Analog Devices
        AD1816 Soundport Controller has no jumpers or switches;
        all of the hardware configuration is from this window.
     7.Click the "OK" button. You will receive several
        additional notifications: installation windows for
        several driver components,  that your CONFIG.SYS file was
        backed up, and that the installation is complete. Click
        "OK" on each of these alerts.
     8.Exit OS/2 and reboot your system. When you reboot your
        system you should hear the OS/2 start-up sounds,
        indicating that your audio card is properly installed and
        working.

VI. CONFIGURING THE  3D SOUND FEATURES
--------------------------------------------------------------------------------------------------------------------------     The Analog Devices AD1816 Soundport Controller can produce
sound in simulated 3D. This feature is controlled using the
card's configuration window. To access these settings:

     1.Open the "OS/2 System" folder on the OS/2 desktop. Double-
        click the "System Setup" icon.
     2.From its window, run "Selective Install" to display the
        "System Configuration" window.
     3.In the "System Configuration" window, the "Multimedia
        Device Support" drop-down list should show the "Analog
        Devices AD1816 Soundport" as the active device. Click the
        square button next to the device name.
     4.Click the "Device Settings" button to display the card's
        hardware settings.The "Analog Devices AD1816" window
        appears. This window contains controls to turn 3D effects
        on or off, and change the acoustic properties of the 3D
        simulation algorithm.
     5.After you have changed the settings, click the "OK"
        button. The changed settings take effect immediately, and
        are written to your CONFIG.SYS file to be used when you
        start OS/2.

VII. TROUBLESHOOTING
--------------------------------------------------------------------------------------------------------------------------     A majority of problems observed with the AD1816 Soundport
device drivers for OS/2 Warp 3 are caused by inconsistent
versions of the following system files: CLOCK01.SYS,
CLOCK02.SYS, TIMER0.SYS, and OPL3.SYS. Before continuing,
make sure that your versions of these system files match the
AD1816 Soundport device driver install diskette files:
     
        \OS2\BOOT\CLOCK01.SYS
        \OS2\BOOT\CLOCK02.SYS
        \MMOS2\TIMER0.SYS
        \MMOS2\OPL3.SYS
     
This is done by visually comparing the file time, date, 
and size for each one of the files listed above against the
same filename on the driver install diskette.

If your files do not match the versions on the diskette,
then either copy the diskette files over the files on your
system, or use the UPDTCLK.CMD or UPDTCLK.BAT command files
to update your system files.

Note that this command file saves a copy of CLOCK01.SYS and
CLOCK02.SYS to CLOCK01.WRP and CLOCK02.WRP respectively. Do
not overwrite or delete these files as these files can be
used to restore your original configuration, if required.
Use the RSTRCLK.BAT command file to restore your original
CLOCK01.SYS and CLOCK02.SYS drivers in the \OS2\BOOT
directory.

VIII. PROBLEMS OBSERVED AND POSSIBLE SOLUTIONS
--------------------------------------------------------------------------------------------------------------------------  A. Exception in device driver: CLOCK$
    TRAP 00d
     
    This problem is due to mismatched or inconsistent 
     revision levels of CLOCK01.SYS, CLOCK02.SYS,
     and TIMER0.SYS drivers installed on your system. Make sure
     that the CLOCK01.SYS, CLOCK02.SYS and TIMER0.SYS drivers
     from the AD1816DD.SYS driver install diskette are copied
     into the proper subdirectories of the system.
     Make sure that the CLOCK01.SYS and CLOCK02.SYS has its read-only
     attributes reset. Use ATTRIB CLOCK0?.SYS to view the
     attributes, and ATTRIB -r to reset the read-only attributes,
     if required. To install the files: 

        1.Copy CLOCK01.SYS to \OS2\BOOT
        2.Copy CLOCK02.SYS to \OS2\BOOT
        3.Copy TIMER0.SYS to \MMOS2

    Or, use the UPDTCLK.BAT command file to update these
    drivers.
     
B. MINSTALL Display "MMPM/2 Copy Failed File in Use" while doing
     install
     
     This problem is due to some CLOCK01.SYS and CLOCK02.SYS
     files having the read-only attribute set. Use OS/2's
     ATTRIB.EXE utility to reset the read-only attribute for
     these files. Note that on some versions of Warp, an
     option is presented to retry the operation, and when a retry
     is attempted, the copy appears to have succeeded, and in
     fact fails. This problem may manifest itself as a trap when
     trying to play a MIDI file (see TRAP in CLOCK$ driver when
     opening MIDI player). If you see this problem, be sure to check
     the files CLOCK01.SYS and CLOCK02.SYS in the \OS2\BOOT 
     subdirectories to make sure that these were properly copied
     from the install diskette.
     
C. When performing a shutdown while the MIDI player is still
    open, the system hangs.
     
     This problem is due to mismatched CLOCK01.SYS, CLOCK02.SYS,
     and TIMER0.SYS drivers. Use the procedure described above to
     correct this problem.
     
  
D. When playing a MIDI file, switch to Audio Player, then back
    to MIDI player. No audio is heard, and an error occurs when 
    start, pause, or stop.

     This problem is due to an inconsistent version of OPL3 with
     the version of WARP 3 and the TIMER0.SYS set of
     drivers. Use the procedure described above to correct this
     problem.

VIII. KNOWN PROBLEMS IN THIS RELEASE
--------------------------------------------------------------------------------------------------------------------------     There are four known problems that will be corrected in sub-sequent releases. 
Where required, we are working with IBM to resolve these problems as quickly 
and efficiently as possible. Three of the problems relate to a conflict between 
multimedia applications and the use of system sounds. These problems can 
be solved by turning off system sounds.
  
  Problem 1
     The Digital Audio applet gives an error message after you:

     1.Click Record.
     2.Click Stop.
     3.Click New.
     4.Click Discard.

     The error message may say that either the device is busy or
     that there was a device error.
     This is a problem wih the way Digital Audio interacts with
     the device driver while Warp trys to play system sounds. To
     avoid this problem, turn off system sounds. Alternatively,
     close Digital Audio and restart it to continue, or save the
     recorded audio to a file.
  
  Problem 2
     The MIDI Player Applet displays an error after you take the
     following steps:

     1.Start playing a MIDI file using the MIDI Player applet.
     2.Bring up another multimedia application, such as Master
       Volume or Digital Audio.
     3.Click on the MIDI Player applet.
     4.Close the other application.
     5.Click the MIDI Player applet Start button.

     This is a problem wih the way MIDI Player interacts with the
     device driver while Warp trys to play system sounds. To
     avoid this problem, turn off system sounds.
  
  Problem 3
     When playing a MIDI file, switching to master volume
     control, then back to MIDI play causes the MIDI audio to
     appear to be muted.
     This is a problem with the way Warp plays systems sounds.
     Turn off system sounds to avoid this problem.
  
  Problem 4
     The AD1815/AD1816 audio cards are plug-and-play cards. Since
     OS/2 Warp 3 does not support plug-and-play, the Warp 3
     driver for these cards needs to set the resources according
     to what resources the user knows is not being used. In a few
     cases, the system BIOS does not support plug-and-play BIOS
     enumeration in cooperation with a non plug-and-play enabled
     operating system, such as Warp 3. This is complicated by the
     fact that since the AD1815/AD1816 devices are not critical
     to system operation (such as a hard disk controller, or
     graphics controller) the card is not enabled by the BIOS. In
     some cases, the system plug-and-play BIOS does not properly
     setup system resources to coexist with the AD1815/AD1816
     device. If the system appears to behave strangely, that is,
     audio files play continuously, or the system appears to
     freeze, or a sound file snippet plays continuously, or other
     devices behave unexpectedly, some ROM setup modifications
     may be necessary. Most plug-and-play enabled systems have a
     ROM-based setup menu which allows different plug-and-play
     options. It may be necessary to try different plug-and-play
     settings within these ROM-based BIOS settings to allow
     proper operation of the AD1815/AD1816 device in certain
     systems.

     For example, a Gateway-2000 P5-133 system required setting
     the "Plug-and-Play Configuration" mode to "Use ICU or PnP
     OS" with an Operating System setting of "Other OS" in order
     for the AD1815 card to work properly. The AD1816 does not
     require this option. Other systems may require other
     settings in order for these cards to work properly.

IX. DRIVER REFERENCE -- FOR ADVANCED USERS ONLY
--------------------------------------------------------------------------------------------------------------------------     WARNING: The following information allows advanced users to
     adjust driver parameters. Improper use of the parameters can
     damage your system. DO NOT attempt to adjust parameters if
     you are not knowledgeable in OS/2 driver and system
     configuration issues.
     
  
 A. AD1816DD - AD1816 Soundport controller device driver
     This device driver initializes the AD1816 for WAV, MIDI,
     and Joystick operation, as specified by the device driver 
     command line parameters. Plug-and-play resources specified 
     by the operating system will be used if available, otherwise 
     the driver will initialize the AD1816 through the plug-and-play 
     hardware interface. See the "Plug and Play ISA Specification," 
     version 1.0a for more details. This driver also supports the 
     WAV file format for playback and record.
     
     This driver takes the following parameters for resources
     in the event that OS/2 PnP is not installed or available. 
     PnP for OS/2 will be available with the release of OS/2 
     Warp Version 4.
     
        DEVICE=c:\mmos2\ad1816dd.sys <parameter list>

        Where <parameter list> is :
 
        Option      - Description (Default value)
        ====================================================
        /S:xxxx     - Soundblaster IO port in hex (240)
        /C:xxxx     - CODEC Base Address in hex (FFE0)
        /F:xxx      - FM Synth base address in hex (388)
        /I:y        - Interrupt level in decimal (5)
        /N:$strng$  - Device driver name assigned by MINSTALL
        /P:y        - Playback DMA channel in decimal (1)
        /R:y        - Record DMA Channel in decimal (3)
        /M:xxx      - MPU-401 Base address (330)
        /J:xxx      - Joystick base address (200)
        /T:y        - MPU-401 interrupt level (15)
        /3:y        - 3D Phase expansion (0-31)
     
     
  
  B. OPL3, or FM Synthesis device driver
     This driver provides the support required for FM synthesis
     through OPL3   emulation. The AD1816DD driver initializes
     the OPL3, and allows the OPL3 driver to control FM
     synthesis.
     
        DEVICE=c:\mmos2\opl3.sys /P:xxx /N:OPL31$
     
        /P:xxx      - Base address of OPL3
        /N:$strng$  - Device driver name assigned by MINSTALL
     
  
  C. GAMEDD, or Joystick support
     This driver provides OS/2 Joystick support.
     
        DEVICE=c:\mmos2\gamevdd.sys
        DEVICE=c:\mmos2\gamedd.sys
     
     These device drivers take no parameters.
  
  D. MPU-401 Device Interface
     This driver provides the MPU-401 device support required for
     external MIDI devices.
     
       DEVICE=c:\mmos2\mpu401.sys <parameter list>
     
       /Pn:yyy   - Base I/O: Sets the base I/O address for port n, usually 300 
                        or 330 (# is in hex)

       /In:yyy    - IRQ level: Sets the IRQ level for port n.  yyy is a decimal 
                       number from 1 to 15.  If the base I/O address for a given 
                       port is specified (e.g. /P1:300), but the IRQ is _not_ 
                       specified, the driver will attempt to autodetect the IRQ.  
                       Note that an IRQ is not used for MMPM/2 playback anyway.
   
       /L           - Long name support.  If specified, /L directs the driver to
                       include the base I/O address and the IRQ in the instance name
                       for RTMIDI Type A registration.  For example, without /L the
                       instance name might be "MPU-401 #1".  With /L, it would look
                       like "MPU-401 #1 (I/O=0330, IRQ=05)"
   
        /N:sss    - Driver name, an 8-character length string, ending in a $. Do
                       not specify a port number.  Default is "MPU401$".
   
        /Q          - Tells the driver to ignore errors when initializating the
                        hardware for playback.  May be necessary for some cards.
   
       /R:yyy      - Resolution of MMPM/2 timing.  If the highres timer 
                        (TIMER0.SYS) is installed, this parameter tells the MPU-401 
                        driver what resolution to use (where yyy is the number of 
                        milliseconds) when playing MMPM/2 MIDI streams.  Default is 
                        one millisecond.  Default is 2.
   
       /V           - Verbose output during boot.  If used, this should be the 
                        irst parameter.
     
    
