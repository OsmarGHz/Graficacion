#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

float polar(float theta){
	return sin(theta)*(sqrt(fabs(cos(theta)))/(sin(theta)+(7.0/5)))-2*sin(theta)+2;
}

int main(){
	int xp, yp, xpmax, ypmax, xpmin, ypmin, xpc, ypc;
	float x, y, deltaX, deltaY, xmin, ymin, xmax, ymax;
	float incremento;
	int gd, gm, nv;
	float theta, r;
	
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
	// Graficamos en coordenadas polares
	incremento = 0;
	nv = 1;
	while (incremento<360*nv){
		theta = (incremento*acos(-1))/180;
		r = polar(theta);
		x = r*cos(theta);
		y = r*sin(theta);
		xp = xpc + x*deltaX;
		yp = ypc - y*deltaY;
		putpixel(xp, yp, 4);
		incremento+= 0.1;
	}
	getch();
	closegraph();
	 
	return 0;
}