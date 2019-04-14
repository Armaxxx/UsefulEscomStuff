all: emisor receptor
emisor: emisor.c
	gcc -pthread emisor.c -o emisor
receptor: receptor.c
	gcc -pthread receptor.c -o receptor
clean:
	rm emisor receptor