#include "Solicitud.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    int puerto,operation, num,x;
    char IP[16], respuesta[TAM_MAX_DATA];
    Solicitud cliente;
    char *one = "1";

    strcpy(IP,argv[1]);
    puerto = atoi(argv[2]);
    operation = atoi(argv[3]);
    num = atoi(argv[4]);
    if(operation == 2){
        for(x = 0; x < num; x++){
            memcpy(respuesta,cliente.doOperation(IP, puerto, operation, one),sizeof(int));
            cout << "La respuesta del servidor es: " << atoi(respuesta) << endl;
        }
    }else{
        memcpy(respuesta,cliente.doOperation(IP, puerto, operation, (char*)&num),sizeof(int));
        cout << "La respuesta del servidor es: " << atoi(respuesta) << endl;
    }
    return 0;
}
