//CLASE PARA LA DEFINICI�N DEL ENEMIGO EST�NDAR
#pragma once
#include "Nave.h"
#include"ColorRGB.h"
class NaveEnemiga :public Nave
{
protected:
	//PROVISIONAL PARA HACER DIBUJOS DE PRUEBA
	float altura;
	float radio;
	ColorRGB color;
public:
	NaveEnemiga();
	void dibuja(); //Se debe definir c�mo se dibuja el enemigo est�ndar
	friend class Interaccion;
};

