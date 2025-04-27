//Realizando un muneco en opengl
#include <GL/glut.h>

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Para limpiar buffers de color y profundidad
    glLoadIdentity(); // Cargar la matriz identidad

    glTranslatef(0.0f, 0.0f, -9.7f); // Aleja la vista para que sea visible

    //Dibuja el pasto
    glPushMatrix(); // Guardamos la matriz actual
        glTranslatef(0.0f, -3.8f, 0.0f); // Posicionamos el centro del cuadrado como el centro general
        glColor3f(0.0f, 1.0f, 0.0f); // Color verde
        glBegin(GL_QUADS); // Pasto
            glVertex3f(-5.0f, -0.3f, 0.0f); // Esquina inferior izquierda
            glVertex3f(5.0f, -0.3f, 0.0f); // Esq inferior derecha
            glVertex3f(5.0f, 0.3f, 0.0f); // Esq superior derecha
            glVertex3f(-5.0f, 0.3f, 0.0f); // Esq superior izquierda
        glEnd(); // Terminamos de dibujar el contorno
    glPopMatrix(); // Restauramos la matriz guardada

    glPushMatrix(); //Para elCuerpo del muneco
        glTranslatef(-2.0f, -2.0f, 0.0f);
        
        glColor3f(1.0f, 0.0f, 0.8f); // Color rosa oscuro

        glBegin(GL_QUADS);//Cuerpo del muneco
            glVertex3f(-0.5f, -0.5f, 0.0f); // Esquina inferior izquierda
            glVertex3f(-0.5f, 0.5f, 0.0f); // Esq superior izquierda
            glVertex3f(0.5f, 0.5f, 0.0f); // Esq superior derecha
            glVertex3f(0.5f, -0.5f, 0.0f); // Esq inferior derecha
        glEnd(); // Terminamos de dibujar
        
        glColor3f(0.0f, 1.0f,1.0f); //Color azul celeste

        glBegin(GL_TRIANGLES); //Corbata triangular
            glVertex3f(0.0f, 0.35f, 0.0f); // Esquina inferior centro
            glVertex3f(0.15f,0.5f, 0.0f); // Esq superior derecha
            glVertex3f(-0.15f, 0.5f, 0.0f); // Esq superior izquierda
        glEnd(); // Terminamos de dibujar

        glBegin(GL_TRIANGLES); //Triangulo de la cabeza
            glVertex3f(0.0f,0.5f,0.0f); // Esquina inferior centro
            glVertex3f(0.35f,1.1f,0.0f); // Esq superior derecha
            glVertex3f(-0.35f,1.1f,0.0f); // Esq superior izquierda
        glEnd(); // Terminamos de dibujar
        
        glColor3f(1.0, 0.0f, 0.0f); //Color rojo

        glBegin(GL_TRIANGLES); //Triangulo de un brazo
            glVertex3f(-0.5f,0.5f,0.0f);
            glVertex3f(-1.0f,0.0f,0.0f);
            glVertex3f(-0.8f,-0.5f, 0.0f);
        glEnd();
        
        glBegin(GL_TRIANGLES); //Triangulo del otro brazo
            glVertex3f(0.5f,0.5f,0.0f);
            glVertex3f(1.0f,0.0f,0.0f);
            glVertex3f(0.8f,-0.5f, 0.0f);
        glEnd();
        
        glColor3f(0.0f, 1.0f,1.0f); //Color azul celeste

        glBegin(GL_TRIANGLES); //Triangulo para una mano
            glVertex3f(-1.0f,0.0f,0.0f);
            glVertex3f(-1.15f,0.15f,0.0f);
            glVertex3f(-1.30f,-0.15f, 0.0f);
        glEnd();

        glBegin(GL_TRIANGLES); //Triangulo para la otra mano
            glVertex3f(1.0f,0.0f,0.0f);
            glVertex3f(1.15f,0.15f,0.0f);
            glVertex3f(1.30f,-0.15f, 0.0f);
        glEnd();

        glColor3f(1.0f, 1.0f, 0.0f); //Color amarillo

        glBegin(GL_TRIANGLES); //Triangulo para el sombrero
            glVertex3f(-0.7f,1.1f,0.0f);
            glVertex3f(0.7f,1.1f,0.0f);
            glVertex3f(0.0f,1.4f,0.0f);
        glEnd(); // Terminamos de dibujar

        glColor3f(1.0, 0.0f, 0.0f); //Color rojo

        glBegin(GL_TRIANGLES); //Triangulo para la pierna
            glVertex3f(-0.15,-0.5f,0.0f);
            glVertex3f(-0.5,-0.8f,0.0f);
            glVertex3f(-0.15,-1.7f,0.0f);
        glEnd(); // Terminamos de dibujar

        glColor3f(1.0f, 1.0f, 1.0f); //Color blanco

        glBegin(GL_TRIANGLES); //Triangulo extra para la 1ra pierna
            glVertex3f(-0.55f,-1.7f,0.0f);
            glVertex3f(-0.41f,-1.55f,0.0f);
            glVertex3f(-0.15f,-1.7f,0.0f);
        glEnd(); // Terminamos de dibujar

        glColor3f(1.0, 0.0f, 0.0f); //Color rojo

        glBegin(GL_TRIANGLES); //Triangulo para la otra pierna
            glVertex3f(0.15,-0.5f,0.0f);
            glVertex3f(0.15,-0.8f,0.0f);
            glVertex3f(0.8,-0.8f,0.0f);
        glEnd(); // Terminamos de dibujar
        
        glColor3f(0.0f, 1.0f,1.0f); //Color azul celeste

        glBegin(GL_TRIANGLES); //Triangulo extra para la otra pierna
            glVertex3f(0.8,-0.8f,0.0f);
            glVertex3f(0.5f,-0.95f,0.0f);
            glVertex3f(0.65f,-1.2f,0.0f);
        glEnd(); // Terminamos de dibujar

        glColor3f(1.0f, 1.0f, 1.0f); //Color blanco

        glBegin(GL_TRIANGLES); //Triangulo extra 2 para la otra pierna
            glVertex3f(0.65f,-1.2f,0.0f);
            glVertex3f(0.79f,-1.05f,0.0f);
            glVertex3f(1.05f,-1.2f,0.0f);
        glEnd(); // Terminamos de dibujar

        
        glColor3f(1.0, 0.0f, 0.0f); //Color rojo

        glBegin(GL_POLYGON); // Hexagono
            glVertex3f(0.78f, -1.59f, 0.0f); // Punto inferior izquierdo
            glVertex3f(0.65f, -1.46f, 0.0f); // Punto medio inferior izquierdo
            glVertex3f(0.65f, -1.33f, 0.0f); // Punto medio superior izquierdo
            glVertex3f(0.78f, -1.2f, 0.0f); // Punto superior izquierdo
            glVertex3f(0.95f, -1.2f, 0.0f); // Punto superior derecho
            glVertex3f(1.04f, -1.33f, 0.0f); // Punto medio superior derecho
            glVertex3f(1.04f, -1.46f, 0.0f); // Punto medio inferior derecho
            glVertex3f(0.95f, -1.59f, 0.0f); // Punto inferior derecho
        glEnd(); // Terminamos de dibujar
        
        glColor3f(1.0f, 1.0f, 0.0f); //Color amarillo

        glBegin(GL_TRIANGLES); // Triangulo del trofeo
            glVertex3f(1.03f,0.65f,0.0f);
            glVertex3f(1.48f,-0.5f,0.0f);
            glVertex3f(1.93f,0.65f,0.0f);
        glEnd(); // Terminamos de dibujar
        
        glColor3f(0.0f, 0.0f, 0.0f); //Para el Color negro

        glBegin(GL_TRIANGLES); // Triangulo izquierdo secundario del trofeo
            glVertex3f(1.33f,0.65f,0.0f);
            glVertex3f(1.21f,0.5f,0.0f);
            glVertex3f(1.48f,-0.5f,0.0f);
        glEnd(); // Terminamos de dibujar

        glBegin(GL_TRIANGLES); // Triangulo derecho secundario del trofeo
            glVertex3f(1.63f,0.65f,0.0f);
            glVertex3f(1.75f,0.5f,0.0f);
            glVertex3f(1.48f,-0.5f,0.0f);
        glEnd(); // Terminamos de dibujar

        glColor3f(1.0f, 1.0f, 0.0f); //Color amarillo

        glBegin(GL_TRIANGLES); // Triangulo inferior secundario del trofeo
            glVertex3f(1.21f,-0.7f,0.0f);
            glVertex3f(1.75f,-0.7f,0.0f);
            glVertex3f(1.48f,-0.5f,0.0f);
        glEnd(); // Terminamos de dibujar

    glPopMatrix(); // Restauramos la matriz guardada

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
    glutCreateWindow("Munequito en OpenGL");
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    
    glutMainLoop();
    
    return 0;
}