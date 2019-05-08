#include <graphics.h>
#include <conio.h>
void borde(void);
void cuadro(int xinicial, int yinicial, int xfinal, int yfinal, int color);

main (void)
{ int controlador, modo;
 register int i;

 controlador=DETECT;
 modo=0;
 initgraph(&controlador,&modo,"BGI");

 borde();
 setcolor(1);
 line (0,0,639,349);
 cuadro(100,100,300,200,1);
 setcolor (2);
 floodfill(110,110,1);//rellen parte de un cuadro

 setcolor(1);
 line (50,200,400,125);
 //algunos puntos
 for (i=0; i<640; i+=10)
  putpixel(i,175,5);
  //dibuja varios circulos
  circle (50,50,35);
  circle (320,175,100);
  circle (500,250,90);
  circle (100,100,200);

  setfillstyle (SOLID_FILL,GREEN);
  floodfill(500,250,1); //rellena parte de un circulo

  getch(); //espera a que se pulse un tecla
  restorecrtmode();
  return (0);
  }
  void borde(void) //dibuja un borde al rededor de la pantalla para perspectiva
  { line (0,0,639,0);
    line (0,0,0,349);
    line (0,349,639,349);
    line (639,0,639,349);
  }

  void cuadro(int xinicial, int yinicial,int xfinal,int yfinal,int color)
  { setcolor(color);

   line(xinicial,yinicial,xinicial,yfinal);
   line(xinicial,yinicial,xfinal,yinicial);
   line(xfinal,yinicial,xfinal,yfinal);
   line(xfinal,yfinal,xinicial,yfinal);
   }