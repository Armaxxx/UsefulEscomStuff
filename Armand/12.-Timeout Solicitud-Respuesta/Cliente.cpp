#include "Solicitud.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    int puerto, operation, num, x, ndb;
    char IP[16], respuesta[TAM_MAX_DATA], aux[TAM_MAX_DATA];
    Solicitud cliente;

    sprintf(aux,"%d",1);

    strcpy(IP,argv[1]);
    puerto = atoi(argv[2]);
    operation = atoi(argv[3]);
    num = atoi(argv[4]);
    if(operation == 2){
        memcpy(respuesta,cliente.doOperation(IP, puerto, 1, aux),sizeof(respuesta));
        ndb = atoi(respuesta);
        for(x = 0; x < num; x++){
            memcpy(respuesta,cliente.doOperation(IP, puerto, operation, aux),sizeof(respuesta));
            cout << "La respuesta del servidor es: " << atoi(respuesta) << endl;
            ndb++;
            memcpy(respuesta,cliente.doOperation(IP, puerto, 1, aux),sizeof(respuesta));
            if(ndb != atoi(respuesta)){
                cout << "Hubo un error\nValor esperado: " << ndb << "\nValor devuelto por server: " << respuesta << endl;
                return -1;;
            }
        }
    }else{
        sprintf(aux,"%d",num);
        memcpy(respuesta,cliente.doOperation(IP, puerto, operation, aux),sizeof(respuesta));
        cout << "La respuesta del servidor es: " << atoi(respuesta) << endl;
    }
    return 0;
}
