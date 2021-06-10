#include "Bonus.h"
#include <stdlib.h> //para rand()
#include "freeglut.h"

Bonus::Bonus() {
	lado = 1.0f;
	aceleracion.y = -9.8f;
}

void Bonus::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * 0.5 * t * t;
	velocidad = velocidad + aceleracion * t;
}

Bonus::~Bonus() {

}

void Bonus::dibuja() {
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(30, 1, 1, 1);
	glColor3f(rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX);//color aleatorio
	glutSolidCube(lado);
	glPopMatrix();
}
