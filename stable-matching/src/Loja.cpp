#include "Loja.h"

Loja::Loja(int identificacao, int numProdutos, int localizacaoX, int localizacaoY)
{
	this->id = identificacao;
	this->estoque = numProdutos;
	this->X = localizacaoX;
	this->Y = localizacaoY;
}

int Loja::getNumProdutos()
{
	return estoque;
}

int Loja::getProximoCliente()
{
	return this->proximoCliente;
}

void Loja::mudarProximoCliente()
{
	this->proximoCliente++;
}

void Loja::imprimirLojaMaisClientes()
{
	std::cout << this->id << "\n";
	unsigned int i = 0;
	for (; i < this->idClientesAlocados.size(); i++) {
		std::cout << this->idClientesAlocados[i];
		if (i != this->idClientesAlocados.size() - 1) {
			std::cout << " ";
		}
	}

	std::cout << "\n";
}

