#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <iostream>
using namespace std;

typedef struct{
	int n;
	float x[10000];
	float y[10000];
}poligono;

void dibuja_poligono(poligono figura, int xpc, int ypc, float deltaX, float deltaY){
	int i, n;
	int xpant, ypant, xp, yp;
	
	n = figura.n;
	for (i=0; i<n; i++){
		xpant = xpc + figura.x[ i%n ] * deltaX;
		ypant = ypc - figura.y[ i%n ] * deltaY;
		xp = xpc + figura.x[ (i+1)%n ] * deltaX;
		yp = ypc - figura.y[ (i+1)%n ] * deltaY;
		line(xpant, ypant, xp, yp);
	}
}

void dPCPerCaballera(poligono figura, int xpc, int ypc, float deltaX, float deltaY){
	int i, n;
	int xpant, ypant, xp, yp;
	
	n = figura.n;
	for (i=0; i<n; i++){
		xpant = xpc + figura.x[ i%n ] * deltaX;
		ypant = ypc - figura.y[ i%n ] * (deltaY*0.5);
		xp = xpc + figura.x[ (i+1)%n ] * deltaX;
		yp = ypc - figura.y[ (i+1)%n ] * (deltaY*0.5);
		line(xpant, ypant, xp, yp);
	}
}

int main(){
	int xp, yp, xpmax, ypmax, xpmin, ypmin, xpc, ypc;
	float x, y, deltaX, deltaY, xmin, ymin, xmax, ymax;
	float incremento;
	int gd, gm;
	float theta, r;
	int xpant, ypant;
	
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
	setcolor(4);
	
	// Graficamos un poligono
	poligono figura;
	figura.n = 10; // numero de lados del poligono
	
	//Variables para todos los poligonos
	int n = figura.n;
	float ang_pol = 360/n; 
	int i;
	
	// Determina los vertices del poligono
	incremento = 0;
	r = 2; // radio
	
	//Calculo poligono normal
	for (i=0; i<n; i++){
		theta = (incremento*acos(-1))/180;
		x = r*cos(theta);
		y = r*sin(theta);
		figura.x[i] = x;
		figura.y[i] = y;
		cout << figura.x[i] << " , " << figura.y[i] << "\n";
		incremento += ang_pol;
	}
	// Dibuja el poligono
	dibuja_poligono(figura, xpc, ypc, deltaX, deltaY);
	
	cout << "\n";
	
	
	//Poligono Trasladado
	poligono figuraTrasladada;
	figuraTrasladada.n = figura.n;
	setcolor(8);
	float z = r;
	
	for (i=0; i<n; i++){
		figuraTrasladada.x[i] = figura.x[i] + z*cos(45);
		figuraTrasladada.y[i] = figura.y[i] - z*sin(45)*0.5;
	}
	// Dibuja el poligono
	dibuja_poligono(figuraTrasladada, xpc, ypc, deltaX, deltaY);
	
	getch();
	closegraph();
	 
	return 0;
}
