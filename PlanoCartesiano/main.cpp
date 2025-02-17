#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int gd, gm; //Graphic detect and graphics mode
	int xmax, ymax, xmin, ymin;
	int xpmax, ypmax, xpmin, ypmin;
	int xpc, ypc, x, y, xp, yp;
	int deltaX, deltaY;
	
	gd = DETECT;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	
	setbkcolor(15);
	//Clear device also works here
	setcolor(4);
	cleardevice();
	
	xmax = ymax = 10;
	xmin = ymin = -10;
	xpmin = ypmin = 0;
	xpmax = getmaxx();
	ypmax = getmaxy();
	xpc = (xpmax - xpmin)/2;
	ypc = (ypmax - ypmin)/2;
	deltaX = (xpmax - xpmin)/(xmax - xmin);
	deltaY = (ypmax - ypmin)/(ymax - ymin);
	
	line(xpmin, ypc, xpmax, ypc);
	line(xpc, ypmin, xpc, ypmax);
	x = 1;
	y = 1;
	xp = xpc + x*deltaX;
	yp = ypc - y*deltaY;
	putpixel(xp, yp, 1);
	circle(xp, yp, 5);
	
	getch();
	closegraph();
	return 0;
}