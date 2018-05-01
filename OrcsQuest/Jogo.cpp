#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "engcomp_glib.h"

using namespace std;
#include "Flecha.h"
#include "OrcsSoldados.h"
#include "Floresta.h"
#include "Elfo.h"
#include "Sons.h"
#include "Jogo.h"


string converte(int val)
{
	string temp;
	stringstream conv;

	conv << val;
	conv >> temp;

	return temp;
}


Jogo::Jogo(void)
{
}

Jogo::~Jogo(void)
{
}


void Jogo::rodar()
{
	egl_inicializar(800,600,true);

	player1.carregarSprites();
	floresta.carregarSprites();
	or.CarregarSprites();
	menu.carregar("minigame4.bmp");
	help.carregar("minigame5.bmp");
	configuracao.carregar("minigame6.bmp");
	gov.carregar("gameover.bmp");
	venceu.carregar("minigame7.bmp");

	player1.setMapa(&floresta);

	life = 1000;
	exp = 0;
	men = true;

	Sons song;
	song.CarregarSons();
	song.TocarSons();
	

	while(!key[KEY_ESC])
	{
		if (key[KEY_S])
		{
			ofstream salvar ("salvar.txt");

			salvar << life;
			
			ofstream salvexp ("salvexp.txt");

			salvexp << exp;
		}

		if (key[KEY_L])
		{
			ifstream salvar ("salvar.txt");

			salvar >> life;

			ifstream salvexp ("salvexp.txt");

			salvexp >> exp;
		}

		if (!key[KEY_ESC] && men == true )
		{
			menu.desenha(0,0);
		}

		if (key[KEY_F1])
		{
			men = false;
			game = true;
			helps = false;
			config = false;
		}
		if (key[KEY_F2])
		{
			helps = true;
			game = false;
			config = false;
		}

		if (key[KEY_F3])
		{
			config = true;
			game = false;
			helps = false;
		}

		if (!key[KEY_ESC] && config == true && helps == false && game == false)
		{
			configuracao.desenha(0,0);
			
			if(key[KEY_P])
			{
				song.PararSons();
			}
			if(key[KEY_1])
			{
				song.TocarM();
			}
			if(key[KEY_2])
			{
				song.TocarMu();
			}
			if(key[KEY_3])
			{
				song.TocarMus();
			}

			if(key[KEY_BACKSPACE])
			{
				config = false;
				game = false;
				men = true;
			}
		}



		if (!key[KEY_ESC] && helps == true && game == false && config == false)
		{
			help.desenha(0,0);

			if(key[KEY_BACKSPACE])
			{
				config = false;
				helps = false;
				game = false;
				men = true;
			}

		}
	

		if (!key[KEY_ESC] && game == true && helps == false)
		{

			if(key[KEY_BACKSPACE])
			{
				config = false;
				helps = false;
				game = false;
				men = true;
			}

		floresta.mostrar();
		player1.atualiza();
		player1.mostrar();
		or.desenha();
		

		for(int i = 0; i < 10; i++)
		{
			if (player1.getimages().colide(player1.getx(),player1.gety(),floresta.getOrc(i).getx(),floresta.getOrc(i).gety(),or.getimages()))
			{
				life --;
			
				if (life < 0)
				{
					game = false;
					song.TocarLoose();
					song.PararSons();
				}
			}
		}
		for(int i = 0; i < 10; i++)
		{
			for (int j = 0; j < floresta.flechasize(); j++)
			{
				if (floresta.getDisparo(j).getimages().colide(floresta.getDisparo(j).getx(),floresta.getDisparo(j).gety(),floresta.getOrc(i).getx(),floresta.getOrc(i).gety(),or.getimages()))
				{
					exp++;

					if (life > 0 && exp > 5000)
					{
						game = false;
						song.PararSons();
						song.TocarWin();
					}

				}
			}
		}

		for(int i = 0; i < 10; i++)
		{
			if (exp < 500)
			{
				floresta.getOrc(i).getvel();
			}

			if (exp > 500)
			{
				floresta.getOrc(i).getvelo();
			}
			if (exp > 1000)
			{
				floresta.getOrc(i).getveloc();
			}
			if (exp > 1500)
			{
				floresta.getOrc(i).getvelocidad();
			}

		}
	

		egl_texto(converte(life),265,405);
		egl_texto(converte(exp),520,405);
		}

		if (!key[KEY_ESC] && game == false && life < 0)
		{
			gov.desenha(0,0);
		}

		if (!key[KEY_ESC] && game == false && life > 0 && exp > 5000)
		{
			venceu.desenha(0,0);
		}

		egl_desenha_frame();
	}

	void egl_finalizar();
}