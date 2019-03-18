#include "PaqueteDatagrama.hpp"
#include "SocketDatagrama.hpp"
#include <iostream>

int puerto = 7200;

int main(void){
    PaqueteDatagrama msgclient;
    SocketDatagrama serverAddr;

    serverAddr = new SocketDatagrama(htons(7200));

    while(1){
        serverAddr.recibe(msgclient);
        msgclient.inicializaDatos("Recibido");
        serverAddr.envia(msgclient);
    }
}