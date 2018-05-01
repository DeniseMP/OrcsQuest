#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "engcomp_glib.h"

using namespace std;

#include "Flecha.h"

Flecha::Flecha(int px_flecha, int py_flecha)
{
	x_flecha = px_flecha;
	y_flecha = py_flecha;
}

Flecha::Flecha()
{
}

Flecha::~Flecha(void)
{
}

int Flecha::getx()
{
	return x_flecha;
}
int Flecha::gety()
{
	return y_flecha;
}
imagem& Flecha::getimages()
{
	return flecha;
}

void Flecha::carregarSprites()
{
	flecha.carregar("flecha.bmp");
}
void Flecha::mostrar()
{
}
void Flecha::desenha()
{
	flecha.desenha(x_flecha,y_flecha);

	x_flecha++;

	if (x_flecha > 550)
	{
		x_flecha = 5000;
	}
}
