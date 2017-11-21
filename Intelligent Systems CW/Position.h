#pragma once
#include"Direction.h"
class Position
{
public:
	Position(int x, int y);
	~Position();

	int getX();
	int getY();

	void setX(int x);
	void setY(int y);

	void move(Direction d);

private:
	int x, y;
};

