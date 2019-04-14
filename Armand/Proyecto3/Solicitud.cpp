#include "Solicitud.hpp"
using namespace std;
char *END_FLAG = "================END";
Solicitud::Solicitud(){
    socketlocal = new SocketDatagrama(0);
}

char *Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments){
	int fd,n;
	char buf[TAM_MAX_DATA];
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

    paquete = new PaqueteDatagrama((char*)&msj, sizeof(struct mensaje), IP, puerto);
	if( operationId == 1){
		socketlocal->envia(*paquete);
		fd = open(msj.arguments, O_RDONLY);
		paquete = new PaqueteDatagrama(TAM_MAX_DATA);
		socketlocal->recibe(*paquete);
		cout << paquete << endl;
		while ((n = read(fd, buf, TAM_MAX_DATA)) > 0) {
			strcpy(msj.arguments,buf);
			paquete = new PaqueteDatagrama((char*)&msj, sizeof(struct mensaje), IP, puerto);
			socketlocal->envia(*paquete);
		}
		strcpy(msj.arguments,END_FLAG);
		paquete = new PaqueteDatagrama((char*)&msj, sizeof(struct mensaje), IP, puerto);
		socketlocal->envia(*paquete);
	}

	cout << "La respuesta fue: " << resultado << endl;
	
	return resultado;
}