#pragma once
#define sprit 1
#define prep 2
#define atac 3
#define parad 4
#define puland 5

class Elfo
{
private:
	float x_elfo;
	float y_elfo;
	int estado;
	float vx;
	float vy;
	int tempo;
	float gravidade;
	bool repete;

	imagem sprite;
	imagem prepara;
	imagem ataque;
	imagem parado;
	imagem pulando;
	
	Floresta* floresta;
		

public:
	Elfo(void);
	~Elfo(void);
	void mostrar();
	void carregarSprites();
	void atualiza();
	void testacolisao();
	void setMapa(Floresta* novo);
	float getx ();
	float gety ();
	imagem& getimages();

};
