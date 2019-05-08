#include "c:\tc\bin\MAINHEAD.H"
void menuagenda(){
struct names arch;
char op;
int i=0;//,controlador,modo;
//controlador=DETECT; modo=0;
//initgraph(&controlador,&modo,"");
FILE *fp;
//cuadro(14,350,360,390,9);
/*gotoxy(18,350);*/printf("QUE NOMBRE DESEAS PONERLE AL ARCHIVO...\n");
scanf ("%s",arch.nombre);
fp=fopen(arch.nombre,"w");
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
	case '1' : capturar(amigo,&i,fp);
		  break;
	case '2' :bye(amigo,i,fp,arch);
		  break;
	case '3' :byname(amigo,i);
		  break;
	case '4' :bycity(amigo,i);
		  break;
	case '5' :fecha(amigo,d,i);
		 break;
	case '6' :all(amigo,i,fp);
		  break;
	case '7' :bysex(amigo,i);
		  break;

      } //fin de switch
   } while (op !='0');
     fclose (fp);
} //fin de main

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
	 getch(); }/*fin if*/    }  //fin for
  clrscr();
   gotoxy(13,15);
   printf("UFFFFFF!!!!! HOY NO TENEMOS QUE COMPRAR REGALOS...");
   gotoxy(13,17);
   printf("PRESIONA  [ENTER] PARA SEGUIR CON TU TRABAJO ");
   getch();
}//fin fecha

void capturar(datos *amigo,int *j,FILE *fp){
int i=*j;
clrscr();
	if (i<max){
printf ("­­TENEMOS UN NUEVO AMIGO!!, DAME SUS DATOS\n"); fflush(stdin);
printf("NOMBRE:");     scanf ("%[^\n]",amigo[i].name);fflush(stdin);
printf("DIRECCION:");  scanf ("%[^\n]",amigo[i].direc);fflush(stdin);
printf("E-MAIL:");     scanf ("%[^\n]",amigo[i].mail);fflush(stdin);
printf("EDAD:");       scanf ("%[^\n]",amigo[i].edad);fflush(stdin);
printf("FECHA DE CUMPLEA¥OS [DD/MM]: "); scanf ("%[^\n]",amigo[i].cumple);fflush(stdin);
printf("CIUDAD :");    scanf ("%[^\n]",amigo[i].city);fflush(stdin);
printf("SEXO:");       scanf ("%[^\n]",amigo[i].sex);fflush(stdin);
fprintf (fp,"NOMBRE: %s\n",              amigo[i].name);
fprintf (fp,"DIRECCION: %s\n",           amigo[i].direc);
fprintf (fp,"E-MAIL: %s\n",              amigo[i].mail);
fprintf (fp,"EDAD: %s\n",                amigo[i].edad);
fprintf (fp,"FECHA DE CUMPLEA¥OS: %s\n", amigo[i].cumple);
fprintf (fp,"CIUDAD: %s\n",              amigo[i].city);
fprintf (fp,"SEXO: %s\n",                amigo[i].sex);
fprintf (fp,"\n");
amigo[i].edo='a';

i++;

		   }
	else
{clrscr();
gotoxy(10,10);printf("­­SORRY, NUESTRA AGENDA SE ENCUENTRA SATURADA POR EL MOMENTO\n");
gotoxy(10,11);printf ("REGRESA EL A¥O ENTRANTE!!\n"); getch();
}	   *j=i;		   }


void all (datos *amigo,int i,FILE *fp ){
int a=0;
clrscr();
if (i<0) printf ("NO TENEMOS AMIGOS");
   clrscr();
  for  (a=0;a<i; a++)
  if (amigo[a].edo=='a')
       {
	 fscanf (fp,"NOMBRE: %s\n",amigo[a].name);
	 printf("NOMBRE:              %s \n",amigo[a].name);
	 fscanf (fp,"DIRECCION: %s\n",amigo[a].direc);
	 printf("DIRECCION:           %s \n",amigo[a].direc);
	 fscanf (fp,"E-MAIL: %s\n",amigo[a].mail);
	 printf("E-MAIL:              %s \n",amigo[a].mail);
	 fscanf (fp,"EDAD: %s\n",amigo[a].edad);
	 printf("EDAD:                %s \n",amigo[a].edad);
	 fscanf (fp,"FECHA DE CUMPLEA¥OS: %s\n",amigo[a].cumple);
	 printf("FECHA DE CUMPLEA¥OS: %s \n",amigo[a].cumple);
	 fscanf (fp,"CIUDAD: %s\n",amigo[a].city);
	 printf("CIUDAD:              %s \n",amigo[a].city);
	 fscanf (fp,"SEXO: %s\n",amigo[a].sex);
	 printf("SEXO:                %s \n",amigo[a].sex);
	 printf("\n");
       getch();}
			}

