#include "Mundo.h"
#include "freeglut.h"
#include"Interaccion.h"
Mundo::Mundo() :x_ojo(0), y_ojo(0), z_ojo(0), nivel(1)
{

}
Mundo::~Mundo()
{
	enemigos.destruirContenido();
}
void Mundo::inicializa()
{
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 40;

	nivel = 0;
	cargarNivel();
}
void Mundo::dibuja()
{
	//PUNTO DE VISTA DE LA CÁMARA
	gluLookAt(/*x, y, z,*/
		x_ojo, y_ojo, z_ojo, // posicion del ojo
		0.0, y_ojo, 0.0, // hacia que punto mira
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Z)

	//DIBUJAR OBJETOS DE LA PANTALLA
	caja.dibuja();
	personaje.dibuja();
	asteroides.dibuja();
	enemigos.dibuja();
	disparos.dibuja();

	ETSIDI::setTextColor(1, 1, 0);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
	ETSIDI::printxy("ETSIDIOUS", -11, 21);

	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
	ETSIDI::printxy("Infokings", 3.5, 21);
}

void Mundo::mueve()
{
	personaje.mueve(0.025f);
	Interaccion::rebote(personaje, caja);

	asteroides.mueve(0.025f);
	enemigos.mueve(0.025f);

	disparos.mueve(0.025f);
	disparos.colision(caja);
	//Colision de los disparos con naves
	for (int i = 0; i < disparos.getNumero(); i++)
	{
		int tipo = disparos[i]->getTipo();
		if (tipo == DISPARO_ALIADO||tipo==DISPARO_DOBLE||tipo==MISIL)
		{
			for (int n = 0; n < enemigos.getNumero(); n++)
			{
				DisparoAliado* d = (DisparoAliado*)disparos[i];
				if (Interaccion::colision(*d, *enemigos[n]))
				{
					enemigos[n]->setVida((enemigos[n]->getVida()) - (disparos[i]->getDano()));
					if (enemigos[n]->getVida() <= 0.0f)
						enemigos.eliminar(enemigos[n]);
					disparos.eliminar(disparos[i]);
				}
			}
		}
		if (tipo == DISPARO_ENEMIGO)
		{
			DisparoEnemigo* d = (DisparoEnemigo*)disparos[i];
			if (Interaccion::colision(*d, personaje))
			{
				personaje.setVida(personaje.getVida() - disparos[i]->getDano());
				disparos.eliminar(disparos[i]);
			}
		}
	}
	//INTERACCIÓN DE LOS DISPAROS CON LOS ASTEROIDES
	for (int i = 0; i < disparos.getNumero(); i++)
	{
		for (int n = 0; n < asteroides.getNum(); n++)
		{
			int tipo = disparos[i]->getTipo();
			if (tipo == DISPARO_ALIADO || tipo == DISPARO_DOBLE)
			{
				DisparoAliado* d = (DisparoAliado*)disparos[i];
				if (Interaccion::colision(*asteroides[n], *d))
				{
					disparos.eliminar(disparos[i]);
				}
			}
			if (tipo == MISIL)
			{
				Misil* m = (Misil*)disparos[i];
				if (Interaccion::colision(*asteroides[n], *m))
				{
					asteroides.eliminar(asteroides[n]);
					disparos.eliminar(disparos[i]);
				}
			}
		}
	}


}
void Mundo::tecla(unsigned char key)
{
	switch (key)
	{
	//TECLAS PARA CAMBIAR EL PUNTO DE VISTA DURANTE EL DESARROLLO
	case'z':
	{
		x_ojo++;
		break;
	}
	case'x':
	{
		x_ojo--;
		break;
	}
	case'c':
	{
		y_ojo++;
		break;
	}
	case'v':
	{
		y_ojo--;
		break;
	}
	case'b':
	{
		z_ojo++;
		break;
	}
	case'n':
	{
		z_ojo--;
		break;
	}
	//DISPARO ESTÁNDAR
	case' ':
	{
		if (disparos.getNumero() < MAX_DISPAROS)
		{
			if (!personaje.getModoDisparo())
			{
				Disparo* d = new DisparoAliado;
				d->setPos(personaje.getPos());
				disparos.agregar(d);
			}
			else if (personaje.getModoDisparo())
			{
				int misiles = 0;
				for (int i = 0; i < disparos.getNumero(); i++)
				{
					int tipo = disparos[i]->getTipo();
					if (tipo == MISIL)misiles++;
				}
				if (misiles < personaje.getNumMisiles() && personaje.getNumMisiles()>0)
				{
					Disparo* d = new Misil;
					d->setPos(personaje.getPos());
					disparos.agregar(d);
					personaje.setNumMisiles(personaje.getNumMisiles() - 1);
					int p = personaje.getNumMisiles();
				}
			}
			}
		break;
	}
	//MODO DISPARO
	case'd':
	{
		if (personaje.getModoDisparo())personaje.setDisparoMisiles(false);
		else if(personaje.getNumMisiles()>0)personaje.setDisparoMisiles(true);
		break;
	}
	}
}
void Mundo::teclaEspecialUp(unsigned char key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
	{
		if(personaje.getVel().x==-VELOCIDAD_PERSONAJE)
		personaje.setVel(0.0f, 0.0f);
		break;
	}
	case GLUT_KEY_RIGHT:
	{
		if (personaje.getVel().x == VELOCIDAD_PERSONAJE)
		personaje.setVel(0.0f, 0.0f);
		break;
	}
	case GLUT_KEY_UP:
	{
		if (personaje.getVel().y == VELOCIDAD_PERSONAJE)
		personaje.setVel(0.0f, 0.0f);
		break;
	}
	case GLUT_KEY_DOWN:
	{
		if (personaje.getVel().y == -VELOCIDAD_PERSONAJE)
		personaje.setVel(0.0f, 0.0f);
		break;
	}
	}
}

