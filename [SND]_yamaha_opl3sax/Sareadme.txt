                      *********************
                             SETUPSA
                      *********************
------------------
1. What is SETUPSA
------------------
SETUPSA.EXE is an application which makes settings so that the OPL3-
SA can be used in a DOS or Windows 3.1 environment.
SETUPSA.EXE makes sound card settings when the PC is started up.
When the OPL3-SA3 is installed in the PC, this is also used when you
wish to change sound card settings after installation.
The setting data will be saved in OPl3SA.INI

-----------
2. Start-up
-----------
At the command line, input the following.

	SETUPSA [/S] (/S is optional)

If SETUPSA is started up without an option, a setting dialog box will
appear in the screen.
If the /S option is specified, SETUPSA will make the settings for
sound card I/O port, IRQ, DMA, and volume settings that were written
into the OPL3SA.INI file, will display these settings on the screen,
and will exit.
(In this case it will not be possible to change the settings.)

------------
3. Operation
------------
When SETUPSA is started up without an option, a setting dialog box
will appear on the screen. This will display the following.

< When using a keyboard >
[TAB] key       ---> Select the next item.
[SHIFT] + [TAB] ---> Select the previous item.

[<-], [->] keys ---> Modify the setting of the selected item.
                    (Sound Blaster IRQ and MPU401 IRQ are linked.)

[S] key         ---> Test the Sound Blaster mode Wave tone generator.
[W] key         ---> Test the WSS mode Wave tone generator.
[F]             ---> Test the FM tone generator.

[Enter] key     ---> Save the settings to the OPL3SA.INI and exit.
[ESC] key       ---> Exit without saving settings.

< When using a mouse >
Move the cursor to the item that you wish to set, and left-click to
set.
(Sound Blaster IRQ and MPU401 IRQ are linked.)
In the volume section, left-click to set the [UP] and [DOWN] keys.
Double-click the [OK] button to save the settings to OPL3SA.INI and
exit.
Double-click the [CANCEL] button to exit without saving the settings.

< About "3D Control" > 
The YMF715 (OPL3-SA3) contains Yamaha's proprietary "Ymersion" wide 
stereo technology which creates an emphasized sense of spatial spread 
when two speakers are used. In the MAIN window (setting dialog window), 
select [3D] located at the bottom and press the [Enter] key to access 
the "3D Control" window. (If you are using a mouse, double-click the 
[3D] button to access the "3D Control" window.) If you have selected 
the Manual preset, you can adjust the amounts of Ymersion, Bass, and 
Treble. If you have selected the Hall 1, Hall 2, Church or Disco preset, 
the amounts of Ymersion, Bass and Treble are preset, and the Ymersion, 
Bass and Treble setting values will not be displayed.

< About the tone generator tests >
The [S], [W] and [F] keys check whether sound is output correctly
from the monitor speakers or headphones connected to the sound card.
If you modify the settings, we recommend that you use these functions
to check that sound is being output correctly.
If you hear no sound and there is no error message, it is possible
that the volume has been turned down.
If you select the Sound Test item in the 3D window and press the 
[Enter] key, the YMF715 (OPL3-SA3) will perform the above test. 
At this time, if the test fails, a message will be output and you will 
return to the Main window (the setting dialog window).

< About the exit message >
When you use the [OK] button or the [Enter] key to exit, a message of
"Next time, do you want to open this 'setup window' in boot sequence? 
[Y/N]" may appear.
If you wish to display a setting dialog box when the PC is started up
so that settings can be modified, press the [Y] key. If not, press a
key other than the [Y] key.

< About the error messages >
Refer to "7. Explanation of the error messages"in this file.

---------------------------------------
4. When using Config Manager (CM)
---------------------------------------
If Config Manager (CM) is installed in your PC, or if the PC's PnP
BIOS supports the sound card, SETUPSA.EXE will only read the settings
assigned by CM, and will not reset the sound card.
In this case, only the volume can be changed in the above dialog box.
(I/O, IRQ and DMA settings cannot be made.)

-----------------------------
5. About the default settings
-----------------------------
The factory default settings are as follows.
                | I/O   IRQ   DMA
----------------+-------------------
Sound Blaster   | 220h   5     1 
WSS             | 530h   5     0
MPU401          | 330h   5     -
------------------------------------

---------------------------
6. About the error messages
---------------------------
Here is a list of the SETUPSA.EXE error messages and the actions to
be taken.

"OPL3-Sax board is not installed!!"
---> The OPL3-SA board is not installed in the PC.

"IRQ Conflict"(only when using OPL3-SA)
---> OPL3-SA cannot assign the same IRQ to WSS and SB.
    Modify one of the IRQ settings.

"WSS I/O error"
---> The WSS I/O or IRQ or DMA setting is incorrect. Change it.

"SB check failed"
---> Sound Blaster I/O or IRQ or DMA setting is incorrect. Change it.

"Board write Failed"
---> Try changing settings such as WSS, SB or MPU.

"Memory Allocation error"
---> DOS conventional memory is insufficient.
     Remove resident programs such as device drivers to free up 
     conventional memory.

"Please Set WSS IRQ or DMA"
---> WSS IRQ and DMA are set to the [disable] setting.
     Set a setting other than [disable].
 
"IRQ Conflict on SB"
---> The Sound Blaster IRQ is being used by another device.
    Specify a different IRQ number.

"IRQ Conflict on MPU"
---> The MPU IRQ is being used by another device.
     Specify a different IRQ number.

"IRQ Conflict on WSS"
---> The WSS IRQ is being used by another device.
     Specify a different IRQ number.

"File open error"
---> SETUPSA.EXE cannot find the necessary file(s).
     Check that OPL3SA.INI, TEST.WAV, and MESSAGE.TBL are in the same
     directory as SETUPSA.EXE.

"Fail to allocate node buffer"
"Enable to allocate DMA buffer"
"Can't allocate memory!"
---> DOS conventional memory is insufficient.
     Remove resident programs such as device drivers to free up 
     conventional memory.

"OPL3-Sax ctrl register write error!"
---> Either SB, WSS, MPU, Gameport, Modem, or IDE settings are incorrect,
     or it is possible that the board is not connected correctly.

"opl3sa.ini not present!"
---> The OPL3SA.INI file which contains the settings does not exist.
     Check that it is located in the same directory as SETUPSA.EXE.

"SB reset error!"
---> It is possible that the board connections are not correctly.
     Turn off the power, and insert the board correctly.

"WSS Configuration Error: Not Specified Interrupt"
"WSS Configuration Error: Not Specified DMA Channel"
"WSS Configuration Error: Incorrect Base Address"
---> WSS settings are invalid. Modify them.
