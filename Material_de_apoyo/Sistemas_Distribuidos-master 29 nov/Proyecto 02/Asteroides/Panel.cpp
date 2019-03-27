#include "Panel.h"
#include <iostream>
using namespace std;

//Constructor
Panel::Panel()
{
	//Inializamos matriz a 0, en todas puntos
	for (int i = 0; i < AREA_TOTAL_Y; i++)
	{
		for (int j = 0; j < AREA_TOTAL_X; j++)
		{
			plano[i][j] = 0;
		}
	}
}

void Panel::llenarMatriz(Poligono &Poli)
{

	//Dibujamos un Hexagono
	if (Poli.tipofigura == 0)
	{
		//printf("\tHexagono en Proceso\n");
		//dibujarHexagono(Poli);
	}
	else
	{
		printf("\tOctagono en Proceso\n");
		dibujoAsteroideOctagono(Poli);
	}
}
void Panel::dibujoAsteroideOctagono(Poligono &Poli)
{
	//Encontramos Punto x,y
	int puntoX, puntoY;
	int numdeIntentos = 0;
	bool espacio_disponible = false;

	//Buscaremos hasta encontrar un espacio libre en la matriz
	do
	{
		puntoX = rand() % (AREA_TOTAL_X - (Poli.base + 1)) + 1;
		puntoY = rand() % ((AREA_TOTAL_Y - 1) - 60);

		//Buscamos primer punto de la figura
		if (plano[puntoY][puntoX] == 0)
		{
			espacio_disponible = true;
		}
		else
		{
			espacio_disponible = false;
		}

		//Dibujamos Primera Parte /~\ 
		if (espacio_disponible == true)
		{
			for (int i = puntoY, j = 0; i <= puntoY + 20; i++, j++)
			{
				for (int k = puntoX - j; k <= puntoX + Poli.base + j; k++)
				{
					if (plano[i][k] == 0)
					{
						plano[i][k] = Poli.identificador;
						//Guardamos Primera Vertice
						if (k == puntoX && i == puntoY)
						{
							Poli.vertice_coordenadasX[0] = k;
							Poli.vertice_coordenadasY[0] = i;
							//printf("1° Coordenas x:%d y:%d\n", k, i);
						}
						//Guradamos Octavo Vertice
						else if (k == (puntoX + (Poli.base)) && i == puntoY)
						{
							Poli.vertice_coordenadasX[7] = k;
							Poli.vertice_coordenadasY[7] = i;
							//printf("8° Coordenas x:%d y:%d\n", k, i);
						}
						else if (k == (puntoX - 20) && i == (puntoY + 20))
						{
							Poli.vertice_coordenadasX[1] = k;
							Poli.vertice_coordenadasY[1] = i;
							//printf("2° Coordenas x:%d y:%d\n", k, i);
						}
						else if (k == (puntoX + (Poli.base) + 20) && i == (puntoY + 20))
						{
							Poli.vertice_coordenadasX[6] = k;
							Poli.vertice_coordenadasY[6] = i;
							//printf("7° Coordenas x:%d y:%d\n", k, i);
						}
					}
					else
					{
						for (int i = 0; i < AREA_TOTAL_Y; i++)
						{
							for (int j = 0; j < AREA_TOTAL_X; j++)
							{
								if (plano[i][j] == Poli.identificador)
								{
									plano[i][j] = 0;
								}
							}
						}
						espacio_disponible = false;
						break; //Rompemos primer for
					}
				}
				if (espacio_disponible == false)
				{
					break; //Rompemos segundo for
				}
			}
		}
		//Dibujamos Segunda Parte | |
		if (espacio_disponible == true)
		{
			for (int i = puntoY + 21; i <= puntoY + 40; i++)
			{
				for (int k = puntoX - 20; k <= puntoX + Poli.base + 20; k++)
				{
					if (plano[i][k] == 0)
					{
						plano[i][k] = Poli.identificador;
						//Guardamos TERCER Vertice
						if (k == puntoX - 20 && i == puntoY + 40)
						{
							Poli.vertice_coordenadasX[2] = k;
							Poli.vertice_coordenadasY[2] = i;
							//printf("3° Coordenas x:%d y:%d\n", k, i);
						}
						//Guradamos SEXTO Vertice
						else if (k == (puntoX + (Poli.base) + 20) && i == puntoY + 40)
						{
							Poli.vertice_coordenadasX[5] = k;
							Poli.vertice_coordenadasY[5] = i;
							//printf("6° Coordenas x:%d y:%d\n", k, i);
						}
					}
					else
					{
						for (int i = 0; i < AREA_TOTAL_Y; i++)
						{
							for (int j = 0; j < AREA_TOTAL_X; j++)
							{
								if (plano[i][j] == Poli.identificador)
								{
									plano[i][j] = 0;
								}
							}
						}
						espacio_disponible = false;
						break; //Rompemos primer for
					}
				}
				if (espacio_disponible == false)
				{
					break; //Rompemos segundo for
				}
			}
		}
		//Dibujamos Tercera Parte \_/
		if (espacio_disponible == true)
		{
			for (int i = puntoY + 41, j = 19; i <= puntoY + 60; i++, j--)
			{
				for (int k = puntoX + j; k <= puntoX + Poli.base - j; k++)
				{
					if (plano[i][k] == 0)
					{
						plano[i][k] = Poli.identificador;
						//Guardamos CUARTO Vertice
						if (k == puntoX && i == puntoY + 60)
						{
							Poli.vertice_coordenadasX[3] = k;
							Poli.vertice_coordenadasY[3] = i;
							//printf("4° Coordenas x:%d y:%d\n", k, i);
						}
						//Guradamos QUINTO Vertice
						else if (k == (puntoX + (Poli.base)) && i == puntoY + 60)
						{
							Poli.vertice_coordenadasX[4] = k;
							Poli.vertice_coordenadasY[4] = i;
							//printf("5° Coordenas x:%d y:%d\n", k, i);
						}
					}
					else
					{
						for (int i = 0; i < AREA_TOTAL_Y; i++)
						{
							for (int j = 0; j < AREA_TOTAL_X; j++)
							{
								if (plano[i][j] == Poli.identificador)
								{
									plano[i][j] = 0;
								}
							}
						}
						espacio_disponible = false;
						break; //Rompemos primer for
					}
				}
				if (espacio_disponible == false)
				{
					break; //Rompemos segundo for
				}
			}
		}

		if (espacio_disponible == false)
		{
			numdeIntentos++;
			if (numdeIntentos == 10)
			{
				printf("\tEstamos teniendo problemas para encotrar espacio para agregar un nuevo asteroide\n");
			}
			else if (numdeIntentos == 20)
			{
				printf("\tInserte un numero menor de asteroides\n");
				exit(0);
			}
		}

	} while (espacio_disponible != true);
}

