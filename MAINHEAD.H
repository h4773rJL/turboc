#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <graphics.h>
struct names{char nombre[20];};
struct date d;
struct datos{
	char name[30],
	direc[30],
	mail[30],
	cumple[30],
	city[20],
	sex[14],
	edad[4],
	edo;
	};
const max=2;
void cuadro(int xinicial,int yinicial,int xfinal,int yfinal,int color);
struct datos amigo[max];
void fecha(datos *amigo,date,int);
void capturar (datos *amigo,int *,FILE *);
void all (datos *amigo,int,FILE *);
void byname (datos *amigo,int);
void bysex (datos *amigo,int);
void bycity (datos *amigo,int);
void bye (datos *amigo,int,FILE *,names arch);
void menuagenda();
//void menuagenda1();
void minimenu();
void bynamemin(datos *amigo,int,FILE *);
void bycitymin(datos *amigo,int,FILE *);