#include "PaqueteDatagrama.hpp"
#include "SocketDatagrama.hpp"
#include <iostream>

int puerto = 7200;

int main(void){
    char dato[9] = "Recibido";
    PaqueteDatagrama msgclient(11);
    SocketDatagrama serverAddr(7200);

    while(1){
        serverAddr.recibe(msgclient);
        msgclient.inicializaDatos(dato);
        serverAddr.envia(msgclient);
    }
}