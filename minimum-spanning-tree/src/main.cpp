#include <iostream>
#include <vector>
#include "Vertice.h"
#include "Aresta.h"
#include "Grafo.h"
#include <iomanip>

int main() {

	//Variaveis do programa 
	int numLojas, numDrones;
	double distanciaLimite, custoMoto, custoCaminhao;

	//Leitura dos parametros da execucao
	std::cin >> numLojas >> distanciaLimite >> numDrones >> custoMoto >> custoCaminhao;

	int auxiliarX = 0;
	int auxiliarY = 0;

	std::vector<Aresta*> arestas;
	std::vector<Vertice*> vertices;

	//Leitura dos dados das lojas e geracao das arestas do grafo
	for (int i = 0; i != numLojas; i++) {

		std::cin >> auxiliarX;
		std::cin >> auxiliarY;

		Vertice* novoVertice = new Vertice(auxiliarX, auxiliarY, i);

		for (unsigned int j = 0; j != vertices.size(); j++) {
			Aresta* novaAresta = new Aresta(novoVertice, vertices[j]);
			arestas.push_back(novaAresta);
		}

		vertices.push_back(novoVertice);

	}

	//Instanciacao do grafo que representa o problema
	Grafo* grafo = new Grafo(arestas, numLojas);

	//Algoritmo de Kruskal executado no grafo
	grafo->kruskal();

	//Retorno da arvore geradora minima calculada pelo algoritmo de Kruskal
	std::vector<Aresta*> agm = grafo->getArvore();

	//Trajetos que serao consideradas para motos e caminhoes
	int trajetos = agm.size() - numDrones + 1;
	
	//Calculo das distancias e custos totais de cada meio de tranporte
	double distanciaTotalMoto = 0;
	double distanciaTotalCaminhao = 0;

	for (int i = 0; i != trajetos; i++) {
		if (agm[i]->getPeso() <= distanciaLimite) {
			distanciaTotalMoto += agm[i]->getPeso();
		}
		else {
			distanciaTotalCaminhao += agm[i]->getPeso();
		}
	}

	double custoTotalMoto = custoMoto * distanciaTotalMoto;
	double custoTotalCaminhao = custoCaminhao * distanciaTotalCaminhao;

	//Impressao do resultado
	std::cout << std::fixed;
	std::cout << std::setprecision(3);
	std::cout <<  custoTotalMoto << " " << custoTotalCaminhao;

	//Liberacao da memoria alocada
	delete grafo;

	for (Aresta* are : arestas) {
		delete are;
	}

	for (Vertice* vert : vertices) {
		delete vert;
	}

	return 0;
}