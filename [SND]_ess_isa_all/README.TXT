Microsoft Windows95 AudioDrive® Device Drivers Version 4.05.02
July 19, 1996

This version of the Windows95 drivers supports the AudioRack32
version 2.00 release for ES1688/ES1788/ES1888/ES1868 hardware.

AudioRack32 2.0 is a 32-bit application written for Windows95.
The AudioRack32 2.0 application consists of six modules:
Command Center, 3-D/Tone Controller, Audio Mixer,
Digital Audio Player, MIDI Player, and CD Player.

If your hardware supports 3-D and Tone control, i.e. includes ES938
hardware, the Windows95 drivers need to have the 3-D/Tone support
enabled.  To do so, the OEMSETUP.INF (of ESS Windows95 drivers
diskette) needs to be modified prior to installing the Windows95
drivers.  The OEMSETUP.INF contains a section named [ES938.AddReg]
which allows an OEM to enable the installation of the controls
for ES938.

The AudioRack32 release 2.00 has limited support for the ES1878 hardware.

