#ifndef PANEL_H_
#define PANEL_H_
#define AREA_TOTAL_X 950
#define AREA_TOTAL_Y 950
#define AREA_VISIBLE_X 800
#define AREA_VISIBLE_Y 800

#include "Poligono.h"

class Panel
{

  public:
	int plano[AREA_TOTAL_Y][AREA_TOTAL_X];

  public:
	Panel();
	void llenarMatriz(Poligono &);
	void movimientoAsteroides(Poligono &);

  private:
	void dibujoAsteroideOctagono(Poligono &);
	void actualizoPosicionOctagonos(Poligono &P, int, int );

};

#endif