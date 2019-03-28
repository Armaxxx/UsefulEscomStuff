#include "SocketDatagrama.h"
#include "Solicitud.h"
#include "mensaje.h"

Solicitud::Solicitud() {
	socketlocal = new SocketDatagrama(0);
}

char * Solicitud::doOperation(char* IP, int puerto, int operationId, char* arguments) {

	
	struct mensaje msj;
	msj.messageType = 0;

	msj.requestId = id;

	id++;

	memcpy(msj.IP, IP, 16);

	msj.puerto = puerto;
	msj.operationId = operationId;
	//cout << "numero: " << operationId << endl;
	cout << "Id operacion: " << msj.operationId << endl;
	//cout << "ip: " << IP << endl;
	cout << "ip: " << msj.IP << endl;
	memcpy(msj.arguments, arguments, 100);
	//cout << "puerto: " << puerto << endl;
	cout << "puerto: " << msj.puerto << endl;
	//cout << "argumentos: " << arguments << endl;
	cout << "argumentos: " << msj.arguments << endl;




	//SocketDatagrama socket(puerto);
	PaqueteDatagrama paq((char*) &msj, sizeof(msj), IP, puerto);

	socketlocal->envia(paq);
	cout << "Llego a esta linea" << endl;

	PaqueteDatagrama paq1(sizeof(msj));
	socketlocal->recibe(paq1);



	char* resultado;
	resultado = paq1.obtieneDatos();

	cout << "resultado: " << resultado << endl;
	//cout << "resultado ip: " << resultado->IP << endl;
	
	return resultado;
}