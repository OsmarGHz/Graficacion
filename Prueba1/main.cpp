#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int gd, gm; //Graphic detect y graphics mode
	gd = DETECT;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	
	line(0,0,200,200);
	line(200,200,400,0);
	getch();
	closegraph();
	return 0;
}