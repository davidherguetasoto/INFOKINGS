#include "DisparoAliado.h"
//Por defecto tendr� 35 puntos de da�o
DisparoAliado::DisparoAliado() :Disparo(35)
{
	radio = 0.5f;
}
/*
DisparoAliado::DisparoAliado(float da�o) : Disparo(da�o)
{
	radio = 0.5f;
}
*/
void DisparoAliado::dibuja()
{
	//PROVISIONAL
	glPushMatrix();
	glColor3f(0, 255, 255);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);
	glPopMatrix();
}