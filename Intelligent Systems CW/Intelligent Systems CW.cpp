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


	/*
	How to use:
	Create a player with a position in the field size(from 1 to the size, not from 0)
	Create the goal player position the same way

	Create as many blocks as you want with Positions and a char name and then put them in a vector

	Create a field with width, height, and the player and blocks in it

	Do the same for the goal state

	The algorithms each return the goal node, so through that you can follow the path through to the root,
	or pass it to the printing function

	After the goal is returned, there are 2 global variables, numberOfMoves and nodesExpanded that you can print or do whatever you want with

	*/
	Player startPlayer(Position(4,4));
	Player goalPlayer(Position(1,1));


	
	Block a(Position(1, 4), 'A');
	Block b(Position(2, 4), 'B');
	Block c(Position(3, 4), 'C');

	std::vector<Block> blocks;
	blocks.push_back(a);
	blocks.push_back(b);
	blocks.push_back(c);

	std::vector<Block> assignmentGoal;
	assignmentGoal.push_back(Block(Position(2, 2), 'A'));
	assignmentGoal.push_back(Block(Position(2, 3), 'B'));
	assignmentGoal.push_back(Block(Position(2, 4), 'C'));

	std::vector<Block> myGoal;
	myGoal.push_back(Block(Position(2, 4), 'A'));
	myGoal.push_back(Block(Position(2, 3), 'B'));
	myGoal.push_back(Block(Position(4, 4), 'C'));
	
	
	std::cout << "Start state is:\n";
	Field startField(4, 4, startPlayer, blocks);
	startField.printField();

	Field assignmentGoalField(4, 4, startPlayer, assignmentGoal);
	
	std::cout << "Goal state is:\n";
	Field myGoalField(4, 4, goalPlayer, myGoal);
	myGoalField.printField();


	std::cout << "------------------- \n\n";

	int total = 0;

	Tree* result = doIDS(startField, myGoalField,true);
	std::cout << "Result is: \n\n";

	printPathFromLeafToRoot(result);

	std::cout << "Nodes expanded is " << nodesExpanded<<" with "<<numberOfMoves<<" number of moves";

	
	int x;
	std::cin >> x;

	return 0;
}