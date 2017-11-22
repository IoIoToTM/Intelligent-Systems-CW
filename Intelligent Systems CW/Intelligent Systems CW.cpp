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

void doBFS(Field f)
{
	std::queue <Tree*> checkNodes;
	Tree root(f.getFieldState());
	Tree* rootPointer = &root;

	int fieldHeigth = f.getHeigth();
	int fieldWidth = f.getWidth();
	int moves = 0;

	checkNodes.push(&root);

	while (true)
	{
		Tree* nodeToExplore = checkNodes.front();
		FieldState currentState = *nodeToExplore->getState();
		checkNodes.pop();

		for (int i = 0; i <4; i++)
		{
			Field temp(fieldWidth,fieldHeigth,currentState);
			temp.movePlayer(static_cast<Direction> (i));
			if (temp.isGoalReached()) 
			{
				std::cout << "GOAL REACHED";
				return; 
			}
			Tree *child = new Tree(temp.getFieldState(), nodeToExplore);
			nodeToExplore->addChild(child);
			checkNodes.push(child);
		}
		moves++;

		/*if (moves % 100 == 0)
		{
			std::cout << "";
		}*/


	}



}

void doDFS(Field f)
{

	Tree root(f.getFieldState());
	Tree* rootPointer = &root;
	

	int fieldHeigth = f.getHeigth();
	int fieldWidth = f.getWidth();
	int moves = 0;
	while(!f.isGoalReached())
	{
		
		Direction randomDir = getRandomDirection();
		

		for (int i = 0; i <4; i++)
		{
			if (i == randomDir) continue;

			Field temp(fieldWidth, fieldHeigth, f.getFieldState());
			temp.movePlayer(static_cast<Direction> (i));
			Tree *child = new Tree(temp.getFieldState(), rootPointer);
			rootPointer->addChild(child);
		}

		f.movePlayer(randomDir);

		Tree* child = new Tree(f.getFieldState() , rootPointer);

		rootPointer->addChild(child);
		rootPointer = child;

		moves++;
		//if (moves % 1000==0) f.printField();
	}

	f.printField();
	std::cout << moves;
}
void doDFSNoMemory(Field f)
{
	int moves = 0;
	while (!f.isGoalReached())
	{
		f.movePlayer(getRandomDirection());
		moves++;
	}
	f.printField();
	std::cout << moves;
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
	winningBlocks.push_back(Block(Position(2, 2), 'A'));
	winningBlocks.push_back(Block(Position(2, 3), 'B'));
	winningBlocks.push_back(Block(Position(2, 4), 'C'));


	std::cout << "Size of Tree " << sizeof(Tree)<<std::endl;

	FieldState winning(Player(Position(4,4)), winningBlocks);

	Field f(4, 4, p, blocks);
	f.setWinningState(winning);
	f.printField();

	Field f1(4, 4, p, blocks);
	f1.setWinningState(winning);

	/*doDFS(f);
	doDFSNoMemory(f1);*/


	/*std::thread first (doDFS,f);
	std::thread second(doDFSNoMemory,f1);
	
	std::cout << "I AM CONCURRENT " << std::endl;

	first.join();
	second.join();*/


	//doDFSNoMemory(f);
	doBFS(f);

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