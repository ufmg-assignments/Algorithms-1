#include "Funcoes.h"
#include <iostream>

bool compararArestas(Aresta* a1, Aresta* a2)
{
	return a1->getPeso() < a2->getPeso();
}