void bye(datos *amigo,int i,FILE *fp,names arch)
{char n[40],opc;
 int b=0,y=i,x=0;
 clrscr();
 if (b<0) {
	printf ("NO TENEMOS AMIGOS...");
	getch(); fflush(stdin);
	  }
  else { //y
  printf ("¨QUIEN YA NO ES NUESTRO AMIGO...?");scanf ("%[^\n]",n); fflush(stdin);
  for (b=0; b<i; b++)
    if (amigo[b].edo=='a')
     { if ((strcmp(n,amigo[b].name))==0)
	    {  x=1;
	       printf ("NOMBRE :             %s \n",amigo[b].name);
	       printf ("DIRECCION: :         %s \n",amigo[b].direc);
	       printf ("E-MAIL :             %s \n",amigo[b].mail);
	       printf ("EDAD:                %s \n",amigo[b].edad);
	       printf ("FECHA DE CUMPLEA¥OS: %s \n",amigo[b].cumple);
	       printf ("CIUDAD:              %s \n",amigo[b].city);
	       printf ("SEXO:                %s \n",amigo[b].sex);
	       amigo[b].edo='i';
	       getch();
	       fclose(fp);
	       fp=fopen (arch.nombre,"w");
	       for (int del=0; del<y; del++)
		 if (amigo[del].edo=='a')
		    {fprintf (fp,"NOMBRE: %s\n",              amigo[del].name);
		     fprintf (fp,"DIRECCION: %s\n",           amigo[del].direc);
		     fprintf (fp,"E-MAIL: %s\n",              amigo[del].mail);
		     fprintf (fp,"EDAD: %s\n",                amigo[del].edad);
		     fprintf (fp,"FECHA DE CUMPLEA¥OS: %s\n", amigo[del].cumple);
		     fprintf (fp,"CIUDAD: %s\n",              amigo[del].city);
		     fprintf (fp,"SEXO: %s\n",                amigo[del].sex);
		     fprintf (fp,"\n");

		 }

	    } }
     if (x==0) { clrscr();
       printf ("EL AMIGO QUE BUSCAS NO ESTA REGISTRADO");
       getch();}

 } //else
 }//main


