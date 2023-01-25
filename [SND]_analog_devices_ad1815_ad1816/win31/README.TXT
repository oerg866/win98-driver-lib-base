[Start of README.TXT]
*************************************************************************
*******************************************************************************************
************************************************************************************************************
C o n t e n t s

1.  Overview
2.  Release Notes
3.  System Requirements
4.  Driver Installation
5.  Driver De-Installation
6.  Willow Pond MediaRack Installation
7.  Resource Configuration Under MS-Win3.1x
8.  Resource Configuration Under DOS
9. Volume Control Under DOS
10. Playing DOS Games
11. Manufacturer Notes
---------------------------------------------------------------------------------------
1.  O v e r v i e w

This README.TXT contains instructions to install and configure the MS-Win3.1x driver
and MediaRack application for the AD1815 and the AD1816 SoundPort Controller. This
release is designed to run with the AD1816JST3, AD1816JST4 and AD1816JST5 SoundPort
Controller. Earlier revisions of the AD1816 SoundPort controller are not supported by
this release.
---------------------------------------------------------------------------------------
2.  R e l e a s e   N o t e s

This release of the MS-Win3.1x driver supports the following features on the AD1815 and the AD1816:

1. MPC Level 3 Mixer
2. Digital Mixer
3. WSS Codec
4. Included Files
5. SBPro Codec
6. Game Port
7. MIDI Port
8. I2S0 & I2S1
9. 3D Sound Control (AD1816 only)
10. External two-pin control (XCTL[0:1])

The following features are NOT supported by this release:

1. Extra Logical Device (AD1816 only)
2. DSP Serial Port
3. Power Management
---------------------------------------------------------------------------------------
3.  S y s t e m   R e q u i r e m e n t s

  - 80486 PC-AT compatible or faster machine.
  - 4 MB DRAM or greater.
  - 1 free 16-bit ISA-bus expansion slot.
  - 400 KB free hard disk space for minimum software installation.
  - Microsoft Windows 3.1x
  - DOS 6.2 or higher
---------------------------------------------------------------------------------------
4.  I n c l u d e d    F i l e s

AD1815   EXE        21,824 11-06-96  10:36p
ADICORAL 386        16,607 09-05-96   9:20a
ADICORAL DRV        63,456 10-08-96   2:42p
DEVICE   INI           412 11-04-96   5:33p
DOSCFG   EXE        53,460 11-06-96   5:41a
DOSMIXER CFG            92 11-08-96   9:47a
DOSMIXER EXE        48,546 11-06-96   6:07a
HWSETUP  EXE        42,800 11-06-96   5:47a
MIDIMAP  CFG        22,022 11-08-96   9:50a
MPU401   DRV         7,088 12-31-93   3:11a
MSCOMSTF DLL        74,528 02-11-93   7:32p
MSCUISTF DLL        48,188 10-14-96   6:10a
MSDETSTF DLL        24,544 02-11-93   7:32p
MSINSSTF DLL        65,440 02-11-93   7:32p
MSMIXMGR DLL        12,688 01-05-96  12:00a
MSSHLSTF DLL        14,928 02-11-93   7:32p
MSUILSTF DLL         6,144 02-11-93   7:32p
SETUP    EXE        56,080 11-07-96  11:59p
SETUP    INF         1,437 11-08-96   1:31p
DOSSETUP BAT            35 10-16-96  12:12p
WPUNIMIX INI           805 10-15-96   4:42p
README   TXT        12,666 11-08-96   1:30p
UNINSTAL EXE        25,632 11-06-96   4:42a
       23 file(s)   619,652     
---------------------------------------------------------------------------------------
5.  D r i v e r   I n s t a l l a t i o n

MS-Win3.1x:

1. Turn on the PC and start MS-Win3.1x. Remove all previously installed sound card 
   drivers. Make sure that all references to these drivers are removed from the 
   AUTOEXEC.BAT, CONFIG.SYS and SYSTEM.INI files.

2. Switch off the PC and remove all other sound cards.

3. Insert the AD1815/AD1816 sound card firmly in an available ISA bus expansion slot and
   close the computer. Connect a speaker pair to the Line_Out or Speaker connector on the
   sound card's face plate.

