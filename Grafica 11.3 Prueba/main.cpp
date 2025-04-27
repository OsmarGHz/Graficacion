#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

#define PI 3.14159265

// Estructura para representar un prisma regular con base poligonal
typedef struct {
    int n;         // número de lados de la base
    float x[100];  // coordenadas x de los vértices de la base
    float y[100];  // coordenadas y de los vértices de la base
    float h;       // altura del prisma (coordenada z para la tapa)
} Prism;

// Función que proyecta el prisma en 3D a 2D usando la proyección caballera
void proyecta_prisma(Prism p, int xpc, int ypc, float deltaX, float deltaY) {
    int i;
    float angle = PI / 4;  // 45 grados para la proyección
    float factor = 0.5;    // factor reductor para la componente z
    int n = p.n;
    
    // Arreglos para almacenar las coordenadas proyectadas de la base y la tapa
    int xb[100], yb[100]; // base (z = 0)
    int xt[100], yt[100]; // tapa (z = p.h)
    
    // Proyectar la base (z = 0)
    for (i = 0; i < n; i++) {
        float x = p.x[i];
        float y = p.y[i];
        float z = 0;
        xb[i] = xpc + (x + z * cos(angle)) * deltaX;
        yb[i] = ypc - (y - z * sin(angle) * factor) * deltaY;
    }
    
    // Proyectar la tapa (z = p.h)
    for (i = 0; i < n; i++) {
        float x = p.x[i];
        float y = p.y[i];
        float z = p.h;
        xt[i] = xpc + (x + z * cos(angle)) * deltaX;
        yt[i] = ypc - (y - z * sin(angle) * factor) * deltaY;
    }
    
    // Dibujar la base
    for (i = 0; i < n; i++) {
        int j = (i + 1) % n;
        line(xb[i], yb[i], xb[j], yb[j]);
    }
    
    // Dibujar la tapa
    for (i = 0; i < n; i++) {
        int j = (i + 1) % n;
        line(xt[i], yt[i], xt[j], yt[j]);
    }
    
    // Dibujar las aristas verticales que conectan la base con la tapa
    for (i = 0; i < n; i++) {
        line(xb[i], yb[i], xt[i], yt[i]);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    
    // Centro de la pantalla
    int xpc = getmaxx() / 2;
    int ypc = getmaxy() / 2;
    // Factores de escala (ajústalos según tu resolución y dimensiones deseadas)
    float deltaX = 1, deltaY = 1;
    
    // Configuración del prisma: base poligonal de n lados
    Prism p;
    p.n = 6; // Puedes cambiar este valor para usar otro número de lados (por ejemplo, 5 para un pentágono)
    float r = 50; // Radio del polígono base
    int i;
    for (i = 0; i < p.n; i++) {
        float theta = 2 * PI * i / p.n;
        p.x[i] = r * cos(theta);
        p.y[i] = r * sin(theta);
    }
    p.h = 30; // Altura del prisma
    
    // Configuración de la pantalla
    setbkcolor(15);  // Fondo blanco
    setcolor(0);     // Dibujo en negro
    cleardevice();
    
    // Dibujar ejes para referencia
    line(0, ypc, getmaxx(), ypc);
    line(xpc, 0, xpc, getmaxy());
    
    // Proyectar y dibujar el prisma
    proyecta_prisma(p, xpc, ypc, deltaX, deltaY);
    
    getch();
    closegraph();
    return 0;
}
