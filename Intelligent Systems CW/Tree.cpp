#include "stdafx.h"
#include "Tree.h"






Tree::Tree(Field field, Tree * parent, int depth)
{
	this->state = field;
	this->parent = parent;
	this->depth = depth;
}

Tree::Tree(Field field, int depth)
{
	this->state = field;
	this->depth = depth;

	this->parent = nullptr;
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

const Field* Tree::getField() const
{
	return &state;
}

Tree * Tree::getParent()
{
	return parent;
}

void Tree::addChild(Tree * child)
{
	if (children.size() >= 4)
	{
		return;
	}
	else children.push_back(child);
}

std::vector<Tree*>::iterator Tree::getChildIteratorBegin()
{
	return children.begin();
}
std::vector<Tree*>::iterator Tree::getChildIteratorEnd()
{
	return children.end();
}


  