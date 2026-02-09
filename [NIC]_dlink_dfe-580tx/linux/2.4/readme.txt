
    D-Link DL10050-based FAST Ethernet Adapter Installation
			     for Linux
							 Sep 27, 2002

Contents
========
 - Compatibility List
 - Quick Install
 - Compiling the Driver
 - Installing the Driver
 - Option parameter
 - Configuration Script Sample
 - Troubleshooting

Compatiblity List
=================
Adapter Support:

D-Link DFE-550TX FAST Ethernet Adapter.
D-Link DFE-530TXS FAST Ethernet 10/100 Adapter.
D-Link DFE-550FX 100Mbps Fiber-optics Adapter.
D-Link DFE-580TX Quad Channel Server Card.
D-Link DL10050-based FAST Ethernet Adapter.


The driver support Linux kernal 2.4.x. We had tested it
on the environments below.

 . Red Hat v7.1 (kernel 2.4.2-2)
 . Red Hat v7.1 (kernel 2.4.6)
 . Red Hat v7.2 (kernel 2.4.7-10)
 . Red Hat v7.3 (kernel 2.4.18-3)

Quick Install
=============
Install linux driver as following command:

1. make all
2. insmod sundance.o
3. ifconfig eth0 up 10.xxx.xxx.xxx netmask 255.0.0.0
		    ^^^^^^^^^^^^^^^\	    ^^^^^^^^\
				    IP		     NETMASK
Now eth0 bring up, you can test it by "ping" or get more information by
"ifconfig". If test ok, then continue next step.

4. cp sundance.o /lib/modules/`uname -r`/kernel/drivers/net
5. Add the following lines at /etc/modules.conf:
	alias eth0 sundance
6. Run "netconfig" or "netconf" to create configuration script ifcfg-eth0
   located at /etc/sysconfig/network-scripts or create it manually.
   [see - Configuration Script Sample]
7. Driver will automatically load and configure at next boot time.


Compiling the Driver
====================
  In Linux, NIC drivers are most commonly configured as loadable modules.
The approach of building a monolithic kernel has become obsolete. The driver
can be compiled as part of a monolithic kernel, but is strongly discouraged.
The remainder of this section assumes the driver is built as a loadable module.
In the Linux environment, it is a good idea to rebuild the driver from the
source instead of relying on a precompiled version. This approach provides
better reliability since a precompiled driver might depend on libraries or
kernel features that are not present in a given Linux installation.

The 2 files necessary to build Linux device driver are sundance.c and Makefile.
To compile, the Linux installation must include the gcc compiler, the kernel
source, and the kernel headers. The Linux driver supports Linux Kernels 2.4.x.
Copy the files to a directory and enter the following command to compile and
link the driver:

CD-ROM drive
------------

[root@XXX /] mkdir cdrom
[root@XXX /] mount -r -t iso9660 -o conv=auto /dev/cdrom /cdrom
[root@XXX /] cd root
[root@XXX /root] mkdir tmp
[root@XXX /root] cd tmp
[root@XXX tmp] cp /cdrom/linux/dlh5x-xx.tgz /root/tmp
[root@XXX tmp] tar xfvz dlh5x-xx.tgz (xx refer to release version)
[root@XXX tmp] make all

Floppy disc drive
-----------------

[root@XXX /] cd root
[root@XXX /root] mkdir tmp
[root@XXX /root] cd tmp
[root@XXX tmp] mcopy a:/linux/dlh5x-xx.tgz /root/tmp
[root@XXX tmp] tar xfvz dlh5x-xx.tgz (xx refer to release version)
[root@XXX tmp] make all

