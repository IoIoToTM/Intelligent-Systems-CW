#include "stdafx.h"
#include "Direction.h"

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