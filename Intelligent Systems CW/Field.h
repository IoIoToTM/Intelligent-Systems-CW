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
	Field(int width, int heigth, FieldState state);
	~Field();

	void printField();

	Block* getBlockAtPos(Position p);
	void movePlayer(Direction d);
	void setWinningState(FieldState winningState);

	bool isGoalReached();

	FieldState getFieldState();

	int getWidth() const;
	int getHeigth() const;

private:
	int width, heigth;
	Player p;
	std::vector<Block> blocks;
	FieldState winningState;

	bool canPlayerMove(Direction d);
	bool canTileMove(Tile t, Direction d);
	bool checkIfBlocksAreTheSame(Block a, Block b);
};


