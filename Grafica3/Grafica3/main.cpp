#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

float funcion(float x){
	//return x*x;
	//return sin(x);
	//return cos(x);
	//return exp(x);
	//return exp(sin(x));
	//return sin(exp(x));
	return tan(x);
	//return sqrt(x);
}

int main(){
	int xp, yp, xpmax, ypmax, xpmin, ypmin, xpc, ypc;
	float x, y, deltaX, deltaY, xmin, ymin, xmax, ymax;
	float incremento;
	int gd, gm;
	int xpant, ypant, color;
	float yant;
	
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
	setbkcolor(15);
	setcolor(0);
	cleardevice();
	line(0, ypc, xpmax, ypc);
	line(xpc, 0, xpc, ypmax);
	// Graficamos la funcion correspondiente en el metodo funcion
	color = 4;
	setcolor(color);
	incremento = 0.01;
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
		if (yant>=ymin && y>=ymin && yant<=ymax &&y<=ymax)
			line(xpant, ypant, xp, yp);
		xpant = xp;
		ypant = yp;
		yant = y;
	}
	getch();
	closegraph();
	 
	return 0;
}