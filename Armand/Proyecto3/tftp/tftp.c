#include "tftp.h"

void aMinusculas(char *cadena, unsigned int longitudCadena)
{
  unsigned int i;
  for(i = 0; i < longitudCadena; i++)
    cadena[i] = tolower(cadena[i]);
}

void aMayusculas(char *cadena, unsigned int longitudCadena)
{
  unsigned int i;
  for(i = 0; i < longitudCadena; i++)
    cadena[i] = toupper(cadena[i]);
}

bool enviarTrama(char *trama, unsigned int longitudTrama, struct host *local, struct host *remoto, int bandera)
{
  bool flg = false;
  int n = sendto(local->descriptorSocket, trama, longitudTrama, bandera, (struct sockaddr *)&remoto->dispositivoRed, sizeof(struct sockaddr_in));
  if(n == -1) perror("sendto()");
  else
    if(n == longitudTrama)  flg = true;
  return flg;
}

bool recibirTrama(char *trama, unsigned int longitudTrama, struct host *local, struct host *remoto, int bandera, int *res)
{
  bool flg = false;
  int cO;
  char *msg;
  unsigned int k;
  socklen_t sa_len = sizeof(struct sockaddr_in);
  *res = recvfrom(local->descriptorSocket, trama, longitudTrama, bandera, (struct sockaddr *)&remoto->dispositivoRed, &sa_len);
  if(*res == -1)  perror("recvfrom()");
  else
  {
    memcpy(&cO, trama, 2*sizeof(char));
    cO = ntohs(cO);
    if(cO < RRQ || cO > ERR)
    {
      msg = MSG_ERR_ILL;
      k = formarTramaERR(trama, ERR_ILL, msg, strlen(msg));
      if(k > 0) enviarTrama(trama, k, local, remoto, MSG_DONTWAIT);
      exit(1);
    }
    else if(cO == ERR)
    {
      interpretarTramaERR(trama, *res, local, remoto);
      exit(1);
    }
    else  flg = true;
  }
  return flg;
}

void imprimirTrama(char *trama, unsigned int longitudTrama)
{
  unsigned int i;
  printf("Bytes: %d",longitudTrama);
  for(i = 0; i < longitudTrama; i++)
	{
		if(i % 16 == 0) printf("\n");
		printf("%.2x",trama[i]);
	}
	printf("\n");
}

unsigned int formarTramaRQ(char *trama, struct host *local, unsigned int modoTransferencia, unsigned int codOp)
{
  unsigned int n = 0;
  char *msg;
  int cO = htons(codOp);
  if((codOp == RRQ || codOp == WRQ) && (modoTransferencia == OCTET || modoTransferencia == NETASCII))
  {
    memcpy(trama+n, &cO, 2*sizeof(char));
    n += 2*sizeof(char);
    memcpy(trama+n, local->nombreFichero, local->longitudNombreFichero*sizeof(char));
    n += local->longitudNombreFichero*sizeof(char);
    memset(trama+n, 0x00, sizeof(char));
    n += sizeof(char);
    if(modoTransferencia == OCTET)  msg = MSG_OCTET;
    else if(modoTransferencia == NETASCII)  msg = MSG_NETASCII;
    memcpy(trama+n, msg, strlen(msg)*sizeof(char));
    n += (unsigned int)(strlen(msg)*sizeof(char));
    memset(trama+n, 0x00, sizeof(char));
    n += sizeof(char);
  }
  return n;
}

unsigned int formarTramaDT(char *trama, char *datos, unsigned int longitudDatos, unsigned int numeroBloque)
{
  unsigned int n = 0, numBloq;
  numBloq = htons(numeroBloque);
  unsigned short int codOp = htons(DAT);
  if(numeroBloque >= 0)
  {
    memcpy(trama+n, &codOp, 2*sizeof(char));
    n += 2*sizeof(char);
    memcpy(trama+n, &numBloq, 2*sizeof(char));
    n += 2*sizeof(char);
    memcpy(trama+n, datos, longitudDatos*sizeof(char));
    n += longitudDatos*sizeof(char);
  }
  return n;
}

