#include"stdafx.h"

#include "Algorithms.h"


//memory deallocation using DFS recursive tree search
void freeMemory(Tree* root)
{
	//if the root is null then we've reached the bottom so we return
	if (root == nullptr)
	{
		return;
	}

	//get the start and end of the tree's children so we can itterate
	std::vector<Tree*>::iterator iterBegin = root->getChildIteratorBegin();
	std::vector<Tree*>::iterator iterEnd = root->getChildIteratorEnd();

	//for each child free the memory at that node recursively
	for (; iterBegin != iterEnd; ++iterBegin)
	{
		freeMemory(*iterBegin);
	}

	//free the memory once we've freed all the memory of the children
	delete root;
}


void printPathFromLeafToRoot(Tree* leaf)
{
	while (leaf != nullptr)
	{
		leaf->getField()->printField();
		leaf = leaf->getParent();
	}
}


Tree* doBFS(Field startField, Field goalField, bool checkIfPlayerPosIsSame)
{
	//for a BFS we use a queue
	std::queue <Tree*> checkNodes;

	//the first pointer to the root
	Tree* root = new Tree(startField);
	Tree* rootPointer = root;

	//local variables for the height and width of the field
	int fieldHeigth = startField.getHeigth();
	int fieldWidth = goalField.getWidth();
	int moves = 0;

	//push the first node and start checking
	checkNodes.push(root);

	while (!checkNodes.empty())
	{
		//get the next node in the queue and get its field
		Tree* nodeToExplore = checkNodes.front();
		Field currentField = *nodeToExplore->getField();

		//if it's the goal state, return the node
		if (currentField == goalField)
		{
			if (checkIfPlayerPosIsSame)
			{
				if (currentField.getPlayerPos() == goalField.getPlayerPos())
				{
					return nodeToExplore;
				}
			}
			else
			{
				//std::cout << "yay22 " << nodeToExplore->getDepth();
				return nodeToExplore;
			}
		}

		//pop the node
		checkNodes.pop();



		//randomising directions in which we expand, should't not make a difference 
		//if we don't because BFS checks all nodes on a current depth before continuing
		
		std::vector<Direction> directions = randomiseDirections();

		//go through each direction
		for (std::vector<Direction>::iterator it = directions.begin(); it != directions.end(); ++it)
		{
			//create a temporary field with the current state
			Field temp(fieldWidth, fieldHeigth, currentField);
			//move the player a direction
			temp.movePlayer(*(it));
			
			//get the depth of the parent
			int parentDepth = nodeToExplore->getDepth();

			//create a new node in the heap and add the child to the current node and push it in the queue
			Tree *child = new Tree(temp, nodeToExplore, ++parentDepth);
			nodeToExplore->addChild(child);
			checkNodes.push(child);
		}
	}

	return nullptr;
}


Tree* doDLS(Field startField, Field goalField, int limit, bool checkIfPlayerPosIsSame)
{

	/*
	from what I did I noticed that DLS and DFS are essentially the same algorithm, the only difference is that DLS stops at a limit
	while DFS stops at the bottom, which we don't have in this case
	so I just added a check, if we pass it a depth of -1, then it never stops at a depth, and continues just like DFS, but any other positive limit and 
	it will stop expanding once it's reached that limit
	*/
	
	//the only difference between DFS and BFS in their non-recursive versions is that DFS uses a stack while BFS uses a queue
	//in theory we could even make the code better if we have a few functions and depending on what we call we use a stack or queue, so we don't duplicate code
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
					return nodeToExplore;
				}
			}
			else
			{
				return nodeToExplore;
			}
		}
		checkNodes.pop();

		//get a random direction
		Direction randomDir = getRandomDirection();

		int parentDepth = nodeToExplore->getDepth();

		//this is the check to see if it's either the limit or DFS
		if (parentDepth == limit && limit != -1)
		{
			//TODO delete?
			//skip the expanding and start from the next node
			continue;
		}

		//for each of the 4 directions
		for (int i = 0; i<4; i++)
		{
			//create a temporary field
			Field temp(fieldWidth, fieldHeigth, currentField);
			parentDepth = nodeToExplore->getDepth();
			//if the current direction is the random chosen one, skip so we add it later on top of the stack
			if (i == randomDir)
			{
				continue;
			}
			//move player with a static cast from int to Direction 
			temp.movePlayer(static_cast<Direction> (i));

			//create a new node on the heap and add it to the children of the parent
			Tree *child = new Tree(temp, nodeToExplore, ++parentDepth);
			nodeToExplore->addChild(child);
			checkNodes.push(child);
		}

		//the same as in the for but for the random direction
		Field temp(fieldWidth, fieldHeigth, currentField);
		parentDepth = nodeToExplore->getDepth();
		temp.movePlayer(randomDir);
		Tree *child = new Tree(temp, nodeToExplore, ++parentDepth);
		nodeToExplore->addChild(child);
		checkNodes.push(child);

	}

	//free the memory in case it's DLS
	freeMemory(rootPointer);
	return nullptr;
}


//iterative deepening is just DLS, each time adding 1 to the limit until we get an asnwer
Tree* doIDS(Field startField, Field goalField, bool checkIfPlayerPosIsSame )
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

//as stated above, DFS is just DLS without a limit, so we pass it -1
Tree* doDFS(Field startField, Field goalField, bool checkIfPlayerPosIsSame)
{
	return doDLS(startField, goalField, -1);
}

//A* was probably the most interesting algorithm to implement, using a priority queue
Tree* doAStar(Field startField, Field goal, bool checkIfPlayerPosIsSame)
{

	//we create a priority queue with a new class CostTree, which is just like a Tree but with an added cost parameter
	//I've also defined a comparator between two CostTrees, so the queue can get the minimal cost each time
	std::priority_queue<CostTree*, std::vector<CostTree*>, TreeComparator> queue;

	CostTree* root = new CostTree(startField, startField.calculateManhattanDistance(goal));
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


		//randomising directions as in BFS
		std::vector<Direction> directions = randomiseDirections();

		for (std::vector<Direction>::iterator it = directions.begin(); it != directions.end(); ++it)
		{
			//mostly the same as the other algorithms except the cost calculating function
			Field temp(fieldWidth, fieldHeigth, currentField);
			int parentDepth = nodeToExplore->getDepth();
			temp.movePlayer(*(it));

			//we create a new node on the heap, with the cost of the current depth (which is the number of moves up until that state)
			//and the manhattan distance from the temporary field to the goal field, the queue takes care of the rest
			CostTree *child = new CostTree(temp, nodeToExplore, nodeToExplore->getDepth() + temp.calculateManhattanDistance(goal), ++parentDepth);
			nodeToExplore->addChild(child);
			queue.push(child);
		}
	}
	return nullptr;
}