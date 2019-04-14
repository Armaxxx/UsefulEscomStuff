#include "tftp.h"

int main(int argc, char **argv)
{
  int dominio = AF_INET, tipo = SOCK_DGRAM, protocolo = 0, puerto;
  struct host local, *remotos, servidor;
  char *direccionServidor;
  in_addr_t ipServidor;
  void *tmp_ptr;
  unsigned int codOp;
  memset(&local.dispositivoRed, 0x00, sizeof(struct sockaddr_in));
  memset(&servidor.dispositivoRed, 0x00, sizeof(struct sockaddr_in));
  if(!validarArgumentos(argc, argv))
  {
    printf("%s -(s|c) {-(r|w) <filename> -srv <AAA.BBB.CCC.DDD>} \n",argv[0]);
    exit(1);
  }
  if(argc == 6)
  {
    tmp_ptr = (char *)calloc(strlen(argv[3]), sizeof(char));
    if(tmp_ptr == NULL)
    {
      printf("calloc() [ERROR]\n");
      exit(1);
    }
    local.nombreFichero = tmp_ptr;
    strcpy(local.nombreFichero,argv[3]);
    local.longitudNombreFichero = strlen(local.nombreFichero);
    local.modoTransferencia = OCTET;
    local.longitudDatosFichero = 0;
    local.offset = 0;
    servidor.modoTransferencia = OCTET;
    servidor.dispositivoRed.sin_family = dominio;
    servidor.dispositivoRed.sin_addr.s_addr = inet_addr(argv[5]);
    servidor.dispositivoRed.sin_port = htons(puertoEscucha);
    puerto = 0;
    if(strcmp(argv[2], "-r") == 0)  codOp = RRQ;
    if(strcmp(argv[2], "-w") == 0)  codOp = WRQ;
  }
  if(argc == 2) puerto = puertoEscucha;
  if(establecerPuntoComunicacion(&local, dominio, tipo, protocolo, puerto))
  {
    printf("Punto de comunicacion [EXITO]\n");
    if(strcmp(argv[1], "-s") == 0)  modoServidor(&local);
    if(strcmp(argv[1], "-c") == 0)  modoCliente(&local, &servidor, codOp);
  }
  else  printf("Punto de comunicacion [ERROR]\n");
  return 0;
}
