#include "DisparoAliado.h"
//Por defecto tendr� 35 puntos de da�o
DisparoAliado::DisparoAliado() :Disparo(35,DISPARO_ALIADO)
{
	velocidad.y = 30.0f;
	radio = 0.65f;
	altura = 1.75f;
	sprite_DisparoAliado.setCenter(radio, altura/2);
	sprite_DisparoAliado.setSize(radio*2, altura);
}
DisparoAliado::DisparoAliado(float da�o, int tipo) : Disparo(da�o, tipo)
{
	velocidad.y = 30.0f;
	radio = 0.65f;
	altura = 1.75f;
	sprite_DisparoAliado.setCenter(radio, altura / 2);
	sprite_DisparoAliado.setSize(radio * 2, altura);
}
void DisparoAliado::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 1);
	glColor3f(1.0f, 0.0f, 0.0f);
	//gestion de direccion y animacion
	sprite_DisparoAliado.setState(0);
	sprite_DisparoAliado.draw();
	glPopMatrix();
}