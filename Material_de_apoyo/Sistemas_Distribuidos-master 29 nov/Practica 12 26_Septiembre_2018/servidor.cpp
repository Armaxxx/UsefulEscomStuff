#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"

using namespace std;

int main()
{
    SocketDatagrama socket(7200);
    int *num;
    while (1) {
        PaqueteDatagrama paq(sizeof(num)*2);
        socket.recibe(paq);
        num = (int *)paq.obtieneDatos();
        int res = num[0] + num[1];
        cout << num[0] <<"+" << num[1] << "=" << res << endl;
        PaqueteDatagrama paq1((char *) &res,sizeof(int),paq.obtieneDireccion(),paq.obtienePuerto());
        socket.envia(paq1);
    }
    return 0;
}