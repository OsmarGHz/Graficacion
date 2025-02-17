#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

float polar(float theta){
	//return 2*theta;
	//return 1-(4*cos(theta));
	//return (4*cos(8*theta))/3;
	//return (0.5)+(0.5*cos(theta));
	//return -theta;
	//return 16*cos(4*theta);
	//return (-4)*theta;
	//return (-2)*sin(8*theta);
	//return 1 - sin(theta);
	//return 1 - cos(theta);
	//return 5;
	return 5*theta;
}

int main(){
	int xp, yp, xpmax, ypmax, xpmin, ypmin, xpc, ypc;
	float x, y, deltaX, deltaY, xmin, ymin, xmax, ymax;
	float incremento;
	int gd, gm, nv;
	float theta, r, rmin, rmax;
	
	gd = DETECT;
	initgraph(&gd, &gm, "C:\\TC\\BGI");

	rmin = -1;
	rmax = 1;
	incremento = 0;
	nv = 1; //Numero de vueltas
	while(incremento<360*nv){
		theta = (incremento*acos(-1))/180;
		r = polar(theta);
		if (r < rmin) rmin = r;
		if (r > rmax) rmax = r;
		incremento += 0.1;
	}
	if (rmin>0 || rmin < 0) xmin = ymin = 2*rmin;
	else xmin = ymin = rmin;

	if (rmin>0 || rmin < 0) xmax = ymax = 2*rmax;
	else xmax = ymax = rmax;

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
	while (incremento<360*nv){
		theta = (incremento*acos(-1))/180;
		r = polar(theta);
		x = r*cos(theta);
		y = r*sin(theta);
		xp = xpc + x*deltaX;
		yp = ypc - y*deltaY;
		putpixel(xp, yp, 0);
		incremento += 0.1;
	}
	getch();
	closegraph();
	 
	return 0;
}