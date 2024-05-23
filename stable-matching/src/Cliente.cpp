#include "Cliente.h"

Cliente::Cliente(int identificacao, int idadeCliente, std::string estadoCliente, std::string pagamento, int localizacaoX, int localizacaoY)
{
	this->id = identificacao;
	this->idade = idadeCliente;
	this->estado = estadoCliente;
	this->tipoDePagamento = pagamento;
	this->X = localizacaoX;
	this->Y = localizacaoY;
	this->alocado = false;
	this->lojaAtual = nullptr;
	calcularTicket();
}

double Cliente::getTicket() {
	return this->ticket;
}

int Cliente::getId() {
	return this->id;
}

void Cliente::calcularTicket()
{
	double fator1 = 60.0 - static_cast<double>(this->idade);
	if (fator1 < 0) { fator1 *= -1; }

	double fator2 = 0.0;
	if (this->estado == "MG") { fator2 = 0.0; }
	else if (this->estado == "PR") { fator2 = 10.0; }
	else if (this->estado == "SP") { fator2 = 20.0; }
	else if (this->estado == "SC") { fator2 = 30.0; }
	else if (this->estado == "RJ") { fator2 = 40.0; }
	else if (this->estado == "RN") { fator2 = 50.0; }
	else if (this->estado == "RS") { fator2 = 60.0; }

	double fator3 = 0.0;
	if (this->tipoDePagamento == "DINHEIRO") { fator3 = 1.0; }
	else if (this->tipoDePagamento == "DEBITO") { fator3 = 2.0; }
	else if (this->tipoDePagamento == "CREDITO") { fator3 = 3.0; }

	this->ticket = (fator1 + fator2) / fator3;

}

int Cliente::calcularDistancia(Loja* loja)
{
	int deltaX = this->X - loja->X;
	int deltaY = this->Y - loja->Y;
	int dist = 0;

	if (deltaX < 0) { deltaX *= -1; }
	if (deltaY < 0) { deltaY *= -1; }

	if (deltaX > deltaY) {
		dist = deltaX - 1;
	}
	else {
		dist = deltaY - 1;
	}

	return dist;
}

void Cliente::analisarProposta(Loja* lojaComProduto, std::vector<int>* idLojas)
{
	int identificacao = lojaComProduto->id;

	if (this->alocado == false) {
		this->alocado = true;
		this->lojaAtual = lojaComProduto;
		this->distanciaAtual = this->calcularDistancia(lojaComProduto);
		this->lojaAtual->estoque--;
		this->lojaAtual->idClientesAlocados.push_back(this->id);
	}
	else {
		if (this->distanciaAtual > this->calcularDistancia(lojaComProduto)) {
			this->distanciaAtual = this->calcularDistancia(lojaComProduto);
			this->lojaAtual->estoque++;
			int indice = 0;
			for (int j : this->lojaAtual->idClientesAlocados) {
				if (j == this->id) {
					this->lojaAtual->idClientesAlocados.erase(this->lojaAtual->idClientesAlocados.begin() + indice);
					break;
				}
				indice++;
			}
			idLojas->push_back(this->lojaAtual->id);
			this->lojaAtual = lojaComProduto;
			this->lojaAtual->estoque--;
			this->lojaAtual->idClientesAlocados.push_back(this->id);
		}
		else if (this->distanciaAtual == this->calcularDistancia(lojaComProduto)) {
			if (this->lojaAtual->id > identificacao) {
				this->lojaAtual->estoque++;
				int indice = 0;
				for (int j : this->lojaAtual->idClientesAlocados) {
					if (j == this->id) {
						this->lojaAtual->idClientesAlocados.erase(this->lojaAtual->idClientesAlocados.begin() + indice);
						break;
					}
					indice++;
				}
				idLojas->push_back(this->lojaAtual->id);
				this->lojaAtual = lojaComProduto;
				this->lojaAtual->estoque--;
				this->lojaAtual->idClientesAlocados.push_back(this->id);
			}
		}
	}
}