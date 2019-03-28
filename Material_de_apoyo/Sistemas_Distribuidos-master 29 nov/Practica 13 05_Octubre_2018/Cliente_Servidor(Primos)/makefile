servidor: ServidorRod.cpp SocketDatagrama.o PaqueteDatagrama.o
	g++ ServidorRod.cpp SocketDatagrama.o PaqueteDatagrama.o -o servidor
SocketDatagrama.o: SocketDatagrama.cpp PaqueteDatagrama.o SocketDatagrama.h
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c
