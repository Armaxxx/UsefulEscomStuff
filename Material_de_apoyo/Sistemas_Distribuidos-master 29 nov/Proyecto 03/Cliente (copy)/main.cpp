#include "Puzzle.h"
#include "Nodo.h"
#include <iostream>
#include <string>
using namespace std;


int main(int argc, char const *argv[])
{
    int inicial[NUEVE] = {2, 8, 3, 1, 6, 4, 7, 0, 5}; 
    int ultimo [NUEVE] = {1, 2, 3, 8, 0, 4, 7, 6, 5}; 
    int nodoEncontrado =0;
    string cadena ="";
    Puzzle NuevoPuzzle(inicial, ultimo);

    while(nodoEncontrado != 1)
    {
        nodoEncontrado = NuevoPuzzle.movimientos();    
    }
    cout<<"Nodo encontrado: "<<nodoEncontrado<<endl;
    
    //cout<<"---Ultimas hojas---"<<endl;
    //NuevoPuzzle.imprimirUltimasHojas();
    
    cout<<"---Almacen---"<<endl;
    NuevoPuzzle.imprimirAlmacen();


    return 0;
}
