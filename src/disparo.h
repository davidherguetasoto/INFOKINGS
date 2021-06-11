//CLASE ABSTRACTA PARA LA DEFINICI�N DE LOS DISPAROS
#pragma once
#include "ObjetoMovil.h"
#include "ColorRGB.h"
#include "Vector2D.h"

//TIPOS DE DISPAROS DEL JUEGO
/*
#define NINGUNO -1
#define DISPARO_ALIADO 0
#define DISPARO_ENEMIGO 1
#define MISIL 2
#define DISPARO_TRIPLE 3
*/


class Disparo:public ObjetoMovil
{
protected:
	float da�o; //Da�o que produce el disparo
	Vector2D origen; //Origen del disparo
	//int tipo; //Atributo para seleccionar los distintos tipos de disparo
public:
	Disparo(float da�o);
	virtual ~Disparo();
	virtual void dibuja()=0;
	Vector2D getOrigen();
	void setOrigen(Vector2D ori);
	void setOrigen(float ix, float iy);
	float getDa�o();
	//int getTipo();
};

