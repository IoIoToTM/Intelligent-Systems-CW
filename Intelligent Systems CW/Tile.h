#pragma once
#include"Direction.h"
#include"Position.h"
class Tile
{
public:
	Tile();
	Tile(int x, int y);
	~Tile();

	Position* getPosition();
	void move(Direction d);
private:
	Position pos;
};

