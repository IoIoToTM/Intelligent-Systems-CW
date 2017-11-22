#pragma once
#include "Tile.h"
class Block :
	public Tile
{
public:
	Block();
	friend bool operator==(const Block& left, const Block& right);

	Block(int x, int y, char name);
	~Block();

	char getName() const;

private:
	char name;
};