void byname (datos *amigo,int i/*,FILE *fp*/)
{char x[50];
 int z=0,flag=0,pos=0;
clrscr();
 printf(" DAME EL NOMBRE DEL AMIGO QUE BUSCAMOS \n");
 scanf ("%[^\n]",x);fflush(stdin);
 for (z=0; z<i; z++ )
  if (amigo[z].edo=='a')
     if (strcmp (x,amigo[z].name)==0) {flag=1; pos=z;}
      {	 if (flag==1) {
	    clrscr();
	    printf ("NOMBRE:             %s \n",amigo[pos].name);
	    printf("DIRECCION:           %s \n",amigo[pos].direc);
	    printf("E-MAIL:              %s \n",amigo[pos].mail);
	    printf("EDAD:                %s \n",amigo[pos].edad);
	    printf("FECHA DE CUMPLEA¥OS: %s \n",amigo[pos].cumple);
	    printf("CIUDAD:              %s \n",amigo[pos].city);
	    printf("SEXO:                %s \n",amigo[pos].sex);
	    printf("\n"); getch();}
	  else{clrscr();
 gotoxy(10,10); printf ("AUCHHH!! POR EL MOMENTO EL AMIGO %s NO ESTA REGISTRADO!!!",x);
 gotoxy(10,11); printf ("PRESIONA [ENTER] PARA VOLVER A LA PANTALLA ANTERIOR");
	      getch();}
       }
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
   { if (flag==1) {
	     clrscr();
	     printf ("NOMBRE:             %s \n",amigo[poz].name);
	     printf("DIRECCION:           %s \n",amigo[poz].direc);
	     printf("E-MAIL:              %s \n",amigo[poz].mail);
	     printf("EDAD:                %s \n",amigo[poz].edad);
	     printf("FECHA DE CUMPLEA¥OS: %s \n",amigo[poz].cumple);
	     printf("CIUDAD:              %s \n",amigo[poz].city);
	     printf("SEXO:                %s \n",amigo[poz].sex);getch();
	     printf("\n");getch();}
    else   {clrscr();
   gotoxy(10,10); printf ("¨QUE CREES?... NO TENEMOS AMIGOS DE SEXO ' %s' SORRY!!",x);
   gotoxy(10,11); printf ("PRESIONA [ENTER] PARA VOLVER AL MENU PRINCIPAL");
		getch();}
}  }

 void bycity (datos *amigo,int i)
{char y[50];
 int s=0,flag=0,sos=0;
clrscr();
 printf(" DE QUE CIUDAD QUIERES VER AMIGOS ?\n");
 scanf ("%[^\n]",y);fflush(stdin);
 for (s=0; s<i; s++ )
 if (amigo[s].edo=='a')
  if (strcmp (y,amigo[s].city)==0) {flag=1; sos=s;}
  {  if (flag==1) {
     clrscr();
     printf ("NOMBRE:             %s \n",amigo[sos].name);
     printf("DIRECCION:           %s \n",amigo[sos].direc);
     printf("E-MAIL:              %s \n",amigo[sos].mail);
     printf("EDAD:                %s \n",amigo[sos].edad);
     printf("FECHA DE CUMPLEA¥OS: %s \n",amigo[sos].cumple);
     printf("CIUDAD:              %s \n",amigo[sos].city);
     printf("SEXO:                %s \n",amigo[sos].sex);
     printf("\n"); getch();}
     else {clrscr();
   gotoxy(10,10); printf("ERES POCO SOCIABLE Y NO TENEMOS AMIGOS DE %s ",y);
   gotoxy(10,11); printf("AHORA PRESIONA  [ENTER], BYE");
   getch();}
   }
}

void cuadro(int xinicial,int yinicial,int xfinal, int yfinal,int color)
{setcolor(color);
line (xinicial,yinicial,xinicial,yfinal);
line (xinicial,yinicial,xfinal,yinicial);
line (xfinal,yinicial,xfinal,yfinal);
line (xfinal,yfinal,xinicial,yfinal);
}



      /*FIN DE MENUAGENDA*/


//FUNCIONES DE MINIMENU*********************************

/*void minimenu()
{struct names arch;
char opc,*a,*b,c,linea[80];
int i=0;
FILE *fp;
printf("QUE ARCHIVO VAMOS A ABRIR?...");
scanf ("%s",arch.nombre);
if ((fp=fopen(arch.nombre,"r"))==NULL) exit(-1);
  while (!feof(fp)) {
	fgets (linea,80,fp);
	*a=linea;
	   if ((strcmp(a,"\n")!=0)){
		b=p=strtok(a, ":");
		c=p=strtok(NULL, ":");
				   }
				   printf ("%s",b);

	}

do{
clrscr();
printf ("1.-BUSCAR UN AMIGO POR NOMBRE\n");
printf ("2.-LISTAR AMIGOS POR CIUDAD\n");
printf ("3.-LISTAR AMIGOS POR FECHA DE CUMPLEA¥OS\n");
printf ("4.-LISTAR TODOS LOS AMIGOS\n");
printf ("5.-LISTAR AMIGOS POR SEXO\n");
printf ("6.-SALIR DE LA AGENDA ANNY\n");
scanf("%[123456]",&opc);
switch (opc){
   case '1':bynamemin(amigo,i,fp);
	     break;
  /* case '2':{  fread(amigo,sizeof amigo,1,fp);
		bycity(amigo,i);}
	     break;
   case '3':  { fread(amigo,sizeof amigo,1,fp);
		fecha(amigo,d,i);}
	     break;
   case '4': {  fread(amigo,sizeof amigo,1,fp);
		all(amigo,i);}
	     break;
   case '5': { fread(amigo,sizeof amigo,1,fp);
		bysex(amigo,i);}
	     break;*/

