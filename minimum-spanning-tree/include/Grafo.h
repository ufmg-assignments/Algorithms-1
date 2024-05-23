#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#pragma once
#include "Aresta.h"
#include "Vertice.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include "Funcoes.h"

class Grafo
{
private:
	int numeroDeVertices;
	std::vector<Aresta*> arestas;
	std::vector<Aresta*> arvoreGeradoraMinima;

public:

	//Construtor que inicializa as arestas e o numero de vertices do grafo
	Grafo(std::vector<Aresta*> arestasDoGrafo, int numVertices);

	//Ordena as arestas pelos pesos e usa a estrutra Union-Find para geracao
	//da arvore geradora minima do grafo
	void kruskal();

	//Encontra o conjunto do vertice passado como parametro
	Vertice* findSet(Vertice* auxiliar);

	//Une os conjuntos dos dois vertices passados como parametro
	void unionSet(Vertice* X, Vertice* Y);

	//Retorna o vetor de arestas "arvoreGeradoraMinima" 
	std::vector<Aresta*> getArvore();
};

#endif //GRAFO_H_INCLUDED