unsigned int formarTramaACK(char *trama, unsigned int numeroBloque)
{
  unsigned int n = 0, numBloq = htons(numeroBloque);
  unsigned short int codOp = htons(ACK);
  if(numeroBloque >= 0)
  {
    memcpy(trama+n, &codOp, 2*sizeof(char));
    n += 2*sizeof(char);
    memcpy(trama+n, &numBloq, 2*sizeof(char));
    n += 2*sizeof(char);
  }
  return n;
}

unsigned int formarTramaERR(char *trama, unsigned int codigoError, char *mensajeError, unsigned int longitudMensaje)
{
  unsigned int n = 0, codE = htons(codigoError);
  unsigned short int codOp = htons(ERR);
  if(codigoError >= ERR_NDEF && codigoError <= ERR_NUSR)
  {
    memcpy(trama+n, &codOp, 2*sizeof(char));
    n += 2*sizeof(char);
    memcpy(trama+n, &codE, 2*sizeof(char));
    n += 2*sizeof(char);
    memcpy(trama+n, mensajeError, longitudMensaje*sizeof(char));
    n += longitudMensaje*sizeof(char);
    memset(trama+n, 0x00, sizeof(char));
    n += sizeof(char);
  }
  return n;
}

bool interpretarTramaRQ(char *trama, unsigned int longitudTrama, unsigned int *codOp, struct host *local, struct host *remoto)
{
  bool flg = false;
  unsigned int n = 0, i, k;
  char *modTrans, *msg;
  int cO;
  memcpy(&cO, trama+n, 2*sizeof(char));
  cO = ntohs(cO);
  n += 2*sizeof(char);
  if((cO == RRQ || cO == WRQ) && longitudTrama > 4 && trama[longitudTrama-1] == '\0')
  {
    *codOp = cO;
    for(i = 2; i < longitudTrama-1; i++)
      if(trama[i] == '\0')  break;
    if(i != longitudTrama-2)
    {
      if((remoto->nombreFichero = (char *)calloc((i-2),sizeof(char))) == NULL)
      {
        printf("calloc() [ERROR]\n");
        exit(1);
      }
      remoto->longitudNombreFichero = (i-2);
      strncpy(remoto->nombreFichero, trama+n, remoto->longitudNombreFichero*sizeof(char));
      remoto->nombreFichero[remoto->longitudNombreFichero] = '\0';
      if((local->nombreFichero = (char *)calloc((i-2),sizeof(char))) == NULL)
      {
        printf("calloc() [ERROR]\n");
        exit(1);
      }
      local->longitudNombreFichero = (i-2);
      strncpy(local->nombreFichero, trama+n, local->longitudNombreFichero*sizeof(char));
      local->nombreFichero[local->longitudNombreFichero] = '\0';
      n += local->longitudNombreFichero*sizeof(char);
      n++;
      if((modTrans = (char *)calloc(i-1,sizeof(char))) == NULL)
      {
        printf("calloc() [ERROR]\n");
        exit(1);
      }
      memcpy(modTrans, trama+n, (longitudTrama-(i+1))*sizeof(char));
      n += (longitudTrama-(i+1))*sizeof(char);
      aMinusculas(modTrans, strlen(modTrans));
      if(strcmp(modTrans, MSG_OCTET) == 0)  remoto->modoTransferencia = OCTET;
      else if(strcmp(modTrans, MSG_NETASCII) == 0)  remoto->modoTransferencia = NETASCII;
      n++;
      flg = true;
    }
  }
  return flg;
}

bool interpretarTramaDT(char *trama, unsigned int longitudTrama, char *datos, unsigned int *longitudDatos, unsigned int *numeroBloque, struct host *local, struct host *remoto)
{
  bool flg = false;
  unsigned int n = 0, k, numBloq;
  int cO;
  char *msg;
  memcpy(&cO, trama+n, 2*sizeof(char));
  cO = ntohs(cO);
  n += 2*sizeof(char);
  if(cO == DAT)
  {
    memcpy(&numBloq, trama+n, 2*sizeof(char));
    n += 2*sizeof(char);
    if((*numeroBloque = ntohs(numBloq)) >= 1)
    {
      if((*longitudDatos = (longitudTrama - n)) <= LEN_DATA)
      {
        memset(datos, 0x00, LEN_DATA*sizeof(char));
        memcpy(datos, trama+n, *longitudDatos*sizeof(char));
        n += *longitudDatos*sizeof(char);
        flg = true;
      }
    }
  }
  return flg;
}

