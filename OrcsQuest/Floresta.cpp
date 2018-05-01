#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "engcomp_glib.h"

using namespace std;

#include "Flecha.h"
#include "OrcsSoldados.h"
#include "Floresta.h"

Floresta::Floresta()
{
	desaparece = false;
}

Floresta::~Floresta(void)
{
}

int Floresta::flechasize()
{
	return flechas.size();
}
void Floresta::adicionarFlecha(int px_flecha, int py_flecha)
{
	Flecha fl(px_flecha,py_flecha);
	fl.carregarSprites();
	flechas.push_back(fl);
}

OrcsSoldados& Floresta::getOrc(int i)
{
	return vetordeorcs[i];
}

Flecha& Floresta::getDisparo(int j)
{
	return flechas[j];
}

void Floresta::adicionarOrcsSoldados()
{
	vetordeorcs[0].setarPos(500,290);
	vetordeorcs[0].CarregarSprites();

	vetordeorcs[1].setarPos(700,280);
	vetordeorcs[1].CarregarSprites();

	vetordeorcs[2].setarPos(900,270);
	vetordeorcs[2].CarregarSprites();

	vetordeorcs[3].setarPos(1100,280);
	vetordeorcs[3].CarregarSprites();

	vetordeorcs[4].setarPos(1300,290);
	vetordeorcs[4].CarregarSprites();

	vetordeorcs[5].setarPos(1500,280);
	vetordeorcs[5].CarregarSprites();

	vetordeorcs[6].setarPos(1800,270);
	vetordeorcs[6].CarregarSprites();

	vetordeorcs[7].setarPos(2000,280);
	vetordeorcs[7].CarregarSprites();

	vetordeorcs[8].setarPos(2200,270);
	vetordeorcs[8].CarregarSprites();
	
	vetordeorcs[9].setarPos(2400,280);
	vetordeorcs[9].CarregarSprites();
	

}


	

void Floresta::desenha()
{

}
void Floresta::carregarSprites()
{
	fundo.carregar("floresta.bmp");

	adicionarOrcsSoldados();

	floresta.carregar("minigame2.bmp");

}

void Floresta::mostrar()
{
	fundo.desenha (217,148);

	for (int j = 0; j < 10; j++)
	{
		vetordeorcs[j].desenha();
		
	} 

	floresta.desenha(0,0);

	for (int i = 0; i < flechas.size(); i++)
	{
		flechas[i].desenha();
	}                                                                                                                                                             

}