/*   }//switch
}//cierra do
while (opc!='6');
fclose(fp);
}//cierra funcion.*/


void minimenu()
{struct names arch;
char opc,*a,*b,c,linea[80];
int i=0;

FILE *fp;

printf("QUE ARCHIVO VAMOS A ABRIR?...");
scanf ("%s",arch.nombre);
if ((fp=fopen(arch.nombre,"r"))==NULL) exit(-1);
 do{
  clrscr();
printf ("1.-BUSCAR UN AMIGO POR NOMBRE\n");
printf ("2.-LISTAR AMIGOS POR CIUDAD\n");
printf ("3.-LISTAR AMIGOS POR FECHA DE CUMPLEA¥OS\n");
printf ("4.-LISTAR TODOS LOS AMIGOS\n");
printf ("5.-LISTAR AMIGOS POR SEXO\n");
printf ("6.-SALIR DE LA AGENDA ANNY\n");
fflush(stdin);
scanf("%[123456%c]",&opc);
fflush(stdin);
switch (opc){
   case '1':bynamemin(amigo,i,fp);
	     break;
   case '2':bycitymin(amigo,i,fp);
	     break;
/*   case '3':  fechamin(amigo,d,i,fp);
	     break;*/
/*   case '4': allmin(amigo,i);
	     break;
   case '5': bysexmin(amigo,i);
	     break;*/

   }//switch
}//cierra do
while (opc!='6');
fclose(fp);
}//cierra funcion.


void bynamemin (datos *amigo,int i,FILE *fp)
{char x[50],y[50];
 int z=0,flag=0,pos=0;
clrscr();
 printf(" DAME EL NOMBRE DEL AMIGO QUE BUSCAMOS \n");
 scanf ("%[^\n]",x);fflush(stdin);
  for (z=0; z<i; z++ )
  if (amigo[z].edo=='a')  fscanf(fp,"%s",amigo[z].name);
     if (strcmp (x,amigo[z].name)==0) {flag=1; pos=z;}
      {	 if (flag==1) {
	    clrscr();
	    printf ("NOMBRE:             %s \n",amigo[pos].name);
	    printf("DIRECCION:           %s \n",amigo[pos].direc);
	    printf("E-MAIL:              %s \n",amigo[pos].mail);
	    printf("EDAD:                %s \n",amigo[pos].edad);
	    printf("FECHA DE CUMPLEA¥OS: %s \n",amigo[pos].cumple);
	    printf("CIUDAD:              %s \n",amigo[pos].city);
	    printf("SEXO:                %s \n",amigo[pos].sex);
	    printf("\n"); getch();}
	  else{clrscr();
 gotoxy(10,10); printf ("AUCHHH!! POR EL MOMENTO EL AMIGO %s NO ESTA REGISTRADO!!!",x);
 gotoxy(10,11); printf ("PRESIONA [ENTER] PARA VOLVER A LA PANTALLA ANTERIOR");
	      getch();}
       }
}

/* void fechamin(datos *amigo,date d,int i,FILE *fp)
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
	 getch(); }/*fin if*/ /*   }  //fin for
}//fin fecha*/

void bycitymin (datos *amigo,int i,FILE *fp)
{char y[50];
 int s=0,flag=0,sos=0;
clrscr();
 printf(" DE QUE CIUDAD QUIERES VER AMIGOS ?\n");
 scanf ("%[^\n]",y);fflush(stdin);
 for (s=0; s<i; s++ )
 if (amigo[s].edo=='a')   fscanf (fp,"%s",amigo[s].city);
  if (strcmp (y,amigo[s].city)==0) {flag=1; sos=s;}
  {  if (flag==1) {
     clrscr();
     printf ("NOMBRE:             %s \n",amigo[sos].name);
     printf("DIRECCION:           %s \n",amigo[sos].direc);
     printf("E-MAIL:              %s \n",amigo[sos].mail);
     printf("EDAD:                %s \n",amigo[sos].edad);
     printf("FECHA DE CUMPLEA¥OS: %s \n",amigo[sos].cumple);
     printf("CIUDAD:              %s \n",amigo[sos].city);
     printf("SEXO:                %s \n",amigo[sos].sex);
     printf("\n"); getch();}
     else {clrscr();
   gotoxy(10,10); printf("ERES POCO SOCIABLE Y NO TENEMOS AMIGOS DE %s ",y);
   gotoxy(10,11); printf("AHORA PRESIONA  [ENTER], BYE");
   getch();}
   }
}


