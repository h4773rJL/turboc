#include<stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <string.h>
#include <math.h>

struct datos1 {char name[80],ren[80];};
struct datos { int  xini,yini,xfin, yfin,color1,color2,inc,ctext;
	       char axion,cad[200];
	     };
const max=200;
struct datos acciones[200];

 void show();
 int initializemouse();
 void cuadro(int xinicial, int yinicial, int xfinal, int yfinal, int color);
 void punto(int x,int y,int color);
 void ocultam();
 void getmousexy(int *x, int *y, int *mousebutton);
 void vgainit();
 void linea(int puntox, int puntoy, int puntox2,int puntoy2,  int color);
 void rectangulo(int puntox, int puntoy, int puntox2,int puntoy2,  int color);
 void circulo(int puntox, int puntoy, int puntox2,int puntoy2,  int color);
 void presentacion();
 void desk(char accion);
 void crea(datos *acciones);
 void abrir(datos *acciones,char accion,int *conta);
 void colors(int x1, int y1, int *c);


union RE{
 struct WORDREGS
	 {unsigned int ax,bx,cx,dx;
	  unsigned int si,di,cflag,flags;}
 x;
 struct BYTEREGS

	{unsigned char al,ah,bl,bh;
	 unsigned char cl,ch,dl,dh;}
 h;
 }REGS;


