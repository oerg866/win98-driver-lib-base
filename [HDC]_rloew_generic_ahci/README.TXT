                   WINDOWS 95/98/98SE/ME AHCI DRIVER

                             Version 3.0

                              07/27/2019

                        Copyright (C) 2017-2019
                          By Rudolph R. Loew
                             
                             

The Windows 95/98/98SE/ME AHCI Driver provides Protected Mode support for
AHCI Mode Hard Disk Controllers. This provides support for AHCI Only
Motherboards and Cards, as well as allowing Multi-Boot Computers to be kept
in AHCI Mode to support newer Operating Systems.


REQUIREMENTS

DOS
Windows 95, 98, 98SE or ME.
AHCI capable Motherboard and/or Card(s).


CONTENTS

AHCI.PDR        AHCI Driver
AHCI4.INF       4 Port Driver INF File
AHCI6.INF       6 Port Driver INF File
AHCILDR.COM     BIOS Replacement for older AHCI implementations 
AHCIMAP.COM     AHCI Disk Driver Mapper
README.TXT      This File
LICENSE.TXT     License File
HISTORY.TXT     Revision History


LICENSE

Read the Licensing terms and conditions in the LICENSE.TXT file before
using this Software Program. Usage of any of the Programs constitutes
acceptance of all of the terms and conditions in the LICENSE.TXT file.


INF FILES

Two INF Files are provided for the AHCI Driver.

AHCI4.INF is for Disk Controllers that have 4 AHCI SATA Connectors.
AHCI6.INF is for Disk Controllers that have 6 AHCI SATA Connectors.

AHCIMAP will list the AHCI Disk Controllers and the number of supported
Drives.

Use the INF for the largest number reported by AHCIMAP.

Some Computers can be switched between 4 and 6 AHCI Ports. These Computers
have a separate BIOS Option to set SATA4 and SATA5 as AHCI or not.
If you intend to use both configurations, use the 6 Port INF File.
AHCI ports 4 and 5 will be reported as having failed when in 4 Port Mode.
This is harmless.

Contact the Author for different configurations.


AHCILDR

Some early AHCI Implementations use Memory access methods not compatible
with Windows 9x. EMM386 will also fail in these systems if a connected Drive
is accessed.

Most, not all, of these Systems or Cards can be switched back to Native Mode.
AHCILDR dynamically switches the Controller back to Native Mode and provides
a replacement DOS Driver. A Warning will be displayed if it cannot be
switched.

So far, only the early Highpoint AHCI Cards have been identified as unusable.
I have a Patch for the HighPoint Rocket 620. Card BIOS

This Program can be listed in the AUTOEXEC.BAT File or run manually before
Windows starts. The Windows AHCI Driver will take over after Boot.


AHCIMAP

AHCIMAP lists each of the AHCI Disk Controllers detected along with the
number of Disks supported. This can be used to select the appropriate INF
File to use. This Program can be run from DOS or Windows 9x.


DMA

AHCI, by design, uses DMA. DMA is always enabled and the DMA Option will not
be visible in the Device Manager Settings.


LIMITATIONS

If you use the AHCI6.INF File and only have 4 AHCI Ports, AHCI ports 4 and 5
will be reported as having failed. This is harmless.

Advanced features of AHCI, such as NCQ, are not supported.

AHCI Port Multipliers are not supported.

If you have a Disk Controller that is not a 4 or 6 Port Controller, contact
Author for a Custom INF File.

Some Add-On AHCI Cards have incompatible Boot ROMs that prevent Windows from
Booting.

If your BIOS sets the Controller to AHCI but does not enable it, this Driver
cannot be used.


NEW WINDOWS INSTALLATION

If your BIOS is switchable, you have the option to Install Windows in IDE
Mode and then add AHCI later. If you do, go to the "Existing Windows
Installation" Section after installing Windows in IDE Mode.

1. Install Windows.
2. If you get an IOS Protection Error:
   1. Reboot to DOS.
   2. Place the AHCILDR.COM File in your C:\ Folder.
   3. Add the line "AHCILDR" to your C:\AUTOEXEC.BAT File.
   4. Reboot
   5. Complete Installation.
3. Place the AHCI.PDR and the AHCI4.INF and/or AHCI6.INF File in a folder
   on your Hard Drive.
4. Go to Step 5 in the "Existing Windows Installation" Section.


EXISTING WINDOWS INSTALLATION

1. Place the AHCI.PDR and the AHCI4.INF and/or AHCI6.INF File in a folder
   on your Hard Drive.
2. Reboot and set your BIOS to AHCI Mode. Optionally set any Secondary
   Controller to AHCI Mode.
3. Boot.
4. If you get a Protection Error:
   1. Reboot to DOS.
   2. Place the AHCILDR.COM File in your C:\ Folder.
   3. Add the line "AHCILDR" to your C:\AUTOEXEC.BAT File.
   4. Reboot
5. Open Device Manager
6. Update any Unknown "PCI Cards" and point it to the Folder with the AHCI
   Files.
7. If both INF Files are present and Device Manager chooses the wrong INF
   File, select "Other Drivers" and choose the appropriate Version.
8. If System hangs during shutdown, press Reset and continue.


ORDERING

To purchase additional copies of this Software for other Computers:
Send $20 US + $1 S&H per copy to:

Rudolph Loew
506 Bieling Rd.
Elmont, NY 11003
USA

Payment can be made as follows:

1. Cash
2. Money Order drawn on a US Bank or Post Office
3. Personal Check drawn on a US Bank (Delivery made after Check clears)
4. International Postal Money Order accepted by the US Postal Service
5. Paypal to rloew@hotmail.com
6. Western Union

Warning: International Checks or Money Orders, not described above, will not
be accepted and will not be returned without an additional $2 US handling
charge.

Other Payment terms and methods may be available through authorized
Distributors of this Product. The following is a list of authorized
Distributors at this time:

C. C. Anderson  http://slesarc.x10hosting.com

Delivery is by E-Mail. You MUST include the E-Mail address you want the
Software to be sent to.
Please type or print your E-Mail address clearly. Sending me an E-Mail when
you place an order will insure that I have your correct E-Mail address.

Prices and Terms may change at any time.

For additional information or help placing your order,
I can be reached in the following ways:

E-Mail: rloew@hotmail.com
Phone:  1-516-352-9078


QUESTIONS AND COMMENTS

Please direct any questions or comments about the Program or the
Documentation to me at rloew@hotmail.com or as described under ORDERING.
Please send any Bug Reports to rloew@hotmail.com.


MAILING LIST

If you would like to be notified about updates and/or fixes or other products
from Rudolph Loew, E-Mail me at rloew@hotmail.com and ask to be put on my
Mailing list. Your E-Mail address will not be given out nor will you receive
any unsolicited mail. You can unsubscribe at any time.
