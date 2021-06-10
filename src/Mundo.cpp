#include "Mundo.h"
#include "freeglut.h"
#include"Interaccion.h"
Mundo::Mundo():x_ojo(0),y_ojo(0),z_ojo(0)
{

}
Mundo::~Mundo()
{
	
}
void Mundo::inicializa()
{
	x_ojo = x;
	y_ojo = y;
	z_ojo = z;

	Obstaculo* e1 = new Obstaculo();
	asteroides.agregar(e1);
	
}
void Mundo::dibuja()
{
	//PUNTO DE VISTA DE LA C�MARA
	gluLookAt(x, y, z, // posicion del ojo
		0.0, 8, 0.0, // hacia que punto mira
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Z)
	
	//DIBUJAR OBJETOS DE LA PANTALLA
	caja.dibuja();
	personaje.dibuja();
	asteroides.dibuja();
	disparos.dibuja();
}
void Mundo::mueve(float t)
{
	personaje.mueve(t);
	asteroides.mueve(0.025f);
	disparos.mueve(0.025f);
	Interaccion::rebote(personaje, caja);
	//personaje.setVel(0.0, 0.0);

	/*for (int i = asteroides.getNum(); i > 0; i--) {
		for (int j = 0; j < disparos.getNumero(); j++) {
			if (Interaccion::colision(*asteroides[i], *disparos[j])) {
				disparos.eliminar(disparos[j]);
				asteroides.eliminar(asteroides[i]);
			}
		}
	}*/
}
void Mundo::tecla(unsigned char key)
{
	//TECLAS PARA CAMBIAR EL PUNTO DE VISTA DURANTE EL DESARROLLO
	switch (key)
	{
	case'z':
	{
		x++;
		break;
	}
	case'x':
	{
		x--;
		break;
	}
	case'c':
	{
		y++;
		break;
	}
	case'v':
	{
		y--;
		break;
	}
	case'b':
	{
		z++;
		break;
	}
	case'n':
	{
		z--;
		break;
	}
	case' ':
	{
		personaje.setVel(0.0, 0.0);
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
		if(!Interaccion::rebote(personaje,caja.pared_izq))
		personaje.setVel(-15.0f, 0.0f);
		break;
	}
	case GLUT_KEY_RIGHT:
	{
		if (!Interaccion::rebote(personaje, caja.pared_dcha))
		personaje.setVel(15.0f, 0.0f);
		break;
	}
	case GLUT_KEY_UP:
	{
		if (!Interaccion::rebote(personaje, caja.techo))
		personaje.setVel(0.0f, 15.0f);
		break;
	}
	case GLUT_KEY_DOWN:
	{
		if (!Interaccion::rebote(personaje, caja.suelo))
		personaje.setVel(0.0f, -15.0f);
		break;
	}	
	}
}
void Mundo::teclaEspecialUp(unsigned char key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		personaje.setVel(0.0f, 0.0f);
		break;
	case GLUT_KEY_RIGHT:
		personaje.setVel(0.0f, 0.0f);
		break;
	case GLUT_KEY_UP:
		personaje.setVel(0.0f, 0.0f);
		break;
	case GLUT_KEY_DOWN:
		personaje.setVel(0.0f, 0.0f);
		break;
	}
}