void main()
{ char frase[60],accion;
  int x1,y1, refx,refy,color=15,recx,recy,cirx,ciry,puntox,puntoy,
  puntox2,puntoy2,x,y,butn=0,cont=0;
  union REGS iReg,oReg;

      vgainit();
      presentacion();
      setcolor(15);
 do {             //inicio do while
       desk(accion);
       show();
       x=0; y=0;
       getmousexy(&x,&y,&butn);//*****  OBTIENE COORDENADAS DEL MOUSE*******
   if (butn==1)
      {          /* INICIO SI EL BOTON ES EL IZQUIERDO  */
	   x1=x; y1=y;
       if  ((x>500)&&(x<600)&&(y>343)&&(y<400))
       {  closegraph();
	  restorecrtmode();
	  exit(1); }
       colors(x,y,&color);
       if ((x>500)&&(x<600)&&(y<57)&&(y>0))
	   accion='1';
       if ((x>500)&&(x<600)&&(y>57)&&(y<114))
	   accion='2';
       if ((x>500)&&(x<600)&&(y>114)&&(y<171))
	   accion='3';
       if ((x>500)&&(x<600)&&(y>171)&&(y<228))
	   accion='4';
       if ((x>500)&&(x<600)&&(y>285)&&(y<343))
	   accion='5';
       if ((x>500)&&(x<600)&&(y>228)&&(y<285))
	   accion='6';
       if ((x>180)&&(x<260)&&(y>0)&&(y<15))//guardar
	   accion='7';
       if ((x>260)&&(x<320)&&(y>0)&&(y<15))//abrir
	   accion='8';
       if ((x>400)&&(x<500)&&(y>0)&&(y<15))//New
	   accion='9';

 switch (accion)
      {
       case '1' :{ // punto
		 if ((x>0)&&(x<500)&&(y>15)&&(y<382))
		    {if(cont<max)
		       { acciones[cont].axion='p';
			 acciones[cont].inc=cont;
			 acciones[cont].xini=x;
			 acciones[cont].yini=y;
			 acciones[cont].color1=color;
			 ocultam();
			 setviewport(0,15,500,382,1);
			 punto(x,y,color);
			 show();
			 cont++;
		       }
		    }
	       }//Fin punto
	       break;

     case '2' :{//case2 linea
		int x2,y2;
		if ((x1>0)&&(x1<500)&&(y1>15)&&(y1<382))
		   { delay(560);
		     getmousexy(&x,&y,&butn);
		     x2=x; y2=y;
		     if ((x2>0)&&(x2<500)&&(y2>15)&&(y2<382))
			{if(cont<max)
			    { acciones[cont].axion='l';
			      acciones[cont].inc=cont;
			      acciones[cont].xini=x1;
			      acciones[cont].yini=y1;
			      acciones[cont].xfin=x2;
			      acciones[cont].yfin=y2;
			      acciones[cont].color1=color;
			      delay(150);
			      ocultam();
			      setviewport(0,15,500,382,1);
			      linea(x1,y1,x2,y2,color);
			      cont++;
			      show();
			    }//fin acciones
			}//if contador acciones
		   }//if Delay
	       }//case linea
	  break;

     case '3':{  //case 3 rectangulo
		if ((x1>0)&&(x1<500)&&(y1>15)&&(y1<382))
		  {delay(450);
		   getmousexy(&x,&y,&butn);
		   if (butn==1)
		    {recx=x; recy=y;
		     if ((recx>0)&&(recx<500)&&(recy>15)&&(recy<382))
			{ if(cont<max)
			     {  acciones[cont].axion='r';
				acciones[cont].inc=cont;
				acciones[cont].xini=x1;
				acciones[cont].yini=y1;
				acciones[cont].xfin=recx;
				acciones[cont].yfin=recy;
				acciones[cont].color1=color;
				delay(150);
				ocultam();
				setviewport(0,15,500,382,1);
				rectangulo(x1,y1,recx,recy,color);
				cont++;
				show();
			     }// Fin acciones
			}//Fin If contador
		    }//Fin If Coordenadas
		  }// fin IF Delay
	      }//Fin Rectangulo
	  break;
     case '4':{//case 4 circulo
	       if ((x1>0)&&(x1<500)&&(y1>15)&&(y1<382))
		  { delay(450);
		    getmousexy(&x,&y,&butn);
		    cirx=x; ciry=y;
		    if ((cirx>0)&&(cirx<500)&&(ciry>15)&&(ciry<382))
		       { delay(250);
			 if(cont<max)
			   { acciones[cont].axion='c';
			     acciones[cont].inc=cont;
			     acciones[cont].xini=x1;
			     acciones[cont].yini=y1;
			     acciones[cont].xfin=cirx;
			     acciones[cont].yfin=ciry;
			     acciones[cont].color1=color;
			     delay(150);
			     ocultam();
			     setviewport(0,15,500,382,1);
			     circulo(x1,y1,cirx,ciry,color);
			     cont++;
			     show();
			   }// Fin Acciones
		       }//fin coordenadas
		  }
	      }//Fin circulo
	  break;

     case '5':{//case texto
	      if ((x>0)&&(x<500)&&(y>15)&&(y<382))
		{ setviewport(0,382,500,400,1);
		  gotoxy(2,25);
		  printf("                                                       ");
		  int b,s,i=0;
		  b=x; s=y;
		  setviewport(0,382,500,400,1);
		  gotoxy(2,25);printf("TEXTO : ");
		  while((frase[i]=getchar()) != '\n')
			 i++;
		  frase[i]='\0';
		  setcolor(color);
		  textcolor(color);
		  acciones[cont].axion='t';
		  strcpy(acciones[cont].cad,frase);
		  acciones[cont].ctext=color;
		  acciones[cont].xini=b;
		  acciones[cont].yini=s;
		  ocultam();
		  setviewport(0,15,500,382,1);
		  outtextxy(b,s,frase);
		  gotoxy(2,25);
   printf("                                                       ");
		  cont++;
		  show();
		}// Fin IF
	      }//Fin Texto
	     break;

   case '6':{//case relleno
	    int borde=-1,relleno=-1;
	    getmousexy(&x,&y,&butn);
	     if ((x>0)&&(x<500)&&(y>15)&&(y<382))
		 { if(butn==1)
		   {x1=x; y1=y;
		    do{
		       gotoxy(2,25); printf ("COLOR CONTORNO");
		       getmousexy(&x,&y,&butn);
		       if (butn==1)
			   colors(x,y,&borde);
		     } while (borde==-1);

		    delay(450);
		    gotoxy(2,25); printf ("                   ");
		    do{
		       gotoxy(2,25); printf ("COLOR FONDO");
		       getmousexy(&x,&y,&butn);
		       if (butn==1)
			  colors(x,y,&relleno);
		    }while (relleno==-1);
		    gotoxy(2,25); printf ("                   ");
		    acciones[cont].xini=x1+2;
		    acciones[cont].yini=y1-16;
		    acciones[cont].axion='f';
		    acciones[cont].color1=relleno;
		    acciones[cont].color2=borde;
		    ocultam();
		    setviewport(2,16,500,380,1);

		    setfillstyle(SOLID_FILL,relleno);
		    floodfill(x1+2,y1-16,borde);
		    cont++;
		    setcolor(color);
		    show();
		   }
		 }
	    }
	  break;//case relleno

   case '7': crea(acciones);
	  break;

   case '8': abrir(acciones,accion,&cont);
	  break;

   case '9':{ //Nuevo By Persa
	     for (int h=0; h<cont; h++)
	     acciones[h].axion='\0';
	     cont=0;
	     color=15;
	     ocultam();
	     cleardevice();
	     show();
	     }
	  break;
   } //fin switch
  }           /*  F I N   SI EL BOTON ES IZQUIERDO    */
}// fin do while
while (butn!=2);
closegraph();
restorecrtmode();
}//Fin Funcion MAIN



