#include "PaqueteDatagrama.hpp"
#include "SocketDatagrama.hpp"
#include <iostream>
using namespace std;

int puerto = 7200;

int main(void){
    cout << "Inicializa el SERVER" << endl;

    char dato[9] = "Recibido";

    cout << "Creando Espacio de Mensaje" << endl;
    PaqueteDatagrama msgclient(18);
    cout << "Espacio de Mensaje Creado" << endl;

    cout << "Creando Socket SERVER" << endl;
    SocketDatagrama serverAddr(7200);
    cout << "Socket server Creado" << endl;

    while(1){
        cout << "Esperando CLIENTE" << endl;
        serverAddr.recibe(msgclient);
        cout << "Mensaje: " << msgclient.obtieneDatos() << msgclient.obtieneDireccion() << endl;
        msgclient.inicializaDatos(dato);
        cout << "Envia mensake al CLIENTE" << endl;
        serverAddr.envia(msgclient);
    }
}