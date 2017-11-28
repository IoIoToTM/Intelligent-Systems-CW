#include "stdafx.h"
#include "Direction.h"


#include<algorithm>

Direction getOppositeDirection(Direction d)
{
	switch (d)
	{
	case UP:
		return DOWN;
		break;
	case DOWN:
		return UP;
		break;
	case LEFT:
		return RIGHT;
		break;
	case RIGHT:
		return LEFT;
		break;
	default:
		break;
	}
}
bool randomGenerated = false;

Direction getRandomDirection()
{
	if (randomGenerated == false)
	{
		randomGenerated = true;
		srand(time(NULL));
	}
	int i = 0;
	i = (rand() % 4) + 1;
	if (i == 1) return UP;
	else if (i == 2) return DOWN;
	else if (i == 3) return LEFT;
	else if (i == 4) return RIGHT;

}

std::vector<Direction> randomiseDirections()
{
	std::vector<Direction> directionVector;
	directionVector.push_back(UP);
	directionVector.push_back(DOWN);
	directionVector.push_back(RIGHT);
	directionVector.push_back(LEFT);

	//srand(NULL);

	std::random_shuffle(directionVector.begin(), directionVector.end());

	return directionVector;


}