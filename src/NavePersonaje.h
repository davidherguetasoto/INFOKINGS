#pragma once
#include "Nave.h"

#define VELOCIDAD_PERSONAJE 15.0f //Macro para decidir el valor de la velocidad a la que ir� el personaje
#define MISILES_MAX 6 //N�mero m�ximo de misiles que puede llevar la nave
#define VIDA_MAX 100 //Vida m�xima del personaje
class NavePersonaje :public Nave
{
private:
	SpriteSequence sprite_nave{ "imagenes/NavePersonaje.png",1 };
protected:
	float t_DisparoDoble; //tiempo restante del disparo doble
	bool disparo_doble; //Modo de disparo doble
	bool disparo_misiles; //Modo de disparo con misiles
	int num_misiles; //Contador de los misiles que podemos disparar
public:
	NavePersonaje();
	void dibuja(); //Define c�mo se dibuja el personaje
	friend class Interaccion;
	
	int getNumMisiles() { return num_misiles; }
	void setNumMisiles(int misiles);

	//TRUE:= La nave dispara misil, FALSE:=Disparo normal
	void setDisparoMisiles(bool modo) { disparo_misiles = modo; }
	bool getModoMisiles() { return disparo_misiles; }

	//TRUE:=La nave dispara doble (si misil false), FALSE:=Disparo normal
	void setDisparoDoble(bool modo) { disparo_doble = modo; }
	bool getModoDoble() { return disparo_doble; }

	void setVida(float vida);
	float get_t_DisparoDoble() { return t_DisparoDoble; }
	void set_t_DisparoDoble(float t);
};