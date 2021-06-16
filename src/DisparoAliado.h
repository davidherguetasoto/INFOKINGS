#pragma once
#include "disparo.h"

class DisparoAliado : public Disparo{
private:
	SpriteSequence sprite_DisparoAliado{ "imagenes/Disparo.png",1 };
public:
	friend class Interaccion;
	DisparoAliado();
	//Constructor sobrecargado para especificar el da�o y tipo de los derivados.
	DisparoAliado(float da�o,int tipo);
	void dibuja();
};

