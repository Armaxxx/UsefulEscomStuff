#include "Solicitud.hpp"
using namespace std;

Solicitud::Solicitud(){
    socketlocal = new SocketDatagrama(0);
}

char *Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments){
    struct mensaje msj;
    char *resultado;
    PaqueteDatagrama *paquete;

	msj.messageType = 0;
	msj.requestId = id;
    strcpy(msj.IP, IP);
    msj.puerto = puerto;
	msj.operationId = operationId;
    strcpy(msj.arguments, arguments);

	id++;

    cout << "Se crea el mensaje con los datos:\n";
	cout << "\tTipo de mensaje: " << msj.messageType << endl;
	cout << "\tIdentificador de petición: " << msj.requestId << endl;
	cout << "\tIP y puerto: " << msj.IP << ":" << msj.puerto << endl;
	cout << "\tID de operación: " << msj.operationId << endl;
    cout << "\tArgumentos: " << msj.arguments << endl;

    paquete = new PaqueteDatagrama((char*)&msj, sizeof(struct mensaje), IP, puerto);

	socketlocal->envia(*paquete);

	paquete = new PaqueteDatagrama(TAM_MAX_DATA);

	socketlocal->recibe(*paquete);

    resultado = (char*)malloc(TAM_MAX_DATA);
	memcpy(resultado, paquete->obtieneDatos(),TAM_MAX_DATA);

	cout << "La respuesta fue: " << resultado << endl;
	
	return resultado;
}