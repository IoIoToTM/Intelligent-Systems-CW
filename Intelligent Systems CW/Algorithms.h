#pragma once

#include"Tree.h"
#include"CostTree.h"

#include<queue>
#include<stack>
#include<time.h>


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
	Tree* root = new Tree(&startField);
	Tree* rootPointer = root;

	int fieldHeigth = startField.getHeigth();
	int fieldWidth = goalField.getWidth();
	int moves = 0;

	checkNodes.push(root);

	int sizeOfChunk = 1000000;

	char* buf = new char[sizeof(Tree) * sizeOfChunk];

	int currentchunk = 0;

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
			if (currentchunk == sizeOfChunk) return nullptr;
			char* buf_local = buf + (sizeof(Tree)*currentchunk);
			Tree* child = new (buf_local) Tree(&temp, nodeToExplore, ++parentDepth);
			currentchunk++;
			//Tree *child = new Tree(temp, nodeToExplore, ++parentDepth);
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
	Tree* root = new Tree(&startField);
	Tree* rootPointer = root;

	int fieldHeigth = goalField.getHeigth();
	int fieldWidth = goalField.getWidth();
	int moves = 0;

	checkNodes.push(root);

	int sizeOfChunk = 10000000;

	char* buf = new char[sizeof(Tree) * sizeOfChunk];

	int currentchunk = 0;

	time_t start = time(0);
	int numOfNodesExpanded = 0;

	while (!checkNodes.empty())
	{
		Tree* nodeToExplore = checkNodes.top();
		Field currentField = *nodeToExplore->getField();

		if (difftime(time(0), start) >= 1)
		{
			std::cout << "Num of nodes expanded for 1 second " << numOfNodesExpanded << "\n";
			numOfNodesExpanded = 0;
			//nodeToExplore->getField()->printField();
			start = time(0);
		}


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
			Field* temp = new Field(fieldWidth, fieldHeigth, currentField);
			parentDepth = nodeToExplore->getDepth();
			if (i == randomDir) continue;
			temp->movePlayer(static_cast<Direction> (i));

			char* buf_local = buf + (sizeof(Tree)*currentchunk);
			Tree* child = new (buf_local) Tree(temp, nodeToExplore, ++parentDepth);
			currentchunk++;

			//Tree *child = new Tree(temp, nodeToExplore, ++parentDepth);
			numOfNodesExpanded++;
			nodeToExplore->addChild(child);
			checkNodes.push(child);
		}

		Field* temp = new Field(fieldWidth, fieldHeigth, currentField);
		parentDepth = nodeToExplore->getDepth();
		temp->movePlayer(randomDir);
		
		char* buf_local = buf + (sizeof(Tree)*currentchunk);
		Tree* child = new (buf_local) Tree(temp, nodeToExplore, ++parentDepth);
		currentchunk++;
		
		//Tree *child = new Tree(temp, nodeToExplore, ++parentDepth);
		numOfNodesExpanded++;
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
		std::cout << "Searching level " << i << "\n";
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

	CostTree* root = new CostTree(&startField,startField.calculateManhatanDistance(goal));
	CostTree* rootPointer = root;

	int fieldHeigth = goal.getHeigth();
	int fieldWidth = goal.getWidth();
	int moves = 0;

	queue.push(root);

	time_t start = time(0);
	int numOfNodesExpanded = 0;

	while (!queue.empty())
	{
		CostTree* nodeToExplore = queue.top();
		Field currentField = *nodeToExplore->getField();

		if (difftime(time(0), start) >= 1)
		{
			std::cout << "Num of nodes expanded for 1 second " << numOfNodesExpanded << "\n";
			numOfNodesExpanded = 0;
			//nodeToExplore->getField()->printField();
			start = time(0);
		}

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
				std::cout << numOfNodesExpanded << "\n";
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
			CostTree *child = new CostTree(&temp, nodeToExplore,parentDepth+temp.calculateManhatanDistance(goal), ++parentDepth);
			numOfNodesExpanded++;
			nodeToExplore->addChild(child);
			queue.push(child);
		}
	}
	return nullptr;
}