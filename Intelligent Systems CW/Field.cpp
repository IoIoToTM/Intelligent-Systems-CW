#include "stdafx.h"
#include "Field.h"







Field::Field()
{

	width = 4;
	height = 4;
	numOfBlocks = 3;
}
Field::Field(int width, int heigth, Player p, std::vector<Block> blocks)
{
	this->height = heigth;
	this->width = width;
	this->p = &p;
	this->blocks = blocks;
}


void Field::printField()
{
	for (int i = 1; i <= width; i++)
	{
		for (int j = 1; j <= height; j++)
		{
			Block* b = getBlock(i, j);
			if (b != nullptr)
			{
				std::cout <<" "<<(*b).getName()<<" ";
			}
			else if (p->getXPos() == i&&p->getYPos() == j)
			{
				std::cout << " p ";
			}
			else std::cout << " x ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
void Field::swapPlayerAndBlock(Player p, Block b)
{
	int tempX = p.getXPos();
	int tempY = p.getYPos();

	p.setXPos(b.getXPos());
	p.setYPos(b.getYPos());

	b.setXPos(tempX);
	b.setYPos(tempY);
	

}

void Field::setWinningState(FieldState winningState)
{
	this->winningState = winningState;
}

void Field::movePlayer(Direction d)
{
	if (canPlayerMove(d))
	{
		Block* b = getBlock(p->getXPos(), p->getYPos());
		if(b!=nullptr)
		{
			swapPlayerAndBlock(*p, *b);
		}
		
		else p->move(d);
			
	}
	
}


bool Field::canPlayerMove(Direction d)
{
	int playerX = p->getXPos();
	int playerY = p->getYPos();

	if (playerX == width && d == RIGHT)
	{
		return false;
	}
	if (playerX == 1 && d == LEFT)
	{
		return false;
	}
	if (playerY == height && d == DOWN)
	{
		return false;
	}
	if (playerY == 1 && d == UP)
	{
		return false;
	}

	return true;
	
}

Block* Field::getBlock(int x, int y)
{
	for (std::vector<Block>::iterator it = blocks.begin(); it != blocks.end(); ++it)
	{
		if ((*it).getXPos() == x && (*it).getYPos() == y)
		{
			return &(*it);
		}
	}
	return nullptr;
}


Field::~Field()
{
}
