#include "Disparo.h"
Disparo::Disparo(float da�o,int tipo) : da�o(da�o), tipo(tipo)
{
	radio = 0.5f;
	altura = 0.5f;
}
Disparo::~Disparo()
{
	radio = 0.5f;
	altura = 0.5f;
}
Vector2D Disparo::getOrigen()
{
	return origen;
}
void Disparo::setOrigen(Vector2D ori)
{
	origen = ori;
}
void Disparo::setOrigen(float ix,float iy)
{
	origen.x = ix;
	origen.y = iy;
}
float Disparo::getDano()
{
	return da�o;
}
int Disparo::getTipo()
{
	return tipo;
}