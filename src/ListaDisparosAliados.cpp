#include "ListaDisparosAliados.h"
#include "Interaccion.h"

ListaDisparosAliados::ListaDisparosAliados()
{
	numero = 0;
	for (int i = 0; i < MAX_DISPAROS; i++)
		lista[i] = 0;
}

ListaDisparosAliados::~ListaDisparosAliados()
{

}

bool ListaDisparosAliados::agregar(Disparo* d) {
	if (numero < MAX_DISPAROS) {
		for (int i = 0; i < numero; i++) {
			if (lista[i] == d)
				return true; //no se ha alcanzado la capacidad max
		}
		lista[numero++] = d; // �ltimo puesto sin rellenar
							 // Despu�s de a�adir el disparo, incrementa numero
	}
	else
		return false; // capacidad m�xima alcanzada
	return true; //no se ha alcanzado la capacidad max
}

void ListaDisparosAliados::destruirContenido() {
	for (int i = 0; i < numero; i++) // destrucci�n de disparos contenidos
		delete lista[i];
	numero = 0; // inicializa lista
}

void ListaDisparosAliados::mueve(float t) {
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}

void ListaDisparosAliados::dibuja() {
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

void ListaDisparosAliados::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void ListaDisparosAliados::eliminar(Disparo* d)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == d)
		{
			eliminar(i); //reutilizaci�n del c�digo anterior
			return;
		}
}

Disparo* ListaDisparosAliados::operator[](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}
