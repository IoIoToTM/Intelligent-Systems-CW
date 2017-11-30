#pragma once



#include"Tree.h"
#include"CostTree.h"

#include<queue>
#include<stack>


//structure for the A* algorithm for comparing costs of two CostTree nodes
struct TreeComparator
{
	bool operator () (const CostTree* a, const CostTree* b) const
	{
		return a->getCost() > b->getCost();
	}
};

extern int nodesExpanded;
extern int IDSnodesExpanded;
extern int numberOfMoves;

int getNumOfNodesInTree(Tree* root);


//function for freeing memory of tree given root
void freeMemory(Tree* root);

//functiong, given a leaf print all the parents in order
void printPathFromLeafToRoot(Tree* leaf);

//every function returns a Tree* so you can go through each parent and look at the moves and states it has passed
//given a start field and a goal, return the path between them depending on the algorithm

Tree* doBFS(Field startField, Field goalField, bool checkIfPlayerPosIsSame = false);

Tree* doBFSGraph(Field startField, Field goalField, bool checkIfPlayerPosIsSame = false);

Tree* doDLS(Field startField, Field goalField, int limit, bool checkIfPlayerPosIsSame = false);

Tree* doDLSWithGraph(Field startField, Field goalField, int limit, bool checkIfPlayerPosIsSame = false);

Tree* doIDS(Field startField, Field goalField, bool checkIfPlayerPosIsSame = false);
Tree* doIDSGraph(Field startField, Field goalField, bool checkIfPlayerPosIsSame = false);

Tree* doDFS(Field startField, Field goalField, bool checkIfPlayerPosIsSame = false);

Tree* doAStar(Field startField, Field goal, bool checkIfPlayerPosIsSame = false);