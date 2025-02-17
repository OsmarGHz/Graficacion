#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>

int main(){
	int gd, gm, xp, yp;
	gd = DETECT;
	initgraph(&gd,&gm, "C:\\TC\\BGI");
	
	setcolor(4);
	setbkcolor(15);
	cleardevice();
	settextstyle(4,0,4);
	yp=getmaxy()/2;
	
	for(xp=getmaxx();xp>=0;xp--){
		circle(xp,yp,50);
		circle(xp-10,yp-15,5);
		circle(xp+10,yp-15,5);
		line(xp,yp-5,xp,yp+5);
		arc(xp,yp+5,210,330,15);
		
		delay(25);
		cleardevice();
	}
	
	closegraph();
	return 0;
	
}