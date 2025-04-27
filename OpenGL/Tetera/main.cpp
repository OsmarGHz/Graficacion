#include <GL/glut.h>

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    glTranslatef(0.0f, 0.0f, -5.0f); // Aleja la tetera para que sea visible
    glRotatef(180.0f, 1.0f, 0.0f, 0.0f);
    glTranslatef(1.0f, 1.0f, 0.0f);
    glScalef(1.5f,1.5f,1.0f);
    glutWireTeapot(1.0); // Dibuja una tetera de alambre con tamaño 1.0
    
    glFlush();
    glutSwapBuffers();
}

void reshape(int w, int h){
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Tetera en OpenGL");
    
    glEnable(GL_DEPTH_TEST);
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    
    return 0;
}
