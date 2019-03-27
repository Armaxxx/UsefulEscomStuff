main: main.cpp Puzzle.o Nodo.o SocketDatagrama.o PaqueteDatagrama.o
	g++ main.cpp Puzzle.o Nodo.o SocketDatagrama.o PaqueteDatagrama.o -o main
SocketDatagrama.o: SocketDatagrama.cpp PaqueteDatagrama.o SocketDatagrama.h
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c
Puzzle.o: Puzzle.cpp Nodo.o Puzzle.h
	g++ Puzzle.cpp -c
Nodo.o: Nodo.cpp Nodo.h
	g++ Nodo.cpp -c
