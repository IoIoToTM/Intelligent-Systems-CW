#pragma once
#include "FieldState.h"

class Tree
{
public:
	Tree(FieldState state);
	Tree(FieldState state,Tree* parent);
	~Tree();

	void addChild(Tree* child);
private:
	Tree* children[4];
	Tree* parent;
	FieldState state;
	
};

