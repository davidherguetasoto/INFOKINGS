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
float Disparo::getDano()
{
	return da�o;
}
int Disparo::getTipo()
{
	return tipo;
}