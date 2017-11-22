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


bool operator==(const Position& left, const Position& right) 
{
	if (left.getX() == right.getX() && left.getY() == right.getY())
	{
		return true;
	}
	else return false;
}
int Position::getX() const
{
	return this->x;
}

int Position::getY() const
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
