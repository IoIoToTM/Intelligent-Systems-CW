#pragma once
#include "Tile.h"
class Player :
	public Tile
{
public:
	Player();
	Player(Position pos);
	~Player();
};

