#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

int gd,gm,nv;
float xmin,ymin,xmax,ymax,xpmin,ypmin,xpmax,ypmax,xpc,ypc,deltaX,deltaY;
float x,y,xAnterior,yAnterior,xp,yp,xpAnterior,ypAnterior;
float incremento,r,theta;

float polar(float theta){
	return 0.2+0.2*theta; //O cualquier otra funcion
}

float funcion(float x){
	//return x*x;
	return tan(x);
}

void graficarParametrica(){ //Grafica pero con ecuaciones parametricas
	float a,b,c,d;
	float j,k;
	float t;
	
	t=0;
	j = 3, k = 3;
	a = 1, b = 2, c = 1, d = 2;
	
	xAnterior = cos(a*t) - pow(cos(b*t),j);
	yAnterior = sin(c*t) - pow(sin(d*t),k);
	xpAnterior = xpc + xAnterior*deltaX;
	ypAnterior = ypc - yAnterior*deltaY;
	
	while(t < 360*nv){
		x = cos(a*t) - pow(cos(b*t),j);
		y = sin(c*t) - pow(sin(d*t),k);
		xp = xpc + x*deltaX;
		yp = ypc - y*deltaY;
		if(y >= ymin && yAnterior >= ymin && y <= ymax && yAnterior <= ymax) line(xpAnterior,ypAnterior,xp,yp);
		xAnterior = x;
		yAnterior = y;
		xpAnterior = xp;
		ypAnterior = yp;
		
		t += 0.002;
	}
}

void graficarPolar(){ //Grafica con coordenadas polares (al incremento se le incrementa)
	nv = 1;
	incremento = 0;
	
	theta = (incremento*acos(-1))/180;
	r = polar(theta);
	xAnterior = r*cos(theta);
	yAnterior = r*sin(theta);
	xpAnterior = xpc + xAnterior*deltaX;
	ypAnterior = ypc - yAnterior*deltaY;
	
	while(incremento < 360*nv){
		incremento += 0.01;
		theta = (incremento*acos(-1))/180;
		r = polar(theta);
		x = r*cos(theta);
		y = r*sin(theta);
		xp = xpc + x*deltaX;
		yp = ypc - y*deltaY;
		if(yAnterior >= ymin && y >= ymin && yAnterior <= ymax && y <= ymax) line(xpAnterior,ypAnterior,xp,yp);
		xAnterior = x;
		yAnterior = y;
		xpAnterior = xp;
		ypAnterior = yp;
	}
	
}

void graficarFuncion(){ //Grafica meramente con la funcion. (El incremento sirve para imcrementar)
	
	incremento = 0.001;
	
	xAnterior = xmin;
	yAnterior = funcion(xAnterior);
	xpAnterior = xpc + xAnterior*deltaX;
	ypAnterior = ypc - yAnterior*deltaY;
	
	x = xAnterior;
	
	while(x<=xmax){
		x += incremento;
		y = funcion(x);
		xp = xpc + x*deltaX;
		yp = ypc - y*deltaY;
		if(yAnterior >= ymin && y >= ymin && yAnterior <= ymax && y <= ymax) line(xpAnterior,ypAnterior,xp,yp);
		xAnterior = x;
		yAnterior = y;
		xpAnterior = xp;
		ypAnterior = yp;
	}
}

int main(){
	gd = DETECT; //Detectar graphics driver
	initgraph(&gd, &gm, "C:\\TC\\BGI"); //Iniciar Graficos. Graphic Driver, Graph mode, and path
	xmin=ymin=-10;
	xmax=ymax=10;
	xpmin = ypmin = 0;
	xpmax = getmaxx();
	ypmax = getmaxy();
	xpc = (xpmax-xpmin)/2;
	ypc = (ypmax-ypmin)/2;
	deltaX = (xpmax-xpmin)/(xmax-xmin);
	deltaY = (ypmax-ypmin)/(ymax-ymin);
	
	setcolor(0);
	setbkcolor(15);
	cleardevice();
	
	line(xpc,0,xpc,ypmax);
	line(0,ypc,xpmax,ypc);
	
	graficarFuncion();
	getch();
	graficarPolar();
	getch();
	graficarParametrica();
	getch();
	
	closegraph();
}