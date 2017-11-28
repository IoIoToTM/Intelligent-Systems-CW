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

void freeMemory(Tree* root)
{
	std::stack <Tree*> checkNodes;

	checkNodes.push(root);

	while (!checkNodes.empty())
	{
		Tree* currentNode = checkNodes.top();
		Tree* children[4];
		for (int i = 0; i < 4; i++)
		{
			children[i] = currentNode->getChild(i);
		}
		checkNodes.pop();

		delete currentNode;

		for (int i = 0; i < 4; i++)
		{
			checkNodes.push(children[i]);
		}
	}

}




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
	winningBlocks.push_back(Block(Position(2, 4), 'A'));
	winningBlocks.push_back(Block(Position(3, 4), 'B'));
	winningBlocks.push_back(Block(Position(4, 4), 'C'));
	/*winningBlocks.push_back(a);
	winningBlocks.push_back(b);
	winningBlocks.push_back(Block(Position(4,4),'C'));*/



	std::cout << "Size of Tree " << sizeof(Tree)<<std::endl;

	FieldState winning(Player(Position(1,1)), winningBlocks);

	Field f(4, 4, p, blocks);
	
	f.printField();

	Field f1(4, 4, p, winningBlocks);

	Tree* result = doDFS(f, f1);
	std::cout << std::endl;

	while (result != nullptr)
	{
		result->getField()->printField();
		result = result->getParent();
	}

	//std::cout << "\n"<< f.numOfMovesfromTwoTiles(*f.getBlockAtPos(Position(1,4)),*f.getBlockAtPos(Position(4,4)));


	//std::cout << "\n" << f.getBlock('A').getPosition()->getY();
	
	//result->getField()->printField();
	//std::cout << "\n" << f.calculateManhatanDistance(f1);


	/*if (f == f1) {
		std::cout << "yay";
	}*/


	/*if (doDLS(f, 20) == true)
	{
		std::cout << "WOW";
	}
	else std::cout << "no";
	//doBFS(f);

	/*doDFS(f);
	doDFSNoMemory(f1);*/


	/*std::thread first (doDFS,f);
	std::thread second(doBFS,f1);
	
	std::cout << "I AM CONCURRENT " << std::endl;

	first.join();
	second.join();
	*/

	//doDFSNoMemory(f);
	//doDFSNoMemory(f);

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