//FIN DE FUNCIONES DE MINIMENU



/*
//funciones de MENUAGENDA1******************************

void menuagenda1(){
struct names arch;
char op;
int i=0;
FILE *fp;
printf("QUE NOMBRE DESEAS PONERLE AL ARCHIVO...");
scanf ("%s",arch.nombre);
fp=fopen(arch.nombre,"w");
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
     fwrite(amigo,sizeof amigo,1,fp);
     fclose (fp);
}           //fin de main



void fecha(datos *amigo,date d,int i,)
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
	 getch(); }/*fin if*/ /*   }  //fin for
}//fin fecha

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
 int b=0;
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
 for (z=0; z<i; z++ )
  if (amigo[z].edo=='a')
     if (strcmp (x,amigo[z].name)==0) {flag=1; pos=z;}
      {	 if (flag==1) {
	    clrscr();
	    printf ("NOMBRE:             %s \n",amigo[pos].name);
	    printf("DIRECCION:           %s \n",amigo[pos].direc);
	    printf("E-MAIL:              %s \n",amigo[pos].mail);
	    printf("EDAD:                %s \n",amigo[pos].edad);
	    printf("FECHA DE CUMPLEA¥OS: %s \n",amigo[pos].cumple);
	    printf("CIUDAD:              %s \n",amigo[pos].city);
	    printf("SEXO:                %s \n",amigo[pos].sex);
	    printf("\n"); getch();}
	  else{clrscr();
 gotoxy(10,10); printf ("AUCHHH!! POR EL MOMENTO EL AMIGO %s NO ESTA REGISTRADO!!!",x);
 gotoxy(10,11); printf ("PRESIONA [ENTER] PARA VOLVER A LA PANTALLA ANTERIOR");
	      getch();}
       }
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
   { if (flag==1) {
	     clrscr();
	     printf ("NOMBRE:             %s \n",amigo[poz].name);
	     printf("DIRECCION:           %s \n",amigo[poz].direc);
	     printf("E-MAIL:              %s \n",amigo[poz].mail);
	     printf("EDAD:                %s \n",amigo[poz].edad);
	     printf("FECHA DE CUMPLEA¥OS: %s \n",amigo[poz].cumple);
	     printf("CIUDAD:              %s \n",amigo[poz].city);
	     printf("SEXO:                %s \n",amigo[poz].sex);getch();
	     printf("\n");getch();}
    else   {clrscr();
   gotoxy(10,10); printf ("¨QUE CREES?... NO TENEMOS AMIGOS DE SEXO ' %s' SORRY!!",x);
   gotoxy(10,11); printf ("PRESIONA [ENTER] PARA VOLVER AL MENU PRINCIPAL");
		getch();}
}  }

 void bycity (datos *amigo,int i)
{char y[50];
 int s=0,flag=0,sos=0;
clrscr();
 printf(" DE QUE CIUDAD QUIERES VER AMIGOS ?\n");
 scanf ("%[^\n]",y);fflush(stdin);
 for (s=0; s<i; s++ )
 if (amigo[s].edo=='a')
  if (strcmp (y,amigo[s].city)==0) {flag=1; sos=s;}
  {  if (flag==1) {
     clrscr();
     printf ("NOMBRE:             %s \n",amigo[sos].name);
     printf("DIRECCION:           %s \n",amigo[sos].direc);
     printf("E-MAIL:              %s \n",amigo[sos].mail);
     printf("EDAD:                %s \n",amigo[sos].edad);
     printf("FECHA DE CUMPLEA¥OS: %s \n",amigo[sos].cumple);
     printf("CIUDAD:              %s \n",amigo[sos].city);
     printf("SEXO:                %s \n",amigo[sos].sex);
     printf("\n"); getch();}
     else {clrscr();
   gotoxy(10,10); printf("ERES POCO SOCIABLE Y NO TENEMOS AMIGOS DE %s ",y);
   gotoxy(10,11); printf("AHORA PRESIONA  [ENTER], BYE");
   getch();}
   }
}
     */