#pragma once
#include"Player.h"
#include"Block.h"

#include<vector>
class FieldState
{

public:
	FieldState(Player p,std::vector<Block> blocks);
	FieldState();
private:

	int width, height;
	Player p;
	std::vector<Block> blocks;
};

