#http://floppsie.comp.glam.ac.uk/Glamorgan/gaius/networks/2.html
tftp: main.c tftp.o
	gcc main.c tftp.o -pthread -o tftp
tftp.o: tftp.c tftp.h
	gcc tftp.c -c
