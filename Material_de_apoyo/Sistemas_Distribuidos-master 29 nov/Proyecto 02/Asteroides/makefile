main: main.o gfx.o
	g++ main.o gfx.o Panel.o Poligono.o -o main -lX11
main.o: main.cpp Panel.o Poligono.o
	g++ main.cpp -c
Panel.o: Panel.cpp Poligono.o Panel.h
	g++ Panel.cpp -c
Poligono.o: Poligono.cpp Poligono.h
	g++ Poligono.cpp -c
gfx.o: gfx.c gfx.h
	gcc gfx.c -c