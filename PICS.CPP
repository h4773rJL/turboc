#include <graphics.h>
#include <conio.h>

void vgacard (); //inicializacion de graficos

void main ()
{
 vgacard();
 setcolor(WHITE);
 rectangle (0,0,639,479);
 setcolor(BLUE);
 rectangle (540,0,639,479);


 asm{ mov ax,0;
      int 33h;
      mov ax,1;
      int 33h;
    }

   getch();
  restorecrtmode();
}


void vgacard()
{int driver, mode;
 driver=DETECT;
 mode=0;
 initgraph(&driver,&mode,"BGI");
}
