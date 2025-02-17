#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>

int main(){
	int gd, gm, xp, yp;
	char nombre[50];
	
	printf("Ingresa un nombre: ");
	scanf("%[^\n]", nombre);
	
	gd = DETECT;
	initgraph(&gd,&gm, "C:\\TC\\BGI");
	
	setcolor(4);
	setbkcolor(15);
	cleardevice();
	settextstyle(4,0,4);
	yp=getmaxy()/2;
	
	/*
	for(xp=0;xp<getmaxx();xp++){
		outtextxy(xp,yp,nombre);
		delay(25);
		cleardevice();
	}
	*/
	
	for(xp=getmaxx();xp>=0;xp--){
		outtextxy(xp,yp,nombre);
		delay(25);
		cleardevice();
	}
	
	//getch(); //Evita que se cierre el programa
	closegraph();
	return 0;
}