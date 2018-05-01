#pragma once


class OrcsSoldados
{
private:
	float x_orc;
	int y_orc;
	imagem orc;

public:
	OrcsSoldados();
	OrcsSoldados(float px_orc, int py_orc);
	void setarPos(float px_orc, int py_orc);
	~OrcsSoldados(void);
	void CarregarSprites ();
	void atualiza();
	void desenha();
	float getx ();
	int gety();
	float getvel ();
	float getvelo ();
	float getveloc ();
	float getvelocidad ();
	imagem& getimages();
};
