#pragma once
#include"Direction.h"
#include"Position.h"
class Tile
{
public:
	Tile();
	Tile(Position pos);
	~Tile();

	const Position* getPosition() const;
	void move(Direction d);
private:
	Position pos;
};

