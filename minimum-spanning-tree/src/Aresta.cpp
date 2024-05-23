#include "Aresta.h"

Aresta::Aresta(Vertice* vertice1, Vertice* vertice2)
{
    this->v1 = vertice1;
    this->v2 = vertice2;
    int deltaX = vertice1->getX() - vertice2->getX();
    int deltaY = vertice1->getY() - vertice2->getY();
    this->peso = std::sqrt(std::pow(deltaX, 2) + std::pow(deltaY, 2));
}

double Aresta::getPeso()
{
    return this->peso;
}
