#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#pragma once
#include <string>
#include <iostream>
#include "Loja.h"

class Cliente
{
private:
	//Dados do cliente
	int id;
	int idade;
	std::string estado;
	std::string tipoDePagamento;
	double ticket;

	//Atributos de localizacao
	int X;
	int Y;

	//Loja que o cliente deve ir
	Loja* lojaAtual;
	bool alocado;
	int distanciaAtual;


public:
	//Construtor de objetos da classe Cliente
	Cliente(int identificacao, int idadeCliente, std::string estadoCliente, std::string pagamento, int localizacaoX, int localizacaoY);

	//Realiza o calculo do ticket que determinara a preferencia do cliente
	void calcularTicket();

	//Com base nas coordenadas da loja passada, calcula a distancia do cliente ate ela
	int calcularDistancia(Loja* loja);

	//Faz o processamento da proposta e determina um comportamento a ser tomado pelo cliente
	void analisarProposta(Loja* lojaComProduto, std::vector<int>* idLojas);

	//Retorna o valor do Ticket do cliente
	double getTicket();

	//Retorna o numero de identificacao do cliente.
	int getId();

	friend class Loja;
};

#endif // CLIENTE_H_INCLUDED