             Avance Logic ALS100+ Sound System Software  ver:ALS11.A1.80
                        Installation and Setup



DOS and Windows 3.1 Installation for ALS100+:
====================================================

[SETUP.EXE for Windows 3.1]

The SETUP.EXE is a Windows 3.1 setup program that installs DOS and Windows
3.1 drivers and utilities.

The user can run SETUP.EXE by selecting File|Run... and typing "A:SETUP" on
the command line under Windows 3.1 Program Manager, or by typing "A:SETUP" at
DOS prompt if Windows directory is in the PATH. The SETUP.EXE copies all the
DOS drivers and utilities to the directory that user specifies during the
setup program.  All the Windows 3.1 drivers and VxDs are copied to the 
Windows system directory.  When the user installs the Avance Sound System
for the first time the A3CONFIG.EXE is started to configure the board setting
after the Setup program is finished.

[DOSINST.EXE for DOS Only installation]

The DOSINST.EXE is a DOS installation program that copies all the DOS drivers
and utilities to the directory that user specifies.  When the user installs
the Avance Sound System for the first time the A3CONFIG.EXE is started to
configure the board setting after the Setup program is finished.  DOSINST.EXE
can be installed by typing A:DOSINST.EXE at the DOS prompt.


Windows 95 installation procedure for ALS100+:
=====================================================

1. After user installs the ALS100+ sound card into the ISA slot in the
   computer and powers on the system, Windows 95 will prompt user with a "New
   Hardware Found" dialog box since the ALS100+ sound card is ISA plug
   and play. To install the Windows 95 drivers, select "Driver from disk
   provided by hardware manufacturer" and click on OK.

2. Insert the "ALS100+ DOS/Win3.1/Win 95 Drivers and Utilities" diskette
   into the appropriate drive and select that drive from the prompted dialog
   box and click on OK. Windows 95 will copy all the needed files and set up
   all the logic devices on the board automatically.

3. Install the ALSRACK player by running the SETUP.EXE file (also provided
   on the "ALS100+ DOS/Win3.1/Win 95 Drivers and Utilities" disk) from
   the Windows 95 Start menu|Run.  This will create the Avance Sound Program
   Group with the ALSRACK utility icon.  
   (See Appendix below for full descr of ALSRACK functions).


Troubleshooting:
================

This appendix provides some tips and information for some of the 
problems you might encounter with your ALS100+ sound card either during
installation or normal use.

[Problems in DOS]

Problem:        Cannot load IDE CD-ROM drive.
Cause:          IDE port is not enabled. Check the config.sys file under 
                C: root directory and you should see "device=c:\a3sound
                \cdsetup.sys /P:xxx" before loading your CD-ROM driver.( xxx
                is the base port of the sound card ). The cdsetup.sys 
                enables the IDE port.
Solution:       Run C:\A3SOUND\A3CONFIG.EXE again and select the CD-ROM
                IDE. When you leave the a3config program, device=c:\a3sound
                \cdsetup.sys /P:xxx will be added to config.sys. Make sure 
                that this line is added before loading the CD-ROM driver.

Problem:        No sound in a DOS application
Cause:          There could be conflicts in the SB16 settings.
Solution:       Rerun the C:\A3SOUND\A3CONFIG.EXE and try another Port,
                DMA, or IRQ.

[Problems in Windows 3.1]

Problem:        There is no "Sound..." or "MIDI Sequencer..." item 
                under the menu "Device" in the Media Player. 
Cause:          Mixer driver is not loaded.
Solution:       Open the SYSTEM.INI file with any file editor. You 
                should see the following: 
                [drivers]
                Wave=a3sndsys.drv
                Aux=a3sndsys.drv
                Mixer=a3sndsys.drv
                Midi=a3opl.drv
                Midi1=a3mpu401.drv

                [386Enh]
                device=a3sndsys.386

                [boot]
                drivers=mmsystem.dll msmixmgr.dll

[Problems with ALS100+ Full Duplex]

Problem:        Can not play and record at same time
Cause:          1. The sound card is not ALS100+ sound card
                2. In ALS3.INI, full duplex function was disable
                3. Only one DMA channel was allocated
                4. The sample rate of playback are not the same as 
                   that of recording.
