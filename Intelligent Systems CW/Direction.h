#pragma once

#include<time.h>
#include<stdlib.h>

enum Direction
{
	UP, DOWN, LEFT, RIGHT
};

extern bool randomGenerated;

Direction getOppositeDirection(Direction d);
Direction getRandomDirection();
