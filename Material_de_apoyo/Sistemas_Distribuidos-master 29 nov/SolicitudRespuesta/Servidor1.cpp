#include <stdlib.h>
#include "Respuesta.h"
#include <vector>
#include <string.h>
#include "mensaje.h"

using namespace std;

char* invertirPalabras(char* arreglo);

int main() {

	Respuesta respuesta(7200);
	
	while(1) {
		cout << "while" << endl;
		struct mensaje* msj;
		//memcpy(msj, respuesta.getRequest(), sizeof(struct mensaje));
		msj = respuesta.getRequest();
		cout << "id: " << msj->operationId << endl;
		cout << "mensaje: " << msj->arguments << endl;
		cout << "IP: " << msj->IP << endl;
		cout << "Tipo: " << msj->messageType << endl;
		cout << "puerto: " << msj->puerto << endl;
		switch(msj->operationId) {
			case 1:
				char *nuevo;
				nuevo = invertirPalabras(msj->arguments);
				cout << "send: " << nuevo << endl;
				respuesta.sendReply(nuevo, msj->IP, msj->puerto);

				break;
			default:
				cout << "Error en el numero de operación" << endl;
				cout << "numero: " << msj->operationId << endl;
				exit(-1);
		}
	}
	
	return 0;
}

char* invertirPalabras(char* arreglo) {

	int j = 0;
	char palabras[100][100];
	char palabra[20];
	char resultado[100];
	int l = 0;
	
	for (int i = 0; arreglo[i] != '\0'; i++) {
		if(arreglo[i] == ' ') {
			palabras[j][l] = ' ';
			j++;
			l = 0;
		} else {
			palabras[j][l] = arreglo[i];
			l++;
		}
	}
	l = 0;
	int m = 0;
	//cout << "palabra = " << palabras[10] << endl;
	for (int k = j-1; k >= 0; k--) {
		for (int i = 0; palabras[k][i] != ' '; i++) {
			resultado[l] = palabras[k][i];
			//cout << "letra: " << palabras[k][i] << endl;
			l++;
		}
		resultado[l] = ' ';
		l++;
	}
	cout << "l =" << l << endl;
	resultado[l] = '\0';
	cout << "arreglo invertido: " << resultado << endl;
	char *send;
	send = resultado;
	cout << "arreglo invertido: " << send << endl;
	return send;
}