void vgainit()
{ int controlador,modo,errorcode;
  controlador=DETECT;
  modo=0;
  initgraph(&controlador,&modo,"");
    errorcode = graphresult();
    if (errorcode != grOk)  /* an error occurred */
       {
	 printf("Graphics error: %s\n", grapherrormsg(errorcode));
	 printf("Press any key to halt:");
	 getch();
	 exit(1);             /* return with error code */
       }
}

void show()
  { union REGS iReg,oReg;
    iReg.x.ax=1;	/* Servicio 0H */
    int86(0x33, &iReg, &oReg);
  }


int initializemouse()
{   union REGS iReg,oReg;
    iReg.x.ax=0;	/* Servicio 0H */
    int86(0x33, &iReg, &oReg);
 if (oReg.x.ax==0xFFFF)
    return oReg.x.bx;
 else
    return 0;
}


void ocultam()
{ union REGS iReg,oReg;
 iReg.x.ax=2;	/* Servicio 0H */
 int86(0x33, &iReg, &oReg);
}



void  getmousexy(int *x, int *y, int *mousebutton)
{
union REGS iReg,oReg;
 iReg.x.ax=3;	/* Servicio 3H */
 int86(0x33, &iReg, &oReg);
 *x=oReg.x.cx;
 *y=oReg.x.dx;
 *mousebutton=oReg.x.bx;
}



void cuadro(int xinicial, int yinicial,int xfinal,int yfinal,int color)
{   setcolor(color);
    line(xinicial,yinicial,xinicial,yfinal);
    line(xinicial,yinicial,xfinal,yinicial);
    line(xfinal,yinicial,xfinal,yfinal);
    line(xfinal,yfinal,xinicial,yfinal);
}

void punto(int x,int y,int  color)
{    setcolor(color);
     putpixel(x,y-16,color);
}

void linea(int puntox,int puntoy,int puntox2,int puntoy2,int color)
{    setcolor(color);
     line(puntox,puntoy-16,puntox2,puntoy2-16);
}

void rectangulo(int puntox,int puntoy,int puntox2,int puntoy2,int color)
{    setcolor(color);
     rectangle(puntox,puntoy-16,puntox2,puntoy2-16);
}

