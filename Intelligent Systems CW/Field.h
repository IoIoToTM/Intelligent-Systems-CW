#pragma once

#include "Player.h"
#include "Block.h"
#include <vector>

#include"Direction.h"

#include<iostream>

#include"FieldState.h"


class Field
{
public:
	Field();
	Field(int width, int heigth, Player p, std::vector <Block> blocks);
	~Field();

	bool canPlayerMove(Direction d);
	Block* getBlock(int x, int y);

	void printField();

	void swapPlayerAndBlock(Player p, Block b);

	void setWinningState(FieldState winningState);



	void movePlayer(Direction d);

private:
	int width, height, numOfBlocks;
	Player *p;
	std::vector<Block> blocks;

	FieldState winningState;
};


