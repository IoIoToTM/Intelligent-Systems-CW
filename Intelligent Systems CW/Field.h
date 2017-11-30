#pragma once

#include "Player.h"
#include "Block.h"
#include <vector>

#include"Direction.h"

#include<iostream>

#include"FieldState.h"

//the field calss 
class Field
{
public:


	Field();
	Field(int width, int heigth, Player p, std::vector <Block> blocks);
	Field(int width, int height, Field field);
	~Field();

	//overloading the == operator to check between two fields
	friend bool operator==(const Field& left, const Field& right);

	//function for printing the field
	void printField() const;

	//getting a block at a given position, returns nullptr if there is no block there
	Block* getBlockAtPos(Position p) const;

	//get a block by it's name, nullptr if no such block
	Block* getBlock(char name);

	//move the player in a given direction
	void movePlayer(Direction d);

	//distance between two tiles
	int distanceBetweenTwoTiles(Tile a, Tile b);

	//calculating the Manhattan distance
	int calculateManhattanDistance(Field winningField, bool checkPlayerPos = false);


	Position getPlayerPos() const;

	Player getPlayer() const;

	int getWidth() const;
	int getHeigth() const;

private:
	int width, heigth;
	Player p;
	std::vector<Block> blocks;

	//a few private functions for checking if a tile can move in that direction, if the player can move(which is just the previous function with the player tile), and checking if two blocks are the same
	bool canPlayerMove(Direction d);
	bool canTileMove(Tile t, Direction d);
	bool checkIfBlocksAreTheSame(Block a, Block b);
};