void circulo(int puntox,int puntoy,int puntox2,int puntoy2,int color)
{    int radius;
     int temp,temp1;
     setcolor(color);
     temp=(puntox2-puntox);
     temp1=(puntoy2-puntoy);
     temp=pow(temp,2);
     temp1=pow(temp1,2);
     radius=(temp+temp1);
     radius=abs(radius);
     radius=sqrt(radius);
     circle(puntox2,puntoy2-16,radius);
}

void presentacion()
{   int i;
    clearviewport();
    i=initializemouse();
    if (i!=0)
    delay(300);
    delay (300);
    cuadro(0,0,600,450,9);
    cuadro(4,4,596,446,13);
    setcolor(1);
    settextstyle(1,0,2);
    outtextxy(30,10,"BENEMERITA UNIVERSIDAD AUTONOMA DE PUEBLA");
    settextstyle(2,0,7);
    setcolor(2);
    outtextxy(100,60,"'' M I N I P A I N T    PERSA ''");
    settextstyle(3,0,2);
    setcolor(1);
    outtextxy(30,90,"MATERIA:");
    outtextxy(30,170,"PROFESORA:");
    outtextxy(30,250,"ALUMNAS:");
    setcolor(CYAN);
    outtextxy(70,130,"PROGAMACION DE SISTEMAS");
    outtextxy(70,210,"SANTIAGO DIAZ MARIA DEL CARMEN");
    outtextxy(70,290,"ZENTENO VAZQUEZ ANA CLAUDIA");
   // outtextxy(70,330,"RUIZ MELENDEZ IVON");
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
    setcolor(14);
    outtextxy(30,410,"* PRESIONE [ENTER] PARA CONTINUAR *");
    /* TERMINA EL PROCESO DE PRESENTACION DEL TRABAJO*/
    show();
    getch();
    fflush(stdin);
    ocultam();
    clearviewport();
}

