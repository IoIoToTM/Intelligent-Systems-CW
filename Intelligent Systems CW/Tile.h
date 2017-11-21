#pragma once
#include"Direction.h"
#include"Position.h"
class Tile
{
public:
	Tile();
	Tile(int x, int y);
	~Tile();

	int getXPos();
	int getYPos();

	void setXPos(int x);
	void setYPos(int y);
	void move(Direction d);
private:
	Position *pos;
};

