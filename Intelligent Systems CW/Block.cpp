#include "stdafx.h"
#include "Block.h"


Block::Block() :Tile()
{
}

Block::Block(Position pos,char name, bool movable) : Tile(pos)
{
	this->name = name;
	this->movable = movable;
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

bool Block::isMovable() const
{
	return movable;
}

char Block::getName() const
{
	return name;
}
