#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "engcomp_glib.h"

using namespace std;


#include "OrcsSoldados.h"


OrcsSoldados::OrcsSoldados()
{
}

OrcsSoldados::OrcsSoldados(float px_orc, int py_orc)
{
}

OrcsSoldados::~OrcsSoldados(void)
{
}

float OrcsSoldados::getx()
{
	return x_orc;
}


int OrcsSoldados::gety()
{
	return y_orc;
}
float OrcsSoldados::getvel()
{
	return x_orc -= 0.3;
}

float OrcsSoldados::getvelo()
{
	return x_orc -=0.4;
}
float OrcsSoldados::getveloc()
{
	return x_orc -=0.5;
}
float OrcsSoldados::getvelocidad()
{
	return x_orc --;
}


imagem& OrcsSoldados::getimages()
{
	return orc;
}


void OrcsSoldados::setarPos(float px_orc, int py_orc)
{
x_orc = px_orc;
y_orc = py_orc;
}

void OrcsSoldados::CarregarSprites()
{
	orc.carregar("orc1.bmp");
	orc.carregar("orc2.bmp");
}
void OrcsSoldados::desenha()
{
	orc.desenha(x_orc,y_orc);


	if (x_orc < 215)
	{
		x_orc = 2400;
	}	

}

