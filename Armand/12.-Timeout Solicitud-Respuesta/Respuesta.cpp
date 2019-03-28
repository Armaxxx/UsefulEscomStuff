#include "Respuesta.hpp"
using namespace std;

Respuesta::Respuesta(int port){
    socketlocal = new SocketDatagrama(port);    
}

struct mensaje *Respuesta::getRequest(){
    struct mensaje *msj;
    PaqueteDatagrama paquete(sizeof(struct mensaje));

	socketlocal->recibe(paquete);

	msj = (struct mensaje*) paquete.obtieneDatos();

    strcpy(msj->IP,paquete.obtieneDireccion());
    msj->puerto = paquete.obtienePuerto();

    cout << "Se recibe el mensaje con los datos:\n";
	cout << "\tTipo de mensaje: " << msj->messageType << endl;
	cout << "\tIdentificador de petición: " << msj->requestId << endl;
	cout << "\tIP y puerto: " << msj->IP << ":" << msj->puerto << endl;
	cout << "\tID de operación: " << msj->operationId << endl;
    cout << "\tArgumentos: " << msj->arguments << endl;
	
	return msj;
}

void Respuesta::sendReply(char *respuesta, char *ipCliente, int puertoCliente){

    PaqueteDatagrama paquete(respuesta, TAM_MAX_DATA, ipCliente, puertoCliente);

    cout << "Se prepara la respuesta:\n";
	cout << "\tArgumentos: " << atoi(respuesta) << endl;
	cout << "\tIP destino: " << ipCliente << ":" << puertoCliente << endl;

	socketlocal->envia(paquete);
    return;
}