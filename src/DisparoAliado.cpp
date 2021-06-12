#include "DisparoAliado.h"
//Por defecto tendr� 35 puntos de da�o
DisparoAliado::DisparoAliado() :Disparo(35,DISPARO_ALIADO)
{
	velocidad.y = 30.0f;
	radio = 0.25f;
}
DisparoAliado::DisparoAliado(float da�o, int tipo) : Disparo(da�o, tipo)
{
	velocidad.y = 30.0f;
	radio=0.25f;
}
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