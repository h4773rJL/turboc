#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

   struct date d;
struct datos{
	char name[30],
	direc[30],
	mail[30],
	cumple[30],
	city[20],
	sex[14],
	edad[4],
	edo;   };

const max=2;
struct datos amigo[max];

void fecha(datos *amigo,date,int);
void capturar (datos *amigo,int *);
void all (datos *amigo,int);
void byname (datos *amigo,int);
void bysex (datos *amigo,int);
void bycity (datos *amigo,int);
void bye (datos *amigo,int);


void main(){
char op;
int i=0;
    do{
clrscr();
printf ("       BIENVENIDO A LA AGENDA * *ANNY* * \n");
printf ("\n");
printf ("1.-CAPTUAR INFORMACION ACERCA DE UN NUEVO AMIGO\n");
printf ("2.-ELIMINAR INFORMACION ACERCA DE UN AMIGO\n");
printf ("3.-BUSCAR UN AMIGO POR NOMBRE\n");
printf ("4.-LISTAR AMIGOS POR CIUDAD\n");
printf ("5.-LISTAR AMIGOS POR FECHA DE CUMPLEA¥OS\n");
printf ("6.-LISTAR TODOS LOS AMIGOS\n");
printf ("7.-LISTAR AMIGOS POR SEXO\n");
printf ("0.-SALIR DE LA AGENDA ANNY\n");
printf ("\n");
printf ("PULSA UN NUMERO 0-7 SEGUN CONVENGA...");
scanf ("%[01234567]%c",&op);
switch (op){ //inicio de switch
	case '1' : capturar(amigo,&i);
		  break;
	case '2' :bye(amigo,i);
		  break;
	case '3' :byname(amigo,i);
		  break;
	case '4' :bycity(amigo,i);
		  break;
	case '5' :fecha(amigo,d,i);
		 break;
	case '6' :all(amigo,i);
		  break;
	case '7' :bysex(amigo,i);
		  break;

      } //fin de switch
   } while (op !='0');

}           //fin de main

void fecha(datos *amigo,date d,int i)
{ int mes,dia,a;
  char *p,*dd,*mm,fecha[30];
  getdate(&d);
 for (a=0; a<i; a++){
 strcpy(fecha,amigo[a].cumple);
    dd=strtok(fecha, "/");
    mm=strtok(NULL, "/");
     mes=atoi(mm);
     dia=atoi(dd);
    if(mes==d.da_mon && dia==d.da_day)
   { printf("\n HOY ES CUMPLEA¥OS DE: %s",amigo[a].name);
	 getch(); }}
}

void capturar(datos *amigo,int *j){
int i=*j;
clrscr();
	if (i<max){
printf ("­­TENEMOS UN NUEVO AMIGO!!, DAME SUS DATOS\n"); fflush(stdin);
printf("NOMBRE:");      scanf ("%[^\n]",amigo[i].name);fflush(stdin);
printf("DIRECCION:");   scanf ("%[^\n]",amigo[i].direc);fflush(stdin);
printf("E-MAIL:");      scanf ("%[^\n]",amigo[i].mail);fflush(stdin);
printf("EDAD:");        scanf ("%[^\n]",amigo[i].edad);fflush(stdin);
printf("FECHA DE CUMPLEA¥OS [DD/MM]: "); scanf ("%[^\n]",amigo[i].cumple);fflush(stdin);
printf("CIUDAD :");     scanf ("%[^\n]",amigo[i].city);fflush(stdin);
printf("SEXO:");        scanf ("%[^\n]",amigo[i].sex);fflush(stdin);
amigo[i].edo='a';

i++;

		   }
	else
{clrscr();
gotoxy(10,10);printf("­­SORRY, NUESTRA AGENDA SE ENCUENTRA SATURADA POR EL MOMENTO\n");
gotoxy(10,11);printf ("REGRESA EL A¥O ENTRANTE!!\n"); getch();
}	   *j=i;		   }


void all (datos *amigo,int i ){
int a=0;
clrscr();
if (i<0) printf ("NO TENEMOS AMIGOS");
   clrscr();
  for  (a=0;a<i; a++)
  if (amigo[a].edo=='a')
       {
	 printf("NOMBRE:              %s \n",amigo[a].name);
	 printf("DIRECCION:           %s \n",amigo[a].direc);
	 printf("E-MAIL:              %s \n",amigo[a].mail);
	 printf("EDAD:                %s \n",amigo[a].edad);
	 printf("FECHA DE CUMPLEA¥OS: %s \n",amigo[a].cumple);
	 printf("CIUDAD:              %s \n",amigo[a].city);
	 printf("SEXO:                %s \n",amigo[a].sex);
	 printf("\n");
       getch();}
			}

