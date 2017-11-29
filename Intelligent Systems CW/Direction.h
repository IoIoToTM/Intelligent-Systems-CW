#pragma once

#include<time.h>
#include<stdlib.h>
#include<vector>

//enum for directions and a few supplementary functions

enum Direction
{
	UP, LEFT, DOWN, RIGHT
};

//a boolean which I use t ostart the random seed only once
extern bool randomGenerated;

//get the opposite direction
Direction getOppositeDirection(Direction d);

//get a random direction
Direction getRandomDirection();

//get a vector with shuffled directions
std::vector<Direction> randomiseDirections();
