#ifndef ARESTA_H_INCLUDED
#define ARESTA_H_INCLUDED
#pragma once
#include "Vertice.h"
#include <cmath>
#include <iostream>

class Aresta
{
private:
	Vertice* v1;
	Vertice* v2;
	double peso;

public:

	//Construtor que inicializa os vertices da aresta e calcula o
	//peso com base nos valores de x e y da cada vertice
	Aresta(Vertice* vertice1, Vertice* vertice2);

	//Retorna o valor do atributo peso
	double getPeso();

	friend class Grafo;
};

#endif //ARESTA_H_INCLUDED