void desk(char accion)
{      //INICIO  REALIZACION DEL ESCRITORIO PAINT
       setviewport(0,0,600,450,1);
       cuadro(0,0,600,450,14);   	//borde principal
       line (0,15,500,15);       	//linea de men£
       settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
       outtextxy(10,5,"MINIPAINT   ''ANIV''");
       line(180,0,180,15);
       outtextxy(190,5,"GUARDAR");
       line(260,0,260,15);
       outtextxy(270,5,"ABRIR");
       line(400,0,400,15);
       outtextxy(420,5,"NUEVO");
       line(320,0,320,15);
       line(500,0,500,400);      //linea vertical izq de acciones
       line(0,400,600,400);      //linea horizontal sup de colores
       line(500,57,600,57);      //sep de punto
       line(500,114,600,114);    //sep de linea
       line(500,171,600,171);    //sep de rectangulo
       line(500,228,600,228);    //sep de relleno
       line(500,285,600,285);    //sep de texto
       line(500,342,600,342);    //sep de EXIT
       line(40,400,40,450);      //sep color blue
       line(80,400,80,450);      //green
       line(120,400,120,450);    //cyan
       line(160,400,160,450);    //red
       line(200,400,200,450);    //magenta
       line(240,400,240,450);    //brown
       line(280,400,280,450);    //lightgray
       line(320,400,320,450);    //darkgray
       line(360,400,360,450);    //lightblue
       line(400,400,400,450);    //lightgreen
       line(440,400,440,450);    //lightcyan
       line(480,400,480,450);    //lightred
       line(520,400,520,450);    //lightmagenta
       line(560,400,560,450);    //yellow
       line(600,400,600,450);    //white
       setfillstyle(1,1);    //color azul
       floodfill(30,420,14);
       setfillstyle(1,2);    //color verde
       floodfill(60,420,14);
       setfillstyle(1,15);    //color BLANCO
       floodfill(100,420,14);
       setfillstyle(1,4);    //color rojo
       floodfill(140,420,14);
       setfillstyle(1,5);    //color magenta
       floodfill(180,420,14);
       setfillstyle(1,6);    //color cafe
       floodfill(220,420,14);
       setfillstyle(1,7);    //color lightgray
       floodfill(260,420,14);
       setfillstyle(1,8);    //color darkgray
       floodfill(300,420,14);
       setfillstyle(1,9);    //color lightblue
       floodfill(340,420,14);
       setfillstyle(1,10);    //color lightgreen
       floodfill(380,420,14);
       setfillstyle(1,11);    //color lightcyan
       floodfill(420,420,14);
       setfillstyle(1,12);    //color lightred
       floodfill(460,420,14);
       setfillstyle(1,13);    //color lightmagenta
       floodfill(500,420,14);
       setfillstyle(1,14);    //color lightyellow
       floodfill(540,420,14);
       setfillstyle(1,0);    //color NEGRO
       floodfill(580,420,14);
       line(510,100,590,72); //      I   C   O   N   O
       putpixel(550,28,14);  //      i   c   o   n   o
       rectangle(515,124,585,160);// i   c   o   n   o
       circle(550,199,15);   //      i   c   o   n   o
       ellipse(550,248,280,270,10,5);//icono
       line(540,247,530,267);        //icono
       line(560,247,550,267);        //icono
       line(530,268,550,268);        //icono
       line(559,249,566,254);        //icono
       line(555,257,566,254);        //icono
	    cuadro(0,382,500,382,14);//PARA LETREROS DE TEXTO O ABRIR ARCHIVO
       settextstyle(0,HORIZ_DIR,2);
       outtextxy(540,300,"A");
       settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
       outtextxy(525,365,"SALIR");

       switch (accion)
       {
       case '1': cuadro(503,3,597,54,1);//cuadropuntos
		 cuadro(503,60,597,111,0);//lineas
		 cuadro(503,117,597,168,0);//rectangulo
		 cuadro(503,174,597,225,0);//circulo
		 cuadro(503,231,597,282,0);//relleno
		 cuadro(503,288,597,339,0);//texto
		 cuadro(183,3,257,12,0);// guardar
		 cuadro(263,3,317,12,0);//abrir
		 gotoxy(2,25);printf("                                                ");
		 break;
       case '2': cuadro(503,60,597,111,1);//cuadro lineas
		 cuadro(503,3,597,54,0);//puntos
		 cuadro(503,117,597,168,0);//rectangulo
		 cuadro(503,174,597,225,0);//circulo
		 cuadro(503,231,597,282,0);//relleno
		 cuadro(503,288,597,339,0);// texto
		 cuadro(183,3,257,12,0);// guardar
		 cuadro(263,3,317,12,0);//abrir
		 gotoxy(2,25);printf("                                                ");
		 break;
       case '3': cuadro(503,117,597,168,1);//marco rectangulos
		 cuadro(503,60,597,111,0);// lineas
		 cuadro(503,3,597,54,0);//puntos
		 cuadro(503,174,597,225,0);//circulo
		 cuadro(503,231,597,282,0);//relleno
		 cuadro(503,288,597,339,0);//texto
		 cuadro(183,3,257,12,0);// guardar
		 cuadro(263,3,317,12,0);//abrir
		 gotoxy(2,25);printf("                                                ");
		 break;
       case '4': cuadro(503,174,597,225,1);//marco circulo
		 cuadro(503,117,597,168,0);// rectangulos
		 cuadro(503,60,597,111,0);// lineas
		 cuadro(503,3,597,54,0);//puntos
		 cuadro(503,231,597,282,0);//relleno
		 cuadro(503,288,597,339,0);//texto
		 cuadro(183,3,257,12,0);// guardar
		 cuadro(263,3,317,12,0);//abrir
		 gotoxy(2,25);printf("                                                ");
		 break;
       case '5': cuadro(503,288,597,339,1);//marco texto
		 cuadro(503,174,597,225,0);// circulo
		 cuadro(503,117,597,168,0);// rectangulos
		 cuadro(503,60,597,111,0);// lineas
		 cuadro(503,3,597,54,0);//puntos
		 cuadro(503,231,597,282,0);//relleno
		 cuadro(183,3,257,12,0);//guardar
		 cuadro(263,3,317,12,0);//marco abrir
		 break;
       case '6': cuadro(503,231,597,282,1);//marco relleno
		 cuadro(503,288,597,339,0);// texto
		 cuadro(503,174,597,225,0);// circulo
		 cuadro(503,117,597,168,0);// rectangulos
		 cuadro(503,60,597,111,0);// lineas
		 cuadro(503,3,597,54,0);//puntos
		 cuadro(183,3,257,12,0);// guardar
		 cuadro(263,3,317,12,0);//marco abrir
		 break;
       case '7': cuadro(183,3,257,12,1);//marco guardar
		 cuadro(503,231,597,282,0);// relleno
		 cuadro(503,288,597,339,0);// texto
		 cuadro(503,174,597,225,0);// circulo
		 cuadro(503,117,597,168,0);// rectangulos
		 cuadro(503,60,597,111,0);// lineas
		 cuadro(503,3,597,54,0);//puntos
		 cuadro(263,3,317,12,0);//marco abrir
		 break;
	case '8':cuadro(263,3,317,12,1);//marco abrir
		 cuadro(183,3,257,12,0);// guardar
		 cuadro(503,231,597,282,0);// relleno
		 cuadro(503,288,597,339,0);// texto
		 cuadro(503,174,597,225,0);// circulo
		 cuadro(503,117,597,168,0);// rectangulos
		 cuadro(503,60,597,111,0);// lineas
		 cuadro(503,3,597,54,0);//puntos
		 break;
       }
}      //       FIN REALIZACION DEL ESCRITORIO PAINT

