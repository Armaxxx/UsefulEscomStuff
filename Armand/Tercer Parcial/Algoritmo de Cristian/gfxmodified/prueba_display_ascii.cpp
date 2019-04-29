#include <iostream>
#include <string.h>
#include <cmath>
#include "gfxModified.h"
#include <unistd.h>

using namespace std;

//Resolución de la pantalla
#define ANCHURA 800
#define ALTURA 600

int main()
{
    int i, contador;

    gfx_open(ANCHURA, ALTURA, "Ejemplo gfx_display_ascii");
    while(1) {
        gfx_color(87,1,2);
        for (i = 48; i < 58; i++){
            cout << "ASCII = " << i << endl;
            gfx_clear();
            gfx_display_ascii(10, 20, 30 , i);
            gfx_flush();
            sleep(1);
        }

        for (i = 65; i < 91; i++){            
            cout << "ASCII = " << i << endl;
            gfx_clear();
            gfx_display_ascii(30, 10 , 10, i);
            gfx_flush();            
            sleep(1);
        }
    }
}