#pragma once
#include "disparo.h"
class DisparoAliado : public Disparo{
protected:
	//provisional para dibujarlos
	float radio;
public:
	friend class Interaccion;
	DisparoAliado();
	DisparoAliado(float da�o,int tipo); //Constructor sobrecargado para crear los dsparos derivados con otro da�o
	void dibuja();
	float getRadio() { return radio; }
};

