#pragma once
#include "Nave.h"
class NavePersonaje :public Nave
{
public:
	NavePersonaje();
	void dibuja(); //Define c�mo se dibuja el personaje
	friend class Interaccion;
};