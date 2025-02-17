#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

float polar(float theta){
	//return 5*cos(4*theta);
	//return 4+4*cos(theta);
	//return 0.2+0.2*theta;
	return 3-7*cos(3*theta);
}

int main(){
	int xp, yp, xp_anterior, yp_anterior, xpmax, ypmax, xpmin, ypmin, xpc, ypc;
	float x, y, deltaX, deltaY, xmin, ymin, xmax, ymax;
	float incremento;
	int gd, gm, nv;
	float theta, r;
	
	gd = DETECT;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	xmin = ymin = -4;
	xmax = ymax = 4;
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
	// Graficamos en ecuaciones parametricas
	float a,b,c,d;
	float t;
	int j,k;
	
	//Variables j,k
	//j=3, k=3;
	j=3, k=4;
	
	//Variables a,b,c,d
	//a = 1, b = 2, c = 1, d = 2;
	//a = 2, b = 1, c = 2, d = 1;
	//a = 1, b = 3, c = 1, d = 3;
	//a = 3, b = 1, c = 3, d = 1;
	//a = 1, b = 4, c = 1, d = 4;
	//a = 4, b = 1, c = 4, d = 1;
	//a = 1, b = 5, c = 1, d = 5;
	//a = 5, b = 1, c = 5, d = 1;
	//a = 1, b = 6, c = 1, d = 6;
	//a = 6, b = 1, c = 6, d = 1;
	//a = 1, b = 7, c = 1, d = 7;
	//a = 7, b = 1, c = 7, d = 1;
	//a = 1, b = 2, c = 1, d = 3;
	//a = 1, b = 3, c = 1, d = 2;
	//a = 1, b = 2, c = 2, d = 1;
	//a = 1, b = 3, c = 3, d = 1;
	
	//a = 1, b = 80, c = 1, d = 80;
	//a = 1, b = 80, c = 1, d = 40;
	//a = 1, b = 60, c = 1, d = 120;
	//a = 80, b = 1, c = 1, d = 80;
	//a = 150, b = 1, c = 1, d = 100;
	//a = 1, b = 200, c = 1, d = 150;
	//a = 1, b = 80, c = 80, d = 80;
	//a = 1, b = 80, c = 80, d = 1;
	//a = 9, b = 100, c = 200, d = 9;
	//a = 9, b = 200, c = 100, d = 9;
	//a = 1, b = 200, c = 200, d = 2;
	a = 2, b = 200, c = 200, d = 1;
	
	t = 0;
	nv = 1;
	
	x = cos(a*t) - pow(cos(b*t), j);
	y = sin(c*t) - pow(sin(d*t), k);
	xp_anterior = xpc + x*deltaX;
	yp_anterior = ypc - y*deltaY;

	while (t < 360 * nv){
		x = cos(a*t) - pow(cos(b*t), j);
		y = sin(c*t) - pow(sin(d*t), k);
		xp = xpc + x*deltaX;
		yp = ypc - y*deltaY;

		line(xp_anterior, yp_anterior, xp, yp);

		xp_anterior = xp;
		yp_anterior = yp;

		t += 0.0002;
	}

	getch();
	closegraph();
	 
	return 0;
}
