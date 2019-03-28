cliente: cliente.cpp Puzzle.o Nodo.o SocketDatagrama.o PaqueteDatagrama.o
	g++ cliente.cpp Puzzle.o Nodo.o SocketDatagrama.o PaqueteDatagrama.o -o cliente
SocketDatagrama.o: SocketDatagrama.cpp PaqueteDatagrama.o SocketDatagrama.h
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c