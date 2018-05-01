#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "engcomp_glib.h"

using namespace std;

#include "Flecha.h"
#include "OrcsSoldados.h"
#include "Floresta.h"
#include "Elfo.h"

Elfo::Elfo(void)
{
	x_elfo = 225;
	y_elfo = 315;
	estado = parad;

	repete = true;
}

Elfo::~Elfo(void)
{
}

float Elfo::getx ()
{
	return x_elfo;
}
float Elfo::gety ()
{
	return y_elfo;
}


imagem& Elfo::getimages()
{
	switch(estado)
	{
	case 1:
		return sprite;
	case 2:
		return prepara;
	case 3:
		return ataque;
	case 4:
		return parado;
	case 5:
		return pulando;
	}
	return parado;
}


void Elfo::carregarSprites()
{
sprite.carregar ("elfo3.bmp");
sprite.carregar ("elfo4.bmp");
sprite.carregar ("elfo5.bmp");

prepara.carregar ("elfo7.bmp");

parado.carregar ("elfo5.bmp");

ataque.carregar ("elfo8.bmp");

pulando.carregar ("elfo_pulando.bmp");
}

void Elfo::setMapa(Floresta* novo)
{
	floresta = novo;
}

void Elfo::mostrar()
{
}
void Elfo::atualiza()
{
	if(key[KEY_LEFT] && (estado != puland) )
	{
		x_elfo-=0.3;
		estado = sprit;
	}
	if(key[KEY_RIGHT]&& (estado != puland))
	{
		x_elfo+=0.3;
		estado = sprit;
	}
	if(key[KEY_C]&& (estado != puland))
	{
		estado = prep;
	}
	if (key[KEY_SPACE]&& (estado != puland) && (repete == true))
	{
		repete = false;
		if (key[KEY_C])
		{
		estado = atac;
		}
	}
	if (!key[KEY_SPACE]) 
	{
		repete = true;
	}
	
	if (key[KEY_UP] && (estado != puland))
	{
		estado = puland;
		gravidade = 0.01;
		vy = -1.4;
	}
	if (!key[KEY_LEFT] && !key[KEY_RIGHT] && !key[KEY_C] && !key[KEY_SPACE] && (estado != puland))
	{
		estado = parad;
	}



	
	if(x_elfo < 225)
	{
		x_elfo = 225;
	}
	if(x_elfo > 520)
	{
		x_elfo = 520;
	}

	switch(estado)
	{
	case 1:
		sprite.desenha(x_elfo,y_elfo);
		break;
	case 2:
		prepara.desenha(x_elfo,y_elfo);
		break;
	case 3:
		ataque.desenha(x_elfo,y_elfo);
		floresta->adicionarFlecha(x_elfo+15,y_elfo+20);
		break;
	case 4:
		parado.desenha(x_elfo,y_elfo);
		break;
	case 5: //pulando
		pulando.desenha(x_elfo,y_elfo);
		y_elfo += vy;
		vy += gravidade;
		if(y_elfo > 315)
		{
			y_elfo = 315;
			estado = parad;
		}

		if(key[KEY_LEFT]) x_elfo-=0.3;
		if(key[KEY_RIGHT]) x_elfo+=0.3;

		break;
	}

}
