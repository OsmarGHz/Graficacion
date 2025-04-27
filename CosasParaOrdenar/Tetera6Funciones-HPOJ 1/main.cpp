#include <GL/glut.h>

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    glTranslatef(0.0f, 0.0f, -6.0f); // Aleja la tetera para que sea visible
    
    glutWireTeapot(1.0); // Dibuja una tetera de alambre con tamaño 1.0
    
    glPushMatrix();
		glTranslatef(-2.0f,1.5f,0.0f);
		// glutWireCone(base, altura, rebanadasEnZ, pilasEnZ);
        glutWireCone(0.5, 1.0, 16, 16);
    glPopMatrix();
    
    glPushMatrix();
		glTranslatef(0.0f,1.5f,0.0f);
		// glutSolidCone(base, altura, rebanadasEnZ, pilasEnZ);
        glutSolidCone(0.5, 1.0, 16, 16);
    glPopMatrix();
    
    glPushMatrix();
		glTranslatef(2.0f,1.5f,0.0f);
		//glutWireCube(tamano);
		glutWireCube(1);
    glPopMatrix();
    
    glPushMatrix();
		glTranslatef(-2.0f,-1.7f,0.0f);
		//glutSolidCube(tamano);
		glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
		glTranslatef(0.0f,-1.7f,0.0f);
        // glutWireSphere(radio, rebanadas, pilas);
        glutWireSphere(0.5, 16, 16);
    glPopMatrix();
    
    glPushMatrix();
		glTranslatef(2.0f,-1.7f,0.0f);
        // glutSolidSphere(radio, rebanadas, pilas);
        glutSolidSphere(0.5, 16, 16);
    glPopMatrix();
    
    
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