Installing the Driver
=====================

  Manual Installation
  -------------------
  Once the driver has been compiled, it must be loaded, enabled, and bound
  to a protocol stack in order to establish network connectivity. To load a
  module enter the command:

  insmod sundance.o


  or

  insmod sundance.o <optional parameter>    ; add parameter

  ========================================================================
   example: insmod sundance.o media=100mbps_hd
   or	    insmod sundance.o media=3
   or	    insmod sundance.o media=1,2,3,4	; for 4 cards or DFE-580TX
  ========================================================================

  Please reference the list of the command line parameters supported by
  the Linux device driver below.

  The insmod command only loads the driver and gives it a name of the form
  eth0, eth1, etc. To bring the NIC into an operational state,
  it is necessary to issue the following command:

  ifconfig eth0 up

  Finally, to bind the driver to the active protocol (e.g., TCP/IP with
  Linux), enter the following command:

  ifup eth0

  Note that this is meaningful only if the system can find a configuration
  script that contains the necessary network information. A sample will be
  given in the next paragraph.

  The commands to unload a driver are as follows:

  ifconfig eth0 down
  rmmod sundance.o

  The following are the commands to list the currently loaded modules and
  to see the current network configuration.

  lsmod
  ifconfig


  Automated Installation
  ----------------------
  This section describes how to install the driver such that it is
  automatically loaded and configured at boot time. The following description
  is based on a Red Hat 7.x distribution, but it can easily be ported to
  other distributions as well.

  Red Hat v7.x
  -----------------
  1. Copy sundance.o to the network modules directory, typically
     /lib/modules/2.4.x/kernel/drivers/net.
  2. Locate the boot module configuration file, most commonly modules.conf
     in the /etc directory. Add the following lines:

     alias ethx sundance
     options sundance <optional parameters>

     where ethx will be eth0 if the NIC is the only ethernet adapter, eth1 if
     one other ethernet adapter is installed, etc. Refer to the table in the
     previous section for the list of optional parameters.
  3. Locate the network configuration scripts, normally the
     /etc/sysconfig/network-scripts directory, and create a configuration
     script named ifcfg-ethx that contains network information.
  4. Note that for most Linux distributions, Red Hat included, a configuration
     utility with a graphical user interface is provided to perform steps 2
     and 3 above.


Parameter Description
=====================
You can install this driver without any addtional parameter. However, if you
are going to have extensive functions then it is necessary to set extra
parameter. Below is a list of the command line parameters supported by the
Linux device
driver.

mtu=packet_size			- Specifies the maximum packet size. default
				  is 1500.
media=xxxxxxxxx			- Specifies the media type the NIC operates at.
				  autosense	Autosensing active media.
				  10mbps_hd	10Mbps half duplex.
				  10mbps_fd	10Mbps full duplex.
				  100mbps_hd	100Mbps half duplex.
				  100mbps_fd	100Mbps full duplex.
				  0		Autosensing active media.
				  1		10Mbps half duplex.
				  2		10Mbps full duplex.
				  3		100Mbps half duplex.
				  4		100Mbps full duplex.
				  By default, the copper devices operate at 
				  autosense, the fiber devices operate at
				  100Mbps full duplex.
				  Note that, the fiber adapter only support 
				  100Mbps half/full duplex types.	

Configuration Script Sample
===========================
Here is a sample of a simple configuration script:

DEVICE=eth0
USERCTL=no
ONBOOT=yes
POOTPROTO=none
BROADCAST=207.200.5.255
NETWORK=207.200.5.0
NETMASK=255.255.255.0
IPADDR=207.200.5.2


Troubleshooting
===============
Q: Couldn't compiler the driver ?
A: Copy all necessary files on same current directory. Make sure all files
   are Unix file format (no LF). You can use some convertible program conver
   it from DOS to UNIX. (Like dos2unix,	 UltraEdit-32 ...).

Q: If I have two or more NICs, how to assgin different speed for each one?
A: Use comma to configure speed respectively. For example:
   insmod sundance.o media=100mbps_half,10mbps_half,100mbps_full,autosense
   OR
   insmod sundance.o media=1,2,0,4

-- End of File --
