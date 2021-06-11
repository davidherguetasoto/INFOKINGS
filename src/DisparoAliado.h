#pragma once
#include "disparo.h"
class DisparoAliado : public Disparo{
protected:
	//provisional para dibujarlos
	float radio;
public:
	friend class Interaccion;
	DisparoAliado();
	//Constructor sobrecargado para especificar el da�o y tipo de los derivados.
	//Si no se especifica el tipo, ser� disparo aliado est�ndar
	DisparoAliado(float da�o,int tipo=DISPARO_ALIADO);
	void dibuja();
	float getRadio() { return radio; }
};

