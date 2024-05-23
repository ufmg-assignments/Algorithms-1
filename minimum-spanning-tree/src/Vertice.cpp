#include "Vertice.h"

Vertice::Vertice(int coordenadaX, int coordenadaY, int identificacao)
{
	this->X = coordenadaX;
	this->Y = coordenadaY;
	this->id = identificacao;
	this->rank = 0;
	this->parent = this;
}

int Vertice::getX()
{
	return this->X;
}

int Vertice::getY()
{
	return this->Y;
}
