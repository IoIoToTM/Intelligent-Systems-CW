#pragma once
#include"Direction.h"
class Position
{
public:
	Position(int x, int y);
	Position();
	~Position();

	friend bool operator==(const Position& left, const Position& right);


	int getX() const;
	int getY() const;

	void setX(int x);
	void setY(int y);

	void move(Direction d);

private:
	int x, y;
};

