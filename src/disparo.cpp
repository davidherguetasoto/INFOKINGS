#include "Disparo.h"
Disparo::Disparo(float da�o) : da�o(da�o)
{
}
Disparo::~Disparo()
{
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
float Disparo::getDa�o()
{
	return da�o;
}
/*
int Disparo::getTipo()
{
	return tipo;
}
*/