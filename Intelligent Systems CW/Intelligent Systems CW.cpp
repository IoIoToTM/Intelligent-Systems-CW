// Intelligent Systems CW.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Player.h"
#include "Block.h"
#include"Field.h"

#include<vector>


int main()
{
	Player p(3,4);
	
	Block a(4, 2, 'A');
	Block b(4, 1, 'B');

	std::vector<Block> blocks;
	blocks.push_back(a);
	blocks.push_back(b);

	Field f(4, 4, p, blocks);

	f.printField();

	f.movePlayer(UP);
	f.movePlayer(UP);
	f.movePlayer(RIGHT);
	f.movePlayer(RIGHT);
	f.movePlayer(RIGHT);
	f.movePlayer(UP);
	//f.movePlayer(DOWN);

	f.printField();


	int x;
	std::cin >> x;


	

}