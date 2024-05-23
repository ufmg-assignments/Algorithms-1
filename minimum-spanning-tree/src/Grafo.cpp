#include "Grafo.h"

Grafo::Grafo(std::vector<Aresta*> arestasDoGrafo, int numVertices)
{
	this->arestas = arestasDoGrafo;
	this->numeroDeVertices = numVertices;
}

void Grafo::kruskal()
{
	std::sort(this->arestas.begin(), this->arestas.end(), compararArestas);

	int contador = this->numeroDeVertices -1;
	int arestaAtual = 0;

	while (contador != 0) {
		
		Vertice* x = findSet(arestas[arestaAtual]->v1);
		Vertice* y = findSet(arestas[arestaAtual]->v2);

		if (x == y) {
			arestaAtual++;
			continue;
		}

		unionSet(x, y);
		this->arvoreGeradoraMinima.push_back(this->arestas[arestaAtual]);

		arestaAtual++;
		contador--;
	}

	//for (Aresta* a : this->arvoreGeradoraMinima) {
		//std::cout << a->v1->getX() << " " << a->v1->getY() << " " << a->v2->getX() << " " << a->v2->getY() << " " << a->getPeso() << "\n";
	//}
	//std::cout << this->arvoreGeradoraMinima.size();
}

Vertice* Grafo::findSet(Vertice* auxiliar)
{
	if (auxiliar != auxiliar->parent) {
		auxiliar->parent = findSet(auxiliar->parent);
	}
	return auxiliar->parent;
}

void Grafo::unionSet(Vertice* X, Vertice* Y)
{
	if (X->rank > Y->rank) {
		Y->parent = X;
	}
	else {
		X->parent = Y;
		if (X->rank == Y->rank) {
			Y->rank += 1;
		}
	}
}

std::vector<Aresta*> Grafo::getArvore()
{
	return this->arvoreGeradoraMinima;
}