bool interpretarTramaACK(char *trama, unsigned int longitudTrama, unsigned int *numeroBloque, struct host *local, struct host *remoto)
{
  bool flg = false;
  unsigned int n = 0, k;
  int numBloq;
  char *msg;
  int cO;
  memcpy(&cO, trama+n, 2*sizeof(char));
  cO = ntohs(cO);
  n += 2*sizeof(char);
  if(cO == ACK)
  {
    memcpy(&numBloq, trama+n, 2*sizeof(char));
    n += 2*sizeof(char);
    if((*numeroBloque = ntohs(numBloq)) >= 0) flg = true;
    else
    {
      msg = MSG_ERR_UNKID;
      k = formarTramaERR(trama, ERR_UNKID, msg, strlen(msg));
      if(k > 0) enviarTrama(trama, k, local, remoto, MSG_DONTWAIT);
    }
  }
  return flg;
}

bool interpretarTramaERR(char *trama, unsigned int longitudTrama, struct host *local, struct host *remoto)
{
  bool flg = false;
  unsigned int n = 0, k, longitudMensaje;
  int cO, cE;
  char *mensajeError;
  memcpy(&cO, trama+n, 2*sizeof(char));
  cO = ntohs(cO);
  n += 2*sizeof(char);
  if(cO == ERR && trama[longitudTrama-1] == '\0')
  {
    memcpy(&cE, trama+n, 2*sizeof(char));
    n += 2*sizeof(char);
    if(ntohs(cE) >= ERR_NDEF && ntohs(cE) <= ERR_NUSR)
    {
      longitudMensaje = (longitudTrama - 5);
      if((mensajeError = (char *)calloc(longitudMensaje, sizeof(char))) == NULL)
      {
        printf("calloc() [ERROR]\n");
        exit(1);
      }
      memcpy(mensajeError, trama+n, longitudMensaje*sizeof(char));
      printf("CODIGO [%d]\t%s\n",ntohs(cE),mensajeError);
      n += longitudMensaje*sizeof(char);
      flg = true;
    }
  }
  return flg;
}