void crea(datos *acciones)
{ FILE *fpt;
  char c,cad1[200];
  int h=0,xi,yi,xf,yf,c1,c2;
  struct datos1 arch;
  struct datos aux;

  ocultam();
    gotoxy(2,25);
    printf("                                                       ");
    gotoxy(2,25);printf("QUE NOMBRE DESEAS PONER AL ARCHIVO?.. ");
    scanf("%s",arch.name);
  fpt=fopen(arch.name,"wb");
    h=0;
    while (acciones[h].axion!='\0')
	{ aux=acciones[h];
	  fwrite(&aux,sizeof(datos),1,fpt);
	  h++;
	}
  fclose(fpt);
  show();
  gotoxy(2,25);printf("EL ARCHIVO HA SIDO GUARDADO,ELIGE OTRA OPCION ");
}// Fin Guardar

void abrir(datos *acciones,char accion,int *conta)  //contenido de archivo
{ FILE *fpt;
  char c;
  int h=0,xi,yi,xf,yf,c1,c2,r,i,flag=1;
  struct datos1 arch;
  struct datos tnt;

   ocultam();
   cleardevice();
   do{
     desk(accion);
     gotoxy(2,25);
     printf("                                                       ");
     gotoxy(2,25);printf("NOMBRE DEL ARCHIVO ");
     scanf("%s",arch.name);
     if ((fpt=fopen(arch.name,"rb"))==NULL)
	{ gotoxy(2,25);printf("ERROR!! IMPOSIBLE ABRIR  ARCHIVO... %s");
	  delay(1000);
	  flag=0;
	} else flag=1;
   } while (flag==0);

   fread(&tnt,sizeof(datos),1,fpt);
   while (!feof(fpt))
	{
	  acciones[h]=tnt;
	  fread(&tnt,sizeof(datos),1,fpt);
	  h++;
	}
     *conta=i=h;
  fclose(fpt);
  setviewport(2,16,500,380,1);
  for(h=0;h<i;h++)
	  switch(acciones[h].axion)
	{//switch
	  case 'p': punto(acciones[h].xini,acciones[h].yini,acciones[h].color1);
	   break;
	  case 'l': linea( acciones[h].xini,acciones[h].yini,acciones[h].xfin,acciones[h].yfin,acciones[h].color1);
	   break;
	 case 'r': rectangulo(acciones[h].xini,acciones[h].yini,acciones[h].xfin,acciones[h].yfin,acciones[h].color1);
	   break;
	 case 'c': circulo(acciones[h].xini,acciones[h].yini,acciones[h].xfin,acciones[h].yfin,acciones[h].color1);
	   break;
	 case 'f': {
		     setfillstyle(SOLID_FILL,acciones[h].color1);
		     floodfill(acciones[h].xini,acciones[h].yini,acciones[h].color2);
		   }
	   break;
	 case 't': {
		     setcolor(acciones[h].ctext);
		     outtextxy(acciones[h].xini,acciones[h].yini,acciones[h].cad);
		   }
	   break;
	}//switch
   show();
   gotoxy(2,25);printf("EL ARCHIVO HA SIDO LEIDO,ELIGE OTRA OPCION!!! ");
} //final funcion

