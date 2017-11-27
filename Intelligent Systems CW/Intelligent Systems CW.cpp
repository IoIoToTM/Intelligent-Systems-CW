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


std::vector<Direction> randomiseDirections()
{
	std::vector<Direction> directionVector;
	directionVector.push_back(UP);
	directionVector.push_back(DOWN);
	directionVector.push_back(RIGHT);
	directionVector.push_back(LEFT);

	//srand(NULL);

	std::random_shuffle(directionVector.begin(), directionVector.end());

	return directionVector;


}
void doBFS(Field f)
{
	std::queue <Tree*> checkNodes;
	Tree root(f.getFieldState());
	Tree* rootPointer = &root;

	FieldState winning = f.getWinningState();

	int fieldHeigth = f.getHeigth();
	int fieldWidth = f.getWidth();
	int moves = 0;

	checkNodes.push(&root);

	while (true)
	{
		Tree* nodeToExplore = checkNodes.front();
		FieldState currentState = *nodeToExplore->getState();
		checkNodes.pop();

		std::vector<Direction> directions = randomiseDirections();

		for (std::vector<Direction>::iterator it = directions.begin();it!=directions.end();++it)
		{
			Field temp(fieldWidth,fieldHeigth,currentState);
			
			temp.movePlayer(*(it));

			if (currentState == temp.getFieldState())
			{
				continue;
			}

			FieldState t1 = temp.getFieldState();
			bool iswin = t1.checkIfOnlyBlocksInPlace(t1, winning);
			if (t1==winning)
			{
				std::cout << "GOAL REACHED\n";

				Tree* parent = nodeToExplore;
				temp.printField();

				while (parent != NULL)
				{
					Field t(fieldWidth, fieldHeigth, *parent->getState());
					t.printField();
					parent = parent->getParent();
				}
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
bool DLS(Tree* start, Tree* goal, int limit)
{
	FieldState startState = *start->getState();
	FieldState goalState = *goal->getState();
	if (startState == goalState)
	{
		return true;
	}

	if (limit <= 0)
	{
		return false;
	}

	std::vector<Direction> directions = randomiseDirections();

	for (std::vector<Direction>::iterator it = directions.begin(); it != directions.end(); ++it)
	{

		Field f(4, 4, startState);

		f.movePlayer(*(it));

		Tree* toCheck = new Tree(f.getFieldState());
		if (DLS(toCheck, goal, --limit) == true)
		{
			return true;
		}

	}
	return false;
}

bool doDLS(Field f,int depth)
{
	Tree* start = new Tree(f.getFieldState());
	Tree* goal = new Tree(f.getWinningState());
	return DLS(start, goal, depth);
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
	/*winningBlocks.push_back(a);
	winningBlocks.push_back(b);
	winningBlocks.push_back(Block(Position(4,4),'C'));*/



	std::cout << "Size of Tree " << sizeof(Tree)<<std::endl;

	FieldState winning(Player(Position(1,1)), winningBlocks);

	Field f(4, 4, p, blocks);
	f.setWinningState(winning);
	f.printField();

	Field f1(4, 4, p, blocks);
	f1.setWinningState(winning);


	if (doDLS(f, 20) == true)
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