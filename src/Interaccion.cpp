#include "Interaccion.h"

bool Interaccion::rebote(NavePersonaje& nave, Pared pared)
{
	Vector2D distancia;
	distancia = pared.distancia(nave.getPos());

	if (distancia.modulo() <= 0.45f )
		return true;
	else return false;
}
void Interaccion::rebote(NavePersonaje& nave, Caja caja)
{
	bool flag_pared_izq = false, flag_pared_dcha = false, flag_techo = false, flag_suelo = 0;
	Vector2D pos = nave.getPos();

	if (pos.x <= caja.pared_izq.getLim1().x+1.95f)flag_pared_izq = true;
	else flag_pared_izq = false;

	if (pos.x >= caja.pared_dcha.getLim1().x-1.95f)flag_pared_dcha = true;
	else flag_pared_dcha = false;

	if (pos.y <= caja.suelo.getLim1().y+1.95f)flag_suelo = true;
	else flag_suelo = false;

	if (pos.y >= caja.techo.getLim1().y-1.95f)flag_techo = true;
	else flag_techo = false;

	if (flag_suelo)
	nave.setPos(nave.posicion.x, caja.suelo.limite1.y+2.0f);
	else if (flag_pared_izq)
		nave.setPos(caja.pared_izq.limite1.x+2.0f, nave.posicion.y);
	else if (flag_pared_dcha)
		nave.setPos(caja.pared_dcha.limite1.x-2.0f, nave.posicion.y);
	else if (flag_techo)
		nave.setPos(nave.posicion.x, caja.techo.limite1.y-2.0f);
}

bool Interaccion::colision(Obstaculo o, DisparoAliado d)
{
	Vector2D distancia = d.getPos() - o.getPos();
	if (distancia.modulo() < (d.getRadio() + o.getRadio()))
		return true;
	return false;
}
bool Interaccion::colision(Obstaculo o, Misil m)
{
	Vector2D distancia = m.getPos() - o.getPos();
	if (distancia.modulo() < (m.getRadio() + o.getRadio()))
		return true;
	return false;
}

bool Interaccion::colision(Obstaculo o, Pared p)
{
	if (o.getPos().y < p.getLim1().y) { return true; }
	return false;
}


bool Interaccion::colision(Obstaculo o, NavePersonaje n)
{
	Vector2D distancia = n.getPos() - o.getPos();
	if (distancia.modulo() < (n.getRadio() + o.getRadio()))
		return true;
	return false;
}

bool Interaccion::colision(DisparoAliado d, Pared p)
{
	Vector2D distancia=p.distancia(d.getPos());
	if (distancia.modulo() <= (d.getRadio() + 0.05f))
		return true;
	return false;

}
bool Interaccion::colision(DisparoEnemigo d, Pared p)
{
	Vector2D distancia = p.distancia(d.getPos());
	if (distancia.modulo() <= (d.getRadio()+0.05f))
		return true;
	return false;

}
bool Interaccion::colision(DisparoAliado d, Caja c)
{

	bool flag_pared_izq=false, flag_pared_dcha=false, flag_techo=false, flag_suelo=0;
	Vector2D pos = d.getPos();
	
	if (pos.y <= c.suelo.getLim1().y)flag_suelo = true;
	else flag_suelo = false;

	if (pos.y >= c.techo.getLim1().y)flag_techo = true;
	else flag_techo = false;

	if (flag_suelo || flag_techo || flag_pared_izq || flag_pared_dcha)
		return true;
	return false;
}
bool Interaccion::colision(DisparoEnemigo d, Caja c)
{
	bool flag_pared_izq = false, flag_pared_dcha = false, flag_techo = false, flag_suelo = 0;
	Vector2D pos = d.getPos();

	if (pos.y <= c.suelo.getLim1().y)flag_suelo = true;
	else flag_suelo = false;

	if (pos.y >= c.techo.getLim1().y)flag_techo = true;
	else flag_techo = false;

	if (flag_suelo || flag_techo || flag_pared_izq || flag_pared_dcha)
		return true;
	return false;
}

bool Interaccion::colision(DisparoAliado d, NaveEnemiga n)
{
	Vector2D distancia = n.getPos() - d.getPos();
	if (distancia.modulo() <= (d.getRadio()+0.07f+n.getRadio()))
	{
		return true;
	}
	return false;
}
bool Interaccion::colision(DisparoEnemigo d, NavePersonaje n)
{
	Vector2D distancia = n.getPos() - d.getPos();
	if (distancia.modulo() < (d.getRadio()+0.07f+n.getRadio()))
	{
		return true;
	}
	return false;
}


//interacciones para que desaparezca el bonus sino lo coge la nave personaje
bool Interaccion::colision(BonusDisparoDoble b, Pared p)
{
	if (b.getPos().y < p.getLim1().y)
	{
		return true;
	}
	return false;
}
bool Interaccion::colision(BonusMisiles b, Pared p)
{
	if (b.getPos().y < p.getLim1().y)
	{
		return true;
	}
	return false;
}
bool Interaccion::colision(BonusPuntExtras b, Pared p)
{
	if (b.getPos().y < p.getLim1().y)
	{
		return true;
	}
	return false;
}
bool Interaccion::colision(BonusVidas b, Pared p)
{
	if (b.getPos().y < p.getLim1().y)
	{
		return true;
	}
	return false;
}

//Interacción  para que la nave coja el bonus que sale
bool Interaccion::colision(BonusDisparoDoble b, NavePersonaje n)
{
	Vector2D distancia = n.getPos() - b.getPos();
	if (distancia.modulo() < (b.getLado()))
	{
		return true;
	}
	return false;
}
bool Interaccion::colision(BonusMisiles b, NavePersonaje n)
{
	Vector2D distancia = n.getPos() - b.getPos();
	if (distancia.modulo() < (b.getLado()))
	{
		return true;
	}
	return false;
}
bool Interaccion::colision(BonusPuntExtras b, NavePersonaje n)
{
	Vector2D distancia = n.getPos() - b.getPos();
	if (distancia.modulo() < (b.getLado()))
	{
		return true;
	}
	return false;
}
bool Interaccion::colision(BonusVidas b, NavePersonaje n)
{
	Vector2D distancia = n.getPos() - b.getPos();
	if (distancia.modulo() < (b.getLado()))
	{
		return true;
	}
	return false;
}