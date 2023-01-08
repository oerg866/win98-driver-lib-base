
all: natsemi.o

natsemi.o: natsemi.c
	gcc -D__KERNEL__ -DMODULE -DMODVERSIONS -include /usr/src/linux-2.4/include/linux/modversions.h -Wall -Wstrict-prototypes -O2 -m486 -c natsemi.c -I/usr/src/linux-2.4/include

clean:
	rm -f core *.o
