#include "stdafx.h"
#include "Block.h"


Block::Block() :Tile()
{
}

Block::Block(Position pos,char name) : Tile(pos)
{
	this->name = name;
}


//if name and position are the same, return true
bool operator==(const Block& left, const Block& right) 
{
	
	if (*left.getPosition() == *right.getPosition() && left.getName()==right.getName())
	{
		return true;
	}
	else return false;
}

Block::~Block() 
{
	
}

char Block::getName() const
{
	return name;
}
