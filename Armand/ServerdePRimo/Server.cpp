#include "SocketDatagrama.hpp"
using namespace std;

int puerto = 7200;

int main(void){
    int *num,x,*respuesta;
    respuesta = new int;
    num = new int[3];
    cout << "Inicializa el SERVER" << endl;

    cout << "Creando Espacio de Mensaje" << endl;
    PaqueteDatagrama *msgclient, serverreply(sizeof(int));
    msgclient = new PaqueteDatagrama(3*sizeof(int));
    cout << "Espacio de Mensaje Creado" << endl;

    cout << "Creando Socket SERVER" << endl;
    SocketDatagrama serverSocket(puerto);
    cout << "Socket server Creado" << endl;

    while(1){
        cout << "Esperando CLIENTE" << endl;
        serverSocket.recibe(*msgclient);

        memcpy(num,msgclient->obtieneDatos(),3*sizeof(int));
        cout << "Recibido el numero " << num[0] << "\nDesde " << num[1] << " hasta " << num[2] << endl;
        serverreply.inicializaIp(msgclient->obtieneDireccion());
        serverreply.inicializaPuerto(msgclient->obtienePuerto());
        cout << "Respuesta inicializada con\nIP: " <<  serverreply.obtieneDireccion() << "\nPuerto: " << serverreply.obtienePuerto() << endl;
        if(num[2] > num[1]){
            cout << num[2] << " es mayor que " << num[1] << endl;
            for(x = num[1]; x <= num[2]; x++){
                cout << num[0] << "%" << x << " = " << num[0] % x << endl;
                if(num[0] % x == 0){
                    *respuesta = 0;
                    break;
                }else
                    *respuesta = 1;
            }
            cout << "Sale del for\n";
        }else{
            *respuesta = 1;
        }

        cout << "Inicializa datos con el resultado = " << *respuesta << endl;
        serverreply.inicializaDatos((char*)respuesta);

        cout << "Envia mensake al CLIENTE" << endl;
        serverSocket.envia(serverreply);
    }
}