void bye(datos *amigo,int i)
{char n[40],opc;
 int b=0;//,p=0,flag=0;
 clrscr();
 if (b<0) {
	printf ("NO TENEMOS AMIGOS...");
	getch(); fflush(stdin);
	  }
  else { //y
  printf ("¨QUIEN YA NO ES NUESTRO AMIGO...?");scanf ("%[^\n]",n); fflush(stdin);
  for (b=0; b<i; i++)
    if (amigo[b].edo=='a')
     { if ((strcmp(n,amigo[b].name))==0)
	    {  printf ("NOMBRE :             %s \n",amigo[b].name);
	       printf ("DIRECCION: :         %s \n",amigo[b].direc);
	       printf ("E-MAIL :             %s \n",amigo[b].mail);
	       printf ("EDAD:                %s \n",amigo[b].edad);
	       printf ("FECHA DE CUMPLEA¥OS: %s \n",amigo[b].cumple);
	       printf ("CIUDAD:              %s \n",amigo[b].city);
	       printf ("SEXO:                %s \n",amigo[b].sex);
	       amigo[b].edo='i';
	       getch();
	    }
	else { clrscr();
       printf ("EL AMIGO QUE BUSCAS NO ESTA REGISTRADO");
       getch();}
     }
 } //else
 }//main


void byname (datos *amigo,int i)
{char x[50];
 int z=0,flag=0,pos=0;
clrscr();
 printf(" DAME EL NOMBRE DEL AMIGO QUE BUSCAMOS \n");
 scanf ("%[^\n]",x);fflush(stdin);
 for (z=0; z<i; z++)
  if (amigo[z].edo=='a')
     if (strcmp (x,amigo[z].name)==0) {flag=1; pos=z;}
	  if (flag==1) {
	    clrscr();
	    printf ("NOMBRE:             %s \n",amigo[pos].name);
	    printf("DIRECCION:           %s \n",amigo[pos].direc);
	    printf("E-MAIL:              %s \n",amigo[pos].mail);
	    printf("EDAD:                %s \n",amigo[pos].edad);
	    printf("FECHA DE CUMPLEA¥OS: %s \n",amigo[pos].cumple);
	    printf("CIUDAD:              %s \n",amigo[pos].city);
	    printf("SEXO:                %s \n",amigo[pos].sex);
	    printf("\n");} // FIN IF
	    else
	    printf ("NO TENEMOS AMIGOS");	        getch();

}


void bysex (datos *amigo,int i)
{char x[15];
 int b=0,flag=0,poz=0;
clrscr();
 printf("MOSTRAR INF. DE MASCULINO O FEMENINO? \n");
 scanf ("%[^\n]",x);fflush(stdin);
 for (b=0; b<i; b++ )
 if (amigo[b].edo=='a')
  if (strcmp (x,amigo[b].sex)==0) {flag=1; poz=b;}
  if (flag==1) {
     clrscr();
     printf ("NOMBRE:             %s \n",amigo[poz].name);
     printf("DIRECCION:           %s \n",amigo[poz].direc);
     printf("E-MAIL:              %s \n",amigo[poz].mail);
     printf("EDAD:                %s \n",amigo[poz].edad);
     printf("FECHA DE CUMPLEA¥OS: %s \n",amigo[poz].cumple);
     printf("CIUDAD:              %s \n",amigo[poz].city);
     printf("SEXO:                %s \n",amigo[poz].sex);getch();
     printf("\n");}
     else
     printf ("NO TENEMOS AMIGOS");		getch();
}

 void bycity (datos *amigo,int i)
{char y[50];
 int s=0,flag=0,sos=0;
clrscr();
 printf(" DE QUE CIUDAD QUIERES VER AMIGOS ?\n");
 scanf ("%[^\n]",y);fflush(stdin);
 for (s=0; s<i; s++ )
 if (amigo[s].edo=='a')
  if (strcmp (y,amigo[s].city)==0) {flag=1; sos=s;}
  if (flag==1) {
     clrscr();
     printf ("NOMBRE:             %s \n",amigo[sos].name);
     printf("DIRECCION:           %s \n",amigo[sos].direc);
     printf("E-MAIL:              %s \n",amigo[sos].mail);
     printf("EDAD:                %s \n",amigo[sos].edad);
     printf("FECHA DE CUMPLEA¥OS: %s \n",amigo[sos].cumple);
     printf("CIUDAD:              %s \n",amigo[sos].city);
     printf("SEXO:                %s \n",amigo[sos].sex);
     printf("\n");}
     else
     printf("NO HAY ELEMENTOS");	       getch();
}

