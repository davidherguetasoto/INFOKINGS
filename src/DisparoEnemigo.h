#pragma once
#include "disparo.h"
class DisparoEnemigo : public Disparo
{
private:
	SpriteSequence sprite_DisparoEnemigo{ "imagenes/Disparo.png",1 };
public:
	DisparoEnemigo();
	//Constructor sobrecargado para especificar el da�o y tipo de los derivados.
	//Si no se especifica el tipo, ser� disparo enemigo est�ndar
	DisparoEnemigo(float da�o, int tipo=DISPARO_ENEMIGO); 
	void dibuja();
	float getRadio() { return radio; }
	friend class Interaccion;
};

