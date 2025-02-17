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
	return sin(exp(x));
}

int main(){
	int xp, yp, xpmax, ypmax, xpmin, ypmin, xpc, ypc;
	float x, y, deltaX, deltaY, xmin, ymin, xmax, ymax;
	float incremento, t;
	int gd, gm;
	
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
	incremento = 0.01;
	t=xmin;
	while (t<=10){
		x = t;
		y = t*t;
		xp = xpc + x*deltaX;
		yp = ypc - y*deltaY;
		putpixel(xp, yp, 4);
		t+= incremento;
	}
	getch();
	closegraph();
	 
	return 0;
}