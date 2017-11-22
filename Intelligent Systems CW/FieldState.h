#pragma once
#include"Player.h"
#include"Block.h"

#include<vector>
class FieldState
{

public:
	FieldState(Player p,std::vector<Block> blocks);
	FieldState();
	friend bool operator==(const FieldState& left, const FieldState& right);
	const Position* getPlayerPos() const;
	std::vector<Block> getBlocks() const;
private:

	int width, height;
	Player p;
	std::vector<Block> blocks;
};

