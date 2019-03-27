#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"

int main()
{
    int num[2];
    char ip[] = "10.100.70.23";
    int *res;
    SocketDatagrama socket;
    num[0] = 2;
    num[1] = 5;
    PaqueteDatagrama paq((char *)num,2 * sizeof(int),ip,7200);
    socket.envia(paq);
    PaqueteDatagrama paq1(sizeof(int));
    socket.recibe(paq1);
    res = (int *)paq1.obtieneDatos();
    std::cout << "RESPUESTA: " << *res << std::endl;
    
    return 0;
}
