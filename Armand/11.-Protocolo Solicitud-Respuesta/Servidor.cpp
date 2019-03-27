#include "Respuesta.hpp"
using namespace std;

char *reverse (char *data);
int puerto = 7200;

int main() {

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
				cout << "Operacion 1: Revertir cadena\n";

                strcpy(msj->arguments, reverse(msj->arguments));
                msj->messageType = 1;;

				respuesta.sendReply((char*) msj->arguments,msj->IP, msj->puerto);
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

char *reverse (char *data){
  string return_data (" "), word;
  size_t size_data = strlen(data);
  for (size_t i = 0;i < size_data+1;i++){
    unsigned char c = data[i];
    switch (c){
      default:
        word += c;
        break;
      case '\0':
      case '\n':
      case ' ':
        if(!word.empty ()){
          word += ' ';
          return_data.insert (0, word);
          word.clear();
        }
        break;
    }
  }
  char * resp = (char*)malloc (size_data);
  memcpy (resp,return_data.c_str(),size_data);
  return resp;
}