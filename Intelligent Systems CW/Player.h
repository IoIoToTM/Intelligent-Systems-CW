#pragma once
#include "Tile.h"

//player is just a tile with added functions (which in this case are 0)
class Player :
	public Tile
{
public:
	Player();
	Player(Position pos);
	~Player();
};

