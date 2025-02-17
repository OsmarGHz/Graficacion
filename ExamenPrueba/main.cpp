#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

int gd,gm,nv;
float x,y,xmin,ymin,xmax,ymax,xpmin,ypmin,xpmax,ypmax,xpc,ypc,deltaX,deltaY;

float polar(float theta){
	return 0.2+0.2*theta; //O cualquier otra funcion
}

void graficarParametrica(){
	
}

void graficarPolar(){
	
}

void graficarFuncion(){
	
}

int main(){
	gd = DETECT; //Detectar graphics driver
	initgraph(&gd, &gm, "C:\\TC\\BGI"); //Iniciar Graficos
	xmin=ymin=-10;
	xmax=ymax=10;
	xpmin = ypmin = 0;
	xpmax = getmaxx();
	ypmax = getmaxy();
	xpc = (xpmax-xpmin)/2;
	ypc = (ypmax-ypmin)/2;
	deltaX = (xpmax-xpmin)/(xmax-xmin);
	deltaY = (ypmax-ypmin)/(ymax-ymin);
	
	line(xpc,0,xpc,ypmax);
	line(0,ypc,xpmax,ypc);
	
	getch();
	closegraph();
}