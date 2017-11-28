#pragma once
#include "Field.h"

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
	//TODO vector of pointers
	std::vector<Tree*> children;
	Tree* parent;
	Field state;
	int depth;
	
	
};

