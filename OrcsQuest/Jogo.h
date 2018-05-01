#pragma once

class Jogo
{
private:
	Floresta level1;
	Elfo player1;
	Flecha disparos;
	Floresta floresta;
	OrcsSoldados or;
	int life;
	int exp;
	bool men;
	bool game;
	bool helps;
	bool config;
	imagem menu;
	imagem help;
	imagem configuracao;
	imagem gov;
	imagem venceu;


public:
	Jogo(void);
	~Jogo(void);
	void rodar();
};
