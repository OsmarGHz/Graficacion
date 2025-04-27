#include <GL/glut.h>

void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Limpia el buffer de color y profundidad
  glLoadIdentity();

  glTranslatef(0.0f, 0.0f, -6.0f); // Aleja la cámara para que el tablero sea visible

  float size = 1.0f; // Tamaño de cada casilla
  int rows = 8, cols = 8; // Dimensiones del tablero

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      // Alterna colores entre blanco y negro
      if ((i + j) % 2 == 0) {
        glColor3f(1.0f, 1.0f, 1.0f); // Blanco
      } else {
        glColor3f(0.0f, 0.0f, 0.0f); // Negro
      }

      glPushMatrix();
      glTranslatef(j * size - (cols / 2.0f) * size, i * size - (rows / 2.0f) * size, 0.0f);
      glBegin(GL_QUADS); // Dibuja un cuadrado
      glVertex3f(0.0f, 0.0f, 0.0f);
      glVertex3f(size, 0.0f, 0.0f);
      glVertex3f(size, size, 0.0f);
      glVertex3f(0.0f, size, 0.0f);
      glEnd();
      glPopMatrix();
    }
  }

  glutSwapBuffers(); // Intercambia los buffers para mostrar el contenido renderizado
}

void reshape(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0, (double)w / (double)h, 1.0, 10.0);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(800, 600);
  glutCreateWindow("Tablero de Ajedrez en OpenGL");

  glEnable(GL_DEPTH_TEST); // Habilita el test de profundidad

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();

  return 0;
}