//CLASE PARA LA DEFINICI�N DEL ENEMIGO EST�NDAR
#pragma once
#include "Nave.h"
class NaveEnemiga :public Nave
{
private:
	SpriteSequence sprite_nave{ "imagenes/NaveEnemiga.png",1 };
public:
	NaveEnemiga();
	void dibuja(); //Se debe definir c�mo se dibuja el enemigo est�ndar
	friend class Interaccion;
};