4. Turn on the PC, and start MS-Win3.1x. In the PROGRAM MANAGER, select 
   File|Run. Insert the driver installation diskette in the A: drive, and type 
   A:\WIN31\SETUP.EXE. Click on OK, and follow the instructions.

Once the PC has rebooted, start MS-Win3.1x and install the Willow Pond MediaRack according to the instructions below.

DOS:

If you are running DOS only, and do not have MS-Win3.1x installed on your computer, follow
the steps below.

1. Turn on the PC and remove all references to previously installed sound cards from the 
   AUTOEXEC.BAT and the CONFIG.SYS files.

2. Turn off the PC, open it and remove all previously installed sound cards. Firmly insert the
   AD1815 or the AD1816 sound card in an empty ISA slot, and close the PC again.

3. Turn on the PC, insert the installation diskette in floppy drive A: and type the following at
   the DOS prompt:

	A:\WIN31\DOSSETUP.BAT
   Hit return.

4. Follow the instructions on the screen. 
---------------------------------------------------------------------------------------
6.  D r i v e r    D e - I n s t a l l a t i o n

1. With this release comes a driver de-installation option. Start MS-Win3.1x. In the 
   Program Manager, select FILE|RUN. In the dialog box, type:
   
	A:\WIN31\uninstall.exe or click UNINSTALL ICON.

3. In the main SETUP panel, select:

	DRIVER UNINSTALLATION

   The driver will be removed  as well as all references in the AUTOEXEC.BAT and the
   CONFIG.SYS files.
---------------------------------------------------------------------------------------
7.  Wi l l o w   P o n d   M e d i a R a c k   I n s t a l l a t i o n

1. Start MS-Win3.1x, if it is not already running. In Program Manager,
   select File|Run.

2. Insert the installation diskette in floppy drive A:. Type the following 
   in the dialog box:

	A:\MRACK\SETUP.EXE

   and click on OK.
   
   The Willow Pond MediaRack will be installed next. Follow the instructions on the
   screen.

Note: Refer to the AD1815/AD1816 Red/Yellow Coral user's manual for detailed instructions
on the operation and customization of the MediaRack.
---------------------------------------------------------------------------------------
7. R e s o u r c e    Co n f i g u r a t i o n    U n d e r    M S - W i n 3 . 1 x

The SETUP.EXE utility installs also a resource configuration utility under MS-Win3.1x for reconfiguration of the I/O base addresses, IRQs and DMAs of the various devices on the AD1815/AD1816. This RESOURCE CONFIGURATION utility is installed with a program group called AD1815/AD1816 SOUNDPORT. You can use this utility to setup the 
resources for the:

1. Windows Sound System Codec
2. SoundBlaster codec
3. MPU-401 driver
4. Gameport/Joystick driver
5. OPL3 (FM) synthesizer
7. IDE CD-ROM controller (only functional on the AD1816A SoundPort Controller)

These resources, except for the IDE CD-ROM controller, can also be setup through the Willow Pond driver SETUP utility from the CONTROL PANEL|DRIVER configuration panel. The Willow Pond driver SETUP utility allows in addition the configuration of:

1. 3D sound 
2. I2S input formats
--------------------------------------------------------------------------------------
8. R e s o u r c e   C o n f i g u r a t i o n   U n d e r   D O S

Included with this release is a simple, but functional DOS resource configuration manager, called DOSCFG.EXE, for the sound codec, the gameport/joystick, the FM synthesizer, the midi port and the IDE controller. DOSCFG.EXE is installed by SETUP.EXE in the directory C:\ADISOUND (the default installation directory if you did not change it at installation).
DOSCFG.EXE is the equivalent of the MS-Win3.1x RESOURCE CONFIGURATION utility. DOSCFG.EXE gives the user the ability to setup the AD1816 entirely from the DOS command line.
---------------------------------------------------------------------------------------
9. V o l u m e    C o n t r o l   U n d e r   D O S

Included with this release is a simple, but functional DOS mixer, called MIXER.BAT. During installation of the device driver, the SETUP.EXE program copies MIXER.BAT into the directory C:\ADISOUND (the default installation directory if you did not change it at installation). 

