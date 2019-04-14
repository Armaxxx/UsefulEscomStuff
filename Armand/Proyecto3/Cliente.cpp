#include "Solicitud.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    int puerto,operation;
    char cadena[TAM_MAX_DATA], IP[16], respuesta[TAM_MAX_DATA];
    Solicitud cliente;

    strcpy(IP,argv[1]);
    puerto = atoi(argv[2]);
    operation = atoi(argv[3]);
    strcpy(cadena,argv[4]);
    
    strcpy(respuesta,cliente.doOperation(IP, puerto, operation, cadena));

    cout << "La respuesta del servidor es: " << respuesta << endl;
    return 0;
}
