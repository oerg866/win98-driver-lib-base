**********************************************************************
*                 Intel740(tm) Graphics Accelerator                  *
*                    Windows* 98 And Windows* 95                     *
*                    Software Driver Release PV3.2W                  *
*                          December 28, 1998                         *
**********************************************************************

PLEASE READ THE INFORMATION CONTAINED IN THIS README BEFORE USING THE 
INTEL740(TM) DRIVERS

**********************************************************************
**********************************************************************

Information in this document is provided in connection with Intel 
products. No licence, express or implied, by estoppel or otherwise, to 
any intellectual property rights is granted by this document.  Except 
as provided in Intel's Terms and Conditions of Sale for such products, 
Intel assumes no liability whatsoever, and Intel disclaims any express 
or implied warranty, relating to sale and/or use of Intel products 
including liability or warranties relating to fitness for a particular 
purpose, merchantability, or infringement of any patent, copyright or 
other intellectual property right. Intel products are not intended for 
use in medical, life saving, or life sustaining applications. Intel 
may make changes to specifications and product descriptions at any 
time, without notice.

The Intel740(tm) graphics accelerator may contain design defects or 
errors known as errata which may cause the product to deviate from 
published specifications.  Current characterized errata are available 
upon request.

The hardware vendor remains solely responsible for the design, sale 
and functionality of its product, including any liability arising from 
product infringement or product warranty.

Copyright (c) Intel Corporation 1998. 

*Third-party brands and names are the property of their respective 
owners.


**********************************************************************
**********************************************************************


README Contents: 

1.0  Introduction
2.0  Release Notes
3.0  Intel740(tm) Graphic Accelerator Driver Installation Procedure
4.0  Web Site Location and Access




**********************************************************************
1.0 Introduction  
**********************************************************************


This README file contains the installation procedure and usage 
information for the Intel740(tm) graphics accelerator 
software, and latest version of DirectX*. The software and hardware 
requirements for this release are as follows:

## Software Drivers (SDR) Version:  	    PV3.2W
## Windows* 95 Version:                     OSR2.1 or 2.5**
## Windows* 98 Version:                     RCO (1691)
## DirectX* 5.0 Version:                    RC2-Gold (4.05.01.1650)
## Indeo CODEC                              4.4, 4.5
## Video BIOS version:                      212, 220, 230, 231, 233
## Intel740 graphics accelerator stepping   A2

----------------
 Version number
----------------
## Driver Release                           Version #
   PV1.0                                    4.10.01.1516-980316
   PV1.0a                                   4.10.01.1526-980326
   PV1.5                                    4.10.01.1701-980501
   PV2.0a                                   4.10.01.1915-980715
   PV2.1                                    4.10.01.1927-980727
   PV3.0w                                   4.10.01.2029-980829
   PV3.02w                                  4.10.01.2227-981027
   PV3.1w                                   4.10.01.2228-981028
   PV3.2w				    4.10.01.2407-981207

Video BIOS/Driver compatible combination
VIDEO BIOS   PV 1.0   PV1.0a   PV 1.5   PV 2.0a   PV 2.1   PV3.0w     PV3.02w    PV3.1w    PV3.2w 
----------   ------   ------   ------   -------   ------   ------     --------   -------  -------- 
VB212         yes      yes      yes       yes	    yes      yes       yes        yes      yes
VB220         no       no       yes       yes       yes      yes       yes        yes      yes
VB230         no       no       no        yes       yes      yes       yes        yes      yes
VB231         no       no       no        no         no      yes       yes        yes      yes
VB233         no       no       no        no         no      yes       yes        yes      yes


The Intel740(tm) graphics accelerator is optimized to run with the 
following PC configurations:
(1) Processor: Intel(R) Pentium(R)II processors
(2) Motherboard: Based on the Intel(R) 440LX, 440BX, 440GX AGPset
    or a later generation Intel AGPset, motherboard must have an 
    unpopulated AGP slot or the Intel740 chip must be down on the 
    motherboard
(3) Operating System: Windows* 95 OSR 2.1 or later (with USB 
    Supplement) or Windows* 98.

**When loading the Intel740 drivers and OSR2.1 or OSR 2.5 for the 
first time, the software should be loaded in the following order:
    (1) Load OSR2.0 or OSR 2.5
    (2) Load the "USB Supplement" (brings it up to OSR2.1 level or 
OSR2.5)
    (3) Load the Intel740(tm) drivers.
    Note: If this is not done in this order, then the Intel740 drivers 
will not be loaded properly and the standard Microsoft VGA drivers 
will be loaded instead.

Also included are release notes describing any problems or issues that 
were known at the time of shipment.


