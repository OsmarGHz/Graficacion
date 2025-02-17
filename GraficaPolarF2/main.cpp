#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

float polar(float theta, int opc){
	switch(opc){
		case 0: break;
		case 1: return 5*cos(4*theta); break;
		case 2: return 4+4*cos(theta); break;
		case 3: return 0.2+0.2*theta; break;
		case 4: return 3-7*cos(3*theta); break;
		case 5: return 2*theta;
		case 6: return 1-(4*cos(theta));
		case 7:	return (4*cos(8*theta))/3;
		case 8: return (0.5)+(0.5*cos(theta));
		case 9: return -theta;
		case 10: return 16*cos(4*theta);
		case 11: return (-4)*theta;
		case 12: return (-2)*sin(8*theta);
		case 13: return 1 - sin(theta);
		case 14: return 1 - cos(theta);
		case 15: return 5;
		case 16: return 5*theta;
		default: printf("Opcion incorrecta\n"); return 0;
	}
	return -1;
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
	//return 5*theta;
}

int main(){
	int xp, yp, xpmax, ypmax, xpmin, ypmin, xpc, ypc;
	float x, y, deltaX, deltaY, xmin, ymin, xmax, ymax;
	float incremento;
	int gd, gm, nv;
	float theta, r, rmin, rmax;
	
	int opc;
	printf("Programa graficador de funciones polares\n");
	printf("1 ... %c(%c) = 5cos(4%c)\n",159,225,225);
	printf("2 ... %c(%c) = 4+4cos(%c)\n",159,225,225);
	printf("3 ... %c(%c) = 0.2+0.2%c\n",159,225,225);
	printf("4 ... %c(%c) = 3-7cos(3%c)\n",159,225,225);
	printf("5 ... %c(%c) = 2*%c\n",159,225,225);
	printf("6 ... %c(%c) = 1-(4*cos(%c))\n",159,225,225);
	printf("7 ... %c(%c) = (4*cos(8*%c))/3\n",159,225,225);
	printf("8 ... %c(%c) = (0.5)+(0.5*cos(%c))\n",159,225,225);
	printf("9 ... %c(%c) = -%c\n",159,225,225);
	printf("10 ... %c(%c) = 16*cos(4*%c)\n",159,225,225);
	printf("11 ... %c(%c) = (-4)*%c\n",159,225,225);
	printf("12 ... %c(%c) = (-2)*sin(8*%c)\n",159,225,225);
	printf("13 ... %c(%c) = 1 - sin(%c)\n",159,225,225);
	printf("14 ... %c(%c) = 1 - cos(%c)\n",159,225,225);
	printf("15 ... %c(%c) = 5\n",159,225);
	printf("16 ... %c(%c) = 5*theta\n",159,225,225);
	printf("0 ... Salir YA");
	printf("Ingrese la opci%cn deseada: ", 162);
	scanf("%d", &opc);
	
	gd = DETECT;
	initgraph(&gd, &gm, "C:\\TC\\BGI");

	rmin = -1;
	rmax = 1;
	incremento = 0;
	nv = 1; //Numero de vueltas
	while(incremento<360*nv){
		theta = (incremento*acos(-1))/180;
		r = polar(theta,opc);
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
		r = polar(theta,opc);
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