void Panel::movimientoAsteroides(Poligono &Poli)
{
	switch (Poli.direccion)
	{
	case 0:
		actualizoPosicionOctagonos(Poli, 0, -Poli.velocidad);
		break;
	case 1:
		actualizoPosicionOctagonos(Poli, -Poli.velocidad, -Poli.velocidad);
		break;
	case 2:
		actualizoPosicionOctagonos(Poli, -Poli.velocidad, 0);
		break;
	case 3:
		actualizoPosicionOctagonos(Poli, -Poli.velocidad, Poli.velocidad);
		break;
	case 4:
		actualizoPosicionOctagonos(Poli, 0, Poli.velocidad);
		break;
	case 5:
		actualizoPosicionOctagonos(Poli, Poli.velocidad, Poli.velocidad);
		break;
	case 6:
		actualizoPosicionOctagonos(Poli, Poli.velocidad, 0);
		break;
	case 7:
		actualizoPosicionOctagonos(Poli, Poli.velocidad, -Poli.velocidad);
		break;
	}
}
void Panel::actualizoPosicionOctagonos(Poligono &Poli, int movX, int movY)
{
	//Ubicamos los puntos de Origen
	int puntoX, puntoY;
	bool espacio_disponible = true;

	//Buscamos Primer puntoX y Primer puntoY
	puntoX = Poli.vertice_coordenadasX[0];
	puntoY = Poli.vertice_coordenadasY[0];

	if ((30 <= puntoX || puntoX < AREA_VISIBLE_X-35) && (30 <= puntoY) )
	{
		espacio_disponible = true;
	}else
	{
		espacio_disponible =false;
	}

	//Limpiamos la matriz de la figura
	for (int i = 0; i < AREA_TOTAL_Y; i++)
	{
		for (int j = 0; j < AREA_TOTAL_X; j++)
		{
			if (plano[i][j] == Poli.identificador)
			{
				plano[i][j] = 0;
			}
		}
	}

	//Dibujamos Primera Parte /~\ 
	if(espacio_disponible == true)
	{
		for (int i = puntoY + movY, j = 0; i <= puntoY + 20 + movY; i++, j++)
		{
			for (int k = puntoX - j + movX; k <= puntoX + Poli.base + j + movX; k++)
			{
				if (plano[i][k] == 0)
				{
					plano[i][k] = Poli.identificador;
					//Guardamos Primera Vertice
					if (k == puntoX + movX && i == puntoY + movY)
					{
						Poli.vertice_coordenadasX[0] = k;
						Poli.vertice_coordenadasY[0] = i;
						//printf("1° Coordenas x:%d y:%d\n", k, i);
					}
					//Guradamos Octavo Vertice
					else if (k == ((puntoX + movX) + (Poli.base)) && i == (puntoY + movY))
					{
						Poli.vertice_coordenadasX[7] = k;
						Poli.vertice_coordenadasY[7] = i;
						//printf("8° Coordenas x:%d y:%d\n", k, i);
					}
					else if (k == ((puntoX + movX) - 20) && i == ((puntoY + movY) + 20))
					{
						Poli.vertice_coordenadasX[1] = k;
						Poli.vertice_coordenadasY[1] = i;
						//printf("2° Coordenas x:%d y:%d\n", k, i);
					}
					else if (k == ((puntoX + movX) + (Poli.base) + 20) && i == ((puntoY + movY) + 20))
					{
						Poli.vertice_coordenadasX[6] = k;
						Poli.vertice_coordenadasY[6] = i;
						//printf("7° Coordenas x:%d y:%d\n", k, i);
					}
				}
				else
				{
					espacio_disponible = false;
					break; //Rompemos primer for
				}
			}
			if (espacio_disponible == false)
			{
				break; //Rompemos segundo for
			}
		}
	}
	//Dibujamos Segunda Parte | |
	if (espacio_disponible == true)
	{
		for (int i = puntoY + 21 + movY; i <= puntoY + 40 + movY; i++)
		{
			for (int k = puntoX - 20 + movX; k <= puntoX + Poli.base + 20 + movX; k++)
			{
				if (plano[i][k] == 0)
				{
					plano[i][k] = Poli.identificador;
					//Guardamos TERCER Vertice
					if (k == (puntoX + movX) - 20 && i == (puntoY + movY) + 40)
					{
						Poli.vertice_coordenadasX[2] = k;
						Poli.vertice_coordenadasY[2] = i;
						//printf("3° Coordenas x:%d y:%d\n", k, i);
					}
					//Guradamos SEXTO Vertice
					else if (k == ((puntoX + movX) + (Poli.base) + 20) && i == (puntoY + movY) + 40)
					{
						Poli.vertice_coordenadasX[5] = k;
						Poli.vertice_coordenadasY[5] = i;
						//printf("6° Coordenas x:%d y:%d\n", k, i);
					}
				}
				else
				{
					espacio_disponible = false;
					break; //Rompemos primer for
				}
			}
			if (espacio_disponible == false)
			{
				break; //Rompemos segundo for
			}
		}
	}
	//Dibujamos Tercera Parte \_/
	if (espacio_disponible == true)
	{
		for (int i = (puntoY + movY) + 41, j = 19; i <= (puntoY + movY) + 60; i++, j--)
		{
			for (int k = (puntoX + movX) + j; k <= (puntoX + movX) + Poli.base - j; k++)
			{
				if (plano[i][k] == 0)
				{
					plano[i][k] = Poli.identificador;
					//Guardamos CUARTO Vertice
					if (k == (puntoX + movX) && i == (puntoY + movY) + 60)
					{
						Poli.vertice_coordenadasX[3] = k;
						Poli.vertice_coordenadasY[3] = i;
						//printf("4° Coordenas x:%d y:%d\n", k, i);
					}
					//Guradamos QUINTO Vertice
					else if (k == ((puntoX + movX) + (Poli.base)) && i == (puntoY + movY) + 60)
					{
						Poli.vertice_coordenadasX[4] = k;
						Poli.vertice_coordenadasY[4] = i;
						//printf("5° Coordenas x:%d y:%d\n", k, i);
					}
				}
				else
				{
					espacio_disponible = false;
					break; //Rompemos primer for
				}
			}
			if (espacio_disponible == false)
			{
				break; //Rompemos segundo for
			}
		}
	}

	if (espacio_disponible == false)
	{
		for (int i = 0; i < AREA_TOTAL_Y; i++)
		{
			for (int j = 0; j < AREA_TOTAL_X; j++)
			{
				if (plano[i][j] == Poli.identificador)
				{
					plano[i][j] = 0;
				}
			}
		}
		if(Poli.exploto==false)
		{
			Poli.vertice_coordenadasX[0] =puntoX;
			Poli.vertice_coordenadasY[0] =puntoY;
			
			Poli.vertice_coordenadasX[1] =puntoX -10;
			Poli.vertice_coordenadasY[1] =puntoY -10;
			Poli.vertice_coordenadasX[2] =puntoX -20;
			Poli.vertice_coordenadasY[2] =puntoY;
			Poli.vertice_coordenadasX[3] =puntoX -10;
			Poli.vertice_coordenadasY[3] =puntoY +10;

			Poli.vertice_coordenadasX[4] =puntoX +10;
			Poli.vertice_coordenadasY[4] =puntoY;
			Poli.vertice_coordenadasX[5] =puntoX +20;
			Poli.vertice_coordenadasY[5] =puntoY +10;
			Poli.vertice_coordenadasX[6] =puntoX +30;
			Poli.vertice_coordenadasY[6] =puntoY;
			Poli.vertice_coordenadasX[7] =puntoX +20;
			Poli.vertice_coordenadasY[7] =puntoY -10;
			Poli.exploto =true;
		}
		else
		{
			for(int i=0; i<7; i++)
			{
			Poli.vertice_coordenadasX[i] =0;
			Poli.vertice_coordenadasY[i] =0;
			}

			dibujoAsteroideOctagono(Poli);
			Poli.exploto =false;
		}
	}
}
