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
acciones[0].xini=122;
acciones[0].yini=221;
acciones[0].axion='p';
acciones[0].color1=6;

fpt=fopen("c:p.p","wb");
fwrite(&acciones,sizeof(datos),1,fpt);
fclose(fpt);



  }