void Mundo::teclaEspecial(unsigned char key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
	{
		if (!Interaccion::rebote(personaje, caja.pared_izq))
		{
			personaje.setVel(-VELOCIDAD_PERSONAJE, 0.0f);
		}
		break;
	}
	case GLUT_KEY_RIGHT:
	{
		if (!Interaccion::rebote(personaje, caja.pared_dcha))
		{
			personaje.setVel(VELOCIDAD_PERSONAJE, 0.0f);
		}
		break;
	}
	case GLUT_KEY_UP:
	{
		if (!Interaccion::rebote(personaje, caja.techo))
		{
			personaje.setVel(0.0f, VELOCIDAD_PERSONAJE);
		}
		break;
	}
	case GLUT_KEY_DOWN:
	{
		if (!Interaccion::rebote(personaje, caja.suelo))
		{
			personaje.setVel(0.0f, -VELOCIDAD_PERSONAJE);
		}
		break;
	}	
	}
}

int Mundo::getNumEnemigos()
{
	return enemigos.getNumero();
}

bool Mundo::cargarNivel()
{
	nivel++;
	personaje.setPos(0, 0);
	enemigos.destruirContenido();
	//disparos.destruirContenido();

	if (nivel == 1) {
		NaveEnemiga* n1 = new NaveEnemiga();
		enemigos.agregar(n1);
		enemigos[0]->setPos(0.0f, 16.0f);
	}
	if (nivel == 2) {
		for (int i = 0; i < 5; i++) {
			//agregar muchos enemigos
		}
	}
	if (nivel == 3) {
			//agregar el jefe
	}
	if (nivel <= 3)
		return true;
	return false;
}

void Mundo::aleatorio()
{
	float lim1 = caja.pared_izq.getLim1().x;
	float lim2 = caja.pared_dcha.getLim1().x;
	float x = lim1 + rand() % (int)(lim2 - lim1);
	Obstaculo* o2 = new Obstaculo();
	o2->setPos(x, caja.techo.getLim1().y);
	asteroides.agregar(o2);
}