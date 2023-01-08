                   3DLABS GLINT DRIVER
                   ===================
               Display Driver Ver 4.03.00.2101-0076
               OpenGL Driver Ver 1.0.16
               Heidi Driver Ver 1.4

This Readme describes how to download and install the above driver
release. It also lists the bug fixes and enhancements in this release.

0) Contents
1) Installation
2) New Display Driver Features
3) Display Driver Bugs Fixed
4) New OpenGL Driver Features
5) OpenGL Driver Bugs Fixed
6) OpenGL known Anomalies


1) Installation
===============

NOTE: If you are upgrading from the 4.03.00.2101-0071 Release Candidate 2
then you will be warned that three files have a for a different language.
This was a bug in RC2 and you should reply NO when asked if you want to
keep the old file in all three cases, so that Windows 95 DOES install the
files from the final release.

1.1 Download into an appropriate scratch directory
    (e.g. C:\3dlabs).
1.2 Use pkUnzip to uncompress the .ZIP file USING THE
    -d OPTION to preserve the directory structure...
    > pkUnzip -d c:\3dlabs\XXXX.ZIP
1.3 This will produce a .DOC file in Microsoft Word 6.0 format, which
    contains the release notes for the Display Driver and OpenGL driver,
    and a the driver files. If you do not have Word 6.0 and wish to
    read or print the release notes then download WordViewer 6.0 from this
    site (file Wordvu.exe see Wordvu.txt for licensing details).
1.4 Use this directory as the "Have Disk" target to install the new
    driver using the control panel display applet in the normal way.
    Full installation instructions can be found in the .DOC file.
1.5 You can now delete the download scratch directory and its contents.


2) New Display Driver Features
==============================

Release 2101-0076
-----------------
• This release now includes support for DDC2B on boards with the
  appropriate hardware support. Note if your board is DDC2B enabled
  it will have a blue video connector.
• Winbench97 performance has been improved.
• User editable controls have been rationalised to hang off the Display
  Properties control panel.


3) Display Driver Bugs Fixed
============================

Release 2101-0076
-----------------
• Polygon drawing under Powerpoint no longer results in stitch marks.
• It is now possible to switch back out of 16 color mode without a
  reboot into SAFE MODE.
• The TDDRAW test of the Microsoft DCT suite now passes.
• While no driver should be installed for the GLINT/Delta processor on
  on boards which have one, attempting to do so no longer causes a lock
  up.
• Software cursors no longer cause corruption when moved over animating
  Direct3D windows.
• Switching to a full screen DOS box while a windowed Direct3D application
  such as the Globe demo is running, no longer causes intermittent lock
  ups.
• DirectX programs now operate correctly at 1600x1200 resolution on
  PERMEDIA boards.


4) New OpenGL Driver Features
=============================
Release 1.0.16
-------------
• This is the first Windows 95 driver release supporting OpenGL.


5) OpenGL Driver Bugs Fixed
===========================
Release 1.0.16
--------------
• This is the first Windows 95 driver release supporting OpenGL.


6) New Heidi Driver Features
============================
Release 1.4
-----------
• This is the first Windows 95 driver release supporting Heidi
  acceleration for 3DStudio MAX.


7) Heidi Driver Bugs Fixed
==========================
Release 1.4
-----------
• This is the first Windows 95 driver release supporting Heidi
  acceleration for 3DStudio MAX.

