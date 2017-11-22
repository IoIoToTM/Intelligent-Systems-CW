#include "stdafx.h"
#include "FieldState.h"

FieldState::FieldState(Player p, std::vector<Block> blocks,int width,int heigth)
{
	this->p = p;
	this->blocks = blocks;
	this->width = width;
	this->height = heigth;
}


bool operator==(const FieldState& left, const FieldState& right)
{
	std::vector < Block> leftBlocks = left.getBlocks();
	std::vector < Block> rightBlocks = right.getBlocks();

	std::vector<Block>::iterator leftIter = leftBlocks.begin();
	

	if (leftBlocks.size() != rightBlocks.size())
	{
		return false;
	}

	if (!(*left.getPlayerPos() == *right.getPlayerPos()))
	{
		return false;
	}

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

FieldState::FieldState():p()
{
	width = 4;
	height = 4;
}

const Position * FieldState::getPlayerPos() const
{
	return this->p.getPosition();
}

std::vector<Block> FieldState::getBlocks() const
{
	return blocks;
}
