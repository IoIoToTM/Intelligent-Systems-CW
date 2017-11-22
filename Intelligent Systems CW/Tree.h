#pragma once
#include "FieldState.h"

class Tree
{
public:
	Tree(FieldState state);
	~Tree();
private:
	Tree* children[4];
	Tree* root;
	FieldState state;
	
};

