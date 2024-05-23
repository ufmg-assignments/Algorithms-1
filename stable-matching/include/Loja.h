#ifndef LOJA_H_INCLUDED
#define LOJA_H_INCLUDED
#pragma once

#include <iostream>
#include <vector>

class Loja
{
public:

	//Atributos da loja
	int id;
	int estoque;

	//Atributos de localizacao da loja
	int X;
	int Y;

	//Clientes alocados
	std::vector<int> idClientesAlocados;

	//Proximo cliente que a loja fara oferta
	int proximoCliente;

public:
	//Construtor de objetos do tipo Loja
	Loja(int identificacao, int numProdutos, int localizacaoX, int localizacaoY);

	//Retorna o numero de produtos em estoque na loja
	int getNumProdutos();

	//Retorna o indice do proximo cliente a ser feita uma proposta
	int getProximoCliente();

	//Incrementa o indice do proximo cliente a ser feita uma proposta
	void mudarProximoCliente();

	//Exibe os clientes alocados a loja
	void imprimirLojaMaisClientes();

	friend class Cliente;
};

#endif // LOJA_H_INCLUDED


