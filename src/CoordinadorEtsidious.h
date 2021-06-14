/*El coordinador ser� la clase encargada de gestionar las llamadas
a los m�todos de la clase mundo por parte de la librer�a
GLUT. Se encargr� as� de controlar los estados que pueda tener
el juego*/

#pragma once
#include"Mundo.h"
#include"ETSIDI.h"
class CoordinadorEtsidious
{
protected:
	Mundo* mundo;
	enum class Estado{INICIO, JUEGO, GAMEOVER, FIN, PAUSA, RANKING};
	Estado estado;
	float puntuacion;
	bool flag_mundo; //�Hay un mundo creado? TRUE:=SI FALSE:=NO
public:
	CoordinadorEtsidious();
	virtual ~CoordinadorEtsidious();
	void teclaEspecial(int key);
	void teclaEspecialUp(int key);
	void tecla(unsigned char key);
	void teclaUp(unsigned char key);
	void mueve(float t);
	void dibuja();
	void inicializa();
	void aleatorio();
};

