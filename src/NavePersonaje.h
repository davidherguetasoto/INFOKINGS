#pragma once
#include "Nave.h"
#include "ColorRGB.h"

class NavePersonaje :public Nave
{
public:
	//prueba bonus
	void IncrementaNumBonus();
	void SetNumBonuns(int num);
	int GetNumBonus();
	//prueba bonus
protected:
	//PROVISIONAL PARA HACER DIBUJOS DE PRUEBA
	float altura;
	float radio;
	ColorRGB color;
	//prueba bonus
	int num_bonus;
public:
	NavePersonaje();
	void dibuja(); //Define c�mo se dibuja el personaje
	friend class Interaccion;
};