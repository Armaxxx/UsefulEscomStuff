#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

#ifndef TFTP_H
#define TFTP_H
  #define RRQ 1
  #define WRQ 2
  #define DAT 3
  #define ACK 4
  #define ERR 5

  #define OCTET 1
  #define NETASCII 2
  #define MSG_OCTET "octet"
  #define MSG_NETASCII "netascii"

  #define ERR_NDEF 0
  #define ERR_NEXT 1
  #define ERR_ACCS 2
  #define ERR_FULL 3
  #define ERR_ILL 4
  #define ERR_UNKID 5
  #define ERR_YEXT 6
  #define ERR_NUSR 7
  #define MSG_ERR_NDEF "ERROR: Not defined."
  #define MSG_ERR_NEXT "ERROR: File not found."
  #define MSG_ERR_ACCS "ERROR: Access violation."
  #define MSG_ERR_FULL "ERROR: Disk full or allocation exceeded."
  #define MSG_ERR_ILL "ERROR: Illegal TFTP operation."
  #define MSG_ERR_UNKID "ERROR: Unknown transfer ID."
  #define MSG_ERR_YEXT "ERROR: File already exists."
  #define MSG_ERR_NUSR "ERROR: No such user."

  #define puertoEscucha 69
  #define LEN_DATA 512
  #define MAX_BUFFER 1024

  struct host
  {
    bool activo;
    int descriptorSocket;
    struct sockaddr_in dispositivoRed;
    unsigned int modoTransferencia;
    char *nombreFichero;
    unsigned int longitudNombreFichero;
    FILE *fichero;
    unsigned int longitudDatosFichero;
    unsigned int offset;
  };

  void aMinusculas(char *cadena, unsigned int longitudCadena);
  void aMayusculas(char *cadena, unsigned int longitudCadena);

  void imprimirTrama(char *trama, unsigned int longitudTrama);

  unsigned int formarTramaRQ(char *trama, struct host *local, unsigned int modoTransferencia, unsigned int codOp);
  unsigned int formarTramaDT(char *trama, char *datos, unsigned int longitudDatos, unsigned int numeroBloque);
  unsigned int formarTramaACK(char *trama, unsigned int numeroBloque);
  unsigned int formarTramaERR(char *trama, unsigned int codigoError, char *mensajeError, unsigned int longitudMensaje);

  bool interpretarTramaRQ(char *trama, unsigned int longitudTrama, unsigned int *codOp, struct host *local, struct host *remoto);
  bool interpretarTramaDT(char *trama, unsigned int longitudTrama, char *datos, unsigned int *longitudDatos, unsigned int *numeroBloque, struct host *local, struct host *remoto);
  bool interpretarTramaACK(char *trama, unsigned int longitudTrama, unsigned int *numeroBloque, struct host *local, struct host *remoto);
  bool interpretarTramaERR(char *trama, unsigned int longitudTrama, struct host *local, struct host *remoto);

  bool enviarTrama(char *trama, unsigned int longitudTrama, struct host *local, struct host *remoto, int bandera);
  bool recibirTrama(char *trama, unsigned int longitudTrama, struct host *local, struct host *remoto, int bandera, int *res);

  bool validarArgumentos(int argc, char **argv);
  bool establecerPuntoComunicacion(struct host *d, int dominio, int tipo, int protocolo, int puerto);

  void escribirDatos(char *datos, unsigned int longitudDatos, struct host *dispositivo);
  unsigned int leerDatos(char *datos, struct host *dispositivo);

  void modoCliente(struct host *local, struct host *servidor, unsigned int codOp);
  void modoServidor(struct host *local);
#endif
