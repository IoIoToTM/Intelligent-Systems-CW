#include "stdafx.h"
#include "Tile.h"


Tile::Tile() :pos(0,0)
{
	
}

Tile::Tile(Position pos)
{
	this->pos = pos;
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
