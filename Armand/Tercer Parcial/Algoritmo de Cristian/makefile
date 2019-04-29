all: animacion

animacion: gfx.o animacion.o
	g++ gfx.o animacion.o -o animacion -lX11
animacion.o: animacion.cpp
	g++ animacion.cpp -c
gfx.o: gfx.c
	gcc gfx.c -c
clean:
	rm gfx.o animacion.o animacion