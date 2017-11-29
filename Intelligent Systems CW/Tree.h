#pragma once
#include "Field.h"


//a tree has a field state, a parent tree, and a vector of children (in theory can be any number between 0 to infinity), but there's a check if I starts adding more than 4
class Tree
{
public:
	Tree(Field field,int depth=0);
	Tree(Field field,Tree* parent, int depth=0);

	

	~Tree();

	int getDepth();

	void incrementDepth();

	const Field* getField() const;
	Tree* getParent();

	void addChild(Tree* child);
	std::vector<Tree*>::iterator getChildIteratorBegin();
	std::vector<Tree*>::iterator getChildIteratorEnd();
private:
	std::vector<Tree*> children;
	Tree* parent;
	Field state;
	int depth;
	
	
};

