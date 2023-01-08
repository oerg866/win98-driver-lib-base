                  NETGEAR FA311/FA312 PCI Adapter Driver 
                  --------------------------------------
  

  Contents of the Subdirectory:
  -----------------------------

      natsemi.c         The linux driver source code file
      natsemi.o        	The linux dirver 
      makefile          Makefile for generating driver object file
                  

  Installation Procedure:
  -----------------------

  1.  Copy natsemi.o into the latest kernel's modules.

          cp natsemi.o /lib/modules/2.4.2-2/kernel/drivers/net/

  2.  Insert natsemi module into kernel

          insmod natsemi

  3.  To configure IP for the network interface

          ifconfig eth0 xxx.xxx.xxx.xxx
                        ^^^^^^^^^^^^^^^ Your IP address
 
  4.  Well done. Your adapter is active now.

  
  5.  To make the driver load when the system boots up, you can execute netconf.

   
  6.  enter setting in the Client tasks/Basic host information/Adaptor 1
      
          IP address:    xxx.xxx.xxx.xxx
          Netmask:       255.255.255.0
          Net device:    eth0
          Kernel mode:   natsemi

  7.  Then your driver will work every time you boot.
  
 
  