#pragma once
#include "ObjetoMovil.h"
class Obstaculo : public ObjetoMovil
{
	float radio;
	float da�o;
public:
	Obstaculo();
	void dibuja();
	float getRadio() { return radio; }
	float getDano() { return da�o; }
	

	friend class Interaccion;
};