void colors(int x1, int y1, int *c)
{
	if ((x1>0)&&(x1<40)&&(y1>400)&&(y1<450))
       {setcolor(1);
	*c=getcolor();
	outtextxy(330,5," COLOR ");}
       if ((x1>40)&&(x1<80)&&(y1>400)&&(y1<450))
       {setcolor(2);
	*c=getcolor();
	outtextxy(330,5," COLOR ");}
       if ((x1>80)&&(x1<120)&&(y1>400)&&(y1<450))
       {setcolor(15);
	*c=getcolor();
	outtextxy(330,5," COLOR ");}
       if ((x1>120)&&(x1<160)&&(y1>400)&&(y1<450))
       {setcolor(4);
	*c=getcolor();
	outtextxy(330,5," COLOR ");}
       if ((x1>160)&&(x1<200)&&(y1>400)&&(y1<450))
       {setcolor(5);
	*c=getcolor();
	outtextxy(330,5," COLOR ");}
       if (( x1>200)&&(x1<240)&&(y1>400)&&(y1<450))
       {setcolor(6);
	*c=getcolor();
	outtextxy(330,5," COLOR ");}
       if ((x1>240)&&(x1<280)&&(y1>400)&&(y1<450))
       {setcolor(7);
	*c=getcolor();
	outtextxy(330,5," COLOR ");}
       if ((x1>280)&&(x1<320)&&(y1>400)&&(y1<450))
       {setcolor(8);
	*c=getcolor();
	outtextxy(330,5," COLOR ");}
       if ((x1>320)&&(x1<360)&&(y1>400)&&(y1<450))
       {setcolor(9);
	*c=getcolor();
	outtextxy(330,5," COLOR ");}
       if ((x1>360)&&(x1<400)&&(y1>400)&&(y1<450))
       {setcolor(10);
       *c=getcolor();
       outtextxy(330,5," COLOR ");}
       if ((x1>400)&&(x1<440)&&(y1>400)&&(y1<450))
       {setcolor(11);
	*c=getcolor();
	outtextxy(330,5," COLOR ");}
       if ((x1>440)&&(x1<480)&&(y1>400)&&(y1<450))
       {setcolor(12);
       *c=getcolor();
       outtextxy(330,5," COLOR ");}
       if ((x1>480)&&(x1<520)&&(y1>400)&&(y1<450))
       {setcolor(13);
       *c=getcolor();
       outtextxy(330,5," COLOR ");}
       if ((x1>520)&&(x1<560)&&(y1>400)&&(y1<450))
       {setcolor(14);
	*c=getcolor();
	outtextxy(330,5," COLOR ");}
       if ((x1>560)&&(x1<600)&&(y1>400)&&(y1<450))
       {setcolor(0);
       *c=getcolor();
       outtextxy(330,5," COLOR ");}

}