#include "stdafx.h"
#include "Tree.h"





Tree::Tree(FieldState state)
{
	this->state = state;
	this->parent = nullptr;

	for (int i = 0; i < 4; i++)
	{
		this->children[i] = nullptr;
	}
}

Tree::Tree(FieldState state, Tree * parent)
{
	this->state = state;
	this->parent = parent;

	for (int i = 0; i < 4; i++)
	{
		this->children[i] = nullptr;
	}
}

Tree::~Tree()
{
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
