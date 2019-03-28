#ifndef POLIGONO_H_
#define POLIGONO_H_

class Poligono
{
  public:
	int tipofigura;
	int base;
	int velocidad;
	int direccion;
	int identificador;
	int *vertice_coordenadasX;
	int *vertice_coordenadasY;
	bool exploto;
	
  public:
	Poligono();
	Poligono(int);
};

#endif