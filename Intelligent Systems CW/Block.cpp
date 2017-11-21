#include "stdafx.h"
#include "Block.h"


Block::Block() :Tile()
{
}

Block::Block(int x, int y,char name) : Tile(x, y)
{
	this->name = name;
}


Block::~Block()
{
}

char Block::getName()
{
	return name;
}
