#pragma once

#include"Tree.h"

#include<queue>
#include<stack>

Tree* doBFS(Field startField, Field goalField, bool checkIfPlayerPosIsSame = false)
{
	std::queue <Tree*> checkNodes;
	Tree* root = new Tree(startField);
	Tree* rootPointer = root;

	int fieldHeigth = startField.getHeigth();
	int fieldWidth = goalField.getWidth();
	int moves = 0;

	checkNodes.push(root);

	while (!checkNodes.empty())
	{
		Tree* nodeToExplore = checkNodes.front();
		Field currentField = *nodeToExplore->getField();

		if (currentField == goalField)
		{
			if (checkIfPlayerPosIsSame)
			{
				if (currentField.getPlayerPos() == goalField.getPlayerPos())
				{
					std::cout << "yay";
					return nodeToExplore;
				}
			}
			else
			{
				std::cout << "yay22 " << nodeToExplore->getDepth();
				//freeMemory(rootPointer);
				return nodeToExplore;
			}
		}
		checkNodes.pop();



		std::vector<Direction> directions = randomiseDirections();

		for (std::vector<Direction>::iterator it = directions.begin(); it != directions.end(); ++it)
		{
			Field temp(fieldWidth, fieldHeigth, currentField);

			int parentDepth = nodeToExplore->getDepth();
			temp.movePlayer(*(it));
			Tree *child = new Tree(temp, nodeToExplore, ++parentDepth);
			nodeToExplore->addChild(child);
			checkNodes.push(child);
		}


		/*if (currentField == temp.getFieldState())
		{
		continue;
		}*/

		/*Field t1 = temp.getFieldState();
		bool iswin = t1.checkIfOnlyBlocksInPlace(t1, winning);
		if (t1==winning)
		{
		std::cout << "GOAL REACHED\n";

		Tree* parent = nodeToExplore;
		temp.printField();

		while (parent != NULL)
		{
		Field t(fieldWidth, fieldHeigth, *parent->getField());
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

	return nullptr;


}
/*bool DLS(Tree* start, Tree* goal, int limit)
{
FieldState startState = *start->getField();
FieldState goalState = *goal->getField();
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
}*/
/*
bool doDLS(Field f,int depth)
{
Tree* start = new Tree(f.getFieldState());
Tree* goal = new Tree(f.getWinningState());
return DLS(start, goal, depth);
}*/






Tree* doDLS(Field startField, Field goalField, int limit, bool checkIfPlayerPosIsSame = false)
{
	std::stack <Tree*> checkNodes;
	Tree* root = new Tree(startField);
	Tree* rootPointer = root;

	int fieldHeigth = goalField.getHeigth();
	int fieldWidth = goalField.getWidth();
	int moves = 0;

	checkNodes.push(root);

	while (!checkNodes.empty())
	{
		Tree* nodeToExplore = checkNodes.top();
		Field currentField = *nodeToExplore->getField();

		if (currentField == goalField)
		{
			if (checkIfPlayerPosIsSame)
			{
				if (currentField.getPlayerPos() == goalField.getPlayerPos())
				{
					std::cout << "yay";
					return nodeToExplore;
				}
			}
			else
			{
				std::cout << "yay22 " << nodeToExplore->getDepth();

				return nodeToExplore;
			}
		}
		checkNodes.pop();



		Direction randomDir = getRandomDirection();

		int parentDepth = nodeToExplore->getDepth();
		if (parentDepth == limit && limit != -1) continue;
		for (int i = 0; i<4; i++)
		{
			Field temp(fieldWidth, fieldHeigth, currentField);
			parentDepth = nodeToExplore->getDepth();
			if (i == randomDir) continue;
			temp.movePlayer(static_cast<Direction> (i));
			Tree *child = new Tree(temp, nodeToExplore, ++parentDepth);
			nodeToExplore->addChild(child);
			checkNodes.push(child);
		}

		Field temp(fieldWidth, fieldHeigth, currentField);
		parentDepth = nodeToExplore->getDepth();
		temp.movePlayer(randomDir);
		Tree *child = new Tree(temp, nodeToExplore, ++parentDepth);
		nodeToExplore->addChild(child);
		checkNodes.push(child);

	}
	return nullptr;
}

Tree* doIDS(Field startField, Field goalField, bool checkIfPlayerPosIsSame = false)
{
	for (int i = 0;; i++)
	{
		Tree* answer = doDLS(startField, goalField, i, checkIfPlayerPosIsSame);
		if (answer != nullptr)
		{
			return answer;
		}
	}
}

Tree* doDFS(Field startField, Field goalField, bool checkIfPlayerPosIsSame = false)
{
	return doDLS(startField, goalField, -1);
}
/*
Tree root(f);
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
std::cout << moves;*/
/*
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
}*/

Tree* doAStar(Field startField, Field goal)
{
	std::priority_queue<Tree*, std::vector<Tree*>, std::greater<int>>   queue;





}