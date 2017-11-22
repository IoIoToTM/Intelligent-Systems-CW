#include "stdafx.h"
#include "Field.h"


Field::Field() :p(4,4)
{
	this->heigth = 4;
	this->width = 4;
	
	
}

Field::Field(int width, int heigth, Player p, std::vector<Block> blocks)
{
	this->heigth = heigth;
	this->width = width;
	this->p = p;
	this->blocks = blocks;
}



Field::~Field()
{
}

void Field::printField()
{

	for (int i = 1; i <= heigth; i++)
	{
		for (int j = 1; j <= width; j++)
		{
			Block* temp = getBlockAtPos(Position(j,i));
			if (temp != nullptr)
			{
				std::cout << " " << temp->getName() << " ";
			}
			else if (p.getPosition()->getX()==j && p.getPosition()->getY()==i)
			{
				std::cout << " p ";
			}
			else std::cout << " x ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

Block* Field::getBlockAtPos(Position p)
{
	for (std::vector<Block>::iterator it = blocks.begin(); it != blocks.end(); ++it)
	{
		if ((*it).getPosition()->getX() == p.getX() && (*it).getPosition()->getY() == p.getY())
		{
			return &(*it);
		}
	}
	return nullptr;
}

void Field::movePlayer(Direction d)
{
	if (canPlayerMove(d))
	{
		p.move(d);

		Position pos = *p.getPosition();

		Block* b = getBlockAtPos(pos);
		if (b != nullptr)
		{
			b->move(getOppositeDirection(d));
		}

	}

}

void Field::setWinningState(FieldState winningState)
{
	this->winningState = winningState;
}

bool Field::isGoalReached()
{
	FieldState stateOfFieldNow(p, blocks);

	if (stateOfFieldNow == winningState)
	{
		return true;
	}
	return false;
}



bool Field::canPlayerMove(Direction d)
{
	return canTileMove(p, d);
}

bool Field::canTileMove(Tile t, Direction d)
{
	int xPos = t.getPosition()->getX();
	int yPos = t.getPosition()->getY();

	if (d == UP && yPos == 1)
	{
		return false;
	}
	else if (d == DOWN && yPos == heigth)
	{
		return false;
	}
	else if (d == LEFT && xPos == 1)
	{
		return false;
	}
	else if (d == RIGHT && xPos == width)
	{
		return false;
	}

	return true;
}



bool Field::checkIfBlocksAreTheSame(Block a, Block b)
{
	if (a.getPosition()->getX() == b.getPosition()->getX() && a.getPosition()->getY() == b.getPosition()->getY())
	{
		if (a.getName() == b.getName())
		{
			return true;
		}
	}
	return false;
}
