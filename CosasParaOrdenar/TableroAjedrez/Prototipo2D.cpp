#include <GL/glut.h>

void display() {
  //glClear(GL_COLOR_BUFFER_BIT);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Limpia el buffer de color y profundidad

  int rows = 8, cols = 8;
  float squareSize = 2.0f / rows; // Cada cuadrado tendrá un tamaño proporcional

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      // Alternar colores
      if ((i + j) % 2 == 0)
        glColor3f(1.0f, 1.0f, 1.0f); // Blanco
      else
        glColor3f(0.0f, 0.0f, 0.0f); // Negro

      // Calcular las coordenadas del cuadrado
      float x1 = -1.0f + j * squareSize;
      float y1 = 1.0f - i * squareSize;
      float x2 = x1 + squareSize;
      float y2 = y1 - squareSize;

      // Dibujar el cuadrado
      glBegin(GL_QUADS);
      glVertex2f(x1, y1);
      glVertex2f(x2, y1);
      glVertex2f(x2, y2);
      glVertex2f(x1, y2);
      glEnd();
    }
  }

  glFlush();
}

void init() {
  glClearColor(0.5f, 0.5f, 0.5f, 1.0f); // Fondo gris
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Coordenadas ortográficas
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(600, 600);
  glutCreateWindow("Tablero de Ajedrez");
  init();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}