Solution:       For 1.  Please contact Avance Logic, Inc. at telephone: 
                        (510) 226-9555 or see us on the World Wide Web 
                        at www.avance.com, for a list of Cards using 
                        Avance Logic products!
                For 2.  In ALS3.ini, make sure the following setting is enabled:
                        [Option]
                        FullDuplexFunction = 1  ---- to enable full duplex
                For 3.  To enable full duplex function in ALS100+
                        two DMA channel must be allocated.
                        
                        In Windows 3.1, run A3CONFIG.EXE to select two DMA
                        channels, from 0,1,3(By default, we provide 2 channels).

                        In Windows 95, system should automatically 
                        provide two DMA channels for ALS100+ sound card.
                        If it did not, either all of 8-bit DMA channels have
                        been allocated to other devices.
                        The user must remove the other devices and try again.
                for 4.  For full duplex, the sample rate for playback and 
                        recording must be same.

Problem:        Third party mixer application with Sound Blaster compatibility
                will not run with Avance Sound System.
Cause:          Avance Sound System is Microsoft Sound System compatible. Avance
                Logic, Inc. does not support previous Sound Blaster Mixer Interface.
Solution:       Use ALSRACK.EXE application that is shipped with this disk.


Problem:        CD audio will not play after the ALS drivers are installed.
Cause:          The user did not install the [MCI]CD-AUDIO driver.
Solution:       Manually add [MCI]CD-AUDIO driver via Control Panel.

        
Appendix - Driver Reference:
============================

[Windows drivers]
ALS100+ has three sets of driver and one set VxD for Windows 95 and
Windows3.1. They are listed below:

                Sound System Driver     OPL3 Driver     MPU401 Driver
Win95 Drivers   A3sndsys.drv            A3opl.drv       A3mpu401.drv
Win95 VxDs      A3sndsys.vxd            A3sndsys.vxd    A3sndsys.vxd
Win3.1 Drivers  A3sndsys.drv            A3opl.drv       A3mpu401.drv
Win3.1 VxDs     A3sndsys.386            A3sndsys.386    A3sndsys.386

The Avance Sound System, OPL3, and MPU401 drivers are binary
compatible with Windows 95 and Windows 3.1 but the VxDs have different 
binaries for Windows 95 and Windows 3.1. The Windows 3.1 VxD have their 
externsion .386 and the Windows 95 VxD have their externsion .vxd.

The Windows 95 joystick drivers are the MSJSTICK.DRV and VJOYD.VXD 
that are Microsoft drivers shipped with Windows 95. Besides these 
five Windows 95 drivers and VxDs, a ALS100P.INF is needed for
Windows 95 installation.

For Windows 3.1, drivers and VxDs have to be specified in the SYSTEM.INI 
file and be loaded when the Windows 3.1 starts. The entries listed in below 
should be added to SYSTEM.INI file by the setup program.

        [386Enh]                        [drivers]
        device = a3sndsys.386           wave  = a3sndsys.drv
                                        mixer = a3sndsys.drv
                                        aux   = a3sndsys.drv
                                        midi  = a3opl.drv
                                        midi1 = a3mpu401.drv

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!                                                                             !
! IMPORTANT NOTES:                                                            !
!       Either you setup under windows 95 or windows 3.1, you MUST insure     !
! that the drivers or VxDs files of old sound card have been removed from your!
! windows's system directory. Otherwise, even if you setup properly, the new  !
! sound card maybe still not work.                                            !
!                                                                             !
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


[DOS drivers]
The DOS drivers include CDSETUP.SYS, A3INIT.EXE, and A3CONFIG.EXE.

CDSETUP.SYS
-----------
The CDSETUP.SYS initializes the CD-ROM IDE port before the CD-ROM driver is 
loaded if the user has a CD-ROM drive attached to the IDE port on the Avance 
sound board.  The Cdsetup.sys is specified in the Config.sys file as below.
                device = C:\A3sound\cdsetup.sys /P:220
                device = C:\Sony\Atapi_cd.sys /D:SNIDE01
The CDSETUP.SYS is not a TSR program. There is no harm in running this 
program if there is no CD-ROM drive attached to the IDE port on the Avance
sound board.

A3INIT.EXE
-----------
The A3INIT.EXE initializes the Avance sound chip ALS100+. It is
specified in the AUTOEXEC.BAT file followed by a path name as below.
                C:\a3sound\a3init.exe C:\Win31
A3INIT.EXE and A3CONFIG.EXE use the path that follows the A3INIT.EXE
in the AUTOEXEC.BAT to find the initial data file ALS3.INI. The ALS3.INI file
will be copied to the Windows directory or the same directory as A3INIT.EXE
for DOS-only installation. The Windows sound system driver ALSNDSYS.DRV and 
the Windows sound rack application ALSRACK.EXE also share ALS3.INI file for
initial values. 

