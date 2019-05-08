#include <conio.h>
#include <stdio.h>
#include <header.h>


void main()
{ int x,y,z;

clrscr();
printf ("dame un n£mero \n");scanf ("%i",&x);
printf ("dame otro n£mero \n");scanf ("%i",&y);
z=suma(x,y);
printf("\nel resultado es: %d",z);
getch();
}
