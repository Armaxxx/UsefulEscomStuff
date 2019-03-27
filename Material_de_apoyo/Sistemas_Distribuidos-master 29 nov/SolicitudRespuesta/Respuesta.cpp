#include "SocketDatagrama.h"
#include "Respuesta.h"

Respuesta::Respuesta(int pl) {

	socketlocal = new SocketDatagrama(pl);

}

struct mensaje* Respuesta::getRequest() {

	struct mensaje *palabras;
	PaqueteDatagrama paq(sizeof(mensaje));
	socketlocal->recibe(paq);
	palabras = (struct mensaje*) paq.obtieneDatos();
	cout << "id: " <<  palabras->operationId << endl;
	cout << "argumentos: " <<  palabras->arguments << endl;
	cout << "IP: " << palabras->IP << endl;
	cout << "Tipo: " << palabras->messageType << endl;
	palabras->puerto = paq.obtienePuerto();
	cout << "puerto: " << palabras->puerto << endl;
	
	return palabras;
}

void Respuesta::sendReply(char * respuesta, char * ipCliente, int puertoCliente) {

	struct mensaje *m1;
	m1 = (struct mensaje *) respuesta;
	cout << "respuesta: " << m1->arguments << endl;
	cout << "ipCliente: " << ipCliente << endl;
	cout << "puertoCliente: " << puertoCliente << endl;
	PaqueteDatagrama paq((char*) m1, 100, ipCliente, puertoCliente);
	cout << "paq datos: " << paq.obtieneDatos() << endl;
	cout << "paq ip: " << paq.obtieneDireccion() << endl;
	socketlocal->envia(paq);

}