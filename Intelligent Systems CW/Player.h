#pragma once
#include "Tile.h"
class Player :
	public Tile
{
public:
	Player();
	Player(int x, int y);
	~Player();
};

