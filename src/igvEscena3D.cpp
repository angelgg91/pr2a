#include <cstdlib>
#include <stdio.h>

#include "igvEscena3D.h"

// Metodos constructores -----------------------------------

igvEscena3D::igvEscena3D() { ejes = true; instanciasYsceneB = 3; instanciasX = 1;  instanciasZ = 1;instanciasY = 2;}

igvEscena3D::~igvEscena3D() {}


// Metodos publicos ----------------------------------------

void pintar_ejes(void) {
	GLfloat rojo[] = { 1,0,0,1.0 };
	GLfloat verde[] = { 0,1,0,1.0 };
	GLfloat azul[] = { 0,0,1,1.0 };

	glMaterialfv(GL_FRONT, GL_EMISSION, rojo);
	glBegin(GL_LINES);
	glVertex3f(1000, 0, 0);
	glVertex3f(-1000, 0, 0);
	glEnd();

	glMaterialfv(GL_FRONT, GL_EMISSION, verde);
	glBegin(GL_LINES);
	glVertex3f(0, 1000, 0);
	glVertex3f(0, -1000, 0);
	glEnd();

	glMaterialfv(GL_FRONT, GL_EMISSION, azul);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 1000);
	glVertex3f(0, 0, -1000);
	glEnd();
}

void igvEscena3D::visualizar(int escena) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // borra la ventana y el z-buffer

	//Luces
	GLfloat light0[] = { 10,8,9,1 }; // point light source
	glLightfv(GL_LIGHT0, GL_POSITION, light0);
	glEnable(GL_LIGHT0);

	glPushMatrix(); // guarda la matriz de modelado

	  // se pintan los ejes
	if (ejes) pintar_ejes();

	// Escena seleccionada a trav�s del men� (click bot�n derecho)
	if (escena == EscenaA) renderEscenaA();
	else if (escena == EscenaB) renderEscenaB();
	else if (escena == EscenaC) renderEscenaC();

	glPopMatrix(); // restaura la matriz de modelado
	glutSwapBuffers(); // se utiliza, en vez de glFlush(), para evitar el parpadeo
}

void igvEscena3D::renderEscenaA() {
    pintarCaja();



}

void igvEscena3D::renderEscenaB() {
    int desplazamiento = 0;


    for (int i= 0; i < instanciasYsceneB; i++){
        glPushMatrix();
        glTranslatef(0,desplazamiento++,0);
        pintarCaja();
        glPopMatrix();
    }


}


void igvEscena3D::renderEscenaC() {
    float desplazamientoY = 1 , desplazamientoZ = 0;
    float desplazamientoX;
    desplazamientoX = 0;
    for ( int x = 0; x < instanciasX; x++) {
        desplazamientoY = 0;
        desplazamientoZ = 0;
        for (int z = 0; z < instanciasZ; z++) {
            desplazamientoY = 0;
            glPushMatrix();
            glTranslatef(desplazamientoX, desplazamientoY, desplazamientoZ);
            pintarCaja();
            glPopMatrix();
            desplazamientoY = 1;

            for (int y = 0; y < instanciasY; y++) {
                glPushMatrix();
                glTranslatef(desplazamientoX, desplazamientoY++, desplazamientoZ);
                pintarCaja();
                glPopMatrix();
            }

            desplazamientoZ += 2.5;
        }
        desplazamientoX += 1.5;
    }

//
//    for (int z = 0; z < 4 ; z++){
//        desplazamientoY = 0;
//        glPushMatrix();
//        glTranslatef(0,desplazamientoY,desplazamientoZ);
//        pintarCaja();
//        glPopMatrix();
//        desplazamientoY = 1;
//
//    for (int x= 0; x < 3; x++){
//        glPushMatrix();
//        glTranslatef(0,desplazamientoY++,desplazamientoZ);
//        pintarCaja();
//        glPopMatrix();
//    }
//
//        desplazamientoZ += 3;
//}



}


void igvEscena3D::pintarCaja() {
    GLfloat color_pieza[] = { 0,0.25,0 };

    // Practica 2a. Parte A.

    glMaterialfv(GL_FRONT, GL_EMISSION, color_pieza);
    glPushMatrix();

    glPushMatrix();
    glTranslatef(0,0.35,0);
    glScalef(4,1,7);
    glutSolidCube(0.3);
    glPopMatrix();

    glScalef(1,1,2);
    glutSolidCube(1);

    glPopMatrix();

}

void igvEscena3D::setInstanciasX(int instanciasX) {
    igvEscena3D::instanciasX = instanciasX;
}

void igvEscena3D::setInstanciasYsceneB(int instanciasY) {
    igvEscena3D::instanciasYsceneB = instanciasY;
}

void igvEscena3D::setInstanciasZ(int instanciasZ) {
    igvEscena3D::instanciasZ = instanciasZ;
}

int igvEscena3D::getInstanciasYsceneB() const {
    return instanciasYsceneB;
}

int igvEscena3D::getInstanciasZ() const {
    return instanciasZ;
}

int igvEscena3D::getInstanciasX() const {
    return instanciasX;
}

int igvEscena3D::getInstanciasY() const {
    return instanciasY;
}

void igvEscena3D::setInstanciasY(int instanciasY) {
    igvEscena3D::instanciasY = instanciasY;
}

