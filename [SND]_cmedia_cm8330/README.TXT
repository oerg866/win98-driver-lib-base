
IMPORTANT NOTES:


* for Windows 98 installation

  1. Make sure that your Windows 98 system is setup completed.
  2. Turn off power and plug in sound card then turn on power.
  3. Windows 98 will auto detect your sound card and ask drivers
     disk. Insert the disk,Windows 98 will auto setup PnP drivers
     and enter Windows 98 system. Now, you can hear the Windows
     starting sound. If not,please run UINSTDRV.EXE to uninstall
     PnP device drivers and reboot Windows 98 to install again.
  4. Press Start button and select run item. Typing your drivers
     disk path and SETUP (ex. A:\SETUP) to install sound card
     Windows applications.

  SPECIAL NOTE:
  1. The DOS mode MPU-401 emulator uses WSS mode to output, so
     please select SB16 mode as waves (voice) output device.
  2. Please notice the I/O resource of DOS mode MPU-401 emulator in
     'System' of 'Control Panel'. Select same I/O resource as I/O
     port of MPU-401 General MIDI in DOS games or applications.
  3. Because we use two devices (SB16 & WSS) to perform full-
     duplex functions, some applications will detect the sound card
     not a full-duplex one. Please make sure that the playback 
     device is set to "Sound System Playback" and the record device
     is set to "SB16 Record" in "Multimedia" of "Control Panel", 
     the item "Use preferred devices only" must also be marked.
     In IPhone 5.0, even when you select the playback and record 
     devices to different ones, still the system will detects the 
     card as being not full-duplex. Even so, you have to set the 
     devices to different ones to enable the full-duplex functions.
     In fact, the full-duplex functions still work in this way.
  4. A3D interface is available only when the playback device is set 
     to "Sound System Playback" in "Multimedia" of "Control Panel".
  5. If you want to run games in Windows 98 DOS box or shut down to
     DOS, you don't have to install DOS drivers. But, If you want to
     run games in pure DOS enviroment, please press 'F8' key and
     select 'COMMAND PROMPT ONLY' to enter DOS during booting to
     install DOS drivers only (don't specify windows directory).
