#pragma once
#include "Tile.h"
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

