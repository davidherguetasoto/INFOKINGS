//CLASE ABSTRACTA PARA LA DEFINICI�N DE LOS DISPAROS
#pragma once
#include "ObjetoMovil.h"

//TIPOS DE DISPAROS DEL JUEGO
#define NINGUNO -1
#define DISPARO_ALIADO 0
#define DISPARO_ENEMIGO 3
#define MISIL 1
#define DISPARO_DOBLE 2


class Disparo:public ObjetoMovil
{
protected:
	float da�o; //Da�o que produce el disparo
	int tipo; //Atributo para seleccionar los distintos tipos de disparo
	float radio;
	float altura;
public:
	Disparo(float da�o,int tipo);
	virtual ~Disparo();
	virtual void dibuja()=0;
	float getDano();
	int getTipo();
	float getRadio() { return radio; }
	float getAltura() { return radio; }
};

