#include "Respuesta.hpp"
using namespace std;

char *reverse (char *data);
int puerto = 7200;

int main() {
  int fd;
  char name[TAM_MAX_DATA + 6];
  char repok[20] = "todo bien";
	Respuesta respuesta(puerto);
	
	while(1) {
		struct mensaje *msj;
		cout << "Servidor Inicializado..." << endl;
		memcpy(msj, respuesta.getRequest(), sizeof(struct mensaje));
    cout << "Peticion obtenida, el mensaje es:\n";
    cout << "\tTipo de mensaje: " << msj->messageType << endl;
    cout << "\tIdentificador de petición: " << msj->requestId << endl;
    cout << "\tIP y puerto: " << msj->IP << ":" << msj->puerto << endl;
    cout << "\tID de operación: " << msj->operationId << endl;
    sprintf(name,"FILES/%s",msj->arguments);
		switch(msj->operationId) {
			case 1:
				cout << "Operacion 1: Receive File\n";
        cout << "Se recibe: " << msj->arguments << endl;
        fd = open(name, O_RDWR | O_CREAT, 0666);
        strcpy(msj->arguments, repok);
        msj->messageType = 1;
				respuesta.sendReply((char*) msj->arguments,msj->IP, msj->puerto);
        memcpy(msj, respuesta.getRequest(), sizeof(struct mensaje));
        write(fd, msj->arguments, TAM_MAX_DATA);
        close(fd);
				cout << "Operación completada\n";
        break;
      case 2:
				cout << "Operacion 2: Send File\n";
        break;
			default:
				cout << "Número de operacion inexistente\n";
				cout << "Número: " << msj->operationId << endl;
				exit(-1);
		}
	}
	return 0;
}