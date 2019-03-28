#include "Respuesta.hpp"
using namespace std;

int puerto = 7200;

int main() {
  int ndb = 0;
  char *reply = (char*)malloc(TAM_MAX_DATA);
	Respuesta respuesta(puerto);
	while(1) {
		struct mensaje *msj;
    char * cadenaInversa;
		cout << "Servidor Inicializado..." << endl;

		memcpy(msj, respuesta.getRequest(), sizeof(struct mensaje));

        cout << "Peticion obtenida, el mensaje es:\n";
        cout << "\tTipo de mensaje: " << msj->messageType << endl;
        cout << "\tIdentificador de petición: " << msj->requestId << endl;
        cout << "\tIP y puerto: " << msj->IP << ":" << msj->puerto << endl;
        cout << "\tID de operación: " << msj->operationId << endl;
        cout << "\tArgumentos: " << msj->arguments << endl;

		switch(msj->operationId) {
			case 1:
				cout << "Operacion 1: Lectura\n";
        sprintf(reply,"%d",ndb);
				respuesta.sendReply((char*) reply, msj->IP, msj->puerto);
				cout << "Operación completada\n";
        break;
      case 2:
        cout << "Operacion 2: Escritura\n";
        ndb += atoi(msj->arguments);
        sprintf(reply,"%d",ndb);
        respuesta.sendReply(reply, msj->IP, msj->puerto);
        cout << "Operación completada\n";
        break;
			default:
				cout << "Número de operacion inexistente\n";
				cout << "Número: " << msj->operationId << endl;
				exit(-1);
		}
	}
	return 0;
}