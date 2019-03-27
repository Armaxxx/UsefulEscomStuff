prac_compo: prac_compo.cpp Ortoedro.o
	g++ prac_compo.cpp Ortoedro.o Rectangulo.o Coordenada.o -o prac_compo
Ortoedro.o: Ortoedro.cpp Rectangulo.o Coordenada.o Ortoedro.h
	g++ Ortoedro.cpp -c
Rectangulo.o: Rectangulo.cpp Coordenada.o Rectangulo.h
	g++ Rectangulo.cpp -c
Coordenada.o: Coordenada.cpp Coordenada.h
	g++ Coordenada.cpp -c