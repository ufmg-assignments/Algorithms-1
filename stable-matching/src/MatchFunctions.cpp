#include <vector>
#include "Cliente.h"
#include "Loja.h"
#include "MatchFunctions.h"

std::vector<Loja*> StableMatch(std::vector<Cliente*> clientes, std::vector<Loja*> lojas) {

	int numClientes = clientes.size();
	int indiceCliente = 0;

	std::vector<int> idLojas;
	for (unsigned int i = 0; i != lojas.size(); i++) {
		idLojas.push_back(i);
	}

	while (idLojas.size() > 0) {
		int atual = idLojas[0];
		while (lojas[atual]->getNumProdutos() > 0 && lojas[atual]->getProximoCliente() < numClientes) {
			indiceCliente = lojas[atual]->getProximoCliente();
			clientes[indiceCliente]->analisarProposta(lojas[atual], &idLojas);
			lojas[atual]->mudarProximoCliente();
		}
		idLojas.erase(idLojas.begin());
	}

	return lojas;
}

bool compararClientes(Cliente* cliente1, Cliente* cliente2)
{
	if (cliente1->getTicket() < cliente2->getTicket()) {
		return false;
	}
	else if (cliente1->getTicket() == cliente2->getTicket()) {
		if (cliente1->getId() < cliente2->getId()) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return true;
	}
}
