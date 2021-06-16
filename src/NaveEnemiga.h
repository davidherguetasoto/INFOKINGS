//CLASE PARA LA DEFINICI�N DEL ENEMIGO EST�NDAR
#pragma once
#include "Nave.h"
#include"ColorRGB.h"
class NaveEnemiga :public Nave
{
private:

	SpriteSequence sprite_nave{ "imagenes/NaveEnemiga.png",1 };
protected:
	
	float da�o; //Da�o que har�n cuando colisionen con la nave del personaje
public:
	Vector2D origen;
	NaveEnemiga();
	void dibuja(); //Se debe definir c�mo se dibuja el enemigo est�ndar
	float getDano() { return da�o; }
	friend class Interaccion;
};