void modoCliente(struct host *local, struct host *servidor, unsigned int codOp)
{
  char tramaLocal[MAX_BUFFER], tramaRemota[MAX_BUFFER], datos[LEN_DATA], *msg;
  unsigned int longitudDatos, numeroBloque, esperadoR = 1, esperadoW = 0, n, i;
  int res, tmp;
  struct host aux;
  memset(&aux, 0x00, sizeof(struct host));
  memset(tramaLocal, 0x00, MAX_BUFFER*sizeof(char));
  memset(tramaRemota, 0x00, MAX_BUFFER*sizeof(char));
  printf("Ejecutando en modo Cliente.\n");
  n = formarTramaRQ(tramaLocal, local, OCTET, codOp);
  if(n > 0)
  {
    if(enviarTrama(tramaLocal, n, local, servidor, 0))
    {
      if(recibirTrama(tramaRemota, MAX_BUFFER, local, &aux, 0, &res))
      {
        servidor->dispositivoRed.sin_port = aux.dispositivoRed.sin_port;
        if(codOp == RRQ)
        {
          if((local->fichero = fopen(local->nombreFichero, "wb")) == NULL)
          {
            perror("fopen() ");
            exit(1);
          }
          do
          {
            if(interpretarTramaDT(tramaRemota, res, datos, &longitudDatos, &numeroBloque, local, servidor))
            {
              if(numeroBloque == esperadoR)
              {
                escribirDatos(datos,longitudDatos,local);
                n = formarTramaACK(tramaLocal, numeroBloque);
                if(n > 0)
                {
                  if(enviarTrama(tramaLocal, n, local, servidor, 0))
                  {
                    if(longitudDatos < LEN_DATA)  break;
                    else  if(recibirTrama(tramaRemota, MAX_BUFFER, local, servidor, 0, &res))
                      if(esperadoR != 65355)  esperadoR++;
                      else esperadoR = 0;
                  }
                }
              }
              else if(numeroBloque == esperadoR - 1)
              {
                esperadoR--;
                n = formarTramaACK(tramaLocal, numeroBloque);
                if(n > 0)
                  if(enviarTrama(tramaLocal, n, local, servidor, 0))
                    if(recibirTrama(tramaRemota, MAX_BUFFER, local, servidor, 0, &res))
                      if(esperadoR != 65355)  esperadoR++;
                      else esperadoR = 0;
              }
              else
              {
                msg = MSG_ERR_UNKID;
                n = formarTramaERR(tramaLocal, ERR_UNKID, msg, strlen(msg));
                if(n > 0) enviarTrama(tramaLocal, n, local, servidor, MSG_DONTWAIT);
                exit(1);
              }
            }
            else
            {
              msg = MSG_ERR_ILL;
              n = formarTramaERR(tramaLocal, ERR_ILL, msg, strlen(msg));
              if(n > 0) enviarTrama(tramaLocal, n, local, servidor, MSG_DONTWAIT);
              exit(1);
            }
          }while(true);
          fclose(local->fichero);
        }
        else if(codOp == WRQ)
        {
          if((local->fichero = fopen(local->nombreFichero, "r")) == NULL)
          {
            perror("fopen() ");
            exit(1);
          }
          fseek(local->fichero, 0L, SEEK_END);
          local->longitudDatosFichero = ftell(local->fichero);
          rewind(local->fichero);
          do
          {
            if(interpretarTramaACK(tramaRemota, res, &numeroBloque, local, servidor))
            {
              if(numeroBloque == esperadoW)
              {
                longitudDatos = leerDatos(datos,local);
                if(esperadoW == 65355)  tmp = 0;
                else tmp = esperadoW+1;
                n = formarTramaDT(tramaLocal, datos, longitudDatos, tmp);
                if(n > 0)
                {
                  if(enviarTrama(tramaLocal, n, local, servidor, 0))
                  {
                    if(longitudDatos < LEN_DATA)  break;
                    else  if(recibirTrama(tramaRemota, MAX_BUFFER, local, servidor, 0, &res))
                      if(esperadoW != 65355)  esperadoW++;
                      else esperadoW = 0;
                  }
                }
              }
              else if(numeroBloque  ==  esperadoW -1)
              {
                esperadoW--;
                if(n > 0)
                  if(enviarTrama(tramaLocal, n, local, servidor, 0))
                    if(recibirTrama(tramaRemota, MAX_BUFFER, local, servidor, 0, &res))
                      if(esperadoW != 65355)  esperadoW++;
                      else esperadoW = 0;
              }
              else
              {
                msg = MSG_ERR_UNKID;
                n = formarTramaERR(tramaLocal, ERR_UNKID, msg, strlen(msg));
                if(n > 0) enviarTrama(tramaLocal, n, local, servidor, MSG_DONTWAIT);
                exit(1);
              }
            }
            else
            {
              msg = MSG_ERR_ILL;
              n = formarTramaERR(tramaLocal, ERR_ILL, msg, strlen(msg));
              if(n > 0) enviarTrama(tramaLocal, n, local, servidor, MSG_DONTWAIT);
              exit(1);
            }
          }while(true);
          fclose(local->fichero);
        }
      }
    }
  }
}

bool existeArchivo(char *fileName)
{
  bool flg = false;
  FILE *archivo = fopen(fileName, "r");
  if(archivo != NULL)
  {
    fclose(archivo);
    flg = true;
  }
  return flg;
}

void escribirDatos(char *datos, unsigned int longitudDatos, struct host *dispositivo)
{
  if(longitudDatos <= LEN_DATA)
  {
    //printf("LONGITUD ACTUAL FICHERO: %u\tOFFSET ANTES ESCRITURA: %u\n", dispositivo->longitudDatosFichero, dispositivo->offset);
    if(fwrite(datos, sizeof(char), longitudDatos, dispositivo->fichero) == longitudDatos)
    {
      dispositivo->offset += longitudDatos;
      dispositivo->longitudDatosFichero += longitudDatos;
    }
    //printf("DATOS ESCRITOS: %u\tOFFSET DESPUES ESCRITURA: %u\n", longitudDatos, dispositivo->offset);
  }
  else
  {
    printf("fwrite() [ERROR]\n");
    exit(1);
  }
}

