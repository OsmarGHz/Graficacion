//Realizando una casa en opengl

#include <GL/glut.h>

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Para limpiar buffers de color y profundidad
    glLoadIdentity(); // Cargar la matriz identidad
    
    glTranslatef(0.0f, -1.5f, -9.7f); // Aleja la casa para que sea visible

    // Dibujar la base de la casa
    glPushMatrix(); // Guardamos la matriz actual
        glTranslatef(0.0f, 0.0f, 0.0f); // Posicionamos el centro del cuadrado como el centro general (lo veras mas abajo tambien, excepto en ventanas)
        // Dibujar el borde negro
    	glColor3f(0.0f, 0.0f, 0.0f); // Color negro
    	glLineWidth(5.0f); // Grosor de la linea del borde
    	//glBegin(GL_LINE_STRIP); //Esto se usa para dibujar lineas sin que se unan los ultimos vertices solito
    	glBegin(GL_LINE_LOOP); // Comenzamos a dibujar el contorno
        	glVertex3f(-2.0f, -2.0f, 0.0f); // Esquina inferior izquierda
        	glVertex3f(2.0f, -2.0f, 0.0f); // Esq inferior derecha
        	glVertex3f(2.0f, 2.0f, 0.0f); // Esq superior derecha
        	glVertex3f(-2.0f, 2.0f, 0.0f); // Esq superior izquierda
    	glEnd(); // Terminamos de dibujar el contorno
    glPopMatrix(); // Restauramos la matriz guardada
    
    glPushMatrix();
    	glTranslatef(0.0f, 0.0f, 0.0f);
    	
    	glColor3f(0.0f, 0.0f, 0.0f); // Color negro
    	glLineWidth(5.0f); // Grosor de la linea del borde
        glBegin(GL_LINE_LOOP); // Comenzamos a dibujar el contorno
        	glVertex3f(-2.0f, 2.0f, 0.0f); // Esquina inferior izquierda
        	glVertex3f(2.0f, 2.0f, 0.0f); // Esq inferior derecha
        	glVertex3f(0.0f, 4.0f, 0.0f); // Esq superior derecha
        glEnd();		    	

    	glColor3f(1.0f,0.0f,0.0f);//Colorcito rojo
        glBegin(GL_TRIANGLES);
        	glVertex3f(-2.0f, 2.0f, 0.0f); //esq inferior izq
        	glVertex3f(2.0f, 2.0f, 0.0f); //esq inferior der
        	glVertex3f(0.0f, 4.0f, 0.0f); //esq superior centro
        glEnd();
    glPopMatrix();
    
    glPushMatrix();
    	glTranslatef(0.0f, 0.0f, 0.0f);
    	
    	glColor3f(0.0f, 0.0f, 0.0f); // Color negro
    	glLineWidth(5.0f); // Grosor de la linea del borde
    	glBegin(GL_LINE_LOOP); //Contorno de puerta
            glVertex3f(-0.5f, -2.0f, 0.0f); // Esq inferior izquierda
            glVertex3f(0.5f, -2.0f, 0.0f); // Esq inferior der
            glVertex3f(0.5f, 0.3f, 0.0f); // Esq superior der
            glVertex3f(-0.5f, 0.3f, 0.0f); // Esq inf izq
        glEnd();
    	
        glColor3f(1.0f, 0.5f, 0.0f); // Color naranja
    	glBegin(GL_QUADS); //PUerta
            glVertex3f(-0.5f, -2.0f, 0.0f); // Esq inferior izquierda
            glVertex3f(0.5f, -2.0f, 0.0f); // Esq inferior der
            glVertex3f(0.5f, 0.3f, 0.0f); // Esq superior der
            glVertex3f(-0.5f, 0.3f, 0.0f); // Esq inf izq
        glEnd();
    glPopMatrix();
    
    glPushMatrix();
    	glTranslatef(-1.25f, -0.75f, 0.0f);
    	
    	glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        	glVertex3f(-0.5f, -0.5f, 0.0f);
        	glVertex3f(-0.5f, 0.5f, 0.0f);
        	glVertex3f(0.5f, 0.5f, 0.0f);
        	glVertex3f(0.5f, -0.5f, 0.0f);
        glEnd();
    	
        glColor3f(0.0f, 0.5f, 1.0f); // Color azul celeste
        glBegin(GL_QUADS); //Ventana 1
        	glVertex3f(-0.5f, -0.5f, 0.0f);
        	glVertex3f(-0.5f, 0.5f, 0.0f);
        	glVertex3f(0.5f, 0.5f, 0.0f);
        	glVertex3f(0.5f, -0.5f, 0.0f);
        glEnd();
	glPopMatrix();
	
	glPushMatrix();
        glTranslatef(1.25f, -0.75f, 0.0f);
        
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        	glVertex3f(-0.5f, -0.5f, 0.0f);
        	glVertex3f(-0.5f, 0.5f, 0.0f);
        	glVertex3f(0.5f, 0.5f, 0.0f);
        	glVertex3f(0.5f, -0.5f, 0.0f);
        glEnd();
    	
        glColor3f(0.0f, 0.5f, 1.0f); // Color azul celeste
        glBegin(GL_QUADS); //Ventana 2
        	glVertex3f(-0.5f, -0.5f, 0.0f);
        	glVertex3f(-0.5f, 0.5f, 0.0f);
        	glVertex3f(0.5f, 0.5f, 0.0f);
        	glVertex3f(0.5f, -0.5f, 0.0f);
        glEnd();
	glPopMatrix();
    
    glutSwapBuffers(); // Intercambiamos los buffers para mostrar el resultado
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
    glutInitWindowSize(600, 600);
    glutCreateWindow("Mi casa en OpenGL");
    
    glEnable(GL_DEPTH_TEST); // Habilitar el test de profundidad
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Fondo blanco
    glClearDepth(1.0f); // Profundidad de limpieza
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    
    glutMainLoop();
    
    return 0;
}