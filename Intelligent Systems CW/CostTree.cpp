#include "stdafx.h"
#include "CostTree.h"





CostTree::CostTree(Field field,int cost, int depth):Tree(field,depth)
{
	this->cost = cost;
}

CostTree::CostTree(Field field, Tree * parent,int cost, int depth):Tree(field,parent,depth)
{
	this->cost = cost;
}

CostTree::~CostTree()
{
}

int CostTree::getCost() const
{
	return cost;
}

bool operator<(const CostTree & left, const CostTree & right)
{
	return (&left)->getCost()<(&right)->getCost();
}
