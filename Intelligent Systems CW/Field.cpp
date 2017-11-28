#include "stdafx.h"
#include "Field.h"


Field::Field() :p(Position(4,4))
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

Field::Field(int width, int heigth, FieldState state) :p(*state.getPlayerPos())
{
	this->heigth = heigth;
	this->width = width;
	this->blocks = state.getBlocks();
	//this->p = state.getPlayerPos();
}

Field::Field(int width, int height, Field field) : p(*field.p.getPosition())
{
	this->heigth = height;
	this->width = width;
	this->blocks = field.blocks;
}



Field::~Field()
{
}

void Field::printField() const
{

	for (int i = 1; i <= heigth; i++)
	{
		for (int j = 1; j <= width; j++)
		{
			Block* temp =  getBlockAtPos(Position(j,i));
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

Block* Field::getBlockAtPos(Position p) const
{
	for (std::vector<Block>::const_iterator it = blocks.begin(); it != blocks.end(); ++it)
	{
		if ((*it).getPosition()->getX() == p.getX() && (*it).getPosition()->getY() == p.getY())
		{
			return (Block*)&(*it);
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

int Field::numOfMovesfromTwoTiles(Tile a, Tile b)
{
	Position* tileA = (Position*) a.getPosition();
	Position* tileB = (Position*) b.getPosition();

	int distance = abs(tileB->getX() - tileA->getX()) + abs(tileB->getY() - tileA->getY());
	return distance;
}

Block* Field::getBlock(char name)
{
	std::vector<Block>::iterator iter = blocks.begin();

	for (; iter != blocks.end(); ++iter)
	{
		if ((*iter).getName() == name)
		{
			return &(*iter);
		}
	}

	return nullptr;
}

int Field::calculateManhatanDistance(Field winningField)
{
	std::vector<Block> winningBlocks = winningField.blocks;

	std::vector<Block>::iterator currentStateIter = blocks.begin();
	int distance = 0;

	for (; currentStateIter != blocks.end(); ++currentStateIter)
	{
		Block* winningBlock = winningField.getBlock((*currentStateIter).getName());

		distance += numOfMovesfromTwoTiles((*currentStateIter), *winningBlock);
	}

	return distance;

	/*
	
	
	x x x x
	x x x x
	x x x x
	A B C p

	x x x x
	x A x x
	x B x x
	x C x p
	
	
	*/

	return 0;
}



/*void Field::setWinningState(FieldState winningState)
{
	this->winningState = winningState;
}*/

/*bool Field::isGoalReached()
{
	FieldState stateOfFieldNow(p, blocks);

	if (stateOfFieldNow == winningState)
	{
		return true;
	}
	return false;
}*/

/*FieldState Field::getFieldState()
{
	return FieldState(p,blocks);
}

FieldState Field::getWinningState()
{
	return this->winningState;
}*/

Position Field::getPlayerPos()
{
	return *p.getPosition();
}

int Field::getWidth() const
{
	return this->width;
}

int Field::getHeigth() const
{
	return this->heigth;
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

bool operator==(const Field & left, const Field & right)
{
	std::vector <Block> leftBlocks = left.blocks;
	std::vector <Block> rightBlocks = right.blocks;

	std::vector<Block>::iterator leftIter = leftBlocks.begin();


	if (leftBlocks.size() != rightBlocks.size())
	{
		return false;
	}

	/*if (!(*left.p.getPosition() == *right.p.getPosition()))
	{
		return false;
	}*/

	bool match = false;

	for (; leftIter != leftBlocks.end(); ++leftIter)
	{
		for (std::vector<Block>::iterator rightIter = rightBlocks.begin(); rightIter != rightBlocks.end(); ++rightIter)
		{
			if (*leftIter == *rightIter)
			{
				match = true;
			}
		}
		if (match == false) return false;
		else match = false;
	}
	return true;
}