unsigned int leerDatos(char *datos, struct host *dispositivo)
{
  unsigned int len = 0;
  //printf("LONGITUD TOTAL FICHERO: %u\tOFFSET ANTES LECTURA: %u\n",dispositivo->longitudDatosFichero,dispositivo->offset);
  if((dispositivo->longitudDatosFichero - dispositivo->offset) <= LEN_DATA)  len = (dispositivo->longitudDatosFichero - dispositivo->offset);
  else  len = LEN_DATA;
  memset(datos, 0x00, LEN_DATA*sizeof(char));
  if(fread(datos, sizeof(char), len, dispositivo->fichero) == len)
  {
    dispositivo->offset += len;
    //printf("DATOS A ENVIAR: %u\tOFFSET DESPUES LECTURA: %u\n",len,dispositivo->offset);
  }
  return len;
}

void modoServidor(struct host *local)
{
  char tramaLocal[MAX_BUFFER], tramaRemota[MAX_BUFFER], datos[LEN_DATA], *msg;
  unsigned int longitudDatos, numeroBloque, esperadoR = 0, esperadoW = 0, n = 0, i, codOp;
  int res, tmp;
  struct host cliente;
  memset(&cliente, 0x00, sizeof(struct host));
  memset(tramaLocal, 0x00, MAX_BUFFER*sizeof(char));
  memset(tramaRemota, 0x00, MAX_BUFFER*sizeof(char));
  printf("Ejecutando en modo Servidor.\n");
  if(recibirTrama(tramaRemota, MAX_BUFFER, local, &cliente, 0, &res))
  {
    if(interpretarTramaRQ(tramaRemota, res, &codOp, local, &cliente))
    {
      if(codOp == RRQ)
      {
        printf("Peticion lectura\n");
        if(existeArchivo(local->nombreFichero))
        {
          if((local->fichero = fopen(local->nombreFichero, "r")) == NULL)
          {
            perror("fopen() ");
            exit(1);
          }
          fseek(local->fichero, 0L, SEEK_END);
          local->longitudDatosFichero = ftell(local->fichero);
          rewind(local->fichero);
          res = MAX_BUFFER;
          do
          {
            if(esperadoR == 0)
            {
              longitudDatos = leerDatos(datos,local);
              if(esperadoR == 65355)  tmp = 0;
                else tmp = esperadoR+1;
              n = formarTramaDT(tramaLocal, datos, longitudDatos, tmp);
              if(n > 0)
              {
                if(enviarTrama(tramaLocal, n, local, &cliente, 0))
                {
                  if(longitudDatos < LEN_DATA)  break;
                  else if(recibirTrama(tramaRemota, MAX_BUFFER, local, &cliente, 0, &res))
                    if(esperadoR != 65355)  esperadoR++;
                    else esperadoR = 0;
                }
              }
            }
            else if(esperadoR >= 0)
            {
              if(interpretarTramaACK(tramaRemota, res, &numeroBloque, local, &cliente))
              {
                if(numeroBloque == esperadoR)
                {
                  longitudDatos = leerDatos(datos,local);
                  if(esperadoR == 65355)  tmp = 0;
               		else tmp = esperadoR+1;
                  n = formarTramaDT(tramaLocal, datos, longitudDatos, tmp);
                  if(n > 0)
                  {
                    if(enviarTrama(tramaLocal, n, local, &cliente, 0))
                    {
                      if(longitudDatos < LEN_DATA)  break;
                      else if(recibirTrama(tramaRemota, MAX_BUFFER, local, &cliente, 0, &res))
                        if(esperadoR != 65355)  esperadoR++;
                        else esperadoR = 0;
                    }
                  }
                }
                else if(numeroBloque == esperadoR - 1)
                {
                  esperadoR--;
                  if(n > 0)
                    if(enviarTrama(tramaLocal, n, local, &cliente, 0))
                      if(recibirTrama(tramaRemota, MAX_BUFFER, local, &cliente, 0, &res))
                        if(esperadoR != 65355)  esperadoR++;
                        else esperadoR = 0;
                }
                else
                {
                  msg = MSG_ERR_UNKID;
                  n = formarTramaERR(tramaLocal, ERR_UNKID, msg, strlen(msg));
                  if(n > 0) enviarTrama(tramaLocal, n, local, &cliente, MSG_DONTWAIT);
                  exit(1);
                }
              }
            }
          }while(true);
        }
        else
        {
          msg = MSG_ERR_NEXT;
          n = formarTramaERR(tramaLocal, ERR_NEXT, msg, strlen(msg));
          if(n > 0) enviarTrama(tramaLocal, n, local, &cliente, MSG_DONTWAIT);
          exit(1);
        }
      }
      else if(codOp == WRQ)
      {
        printf("Peticion escritura\n");
        if(existeArchivo(local->nombreFichero))
        {
          msg = MSG_ERR_YEXT;
          n = formarTramaERR(tramaLocal, ERR_YEXT, msg, strlen(msg));
          if(n > 0) enviarTrama(tramaLocal, n, local, &cliente, MSG_DONTWAIT);
          exit(1);
        }
        else
        {
          if((local->fichero = fopen(local->nombreFichero, "wb")) == NULL)
          {
            perror("fopen() ");
            exit(1);
          }
          n = formarTramaACK(tramaLocal, esperadoW);
          if(n > 0)
            if(enviarTrama(tramaLocal, n, local, &cliente, 0))
              if(recibirTrama(tramaRemota, MAX_BUFFER, local, &cliente, 0, &res))
                if(esperadoW != 65355)  esperadoW++;
                else esperadoW = 0;
          do
          {
            if(interpretarTramaDT(tramaRemota, res, datos, &longitudDatos, &numeroBloque, local, &cliente))
            {
              if(numeroBloque == esperadoW)
              {
                escribirDatos(datos, longitudDatos, local);
                n = formarTramaACK(tramaLocal, esperadoW);
                if(n > 0)
                {
                  if(enviarTrama(tramaLocal, n, local, &cliente, 0))
                  {
                    if(longitudDatos < LEN_DATA)  break;
                    else if(recibirTrama(tramaRemota, MAX_BUFFER, local, &cliente, 0, &res))
                      if(esperadoW != 65355)  esperadoW++;
                      else esperadoW = 0;
                  }
                }
              }
              else if(numeroBloque == esperadoW - 1)
              {
                esperadoW--;
                if(n > 0)
                  if(enviarTrama(tramaLocal, n, local, &cliente, 0))
                    if(recibirTrama(tramaRemota, MAX_BUFFER, local, &cliente, 0, &res))
                      if(esperadoW != 65355)  esperadoW++;
                      else esperadoW = 0;
              }
              else
              {
                msg = MSG_ERR_UNKID;
                n = formarTramaERR(tramaLocal, ERR_UNKID, msg, strlen(msg));
                if(n > 0) enviarTrama(tramaLocal, n, local, &cliente, MSG_DONTWAIT);
                exit(1);
              }
            }
          }while(true);
          fclose(local->fichero);
        }
      }
      else
      {
        msg = MSG_ERR_NEXT;
        n = formarTramaERR(tramaLocal, ERR_NEXT, msg, strlen(msg));
        if(n > 0) enviarTrama(tramaLocal, n, local, &cliente, MSG_DONTWAIT);
        exit(1);
      }
    }
  }
}