The mixer is used to control playback volumes for application with DOS games. You should use MIXER.BAT to set the playback volume to a desired level before starting a DOS game. The following volume controls are provided:

1. Master volume control
2. LineOut volume control
3. FM (OPL3) volume control
4. CD-Audio (Aux1) volume control
5. Wavetable (Aux2) volume control
6. Line-in volume control
7. Mic-In volume control

1. At the DOS command line, type:

	C:\ADISOUND\MIXER.BAT

2. Follow the menu options to set desired volume levels.
---------------------------------------------------------------------------------------
10. P l a y i n g   D O S   g a m e s

Important:

Playing DOS games in an MS-Win3.1x DOS box can sometimes be problematic. To get around this, follow the instructions below:

1. Exit from MS-Win3.1x

3. Invoke MIXER.BAT to set volume levels appropriately

4. Run the DOS game.

Note: In case you encounter problems setting the music card in a DOS game to GENERAL MIDI, try turning on the Aux2 channel (Wavetable channel) via the Willow Pond MediaRack under MS-Win3.1x. Exit from MS-Win3.1 and run the game in DOS.
---------------------------------------------------------------------------------------
11. M a n u f a c t u r e r    N o t e s

Driver:

Manufacturers of AD1816 SoundPort Controller audio cards should take special notice of the contents of the file DEVICE.INI, which is included with the MS-Win3.1x driver installation diskette. An explanation of the contents of this file is listed below, together with the contents of this file.

[PNP_DEVICE_ID] ; Vendor specific PnP section
PNPID=ADS7180   ; Default ID. Must be changed by a vendor to its own  
			  PnP_Vendor_ID, corresponding with the PnP_Vendor_ID in the
			  E2PROM resource file
PNPSN=FFFFFFFF  ; Default PnP_Vendor_Serial_No. Must be changed by a vendor to
			  its own PnP_Vendor_Serial_No.

[DEFAULT_IO_CONFIG] ; Default settings, copied to SYSTEM.INI during driver installation
WssIO=530                ; Windows Sound System I/O base address
WssIrq=5                 ; Windows Sound System IRQ
WssDmaPlay=1     ; Windows Sound System playback DMA
WssDmaCapture=3  ; Windows Sound System capture DMA
SbIO=220                 ; SoundBlaster I/O base address
OplIO=388                ; OPL3 I/O base address
GameIO=201               ; Gameport/joystick I/O base address
MpuIO=330                ; MPU-401 I/O base address
MpuIrq=9                 ; MPU-401 IRQ
IdeIO=0          ; IDE I/O base address (0 = Disabled, default)

[OPTIONS]
WssIOList=500,510,520,530,540,550,560  ; Windows Sound System I/O base address 
					     choices
WssIrqList=5,7,9,a,b                      ; Windows Sound System IRQ choices
WssDmaList=0,1,3                          ; Windows Sound System DMA choices
SbIOList=220,240,260,280,2A0              ; SoundBlaster I/O base address choices
OplIOList=388                             ; OPL3 I/O base address choices
GameIOList=201                    ; Gameport/joystick I/O base address choices
MpuIOList=0,300,320,330,332,334,336      ; MPU-401 I/O base address choices
MpuIrqList=0,5,7,9                        ; MPU-401 IRQ choices
IdeIOList=0,168,170,1E8           ; IDE 1st I/O base address choices (0=Disabled)
IdeIOList1=0,36e,376,3ef                  ; IDE 2nd I/O base address choices (0=Disabled)
IdeIrqList=0,a,f,b                        ; IDE IRQ choices (0=Disabled)

[CUSTOMIZATION]
Customization of the default for ADICORAL.DRV in system.ini can be included in this section. 
For examples 
		MicMute=No
will turn on the Mic-In chanel on entering windows.

Note: For the IDE controller the IRQ and the 1st & 2nd I/O base addresses are paired. That is, the following triplets are the only possibilities:

1. 10, 168, 36E
2. 15, 170, 376
3. 11, 1E8, 3EF

The 2nd I/O base address may be disabled. Some CD-ROM drives like Sony's and Philips' can operate with a single chip select.

***********************************************************************************************************
[End of README.TXT]
