#include "stdafx.h"
#include "FieldState.h"

FieldState::FieldState(Player p, std::vector<Block> blocks)
{
	this->p = p;
	this->blocks = blocks;
}

FieldState::FieldState():p()
{
}
