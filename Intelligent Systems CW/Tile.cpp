#include "stdafx.h"
#include "Tile.h"


Tile::Tile()
{
	pos = new Position(0,0);
}

Tile::Tile(int x, int y)
{
	pos = new Position(x, y);
}

int Tile::getXPos()
{
	return pos->getX();
}

int Tile::getYPos()
{
	return pos->getY();
}

void Tile::setXPos(int x)
{
	pos->setX(x);
}
void Tile::setYPos(int y)
{
	pos->setY(y);
}

void Tile::move(Direction d)
{
	pos->move(d);
}

Tile::~Tile()
{
}
