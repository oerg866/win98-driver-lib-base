[Start of README.TXT]                                                                 J                               README.TXT
**************************************************************************

		 Analog Devices, Inc., Sound Processing Team

		              AD1812 SoundPort Controller 
			Windows 95 PnP Driver Package

		                Release V1.1, 5 June 1996

**************************************************************************
			Technical support contacts
			Tel:  (65)375-8200
			Fax: (65)275-2225
			Email: yonglin.li@analog.com

**************************************************************************

--------------------------------------------------------------------------
Release notes

This version of the AD1812 Win95 drivers improves over the V1.0 drivers by
adding support or the XCTL0 and the XCTL1 pins. Developers can now write 
applications that directly control spatializers, such as QSound's, through
these pins.

This version also provides even calibration across all gain controls, and
lets the volume increase logarithmically over the entire scale of the 
volume sliders, resulting in a more evenly adjustable volume.
---------------------------------------------------------------------------
First-time driver installation

This section is for users who have not installed an AD1812 evaluation 
board in their system before. If this applies to you, please follow this 
procedure.

1.  Confirm that the AD1812 evaluation board is jumper-configured to 
    operate in PnP mode by inspecting the JP10 jumper. The left and center
    pins should be shorted by the jumper to select PnP mode.
2.  Insert the board into a free ISA-bus expansion slot in your computer.
3.  Power up the computer and start Win95. Win95 will notify you that it 
    has detected new hardware and will try to configure resources for it.
4.  When prompted by the Win95 Device Manager, insert the driver 
    installation disk in your floppy drive and click "Ok". If the Device 
    Manager complains that it can't locate any of the required files, make
    sure that it is looking for them on your floppy drive! If you get such
    error, simply type in the path to your floppy drive and click "Ok".
5.  Device Manager will install drivers for the first three of the five 
    AD1812 logical devices and then request a system restart. This is 
    normal and required. Click "Yes" to restart Windows.
6.  After the restart, Device Manager will go to work again and install
    drivers for the remaining two AD1812 devices.
    NOTE: The 5th and last logical device is the Modem logical device. 
    If the AD1812 has been configured on your board to support PnP for 
    an external modem chipset, his device configures as a standard COM 
    port by Win95.
7.  You're done.

---------------------------------------------------------------------------------------
Disabling the AD1812 logical devices

After installation is completed, you may want to disable AD1812 devices
which you do not intend to use in order to free up their resources for 
other devices.

To disable a particular AD1812 device, perform the following steps:

1.  Open the Windows 95 Control Panel.
2.  Open the "System" applet.
3.  Click on the "Device Manager" tab.
4.  Scroll down to the "Sound, video, and game controllers" device class.
5.  Double-click the device class to show all devices in this class.
6.  Double-click the device you want to disable to bring up its Property 
    Page.
7.  In the "Device Usage" pane of the "General" tab of the device's Property
    Page, uncheck all configurations listed.
8.  Click "Ok".

Note that disabling a device by this procedure is not the same as
"Removing" the device using the "Remove" button of the "Device Manager".
"Removing" a device unloads its drivers, and then breaks the association
between the device's PnP hardware ID key and the drivers in the System
Registry. Subsequently, restarting Win95 will cause the Configuration
Manager to re-establish the association in the System Registry based on
information retained from the first installation. This is why we "Disable"
instead of "Removing".

---------------------------------------------------------------------------------------
Mixer32.exe application

Essentially, all of the AD1812's line and mixing features can be 
controlled using Microsoft's Mixer application (speaker icon in the System 
Tray). We have also included our own mixer application which has some 
features you may find useful. For example, our mixer allows you to 
customize the displayed labels for each of the input and record sources.
Simply copy MIXER32.EXE to your desktop and it will be ready to use.

	GAIN CONTROL SLIDERS:

	* HOME = set gain to zero
	* END = set gain to full scale
	* PAGEUP/PAGEDOWN = course gain adjust
	* UPARROW/DOWNARROW = fine gain adjust
	* TAB = select next control
	* ENTER (or double click) = open/close Enhanced View (Master 
          Playback & Record Gain control sliders only)
	* MOUSE CLICK = set gain to current mouse position setting 
          instantly
	* MOUSE DRAG = drag gain setting to current mouse position

	BALANCE CONTROLS:

	* HOME = set balance 100% to the right channel
	* END = set balance 100% to the left channel
	* INSERT = center the balance
	* PAGEUP/PAGEDOWN = course balance adjust right/left
	* RIGHTARROW/LEFTARROW = fine balance control right/left
	* MOUSE CLICK = set balance to current mouse position instantly
	* MOUSE DRAG = drag balance to current mouse position

	MUTE CONTROLS:

	* SPACEBAR = toggle mute on/off
	* MOUSE CLICK = toggle mute on/off

**************************************************************************
[End of README.TXT]
