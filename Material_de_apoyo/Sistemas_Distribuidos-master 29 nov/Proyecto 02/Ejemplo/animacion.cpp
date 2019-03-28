
#include <unistd.h>
#include "gfx.h"

using namespace std;
int main()
{
 int t;
 gfx_open(800, 600, "Ejemplo Micro Animacion GFX");
 gfx_color(0,200,100);
     for(;;){
         gfx_clear();
         //gfx_line( t*1+80, t*2+40, t*2+40, t*3+80 );
         //gfx_line(t*5+80, t*3+40, t*3+40, t*5+80);
        gfx_line(20,10,50,10); //30
        gfx_line(10,30,60,30); //50
        gfx_line(10,50,60,50); //50
        gfx_line(20,70,50,70); //30

        gfx_flush();
        usleep(41666); //24 por segundo
     }
 return 0;
}
