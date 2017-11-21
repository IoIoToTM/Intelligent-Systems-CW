#pragma once
#include "Tile.h"
class Block :
	public Tile
{
public:
	Block();
	Block(int x, int y, char name);
	~Block();

	char getName();
private:
	char name;
};

