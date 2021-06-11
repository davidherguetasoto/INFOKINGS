#pragma once
#include "ObjetoMovil.h"
#include "ColorRGB.h"
#include "Vector2D.h"

class Disparo:public ObjetoMovil
{
private:
	float da�o; //Da�o que produce el disparo
	Vector2D origen;
public:
	Disparo();
	Disparo(float da�o);
	virtual ~Disparo();
	virtual void dibuja()=0;
	Vector2D getOrigen();
	void setOrigen(Vector2D ori);
	void setOrigen(float ix, float iy);
	float getDa�o();
};

