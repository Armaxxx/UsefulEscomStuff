#ifndef NODO_H_
#define NODO_H_
#define NUEVE 9

#include <iostream>
#include <string.h> 

using namespace std; 

class Nodo
{
    //Declaracion de Variables
  public:
    int identificador;
    int nododearbol[NUEVE] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    string nombre ="";

    //Declaracion de Metodos
  public:
    Nodo();
    void inicializarNodo(int valoresnodo[], int id, string name);
};

#endif