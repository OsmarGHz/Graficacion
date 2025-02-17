#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <cmath>

float funcion(float x){
	//return x*x;
	//return sin(x);
	//return cos(x);
	//return exp(x);
	//return exp(sin(x));
	//return sin(exp(x));
	//return tan(x);
	float r = 5.0;
	return sqrt(r*r-x*x);
}

int main(){
	int xp, yp, xpmax, ypmax, xpmin, ypmin, xpc, ypc;
	float x, y, deltaX, deltaY, xmin, ymin, xmax, ymax;
	float incremento;
	int gd, gm;
	float holgura, yant;
	
	gd = DETECT;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	xmin = ymin = -10;
	xmax = ymax = 10;
	xpmin = ypmin = 0;
	xpmax = getmaxx();
	ypmax = getmaxy();
	xpc = (xpmax-xpmin)/2;
	ypc = (ypmax-ypmin)/2;
	deltaX = (xpmax-xpmin)/(xmax-xmin);
	deltaY = (ypmax-ypmin)/(ymax-ymin);
	holgura = 2.0;
	setbkcolor(15);
	setcolor(0);
	cleardevice();
	line(0, ypc, xpmax, ypc);
	line(xpc, 0, xpc, ypmax);
	// Graficamos en coordenadas polares
	incremento = 0;
	
	x = xmin;
	y = funcion(x);
	yant = y;
	xpant = xpc + x*deltaX;
	ypant = ypc - y*deltaY;
	while (x<=xmax){
		x+= incremento;
		y = funcion(x);
		xp = xpc + x*deltaX;
		yp = ypc - y*deltaY;
		/*
		if(y>=ymin-holgura && y<=ymax+holgura){
			line(xpant, ypant, xp, yp);
		}
		*/
		if(yant >= ymin && y >= ymin && yant <= ymax && y <= ymax) line(xpant, ypant, xp, yp);
		xpant = xp;
		ypant = yp;
		yant = y;
	}
	getch();
	closegraph();
	 
	return 0;
}