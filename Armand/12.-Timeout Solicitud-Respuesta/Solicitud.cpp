#include "Solicitud.hpp"
using namespace std;

Solicitud::Solicitud(){
    socketlocal = new SocketDatagrama(0);
	//id = 0;
}

char *Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments){
    struct mensaje msj;
	int x = 0;
	char* resultado;
    PaqueteDatagrama *paquete,*paquete2;
	msj.messageType = 0;
	//msj.requestId = id;
    strcpy(msj.IP, IP);
    msj.puerto = puerto;
	msj.operationId = operationId;
    strcpy(msj.arguments, arguments);

	//id++;

    cout << "Se crea el mensaje con los datos:\n";
	cout << "\tTipo de mensaje: " << msj.messageType << endl;
	//cout << "\tIdentificador de petición: " << msj.requestId << endl;
	cout << "\tIP y puerto: " << msj.IP << ":" << msj.puerto << endl;
	cout << "\tID de operación: " << msj.operationId << endl;
    cout << "\tArgumentos: " << atoi(msj.arguments) << endl;

    paquete = new PaqueteDatagrama((char*)&msj, sizeof(struct mensaje), IP, puerto);

	socketlocal->envia(*paquete);

	paquete2 = new PaqueteDatagrama(TAM_MAX_DATA);

	while(socketlocal->recibeTimeout(*paquete2,2,500000) < 0 && x < 7){
		socketlocal->envia(*paquete);
		x++;
	}

    resultado = (char*)malloc(TAM_MAX_DATA);
	memcpy(resultado, paquete2->obtieneDatos(),TAM_MAX_DATA);

	cout << "La respuesta fue: " << resultado << endl;
	
	return resultado;
}