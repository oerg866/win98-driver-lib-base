**
**
**  VT6120/VT6122 software package
**
**  Readme file VNT version
**
**  Release 2.4   Aug. 2005
**
**

This package contains the configuration / diagnostic utilities and 
device drivers.


1. Directory structure

After extracting the driver package to a directory (e.g. c:\TEMP\). The 
directory structure should be as below:

C:\TEMP\
+---CE4
+---CE5
+---DMI-GE
+---EEPROM
+---ETHERTOOL
|   +---CE4.2
|   |   +---Debug
|   |   \---Retail
|   \---CE5.0
|       +---Debug
|       \---Retail
+---FLASH
+---FREEBSD
+---GigaCheck
+---LANSVR40.DOS
+---LANTASTI
+---LINUX
+---MACOSX
+---MSLANMAN.DOS
|   \---DRIVERS
|       +---ETHERNET
|       |   \---GETND2
|       \---NIF
+---NETWARE
|   +---CLIENT32
|   +---DOSODI
|   +---SRVRODI.311
|   +---SRVRODI.312
|   +---SRVRODI.4
|   \---SRVRODI.56
+---PCNFS
+---PKTDRVR
+---PXE
+---PXERPL
+---RPL
+---SCO5
+---SOLARIS
+---UNATTEND
|   +---NT40
|   +---W2000
|   +---W9X
|   \---XP
+---UNIXWARE
+---VSNMP-GE
+---WFW311
+---WINSETUP
\---XPE
    

2. User guide for utilities

   Please refer to the text files (*.TXT) in each utility subdirectory.
   For example, for diagnostic utility user guide, please check
   \DIAG32.TXT.
   Notice that flash utility is only used for Add-On-Card BootROM flash 
   purpose. For LAN-On-Motherboard BootROM usage, LAN BootROM should be
   integrated into BIOS and than flash the BIOS (with LAN BootROM image)
   using flash utility provided by motherboard vendors.


3. User guide for drivers

   Please refer to the text files (*.TXT) in each driver subdirectory.
   For example, if you are installing Windows platform drivers, please 
   read the text file in \WIN.TXT for installation information.
   Notice that the BootROM image for both Add-On-Card and LAN-On-Motherboard
   are contained in this software package. Please see the text files (*.TXT)
   included in the BootROM folders for detail.   


4. User Guide for Unattended Mode Installation

   Please refer to the text files (*.TXT) in \UNATTEND\ subdirectory.
   You could find the sample file in each subdirectory as well.


5. User guide for Windows applications and documents for manufacturers

   Please refer to the PDF format files in \DMI-GE, \GigaCheck, and 
   \VSNMP-GE directories.
