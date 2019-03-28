#include "Puzzle.h"
#include "Nodo.h"
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include <iostream>
#include <vector>

using namespace std;


int main(int argc, char const *argv[])
{
    SocketDatagrama socket(8881);
    Puzzle nuevoPuzzle;
    int nodoEncontrado = 0;
    int *cantidad_de_nodos, *arreglo_recibido;
    char *buffer;
    string nombre; 

        cout<<"Servidor listo para recibir"<<endl;
    //Nos preparamos para arreglo que indica cuantos nodos hay
        PaqueteDatagrama paquete0(sizeof(cantidad_de_nodos) * 4);
        socket.recibe(paquete0);
        cantidad_de_nodos = (int *)paquete0.obtieneDatos();
        cout<<"Total de nodos: "<<cantidad_de_nodos[3]<<" Ultimas hojas: "<<cantidad_de_nodos[1]<<" Hojas en almacen: "<<cantidad_de_nodos[2]<<endl;
    //Ahora recibiremos nodos
        for(int i = 0; i < cantidad_de_nodos[3]; i++)
        {
            //Recibo posiciones
            PaqueteDatagrama paquete1(sizeof(int) * 9);
            socket.recibe(paquete1);
            arreglo_recibido = (int *)paquete1.obtieneDatos();
            int posiciones[NUEVE];
            //Recibo nombre
            PaqueteDatagrama paquete2(sizeof(char) * 100);
            socket.recibe(paquete2);
            buffer = (char *)paquete2.obtieneDatos();
            Nodo nodoauxiliar;
            if(i == 0)
            {
                nodoauxiliar.nombre = buffer;
                for(int j = 0; j < NUEVE; j++)
                {
                   nodoauxiliar.nododearbol[j] = arreglo_recibido[j];
                }
                nodoauxiliar.identificador = 1;
                nuevoPuzzle.nodo_inicial = nodoauxiliar;
            }
            else if(i == 1)
            {
                nodoauxiliar.nombre = buffer;
                for(int j = 0; j < NUEVE; j++)
                {
                   nodoauxiliar.nododearbol[j] = arreglo_recibido[j];
                }
                nodoauxiliar.identificador = 1;
                nuevoPuzzle.nodo_final = nodoauxiliar;
            }
            else if(i>1 && i<=cantidad_de_nodos[1]+1)
            {
                nodoauxiliar.nombre = buffer;
                for(int j = 0; j < NUEVE; j++)
                {
                   nodoauxiliar.nododearbol[j] = arreglo_recibido[j];
                }
                nodoauxiliar.identificador = 1;

                nuevoPuzzle.nodo_inicial = nodoauxiliar; 
                nuevoPuzzle.nodos_ultimashojas.push_back(nuevoPuzzle.nodo_inicial);
            }
            else
            {
                nodoauxiliar.nombre = buffer;
                for(int j = 0; j < NUEVE; j++)
                {
                   nodoauxiliar.nododearbol[j] = arreglo_recibido[j];
                }
                nodoauxiliar.identificador = 1;

                nuevoPuzzle.nodo_inicial = nodoauxiliar; 
                nuevoPuzzle.almacen_nodos.push_back(nuevoPuzzle.nodo_inicial);
            }
        }
    cout<<"----Materal recibido del cliente -> "<<endl;
    nuevoPuzzle.imprimirUltimasHojas();
    while(nodoEncontrado != 1)
    {
        nodoEncontrado = nuevoPuzzle.movimientos();
    }

    cout<<"-----------------------------------------------------"<<endl;
    cout<<"----Camino encontrado ->"<<endl;
    nuevoPuzzle.imprimirAlmacen();
    
    Nodo temm = nuevoPuzzle.almacen_nodos[nuevoPuzzle.almacen_nodos.size()-1];
    std::string cadena = temm.nombre;
    char buffer2[100];
    strcpy(buffer2,cadena.c_str());
        PaqueteDatagrama paquetexxc((char *)buffer2, 100 * sizeof(char), paquete0.obtieneDireccion(), paquete0.obtienePuerto());
        socket.envia(paquetexxc);
    
    std::cout<<"Nodo final: "<<cadena<<endl;
    return 0;
}
