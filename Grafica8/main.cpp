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
	int xp, yp, xpmax, ypmax, xpmin, ypmin, xpc, ypc;
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
	j=3;
	k=3;
	a = 1;
	b=7;
	c=1;
	d=7;
	
	t = 0;
	nv = 1;
	while (t<360*nv){
		//theta = (t*acos(-1))/180;
		x = cos(a*t) - pow(cos(b*t), j);
		y = sin(c*t) - pow(sin(d*t), k);
		xp = xpc + x*deltaX;
		yp = ypc - y*deltaY;
		putpixel(xp, yp, 4);
		t += 0.1;
	}
	getch();
	closegraph();
	 
	return 0;
}