C-Media CMI8330 MODDED Windows 98 driver by oerg866

This is not a stock C-Media package. It combines:

  * WSS core from C-Media "ver 2.0": CM8330.VXD 4.10.00.0200 (Jan 2000)
    and CM8330.DRV (Jan 1999 build)
  * Everything else from the C-Media "6.4 light" disk (Oct 1998): INF,
    SB16 driver 4.10.00.0163/0161, MPU-401 VxD 4.0.961, joystick, OPL3.
    No software MIDI synthesizer, no DOS-box MPU-401 emulator.

Changes made to the binaries:

  * CM8330.DRV, CM8330SB.DRV: the "Digital CD Audio" (S/PDIF in) mute
    checkbox in the volume control now works (bug in mixer's mute handler)
  * CM8330.DRV: version resource raised 4.10.00.0161 -> 4.10.00.0200 -
    prevents versioning warning when updating the driver
  * CM8330SB.DRV: fixed-version field, which C-Media had left at
    4.0.0.0, set to match its version string (4.10.0.163) - ditto

No other functional changes.
