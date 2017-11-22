#pragma once
#include"Direction.h"
#include"Position.h"
class Tile
{
public:
	Tile();
	Tile(int x, int y);
	~Tile();

	const Position* getPosition() const;
	void move(Direction d);
private:
	Position pos;
};

