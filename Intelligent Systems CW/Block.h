#pragma once
#include "Tile.h"

//block is just a tile with an overloaded == operator and a name
class Block :
	public Tile
{
public:
	Block();
	friend bool operator==(const Block& left, const Block& right);

	Block(Position pos, char name);
	~Block();

	char getName() const;

private:
	char name;
};

