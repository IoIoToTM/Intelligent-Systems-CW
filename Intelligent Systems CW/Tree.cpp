#include "stdafx.h"
#include "Tree.h"






Tree::Tree(Field field, Tree * parent, int depth)
{
	this->state = field;
	this->parent = parent;
	this->depth = depth;

	for (int i = 0; i < 4; i++)
	{
		this->children[i] = nullptr;
	}
}

Tree::Tree(Field field, int depth)
{
	this->state = field;
	this->depth = depth;

	this->parent = nullptr;

	for (int i = 0; i < 4; i++)
	{
		this->children[i] = nullptr;
	}
}

Tree::~Tree()
{
}

int Tree::getDepth()
{
	return depth;
}

void Tree::incrementDepth()
{
	depth++;
}

Field * Tree::getField()
{
	return &state;
}

Tree * Tree::getParent()
{
	return parent;
}

void Tree::addChild(Tree * child)
{
	for (int i = 0; i < 4; i++)
	{
		if (children[i] == nullptr)
		{
			children[i] = child;
			return;
		}
	}
}

Tree * Tree::getChild(int i)
{
	//TODO if >4
	return children[i];
}

/*bool operator<(const Tree & left, const Tree & right)
{
	Field leftField = *left.getField();
	return ;
}*/
  