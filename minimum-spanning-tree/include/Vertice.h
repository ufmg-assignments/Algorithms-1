#ifndef VERTICE_H_INCLUDED
#define VERTICE_H_INCLUDED
#pragma once

class Vertice
{
private:
	int X;
	int Y;
	int id;
	int rank;
	Vertice* parent;

public:

	//Construtor inicializa os valores de id, X e Y  do vertice
	Vertice(int coordenadaX, int coordenadaY, int identificacao);

	//Retorna o valor do atributo X
	int getX();

	//Retorna o valor do atributo Y
	int getY();

	friend class Grafo;
};

#endif //VERTICE_H_INCLUDED