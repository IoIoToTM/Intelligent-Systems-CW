// Intelligent Systems CW.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Player.h"
#include "Block.h"
#include"Field.h"
#include"Tree.h"


#include<vector>
#include<thread>
#include<queue>
#include<algorithm>
#include<stack>


#include"Algorithms.h"






int main()
{
	Player p(Position(4,4));


	
	Block a(Position(1, 4), 'A');
	Block b(Position(2, 4), 'B');
	Block c(Position(3, 4), 'C');

	std::vector<Block> blocks;
	blocks.push_back(a);
	blocks.push_back(b);
	blocks.push_back(c);

	std::vector<Block> winningBlocks;
	winningBlocks.push_back(Block(Position(2, 3), 'A'));
	winningBlocks.push_back(Block(Position(3, 4), 'B'));
	winningBlocks.push_back(Block(Position(4, 4), 'C'));
	/*winningBlocks.push_back(a);
	winningBlocks.push_back(b);
	winningBlocks.push_back(Block(Position(4,4),'C'));*/



	std::cout << "Size of Tree " << sizeof(Tree)<<std::endl;

	

	Field f(4, 4, p, blocks);
	
	f.printField();

	Field f1(4, 4, p, winningBlocks);

	Tree* result = doAStar(f, f1);
	std::cout << std::endl;

	printPathFromLeafToRoot(result);

	int x;
	std::cin >> x;

	return 0;
}