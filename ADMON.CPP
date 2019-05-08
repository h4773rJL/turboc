#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>
#define null 0
struct datos{char name[82],ren[82]; };
void crea();
void type();
void ren();
void copy();

void main()
{ char a;
do {
  clrscr();
gotoxy(12,4); printf ("** BIENVENIDO  AL MINI ADMINISTRADOR DE ARCHIVOS 'ANNY' **\n \n");
gotoxy(3,6);  printf (" 1.- CREA UN ARCHIVO \n");
gotoxy(3,7);  printf (" 2.- MUESTRA EL CONTENIDO DE UN ARCHIVO \n");
gotoxy(3,8);  printf (" 3.- RENOMBRAR UN ARCHIVO \n");
gotoxy(3,9);  printf (" 4.- COPIAR UN ARCHIVO \n");
gotoxy(3,10);  printf (" 5.- SALIR \n");
gotoxy(3,12); printf ("PULSA UN NUMERO SEGUN CONVENGA..");
	      scanf  (" %[12345]",&a);
  switch ( a )                {
      case '1': crea();
		break;
      case '2' :type();
		break;
      case '3' :ren();
		break;
      case '4' :copy();
		break;
			   }
   }
while (a!='5');
}


void crea()
{
clrscr();
FILE *fpt;
char c;
struct datos arch;
gotoxy(2,2);printf("HOLA!!!, HAS ELEGIDO LA OPCION DE CREAR UN ARCHIVO \n");
gotoxy(2,3);printf("QUE NOMBRE DESEAS PONERLE?.... ");
scanf("%s",arch.name);
clrscr();
gotoxy(2,1);printf("\n PARA FINALIZAR PRESIONA '*' y [ENTER]\n");
gotoxy(17,3);printf("ARCHIVO: %s \n",arch.name);
fpt =fopen(arch.name,"w");
do{
  putc(c=getchar(),fpt);}
  while (c!='*');
  fclose(fpt);
  delay(500);
  }

void type()  //contenido de archivo
{
 clrscr();
FILE *fpt;
char c;
struct datos arch;
gotoxy(2,2);
printf("\n HOLA!!! DAME EL NOMBRE DE UN ARCHIVO PARA MOSTRAR SU CONTENIDO \n");
scanf("%s",arch.name);
if ((fpt=fopen(arch.name,"r"))==null)
printf("\n ERROR!! NO ES POSIBLE ABRIR EL ARCHIVO... %s\n",arch.name);
else
      {	 do
	      {	putchar(c=getc(fpt));}
		while (c!=EOF);}
		fclose(fpt);
 delay(3500);
}
/* renombra un archivo */

void ren()
{ struct datos arch;
 FILE *fpt,*fp;
 char c;
 clrscr();
gotoxy(2,2);  printf("BUENO!!! TENEMOS QUE RENOMBRAR UN ARCHIVO");
gotoxy(2,3);  printf("¨QUE ARCHIVO VAMOS A RENOMBRAR...?");
  scanf ("%s",arch.name);
gotoxy(2,4); printf ("Y ¨CUAL ES EL NUEVO NOMBRE...?");
 scanf ("%s",arch.ren);
 fpt=fopen (arch.ren,"w");
 fp =fopen(arch.name,"r");
  do{
     c=getc(fp);
     putc(c,fpt);}
   while (c!=EOF);
    fclose (fp);
    fclose (fpt);
   remove (arch.name);
 }

 /*copiar*/
void copy()
{struct datos arch;
 FILE *fpt,*fp;
 char c;
 clrscr();
gotoxy(2,2);  printf("¨DE QUE ARCHIVO QUIERES HACER UNA COPIA...?");
  scanf ("%s",arch.name);
gotoxy(2,3); printf ( "¨COMO SE VA A LLAMAR EL GEMELO...?");
 scanf ("%s",arch.ren);
 fpt=fopen (arch.ren,"w");
 fp =fopen(arch.name,"r");
  do{
     c=getc(fp);
     putc(c,fpt);}
   while (c!=EOF);
    fclose (fp);
    fclose (fpt);
 }
