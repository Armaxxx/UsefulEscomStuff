Server: SocketDatagrama.o PaqueteDatagrama.o Server.cpp
	g++ SocketDatagrama.o PaqueteDatagrama.o Server.cpp -o Server
SocketDatagrama.o: PaqueteDatagrama.hpp SocketDatagrama.hpp SocketDatagrama.cpp
	g++ -c SocketDatagrama.cpp
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.hpp
	g++ -c PaqueteDatagrama.cpp
clean:
	rm *.o