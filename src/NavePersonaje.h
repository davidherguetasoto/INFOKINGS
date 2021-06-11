#pragma once
#include "Nave.h"
#include "ColorRGB.h"
class NavePersonaje :public Nave
{
protected:
	//PROVISIONAL PARA HACER DIBUJOS DE PRUEBA
	float altura;
	float radio;
	ColorRGB color;
public:
	NavePersonaje();
	void dibuja(); //Define c�mo se dibuja el personaje
	friend class Interaccion;
};