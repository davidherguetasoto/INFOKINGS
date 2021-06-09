#pragma once
#include "Obstaculo.h"
#define MAX 50

class ListaObstaculos
{
	Obstaculo* lista[MAX];
	int num;

public:
	ListaObstaculos();

	void destruirContenido();
	void eliminar(int index); //elimina esfera por su posici�n en la lista
	void eliminar(Obstaculo* e); //elimina la esfera indica expl�citamente

	bool agregar(Obstaculo* e);	//devuelve 1 si no se ha alcanzado max
								// y 0 si no se ha podido crear

	
	void Mueve(float);
	void Dibuja();

	int getNum() { return num; }
};

