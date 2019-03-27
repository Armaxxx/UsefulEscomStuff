#include "Panel.h"
#include "Poligono.h"
#include "gfx.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <unistd.h>

using namespace std;

int main()
{
	Panel panelprincipal;
	Poligono *poli;
	int numPoligonos;
	srand((unsigned)time(NULL));

	cout << "Ingrese numero de Poligonos: ";
	cin >> numPoligonos;
	poli = new Poligono[numPoligonos];

	//Creamos los Poligonos
	for (int i = 0; i < numPoligonos; i++)
	{
		/*Creamos poligono con un tipo de figura entre 0 y 1, una base entre 20 y 21,
		una velocidad entre 1 y 2, un id*/
		Poligono m(i + 1);
		poli[i] = m;
	}
	//Mandamos cada poligono a la matriz para que esta sea inicializada
	for (int i = 0; i < numPoligonos; i++)
	{
		printf("Poligono %d,  Tipo: %d  Base: %d  Direccion: %d, Velocidad: %d  ", poli[i].identificador, poli[i].tipofigura, poli[i].base, poli[i].direccion, poli[i].velocidad);
		panelprincipal.llenarMatriz(poli[i]);
	}

	//Dibujamos Panel
	gfx_open(AREA_VISIBLE_X, AREA_VISIBLE_Y, "Movimiento de Asteroides");
	while (true)
	{
		gfx_clear();
		gfx_color(0, 200, 100);

		for (int i = 0; i < numPoligonos; i++)
		{

				int j = 0;
				for (j = 0; j < 7; j++)
				{
					gfx_line(poli[i].vertice_coordenadasX[j], poli[i].vertice_coordenadasY[j], poli[i].vertice_coordenadasX[j + 1], poli[i].vertice_coordenadasY[j + 1]);
				}
				gfx_line(poli[i].vertice_coordenadasX[j], poli[i].vertice_coordenadasY[j], poli[i].vertice_coordenadasX[0], poli[i].vertice_coordenadasY[0]);

		}

		//Actualizamos puntos para movimiento
		for (int i = 0; i < numPoligonos; i++)
		{
			panelprincipal.movimientoAsteroides(poli[i]);
		}
		gfx_flush();
		usleep(41666); //24 por segundo
	}

	return 0;
}

/*
	//Imprimimos Matriz
	for (int i = 0; i < AREA_TOTAL_Y; i++)
	{
		for (int j = 0; j < AREA_TOTAL_X; j++)
		{
			printf("%3d", panelprincipal.plano[i][j]);
		}
		printf("\n");
	}
*/