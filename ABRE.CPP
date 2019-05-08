#include<stdlib.h>
//#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <string.h>
//#include <math.h>
//#define  null 0
struct datos1 {char name[80],ren[80];};
struct datos { int  xini,yini,xfin, yfin,color1,color2,inc,ctext;
	       char axion,cad[200];
	     };
const max=5;
 struct datos acciones[max];


 void main()
{
FILE *fpt;
char c,cad1[200];
int h=0,xi,yi,xf,yf,c1,c2;
struct datos1 arch;
fpt=fopen("c:p.p","rb");
fread(acciones,sizeof(acciones),1,fpt);
printf ("%i\n",acciones[0].xini);
printf ("%i\n",acciones[0].yini);
printf ("%i\n",acciones[0].color1);
printf ("%c\n",acciones[0].axion);
	getch();

  }
