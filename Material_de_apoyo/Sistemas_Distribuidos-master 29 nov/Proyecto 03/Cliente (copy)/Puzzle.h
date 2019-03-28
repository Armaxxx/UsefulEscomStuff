#ifndef PUZZLE_H_
#define PUZZLE_H_

#include <iostream>
#include <vector>
#include <string.h>
#include "Nodo.h"

using namespace std;

class Puzzle
{
  //Declaracion de Variables
public:
  Nodo nodo_inicial, nodo_final;
  vector<Nodo> almacen_nodos;
  vector<Nodo> nodos_ultimashojas;

  //Declaracion de Metodos
public:
  Puzzle();
  Puzzle(int nodoInicial[], int nodoFinal[]);
  void imprimirAlmacen();
  void imprimirUltimasHojas();
  int revisarEstadoNodo(Nodo nodo);
  int buscarExistenciaDeNodo(Nodo nodo);
  int movimientos();
};

#endif