**********************************************************************
2.0 Release Notes
**********************************************************************

 -----------------
 Version 3.02w
-----------------
Same as PV3.0w except the following issues have been resolved:
(1) May improve system stability when running certain applications 
    (e.g.  Microsoft Internet Explorer).

(2) Software Cursor Interrupt error while halting the system,
    has been resolved.

---------------
Version 3.1w
---------------
Same as PV3.02w except the following issues have been resolved:
(1) Third party Chipset support was added.

(2) Memory leak issue resolved, reduces freezes and prevents certain 
    applications (Terra*, Final Reality*,etc.) from slowing down.

(3) Intel740(tm) as Primary adapter in multimonitor systems in enabled.  

(4) Lockups in Korean Windows98 have been resolved.  

(5) The advance property page is now completed.

(6) The Castle Creator (application) ALT-TAB error with the 450Mhz Pentium (R) II processor
    has been resolved.

(7) Gamma Ramp fix for Unreal* has been added.

(8) The X-Plane* Demo OGL fog issue has been resolved. 

---------------
Version 3.2w
---------------
Same as PV3.1w except the following issues have been resolved:
(1) Several application (Foresaken*,Israeli Air Force*, Rainbow6*, etc...) 
    issues have been resolved.


**********************************************************************
3.0  Intel740 Graphics Accelerator Driver Installation Procedure
**********************************************************************

----------------------------
 General Installation Notes
----------------------------
** The operating system and DirectX* must be installed on the system 
prior to installation (note: DirectX* is provided on the CD along with 
the Intel740 drivers). To update or install DirectX*, simply go to the 
DirectX* directory on the CD and click on "Setup.exe".

** This installation procedure is specific only to the version of 
driver and installation file included in this release. 

** The ".INF" file is the installation file and includes all of the 
driver and Graphics properties page files associated with this 
release.

** This procedure assumes that all of the software associated with 
this release is located in the same directory.

------------------------------------------------------
 Installing the Drivers from floppy disk or hard disk
------------------------------------------------------

(1) After Windows* has loaded, click on "My Computer" icon, "Control 
Panel" icon, and then the "Display" icon.

(2) You should now be in the "Display Properties" window.  Select the 
"Settings" tab, and click on the "Advanced Properties" button. 

(3) In the "Advanced Display Properties" window, select the "Adapter" 
tab, and click the "Change..." button.

For Windows* 95 installation, continue to Step 4.  In Windows* 98, the 
following window appears:

(A) The "Update Device Driver Wizard" window appears.  If you are 
installing the Intel740(tm) graphics accelerator card and drivers for 
the first time, this window may denote Intel740(tm) graphics 
accelerator as a "Standard PCI VGA Graphics Adapter."  Click on the 
"Next" button to continue.

(B) A new window appears, prompting either for Windows* to 
search for a device driver or to select one manually.  Click the 
option for "Display a list of all the drivers in  a specific location, 
so you can select the driver you   want." After this, click on the 
"Next" button, and continue to Step 4.

Continue with both Windows* 95 and Windows* 98 installation from this 
point.

(4) From the new window, click on the "Have Disk" button.

(5) You should now be in the "Install From Disk" window. In the "Copy 
manufactures files from:" box, enter the location of the Intel740(tm) 
graphics accelerator drivers and press the "OK" button.

(6) A window should pop up stating that the " Intel740-854 Win9x 
PC3.1W 3.1.2407-981207." drivers are about to be installed.  Click the 
"OK" button to accept the display driver change, and then click the 
"Close" button in the "Advanced Display Properties" window as well as 
the "Display Properties" window to complete the installation.  Restart 
the computer when prompted to do so.

(7) The drivers should now be loaded. To determine if the drivers have 
been loaded correctly, Refer to the "Verifying Installation" section, 
below.

**** Verifying Driver Installation

(1) From the Windows* 9x desktop, click on "My Computer", then "Control 
Panel", and then, finally, "System".

(2) You should be in the "System Properties" window.  Click on the 
"Device Manager" tab.  From here, go down to "Display Adapter" and 
click. The drivers associated with the display adapter should read: 
"Intel740-854 Win9x PC3.1W 3.1.2407-981207". If this is not the case, 
the drivers will need to be re-installed.


**********************************************************************
4.0  Web Site location and access 
**********************************************************************

Several web sites have been provided for access to the latest drivers 
and driver related information, including software and hardware 
issues.  
The developers web site is located at:
http://developer.intel.com/design/graphics/740.htm.

For a specific vendor driver, please contact that vendor.

The public web site is located at:
http://developer.intel.com/design/graphics/drivers.


*Third-party brands and names are the property of their respective 
owners.
