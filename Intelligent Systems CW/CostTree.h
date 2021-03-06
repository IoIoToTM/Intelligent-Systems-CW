#pragma once
#include "Tree.h"

//tree with an added cost of the node
class CostTree :
	public Tree
{
public:
	CostTree(Field field,int cost ,int depth = 0);
	CostTree(Field field, Tree* parent,int cost ,int depth = 0);
	~CostTree();
	int getCost() const;

	friend bool operator<(const CostTree& left, const CostTree& right);
private:

	int cost;
};

