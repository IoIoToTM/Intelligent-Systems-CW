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
	Field(int width, int height, Field field);
	~Field();


	friend bool operator==(const Field& left, const Field& right);

	void printField();

	Block* getBlockAtPos(Position p);
	void movePlayer(Direction d);

	int numOfMovesfromTwoTiles(Tile a, Tile b);

	Block* getBlock(char name);

	int calculateManhatanDistance(Field winningField);
	//void setWinningState(FieldState winningState);

	//bool isGoalReached();

	/*FieldState getFieldState();
	FieldState getWinningState();*/

	Position getPlayerPos();

	int getWidth() const;
	int getHeigth() const;

private:
	int width, heigth;
	Player p;
	std::vector<Block> blocks;
	//FieldState winningState;

	bool canPlayerMove(Direction d);
	bool canTileMove(Tile t, Direction d);
	bool checkIfBlocksAreTheSame(Block a, Block b);
};


