#pragma once

class Flecha
{
private:
	int x_flecha;
	int y_flecha;
	imagem flecha;

public:
	Flecha(int px_flecha, int py_flecha);
	Flecha ();
	~Flecha(void);
	void carregarSprites();
	void mostrar();
	void desenha ();
	int getx ();
	int gety ();
	imagem& getimages();
};
