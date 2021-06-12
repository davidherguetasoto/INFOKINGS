#pragma once
#include "Nave.h"
#include "ColorRGB.h"


#define VELOCIDAD_PERSONAJE 15.0f //Macro para decidir el valor de la velocidad a la que ir� el personaje
#define MISILES_MAX 10 //N�mero m�ximo de misiles que puede llevar la nave
#define VIDA_MAX 100 //Vida m�xima del personaje
class NavePersonaje :public Nave
{
protected:
	//PROVISIONAL PARA HACER DIBUJOS DE PRUEBA
	float altura;
	float radio;
	ColorRGB color;
	//prueba bonus
	int num_bonus;
	bool disparo_misiles; //Modo de disparo con misiles
	int num_misiles; //Contador de los misiles que podemos disparar
public:
	NavePersonaje();
	void dibuja(); //Define c�mo se dibuja el personaje
	friend class Interaccion;
	float getRadio() { return radio; }
	float getAltura() { return altura; }
	int getNumMisiles() { return num_misiles; }
	void setNumMisiles(int misiles);

	//TRUE:= La nave dispara misil, FALSE:=Disparo normal
	void setDisparoMisiles(bool modo) { disparo_misiles = modo; }
	bool getModoMisiles() { return disparo_misiles; }

	//prueba bonus
	void IncrementaNumBonus();
	void SetNumBonuns(int num);
	int GetNumBonus();
	void setVida(float vida);
	//prueba bonus
};