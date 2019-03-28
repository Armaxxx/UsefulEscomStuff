servidor: Primos.cpp SocketDatagrama.o PaqueteDatagrama.o
	g++ Primos.cpp SocketDatagrama.o PaqueteDatagrama.o -o Primos
SocketDatagrama.o: SocketDatagrama.cpp PaqueteDatagrama.o SocketDatagrama.h
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c
