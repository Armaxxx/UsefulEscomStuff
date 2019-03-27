#include "Nodo.h"
using namespace std;
Nodo::Nodo()
{
    
}

void Nodo::inicializarNodo(int valoresnodo[], int id, string name)
{
    int indice;
    identificador =id;
    nombre =name;
    //nombre =name;
    for (indice = 0; indice < NUEVE; indice++)
    {
        nododearbol[indice] = valoresnodo[indice];
    }
    return;
}
