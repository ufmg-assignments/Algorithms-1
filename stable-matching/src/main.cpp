#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Cliente.h"
#include "Loja.h"
#include "MatchFunctions.h"

int main() {

	//Tamanho da Malha
	int coordenadaX, coordenadaY;
	std::cin >> coordenadaX >> coordenadaY;

	//Variaveis auxiliares para leitura dos dados
	int numeroDeLojas = 0;
	int parametro1 = 0;
	int parametro2 = 0;
	int parametro3 = 0;

	//Leitura dos dados das lojas
	std::cin >> numeroDeLojas;
	std::vector<Loja*> lojas;

	for (int i = 0; i != numeroDeLojas; i++) {

		std::cin >> parametro1 >> parametro2 >> parametro3;
		Loja* novaLoja = new Loja(i, parametro1, parametro2, parametro3);
		lojas.push_back(novaLoja);

	}

	//Leitura dos dados dos clientes
	int numeroDeClientes = 0;
	std::cin >> numeroDeClientes;
	std::string parametroString1 = "";
	std::string parametroString2 = "";
	std::vector<Cliente*> clientes;

	for (int j = 0; j != numeroDeClientes; j++) {

		std::cin >> parametro1;
		std::cin >> parametroString1 >> parametroString2;
		std::cin >> parametro2 >> parametro3;
		Cliente* novoCliente = new Cliente(j, parametro1, parametroString1, parametroString2, parametro2, parametro3);
		clientes.push_back(novoCliente);

	}

	//Ordenacao dos clientes de acordo com sua prioridade
	std::sort(clientes.begin(), clientes.end(), compararClientes);

	//Chamada da funcao que alocara os clientes em lojas
	lojas = StableMatch(clientes, lojas);

	//Impressao dos clientes alocados a cada uma das lojas
	for (unsigned int i = 0; i != lojas.size(); i++) {
		lojas[i]->imprimirLojaMaisClientes();
	}

	//Desalocacao dos elementos do vetor de lojas
	for (Loja* loja : lojas) {
		delete loja;
	}

	//Desalocacao dos elementos do vetor de clientes
	for (Cliente* cliente : clientes) {
		delete cliente;
	}

	return 0;
}