If the user wishes to enable or disable sound during initialization, the
following line should be changed using the option value in the ALS3.INI file:

                [Option]
                PlaySoundAtInitial=No/Yes


A3CONFIG.EXE
------------
The A3CONFIG.EXE is a DOS program to help users change the IO, IRQ,
and DMA resource for the Avance sound system on board devices and to 
test the new settings through playing the STEST8.WAV, STEST16.WAV, 
and FMTEST.MID test files. The new settings are saved in the ALS3.INI
file which will be used when A3INIT.EXE initializes the board.

Information Files:
------------------
ALS100P.INF is a installation information file for Avance Logic ALS100+
sound chip under Windows 95. This file tell Windows 95 where the drivers should
be copied during installation.
See the instructions above for ALS100+ Windows 95 installation.

ALSRACK for ALS100+
--------------------------
1.   Structure and components:
     The ALSRACK consists of a MIXER control panel, MIDI panel, WAVE panel, 
     and CD panel.
1.1  To enable or disable a panel:
     Clicking the mouse button on the MIDI, WAVE, or CD in MIXER control panel 
     will cause the corresponding panel to disappear, another click will cause the
     corresponding panel to re-appear.
1.2  To change a channel:
     Click channel LEFT or RIGHT button to change to the channel you want.
1.3  To activate volume and balance control:
     Change to the channel you want (see 1.2), then click up or down arrow buttons 
     to change the volume, or click balance LEFT or RIGHT arrow buttons to change balance.
1.4  To mute system:
     Change to the channel you want, then click MUTE check mark to disable sound,
     click again to re-enable sound.


2.   MIDI panel
2.1  To open or close a MIDI file:
     Click the button of the MIDI sign on the MIDI panel, choose OPEN to open a
     MIDI file, or choose CLOSE to close a file.
2.2  Auto repeat and show information:
     Click the button of the MIDI sign on MIDI panel.  Clicking on AUTO REPEAT or
     SHOW INFORMATION will enable or disable the selection. When AUTO REPEAT is
     selected, the MIDI file will be played again when it reaches the end.
     When SHOW INFORMATION is selected, the MIDI window will open and the
     information from the MIDI file will appear on the MIDI window. When a MIDI
     file is opened, you can also click the MIDI window to show the information of 
     that file.
2.3  Other operations:
     When a MIDI file is opened, you can click PLAY to play it, or click PAUSE,
     STOP, FF or RW to manipulate the selection. You can also use the volume control
     buttons on the MIDI panel to control the volume directly.


3.   WAVE panel
3.1  Select TAPE I or TAPE II to playback:
     There are two TAPE boxes on the WAVE panel. TAPE I can only play wave
     files. TAPE II can play and record wave files. There is one set of
     control buttons on the right of WAVE panel. When Tape I is selected,
     the control buttons will take effect for TAPE I. When Tape II is selected,
     the control buttons will work for TAPE II. Click the button
     TAPEI/TAPEII to select between TAPEI or TAPEII, or push the button TAPEI
     PLAYBACK on TAPE I box to select TAPE I, while pushing the button TAPEII REC/PLAY
     on TAPE II box to select TAPEII. 

Note: When you want to playback a wave file, you need to select TAPE I/TAPE II first.

3.2  Open a wave file to play:
     Push the OPEN button, select OPEN on the menu, select a wave
     file to play. When the wave file is opened, the TAPE containing the
     file is automatically selected, just push the PLAY button to play it.
3.3  Record a wave file:
     Push the button REC.INPUT to select the input media (Line in, MIDI, 
     Audio CD, or MIC), then push the the button OPEN on TAPE II and select NEW 
     to create a new wave file.  The TAPEII indicator will be red to show it
     is waiting to record.  Play the source media, and push recording button on TAPEII 
     to begin recording. When finished recording, push the record button (now it is a
     red square) to stop.  After finished, save the file as the name you specified.     
3.4  Synchronous recording (record and play simultaneously):
     After selecting an INPUT media and new wave file for recording, push button 
     SYNC.REC to begin a synchronous recording. The mixer will automatically 
     play the source file and begin recording at the same time.


4.   CD
4.1  EDIT and Program:
     Push EDIT to select which tracks (selections on the CD) to play
     and add it to the Playlist. Then click the Program button to play the selected tracks.
4.2  Random play:
     The Random button plays tracks in a random order.
4.3  Repeat:
     To repeat one track of a CD, select the track and push the repeat button one time.
     A single repeat signal will appear in the CD player window.       
     To repeat the full CD, push the repeat button 2 times.
     A full repeat signal will appear in the CD player window.

