#pragma once

class Floresta
{
private:

	imagem fundo;
	imagem floresta;
	int x_floresta;
	int y_floresta;
	bool desaparece;
	OrcsSoldados vetordeorcs[10];
	vector<Flecha> flechas;
	
public:
	Floresta();
	~Floresta(void);
	void adicionarFlecha (int px_flecha, int py_flecha);
	void adicionarOrcsSoldados ();
	void desenha();
	void mostrar();
	void carregarSprites();
	int flechasize();
	OrcsSoldados& getOrc(int i);
	Flecha& getDisparo (int j);

	
};
