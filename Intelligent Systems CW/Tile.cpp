#include "stdafx.h"
#include "Tile.h"


Tile::Tile() :pos(0,0)
{
	
}

Tile::Tile(int x, int y) :pos(x,y)
{
	
}

const Position* Tile::getPosition() const
{
	return &pos ;
}

void Tile::move(Direction d)
{
	this->pos.move(d);
}

Tile::~Tile()
{
	
}
