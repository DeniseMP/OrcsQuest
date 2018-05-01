#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "engcomp_glib.h"

using namespace std;


#include "Sons.h"

Sons::Sons(void)
{
}

Sons::~Sons(void)
{
}

void Sons::CarregarSons()
{
	music.carregar("nature.wav");
	m.carregar("som8.wav");
	mu.carregar("som4.wav");
	mus.carregar("som9.wav");
	loose.carregar("over.wav");
	win.carregar("win.wav");
}
void Sons::TocarSons()
{
	music.tocar(1);
}

void Sons::TocarLoose()
{
	loose.tocar(1);
}

void Sons::TocarWin()
{
	win.tocar(1);
}

void Sons::TocarM()
{
	m.tocar(1);
	music.parar();
	mu.parar();
	mus.parar();
}

void Sons::TocarMu()
{
	mu.tocar(1);
	music.parar();
	m.parar();
	mus.parar();
}

void Sons::TocarMus()
{
	mus.tocar(1);
	music.parar();
	m.parar();
	mu.parar();
}


void Sons::PararSons()
{
	music.parar();
	m.parar();
	mu.parar();
	mus.parar();
}