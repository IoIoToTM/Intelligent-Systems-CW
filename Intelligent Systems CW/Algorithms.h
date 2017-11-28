#pragma once

#include"Tree.h"
#include"CostTree.h"

#include<queue>
#include<stack>


void freeMemory(Tree* root)
{
	
	if (root == nullptr)
	{
		return;
	}

	std::vector<Tree*>::iterator iterBegin = root->getChildIteratorBegin();
	std::vector<Tree*>::iterator iterEnd = root->getChildIteratorEnd();

	for (; iterBegin != iterEnd; ++iterBegin)
	{
		freeMemory(*iterBegin);
	}

	delete root;

	
	
	
	/*
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
	*/
}

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
		if (parentDepth == limit && limit != -1)
		{
			//TODO delete?
			continue;
		}
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
	
	freeMemory(rootPointer);
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

struct node_comparison
{
	bool operator () (const CostTree* a, const CostTree* b) const
	{
		return a->getCost() > b->getCost();
	}
};

Tree* doAStar(Field startField, Field goal,bool checkIfPlayerPosIsSame = false)
{
	std::priority_queue<CostTree*,std::vector<CostTree*>, node_comparison> queue;

	CostTree* root = new CostTree(startField,startField.calculateManhatanDistance(goal));
	CostTree* rootPointer = root;

	int fieldHeigth = goal.getHeigth();
	int fieldWidth = goal.getWidth();
	int moves = 0;

	queue.push(root);

	while (!queue.empty())
	{
		CostTree* nodeToExplore = queue.top();
		Field currentField = *nodeToExplore->getField();

		if (currentField == goal)
		{
			if (checkIfPlayerPosIsSame)
			{
				if (currentField.getPlayerPos() == goal.getPlayerPos())
				{
					return nodeToExplore;
				}
			}
			else
			{
				return nodeToExplore;
			}
		}

		queue.pop();

		std::vector<Direction> directions = randomiseDirections();

		for (std::vector<Direction>::iterator it = directions.begin(); it != directions.end(); ++it)
		{
			Field temp(fieldWidth, fieldHeigth, currentField);

			int parentDepth = nodeToExplore->getDepth();
			temp.movePlayer(*(it));
			CostTree *child = new CostTree(temp, nodeToExplore,nodeToExplore->getDepth()+temp.calculateManhatanDistance(goal), ++parentDepth);
			nodeToExplore->addChild(child);
			queue.push(child);
		}

		/*Tree* nodeToExplore = checkNodes.front();
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
		}*/
	}


	/*std::vector<Block> startingBlocks;
	startingBlocks.push_back(Block(Position(1, 4), 'A'));
	startingBlocks.push_back(Block(Position(2, 4), 'B'));
	startingBlocks.push_back(Block(Position(3, 4), 'C'));

	std::vector<Block> winningBlocks;
	winningBlocks.push_back(Block(Position(2, 4), 'A'));
	winningBlocks.push_back(Block(Position(3, 4), 'B'));
	winningBlocks.push_back(Block(Position(4, 4), 'C'));

	Field f(4, 4, Player(Position(4, 4)), startingBlocks);

	Field w(4, 4, Player(Position(1, 1)), winningBlocks);

	CostTree* temp= new CostTree(f, f.calculateManhatanDistance(w));

	CostTree* temp2 = new CostTree(w, w.calculateManhatanDistance(w));

	queue.push(temp);
	queue.push(temp2);

	CostTree* x = queue.top();
	queue.pop();
	*/

	return nullptr;


}