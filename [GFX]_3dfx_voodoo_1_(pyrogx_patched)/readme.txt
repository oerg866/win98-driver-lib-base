Voodoo Graphics(TM) Based 3D Accelerators Driver Kit

Voodoo Graphics Driver kit Version: 3.01.00
Voodoo Graphics Glide(TM) Driver Version: 2.48.00.0455
Voodoo Graphics Glide3 Driver Version: 3.04.00.0455
Voodoo Graphics DirectX(r) Release Number : 2.17
Voodoo Graphics DirectX Driver Version: 4.10.01.0017
OpenGL(r) Driver Version: 1.0.0.0438 ICD

Platform: Windows(r) 95/98 and DOS(r)

Copyright ( 1997-1999 3dfx Interactive, Inc. )
All Rights Reserved

NOTE: Use of this software is subject to the terms in the 3dfx license 
agreement.

3dfx Interactive, Inc.
Website: http://www.3dfx.com
News Server: news://news.3dfx.com

This product may be covered by one or more of the following
US patents: 5,724,561  5,740,343


=======================================================================
What's in the distribution?
=======================================================================
This distribution contains Glide, Glide3, Direct3D(r) drivers for 
Voodoo Graphics Based 3D Accelerators and the Voodoo Graphics Control 
Panel Applet.

The following Voodoo Graphics boards will function with these drivers:

- 3dfx Interactive Voodoo Graphics reference boards

Included Files
--------------
3DFXPS.DLL   - Control Panel Applet
MM3DFX.DRV   - DirectDraw Driver
MM3DFX16.DLL - DirectDraw 16 Bit DLL
MM3DFX32.DLL - DirectDraw 32 Bit DLL
FXMEMMAP.VXD - Voodoo VXD for Mapping Memory
MSVCRT.DLL   - Microsoft Redistributable File
GLIDE2X.DLL  - Win95/98 Glide for Voodoo2 (Supports Glide 2.31+)
FXOEM2X.DLL  - Win95/98 Glide OEM Extension DLL
GLIDE2X.OVL  - DOS Glide for Voodoo2 (Supports Glide 2.31+)
GLIDE3X.DLL  - Win95/98 Glide3 for Voodoo2
VOODOO.INF   - INF File for installing Drivers
LICENSE.TXT  - 3dfx License Agreement
MANIFEST.TXT - Listing and size of files
README.TXT   - This File


=======================================================================
Installation 
=======================================================================

Requirements
------------

- Windows 95 or Windows 98
- PC with an Intel(r), AMD(r) or, Cyrix(r) based processor
- One free PCI slot (or two free PCI slots for SLI)
- 16MB of RAM or more Suggested


Installation
------------
The installation below can vary depending on which version of Windows
is installed.  To determine the Windows 95 version click Start, 
Settings, Control Panel. Double-click on the system icon. If the 
Windows version is 4.00.950b, Windows 95 OEM SR2 is running.


Existing Drivers Installed or PCI Multimedia Device shown in Device Mgr
-----------------------------------------------------------------------
1) Start Windows and extract the drivers to a temporary directory.

2) Open Device Manager (Start, Settings, Control Panel, System)

3) Locate the existing reference to the card it will be listed as:

       Reference Card: Other Devices / PCI Multimedia Device or
		       Sound, Video, Game Controllers / Voodoo2

4) Double Click on the card, then click the driver Tab

     Windows 95 Standard Release users: Click "Change Driver" and choose
                                        "Have Disk"
              Windows 95 OEM SR2 users: Click "Update Driver" then click
                                        the Next Button.  Click "Other
                                        Locations" 
                      Windows 98 users: Click "Update Driver" then click
                                        the Next Button twice on the
                                        Detection Dialog Box. Ensure that
                                        "Specify a Location" is checked and
                                        "Microsoft Windows Update" is not
                                        checked. Click Browse to continue.

5) Point the driver location to where the files are extracted to and click
   OK.  

     Windows Standard Release 95 users: Select "Voodoo2 3D Accelerator" 
                                        from the List and click OK.
                                        Click OK again to save changes in
                                        Device Manager.
              Windows 95 OEM SR2 Users: Click on Finish to continue.
                      Windows 98 users: Click on Next to continue.

6) You MAY then be prompted to insert the "Voodoo Graphics Drivers for
   Windows 9X" Disk.  Again, point to the path you extracted the files 
   to and press OK.

7) Windows will copy the drivers. Reboot the system when prompted

8) Install DirectX 5.0 or higher  (If not already installed)



No Current Drivers Installed
---------------------------------------------------

1) Start Windows and extract the drivers to a temporary directory.

2) Shutdown Windows, Power off the system and install your Voodoo2
   3D board into a PCI slot. 

3) Restart Windows after hardware installation.

4) Windows will detect a "PCI Multimedia Device", you need to:

     Windows 95 Standard Release users: Select "Use Driver from Mfr"
                                        and click OK
              Windows 95 OEM SR2 users: Click the Next Button on the
                                        Detection Dialog Box. Then click
                                        "Other Locations"
                      Windows 98 users: Click the Next Button twice on the
                                        Detection Dialog Box. Ensure that
                                        "Specify a Location" is checked and
                                        "Microsoft Windows Update" is not
                                        checked. Click Browse to continue.

5) Point the driver location to where the files are extracted to and click
   OK.  (Windows 98: You will need to click on Next to continue)

6) You MAY then be prompted to insert the "Voodoo2 Drivers for Windows 9X"
   Disk.  Enter the path the drivers are extracted to and press OK.

7) Windows will copy the drivers. Reboot the system when prompted

8) Install DirectX 5.0 or higher  (If not already installed)




OpenGL(r) ICD: Known Limitations
----------------------------------
The OpenGL ICD included with this kit is meant for use with OpenGL based 
games only. It may not be compatible with other applications that use the 
OpenGL API for 3D rendering support.

