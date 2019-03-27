#include "SocketDatagrama.hpp"
using namespace std;

int puerto = 7200;

int main(void){
    unsigned int *num,x,*respuesta;
    respuesta = new unsigned int;
    num = new unsigned int[3];

    PaqueteDatagrama *msgclient, serverreply(sizeof(int));
    msgclient = new PaqueteDatagrama(3*sizeof(int));

    SocketDatagrama serverSocket(puerto);

    while(1){
        serverSocket.recibe(*msgclient);

        memcpy(num,msgclient->obtieneDatos(),3*sizeof(int));
        cout << "Recibido el numero " << num[0] << "\nDesde " << num[1] << " hasta " << num[2] << endl;
        serverreply.inicializaIp(msgclient->obtieneDireccion());
        serverreply.inicializaPuerto(msgclient->obtienePuerto());
        if(num[2] > num[1]){
            for(x = num[1]; x <= num[2]; x++){
                if(num[0] % x == 0){
                    *respuesta = 0;
                    break;
                }else
                    *respuesta = 1;
            }
        }else{
            *respuesta = 1;
        }

        serverreply.inicializaDatos((char*)respuesta);

        serverSocket.envia(serverreply);
    }
}