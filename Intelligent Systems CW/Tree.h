#pragma once
#include "Field.h"

class Tree
{
public:
	Tree(Field field,int depth=0);
	Tree(Field field,Tree* parent, int depth=0);

	friend bool operator<(const Tree& left, const Tree& right);

	~Tree();

	int getDepth();

	void incrementDepth();

	Field* getField();
	Tree* getParent();

	void addChild(Tree* child);
	Tree* getChild(int i);
private:
	//TODO vector of pointers
	Tree* children[4];
	Tree* parent;
	Field state;
	int depth;
	
	
};

