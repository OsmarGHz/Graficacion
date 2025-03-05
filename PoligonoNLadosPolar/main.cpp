#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

int gd,gm,nv;
float xmin,ymin,xmax,ymax,xpmin,ypmin,xpmax,ypmax,xpc,ypc,deltaX,deltaY;
float x,y,xAnterior,yAnterior,xp,yp,xpAnterior,ypAnterior;
float r,theta;
int lados;

void moduloPedirDatos(){
	printf("\n\tPor favor, ingresa el numero de lados que quieres para el poligono: ");
	scanf("%d", &lados);
	printf("\n\tPor favor, ingresa el radio que desee para la figura: ");
	scanf("%f", &r);
}

float polar(float theta){
	return 0.2+0.2*theta; //O cualquier otra funcion
}

void graficarPoligonoPolar(float coordenadas[][2]){ //Grafica con coordenadas polares
	float aumentoPorLado = (2*acos(-1))/lados;
	theta = 0;
	
	xAnterior = r*cos(theta);
	yAnterior = r*sin(theta);
	xpAnterior = xpc + xAnterior*deltaX;
	ypAnterior = ypc - yAnterior*deltaY;
	
	coordenadas[0][0] = xpAnterior;
	coordenadas[0][1] = ypAnterior;
	
	for(int i=1;i<lados;i++){
		theta += aumentoPorLado;
		
		x = r*cos(theta);
		y = r*sin(theta);
		xp = xpc + x*deltaX;
		yp = ypc - y*deltaY;
		
		line(xpAnterior,ypAnterior,xp,yp);
		coordenadas[i][0] = xp;
		coordenadas[i][1] = yp;
		
		xpAnterior = xp;
		ypAnterior = yp;
	}
	
	line(xp,yp,coordenadas[0][0],coordenadas[0][1]);
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
	
	do{ moduloPedirDatos(); } while (lados<0);
	float coordenadas[lados][2];
	
	line(xpc,0,xpc,ypmax);
	line(0,ypc,xpmax,ypc);
	if(lados>0) graficarPoligonoPolar(coordenadas);
	getch();
	cleardevice();
	
	closegraph();
}