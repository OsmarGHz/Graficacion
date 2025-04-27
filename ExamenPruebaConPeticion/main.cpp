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

void graficarParametrica(float a, float b, float c, float d, float j, float k){ //Grafica pero con ecuaciones parametricas

	float t, step = 0.01;
	float x_min = 1e30, x_max = -1e30;
	float y_min = 1e30, y_max = -1e30;
	for(t = 0; t < 360; t += step) {
	    float x_val = cos(a*t) - pow(cos(b*t), j);
	    float y_val = sin(c*t) - pow(sin(d*t), k);
	    if(x_val < x_min) x_min = x_val;
	    if(x_val > x_max) x_max = x_val;
 	   	if(y_val < y_min) y_min = y_val;
 	   	if(y_val > y_max) y_max = y_val;
	}
	
	float margen = 1; // Puedes ajustar este valor según lo que necesites
	xmin = x_min - margen;
	xmax = x_max + margen;
	ymin = y_min - margen;
	ymax = y_max + margen;
	
	deltaX = (xpmax - xpmin) / (xmax - xmin);
	deltaY = (ypmax - ypmin) / (ymax - ymin);
	
	t = 0;
	nv = 1;
	
	xAnterior = cos(a*t) - pow(cos(b*t),j);
	yAnterior = sin(c*t) - pow(sin(d*t),k);
	xpAnterior = xpc + xAnterior*deltaX;
	ypAnterior = ypc - yAnterior*deltaY;
	
	while(t < 360*nv){
		
		t += 0.0004;
		
		x = cos(a*t) - pow(cos(b*t),j);
		y = sin(c*t) - pow(sin(d*t),k);
		xp = xpc + x*deltaX;
		yp = ypc - y*deltaY;
		
		if(y >= ymin && yAnterior >= ymin && y <= ymax && yAnterior <= ymax) line(xpAnterior,ypAnterior,xp,yp);
		
		xAnterior = x;
		yAnterior = y;
		xpAnterior = xp;
		ypAnterior = yp;
	}
}

void graficarPolar(){ //Grafica con coordenadas polares (al incremento se le incrementa)
	nv = 1;
	incremento = 0;
	
	theta = (incremento*acos(-1))/180;
	r = polar(theta); //Para poder usar esto, NECESITAS despejar r de la ecuacion polar
	
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

void graficarFuncion(){ //Grafica meramente con la funcion.
	
	xAnterior = xmin;
	yAnterior = funcion(xAnterior);
	xpAnterior = xpc + xAnterior*deltaX;
	ypAnterior = ypc - yAnterior*deltaY;
	
	x = xAnterior; //ESTO ES IMPORTANTISIMO; AGREGALO O PUEDEN HABER ERRORES. X NO SE CALCULA SOLITO DESDE CERO en funciones normales
	
	while(x<=xmax){
		
		x += 0.001; //Aqui, la x se aumenta con la cantidad de incremento
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
	float a,b,c,d,j,k;
	
	printf("Bienvenido!\n");
	printf("\n\tGRAFICACION PARAMETRICA\n\n");
	printf("Para esta usamos:");
	printf("\n\tx = cos(a*t) - cos(b*t)^j");
	printf("\n\ty = sen(c*t) - sen(d*t)^k");
	printf("\n\nNo te asustes, el valor de t inicia en 0 y se va actualizando para graficar, no te lo pediremos.");
	printf("\nPuedes ingresar los valores de a,b,c,d,j y k que prefieras o que hayas visto en internet :).");
	
	printf("\n\nEn base a eso:");
	printf("\n\tIngrese el valor de a: ");
	scanf("%f", &a);
	printf("\n\tIngrese el valor de b: ");
	scanf("%f", &b);
	printf("\n\tIngrese el valor de c: ");
	scanf("%f", &c);
	printf("\n\tIngrese el valor de d: ");
	scanf("%f", &d);
	printf("\n\tIngrese el valor de j: ");
	scanf("%f", &j);
	printf("\n\tIngrese el valor de k: ");
	scanf("%f", &k);
	
	gd = DETECT; //Detectar graphics driver
	char path[] = "C:\\TC\\BGI"; // Arreglo mutable
    initgraph(&gd, &gm, path);
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
	graficarParametrica(a,b,c,d,j,k);
	getch();
	
	closegraph();
	
	printf("Gracias por usar el programa! Nos vemos a la proxima!");
}