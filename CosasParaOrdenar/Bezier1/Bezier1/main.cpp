#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Definición de puntos de control para la curva de Bézier
vector<float> puntosAnclaje = {
    -0.8f, -0.8f,  // Punto 1
    -0.4f,  0.5f,  // Punto 2
     0.4f, -0.5f,  // Punto 3
     0.8f,  0.8f   // Punto 4
};

// Función de Bernstein para curvas de Bézier (pasa parámetro t)
float bernstein(int i, int n, float t) {
    int coef[] = {1, 3, 3, 1}; // Coeficientes binomiales para una curva cúbica
    return coef[i] * pow(t, i) * pow(1-t, n-i);
}

// Función para dibujar la curva de Bézier
void dibujaCurvaBezier() {
    glColor3f(1.0, 1.0, 0.0); // Color amarillo para la curva
    glLineWidth(2);
    glBegin(GL_LINE_STRIP);
    for (float t=0; t<=1; t+=0.01) {
        float x = 0, y = 0;
        for (int i=0; i<4; i++) {
            x += bernstein(i, 3, t)*puntosAnclaje[i*2];
            y += bernstein(i, 3, t)*puntosAnclaje[i*2+1];
        }
        glVertex2f(x, y);
    }
    glEnd();
}

// Función para dibujar los puntos de anclaje
void dibujaPuntosAnclaje() {
    glColor3f(1.0, 0.0, 0.0); // Rojo
    glPointSize(5);
    glBegin(GL_POINTS);
    for (size_t i=0; i<puntosAnclaje.size(); i+=2) {
        glVertex2f(puntosAnclaje[i], puntosAnclaje[i+1]);
    }
    glEnd();

    // Dibujar líneas entre los puntos de anclaje
    glColor3f(0.5, 0.5, 0.5); // Gris
    glLineWidth(1);
    glBegin(GL_LINE_STRIP);
    for (size_t i=0; i<puntosAnclaje.size(); i+=2) {
        glVertex2f(puntosAnclaje[i], puntosAnclaje[i+1]);
    }
    glEnd();
}

// Función de renderizado
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    dibujaPuntosAnclaje();
    dibujaCurvaBezier();
    glFlush();
}

// Configuración inicial de OpenGL
void init() {
    glClearColor(0, 0, 0, 1);  // Fondo negro
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);  // Configurar el espacio de dibujo
}

// Función principal
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Curva de Bezier por ecuacion cubica");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
