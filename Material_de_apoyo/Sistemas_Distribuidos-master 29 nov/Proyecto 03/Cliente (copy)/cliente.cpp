#include "Puzzle.h"
#include "Nodo.h"
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include <iostream>

#define PUERTO 8881
using namespace std;

void envioAServidor(int numerodeservidor, char ip[], Puzzle puzzleparaenvio);

int main(int argc, char const *argv[])
{
    //Variables para Cliente
    char ip[] = "127.0.0.1";
    char ipUno[] = "127.0.0.1";
    char ipDos[] = "10.100.67.138";
    char ipTres[] = "127.0.0.3";
    int numero_de_servidores = 2;
    int respuesta, numero_de_ramas, contador;

    //Variables para Puzzle
    int inicial[NUEVE] = {2, 8, 3, 1, 6, 4, 7, 0, 5}; 
    int ultimo [NUEVE] = {1, 2, 3, 8, 0, 4, 7, 6, 5};
    Puzzle NuevoPuzzle(inicial, ultimo);
    while(NuevoPuzzle.nodos_ultimashojas.size() % numero_de_servidores != 0)
    {
        respuesta = NuevoPuzzle.movimientos();
        if(respuesta == 1){
            printf("No es necesario repartir\n");
            exit(0);
            break;
        }
    }
    int aux =NuevoPuzzle.nodos_ultimashojas.size();
    printf("Cantidad de ultimas hojas: %d\n", aux);
    //Dividimos el Puzzle original e indicamos cuantas hojas se van a enviar
    Puzzle puzzle_a_enviar = NuevoPuzzle;
    for(int i = 0; i < numero_de_servidores; i++)
    {
        puzzle_a_enviar.nodos_ultimashojas.clear();
        for(contador = 0 + i; contador < (aux/numero_de_servidores) + i; contador++)
        {
            Nodo temp = NuevoPuzzle.nodos_ultimashojas[contador];
            puzzle_a_enviar.nodos_ultimashojas.push_back(temp);
        }
        if(numero_de_servidores == 1)
        {
            envioAServidor((i+1), ipUno, NuevoPuzzle);
        }
        else
        {
            if(i == 0){
                envioAServidor((i+1), ipUno, puzzle_a_enviar);
            }/*
            if(i == 1){
                envioAServidor((i+1), ipDos, puzzle_a_enviar);
            }
            if(i == 2){
                envioAServidor((i+1), ipTres, puzzle_a_enviar);
            }*/
        }
    }
    
    //Esperamos respuesta
    cout<<"Esperando respuesta del servidor..."<<endl;
    SocketDatagrama socketM;
    char *buffer22;
    PaqueteDatagrama paquetef(sizeof(char) * 100);
    socketM.recibe(paquetef);
    buffer22 = (char *)paquetef.obtieneDatos();    
    std::cout<<buffer22<<endl;
    return 0;
}

void envioAServidor(int numerodeservidor, char ip[],  Puzzle puzzleparaenvio)
{
    int totalnodos;
    int cantidad_de_nodos[4];
    int i, j, k;
    cantidad_de_nodos[0] = 2;
    cantidad_de_nodos[1] = puzzleparaenvio.nodos_ultimashojas.size();
    cantidad_de_nodos[2] = puzzleparaenvio.almacen_nodos.size();
    cantidad_de_nodos[3] = cantidad_de_nodos[1] + cantidad_de_nodos[2] + cantidad_de_nodos[0];
    cout<<"Enviar a servidor: "<<numerodeservidor<<endl;
    cout<<"Total de nodos: "<<cantidad_de_nodos[3]<<" Ultimas hojas: "<<cantidad_de_nodos[1]<<" Hojas en almacen: "<<cantidad_de_nodos[2]<<endl;

    //Preparamos para el envio
    SocketDatagrama socket;
    //Primero mandaremos la cantidad de nodos
    PaqueteDatagrama paquete0((char *)cantidad_de_nodos, cantidad_de_nodos[3] * sizeof(int),ip,8881);
    socket.envia(paquete0);   
    //Segundo enviaremos nodos
        Nodo nodotemp;
        char buffer[100];
            //Enviamos posiciones
            nodotemp = puzzleparaenvio.nodo_inicial;
            PaqueteDatagrama paquete1((char *)nodotemp.nododearbol, 9 * sizeof(int),ip, 8881);
            socket.envia(paquete1);
            //Enviamos nombre
            std::string cadena = nodotemp.nombre;
            strcpy(buffer,cadena.c_str());
            PaqueteDatagrama paquete2((char *)buffer, 100 * sizeof(char),ip, 8881);
            socket.envia(paquete2);
        
            //Enviamos posiciones
            nodotemp = puzzleparaenvio.nodo_final;
            PaqueteDatagrama paquete3((char *)nodotemp.nododearbol, 9 * sizeof(int),ip, 8881);
            socket.envia(paquete3);
            //Enviamos nombre
            cadena = nodotemp.nombre;
            strcpy(buffer,cadena.c_str());
            PaqueteDatagrama paquete4((char *)buffer, 100 * sizeof(char),ip, 8881);
            socket.envia(paquete4);
        

    //cout<<"Nodos ultimas Hojas"<<endl;
    for(int i = 0; i < cantidad_de_nodos[1]; i++){
        //Enviamos posiciones
        nodotemp = puzzleparaenvio.nodos_ultimashojas[i];
        PaqueteDatagrama paquetex((char *)nodotemp.nododearbol, 9 * sizeof(int),ip, 8881);
        socket.envia(paquetex);
        //Enviamos nombre
        cadena = nodotemp.nombre;
        strcpy(buffer,cadena.c_str());
        PaqueteDatagrama paquetey((char *)buffer, 100 * sizeof(char),ip, 8881);
        socket.envia(paquetey); 
    }

    //cout<<"Nodos almacen"<<endl;
    for(int i = 0; i < cantidad_de_nodos[2]; i++){
        //Enviamos posiciones
        nodotemp = puzzleparaenvio.almacen_nodos[i];
        PaqueteDatagrama paquetex((char *)nodotemp.nododearbol, 9 * sizeof(int),ip, 8881);
        socket.envia(paquetex);
        //Enviamos nombre
        cadena = nodotemp.nombre;
        strcpy(buffer,cadena.c_str());
        PaqueteDatagrama paquetey((char *)buffer, 100 * sizeof(char),ip, 8881);
        socket.envia(paquetey); 
    }
}
