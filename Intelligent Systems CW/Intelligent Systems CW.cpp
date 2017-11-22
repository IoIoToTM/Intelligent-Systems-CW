// Intelligent Systems CW.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Player.h"
#include "Block.h"
#include"Field.h"

#include<vector>

void doDFS(Field f)
{
	int moves = 0;
	while(!f.isGoalReached())
	{
		f.movePlayer(getRandomDirection());
		moves++;
		if (moves % 1000==0) f.printField();
	}

	f.printField();
	std::cout << moves;
}


int main()
{
	Player p(4,4);


	
	Block a(1, 4, 'A');
	Block b(2, 4, 'B');
	Block c(3, 4, 'C');

	std::vector<Block> blocks;
	blocks.push_back(a);
	blocks.push_back(b);
	blocks.push_back(c);

	std::vector<Block> winningBlocks;
	winningBlocks.push_back(Block(2, 2, 'A'));
	winningBlocks.push_back(Block(2, 3, 'B'));
	winningBlocks.push_back(Block(2, 4, 'C'));



	FieldState winning(Player(4, 4), winningBlocks);

	Field f(4, 4, p, blocks);
	f.setWinningState(winning);
	f.printField();

	doDFS(f);

	int x;
	
	//f.movePlayer(getRandomDirection());
	/*f.movePlayer(UP);
	f.movePlayer(RIGHT);
	f.movePlayer(RIGHT);
	f.movePlayer(RIGHT);
	f.movePlayer(UP);
	//f.movePlayer(DOWN);
	*/
	//f.printField();


	std::cin >> x;


	

}