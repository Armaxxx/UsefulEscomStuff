#include <stdio.h>
#include <stdlib.h>
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"

int main(int argc, char const *argv[])
{
    unsigned int numeroPrimo = atoi(argv[1]);
    //printf("%d", numeroPrimo);
    unsigned int contador =0;
    int rodrigo =0, aidee =0;

    unsigned int num[3];
    char ipRod[] = "10.100.76.215";
    char ipAidee[] = "10.100.74.178";
    char ipErick[] = "10.100.73.194";
    //Rodrigo
    SocketDatagrama socket;
    num[0] = numeroPrimo;
    num[1] = 2;
    num[2] = 3*(numeroPrimo/7); 
    int *resRod; //Debe recibir O no es primo o 1 si es primp    
    PaqueteDatagrama paqRod((char *)num, 3*sizeof(unsigned int),ipRod,7200);
    socket.envia(paqRod);
   //Aidee
    num[0] = numeroPrimo;
    num[1] = (3*(numeroPrimo/7))+1;
    num[2] = 4*(numeroPrimo/6);
    int *resAidee; //Debe recibir O o 1
    PaqueteDatagrama paqAidee((char *)num, 3*sizeof(unsigned int),ipAidee,7200);
    socket.envia(paqAidee);
   //Erick
    num[0] = numeroPrimo;
    num[1] = (4*(numeroPrimo/7))+1;
    num[2] = numeroPrimo-1;
    int *resErick; //Debe recibir O o 1
    PaqueteDatagrama paqErick((char *)num, 3*sizeof(unsigned int),ipErick,7200);
    socket.envia(paqErick);


    //Primera Respuesta
    PaqueteDatagrama paqRes1(sizeof(int));
    socket.recibe(paqRes1);
    resRod = (int *)paqRes1.obtieneDatos();
    std::cout << "Respuesta 1: " << *resRod << std::endl;
    //Segunda Respuesta
    PaqueteDatagrama paqRes2(sizeof(int));
    socket.recibe(paqRes2);
    resAidee = (int *)paqRes2.obtieneDatos();
    std::cout << "Respuesta 2: " << *resAidee << std::endl;
    //Tercera Respuesta
    PaqueteDatagrama paqRes3(sizeof(int));
    socket.recibe(paqRes3);
    resErick = (int *)paqRes3.obtieneDatos();
    std::cout << "Respuesta 3: " << *resErick << std::endl;


    if ((*resRod == 1) && (*resErick == 1) && (*resAidee == 1)){
        std::cout << "\n\nEs primo " << std::endl;
    }
    else{
        std::cout << "\n\nNo es primo " << std::endl;
    }
    return 0;
}
