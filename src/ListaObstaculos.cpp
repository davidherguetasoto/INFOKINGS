#include "ListaObstaculos.h"

ListaObstaculos::ListaObstaculos()
{
	num = 0;
	for (int i = 0; i < MAX; i++)
		lista[i] = 0;
}

void ListaObstaculos::destruirContenido()
{
	for (int i = 0; i < num; i++) // destrucci�n de esferas contenidas
		delete lista[i];
	num = 0; // inicializa lista
}

void ListaObstaculos::eliminar(int index)
{
	if ((index < 0) || (index >= num))
		return;
	delete lista[index];
	num--;
	for (int i = index; i < num; i++)
		lista[i] = lista[i + 1];
}

void ListaObstaculos::eliminar(Obstaculo* e)
{
	for (int i = 0; i < num; i++)
		if (lista[i] == e)
		{
			eliminar(i); //reutilizaci�n del c�digo anterior
			return;
		}
}

bool ListaObstaculos::agregar(Obstaculo* e)
{
	if (num < MAX) {
		for (int i = 0; i < num; i++) {
			if (lista[i] == e)
				return true; //no se ha alcanzado la capacidad max
		}
		lista[num++] = e; // �ltimo puesto sin rellenar
							 // Despu�s de a�adir la esfera, incrementa numero
	}
	else
		return false; // capacidad m�xima alcanzada
	return true; //no se ha alcanzado la capacidad max
}

void ListaObstaculos::Dibuja()
{
	for (int i = 0; i < num; i++)
		lista[i]->Dibuja();
}

void ListaObstaculos::Mueve(float t)
{
	for (int i = 0; i < num; i++)
		lista[i]->Mueve(t);
}