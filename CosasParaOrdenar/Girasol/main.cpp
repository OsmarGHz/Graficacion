#include <GL/glut.h>
#include <cmath>

#define PI 3.14159265358979323846

// Función para dibujar un círculo (centro del girasol)
void drawCircle(float cx, float cy, float r, int num_segments, float R, float G, float B) {
    glColor3f(R, G, B);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= num_segments; i++) {
        float theta = 2.0f * PI * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

// Función para dibujar un pétalo
void drawPetal(float cx, float cy, float angle) {
    float petal_length = 0.2f, petal_width = 0.05f;
    glColor3f(1.0f, 0.9f, 0.0f);  // Amarillo
    glBegin(GL_TRIANGLES);
    
    float x1 = cx + cos(angle) * 0.1f;
    float y1 = cy + sin(angle) * 0.1f;
    
    float x2 = cx + cos(angle + PI / 6) * petal_length;
    float y2 = cy + sin(angle + PI / 6) * petal_length;
    
    float x3 = cx + cos(angle - PI / 6) * petal_length;
    float y3 = cy + sin(angle - PI / 6) * petal_length;
    
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    
    glEnd();
}

// Función para dibujar el tallo
void drawStem() {
    glColor3f(0.0f, 0.6f, 0.0f); // Verde
    glBegin(GL_QUADS);
    
    glVertex2f(-0.02f, -0.5f);
    glVertex2f(0.02f, -0.5f);
    glVertex2f(0.02f, -0.1f);
    glVertex2f(-0.02f, -0.1f);
    
    glEnd();
}

// Función para dibujar una hoja con detalles
void drawLeaf(float cx, float cy, float direction) {
    glColor3f(0.0f, 0.7f, 0.0f); // Verde claro
    
    glBegin(GL_POLYGON);
    glVertex2f(cx, cy); // Punto de unión con el tallo
    glVertex2f(cx + 0.1f * direction, cy - 0.02f); // Parte superior
    glVertex2f(cx + 0.15f * direction, cy - 0.05f); // Punto más ancho
    glVertex2f(cx + 0.12f * direction, cy - 0.08f); // Parte baja
    glVertex2f(cx + 0.07f * direction, cy - 0.1f); // Extremo de la hoja
    glEnd();
    
    // Línea central de la hoja (nervadura)
    glColor3f(0.0f, 0.5f, 0.0f); // Verde oscuro
    glBegin(GL_LINES);
    glVertex2f(cx, cy);
    glVertex2f(cx + 0.08f * direction, cy - 0.08f);
    glEnd();
}

// Función para dibujar el girasol completo
void drawSunflower() {
    drawStem(); // Dibuja el tallo
    
    // Dibuja hojas con más detalles
    drawLeaf(-0.02f, -0.3f, -1); // Hoja izquierda
    drawLeaf(0.02f, -0.4f, 1);   // Hoja derecha

    // Dibuja el centro del girasol (marrón oscuro)
    drawCircle(0.0f, 0.0f, 0.1f, 50, 0.4f, 0.2f, 0.0f);

    // Dibuja los pétalos en círculo
    int num_petals = 20;
    for (int i = 0; i < num_petals; i++) {
        float angle = i * (2.0f * PI / num_petals);
        drawPetal(0.0f, 0.0f, angle);
    }
}

// Función de visualización
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawSunflower();
    glFlush();
}

// Inicialización de OpenGL
void init() {
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);  // Fondo celeste
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-0.5, 0.5, -0.5, 0.5);
}

// Función principal
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Girasol en OpenGL");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