bool establecerPuntoComunicacion(struct host *d, int dominio, int tipo, int protocolo, int puerto)
{
  bool flg = false;
  d->dispositivoRed.sin_family = dominio;
  d->dispositivoRed.sin_addr.s_addr = INADDR_ANY;
  d->dispositivoRed.sin_port = htons(puerto);
  d->descriptorSocket = socket(dominio, tipo, protocolo);
  if(d->descriptorSocket == -1) perror("socket() [ERROR]");
  else
    if(bind(d->descriptorSocket, (struct sockaddr *)&d->dispositivoRed, sizeof(struct sockaddr_in)) < 0)  perror("bind() [ERROR]");
    else  flg = true;
  return flg;
}

bool validarArgumentos(int argc, char **argv)
{
  bool flg = false;
  unsigned int i;
  if(argc == 2)
  if(strcmp(argv[1], "-s") == 0)
    flg = true;
  if(argc == 6)
  {
    if(strcmp(argv[1], "-c") == 0)
    {
      if(strcmp(argv[2], "-r") == 0 || strcmp(argv[2], "-w") == 0)
      {
        if(strlen(argv[3]) <= 255)
          for(i = 0; i < strlen(argv[3]); i++)
            if(argv[3][i] == '/' || (argv[3][i] == '\\' && argv[3][i+1] == '0'))  return flg;
        if(strcmp(argv[4], "-srv") == 0)
          if(inet_addr(argv[5]) != INADDR_NONE) flg = true;
      }
    }
  }
  return flg;
}
