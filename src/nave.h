#pragma once
#include "ObjetoMovil.h"
class Nave : public ObjetoMovil
{
protected:
	float vida; //Vida de las naves
	//provisional
	float radio;
	float altura;
public:
	void Dibuja();
	//a�adir funcion para disparo
};

