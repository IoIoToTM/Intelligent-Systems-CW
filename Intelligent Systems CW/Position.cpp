#include "stdafx.h"
#include "Position.h"


Position::Position(int x, int y)
{
	this->x = x;
	this->y = y;
}


Position::~Position()
{
}

int Position::getX()
{
	return this->x;
}

int Position::getY()
{
	return this->y;
}

void Position::setX(int x)
{
	this->x = x;
}

void Position::setY(int y)
{
	this->y = y;
}

void Position::move(Direction d)
{
	switch (d)
	{
	case UP:
		y--;
			break;
	case DOWN:
		y++;
		break;
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	default:
		break;
	}

}
