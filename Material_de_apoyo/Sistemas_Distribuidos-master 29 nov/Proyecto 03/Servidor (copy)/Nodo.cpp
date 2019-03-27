#include "Nodo.h"
#include "string.h"
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

void Nodo::imprimirElemento()
{
    int indice;
    cout<<"Elementos de la rama: ";
    for (indice = 0; indice < NUEVE; indice++)
    {
        cout<<nododearbol[indice]<<" ";
        
    }
    printf("\n");
}

void Nodo::imprimirNombre()
{
    printf("%s",nombre.c_str());
    //cout<<"Nombre: "<<nombre[0]<<endl;
}