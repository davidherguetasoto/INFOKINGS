#pragma once
#include "Nave.h"
class NaveEnemiga :public Nave
{
public:
	NaveEnemiga(); //Habr� distintos tipos de enemigos
	friend class Interaccion;
};

