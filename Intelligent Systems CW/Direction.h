#pragma once

#include<time.h>
#include<stdlib.h>
#include<vector>

enum Direction
{
	UP, LEFT, DOWN, RIGHT
};

extern bool randomGenerated;

Direction getOppositeDirection(Direction d);
Direction getRandomDirection();

std::vector<Direction> randomiseDirections();
