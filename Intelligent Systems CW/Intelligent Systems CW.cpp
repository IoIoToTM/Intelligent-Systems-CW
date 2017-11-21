// Intelligent Systems CW.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <dos.h>
#include <windows.h>
#include <conio.h>

#include <string>

#include <vector>

#include "Field.h"


using namespace std;

/*
enum type
{
	EmptyTile, Player, Block
};*/
/*
enum Direction
{

	UP, DOWN, LEFT, RIGHT

}*/

class Tile1
{
public:
	int x, y;

	void setTilePos(int x, int y)
	{

		this->x = x;
		this->y = y;

	}

	Tile1(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	Tile1()
	{
		x = 0;
		y = 0;
	}
};

class Player1 : public Tile1
{
public:
	Player1(int x, int y) :Tile1(x, y) {};
	Player1() :Tile1() {};

};

class Block1 : public Tile1
{

public:
	char name;
	Block1(int x, int y, char n) : Tile1(x, y)
	{
		name = n;
	};
	Block1() : Tile1()
	{
		name = ' ';
	};
};



class Field1
{

public:
	int h, w;

	Player1 p;
	Block1 b[3];

	Field1(int w, int h, int p_x, int p_y) :p(p_x, p_y)
	{
		this->h = h;
		this->w = w;
		b[0].setTilePos(1, h);
		b[0].name = 'A';
		b[1].setTilePos(2, h);
		b[1].name = 'B';
		b[2].setTilePos(3, h);
		b[2].name = 'C';
		// p(p_x,p_y);
	}

	bool canPlayerMove(Direction d)
	{
		if (p.x == w && d == RIGHT)
		{
			return false;

		}
		if (p.x == 1 && d == LEFT)
		{
			return false;

		}
		if (p.y == 1 && d == UP)
		{
			return false;

		}
		if (p.y == h && d == DOWN)
		{
			return false;

		}
		return true;

	}

	bool isThereBlock(int x, int y)
	{
		for (int block = 0; block<3; block++)
		{
			if (b[block].x == x&& b[block].y == y)
			{

				return true;
			}

		}
		return false;
	}

	int getBlockNumber(int x, int y)
	{
		for (int block = 0; block<3; block++)
		{
			if (b[block].x == x&& b[block].y == y)
			{

				return block;
			}

		}
		return 0;
	}

	void movePlayer(Direction d)
	{

		switch (d)
		{
		case UP:
			if (isThereBlock(p.x, p.y - 1))
			{
				b[getBlockNumber(p.x, p.y - 1)].y = p.y;
			}
			if (canPlayerMove(UP))
				p.y = p.y - 1;
			break;
		case DOWN:
			if (isThereBlock(p.x, p.y + 1))
			{
				b[getBlockNumber(p.x, p.y + 1)].y = p.y;
			}
			if (canPlayerMove(DOWN))
				p.y = p.y + 1;
			break;
		case LEFT:
			if (isThereBlock(p.x - 1, p.y))
			{
				b[getBlockNumber(p.x - 1, p.y)].x = p.x;
			}
			if (canPlayerMove(LEFT))
				p.x = p.x - 1;
			break;
		case RIGHT:
			if (isThereBlock(p.x + 1, p.y))
			{
				b[getBlockNumber(p.x + 1, p.y)].x = p.x;
			}
			if (canPlayerMove(RIGHT))
				p.x = p.x + 1;
			break;

		}
	}

	void printField()
	{

		for (int i = 1; i <= h; i++)
		{

			for (int j = 1; j <= w; j++)
			{
				if (isThereBlock(j, i))
				{
					std::cout << " " << b[getBlockNumber(j, i)].name << " ";

				}
				else
				{
					if (p.x == j&&p.y == i)
					{
						std::cout << " p ";
					}
					else std::cout << " x ";
				}
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;

	}

	bool checkIfFieldIsOk()
	{

		if (isThereBlock(2, h) && b[getBlockNumber(2, h)].name == 'C'&&isThereBlock(2, h - 1) && b[getBlockNumber(2, h - 1)].name == 'B'&&isThereBlock(2, h - 2) && b[getBlockNumber(2, h - 2)].name == 'A'&&p.x == 4 && p.y == 4)
		{
			return true;
		}
		else return false;

	}

};



#include <string>
#include <sstream>

namespace patch
{
	template < typename T > std::string to_string(const T& n)
	{
		std::ostringstream stm;
		stm << n;
		return stm.str();
	}
}

Direction randDir()
{


	int i = 0;
	i = (rand() % 4) + 1;
	if (i == 1) return UP;
	else if (i == 2) return DOWN;
	else if (i == 3) return LEFT;
	else if (i == 4) return RIGHT;

}

void doDFS(Field1 f)
{



}


#define KEY_UP 119
#define KEY_DOWN 115
#define KEY_LEFT 97
#define KEY_RIGHT 100

#include"Field.h"

#include"Block.h"
#include"Player.h"
#include "FieldState.h"
int main()
{

	Player p (4, 4);
	Block a(4, 1, 'A');
	Block b(4, 2, 'B');
	Block c(4, 3, 'C');

	vector<Block> blocks;
	blocks.push_back(a);
	blocks.push_back(b);
	blocks.push_back(c);

	vector<Block> winningBlocks;
	winningBlocks.push_back(Block(2, 2, 'A'));
	winningBlocks.push_back(Block(2, 3, 'B'));
	winningBlocks.push_back(Block(2, 4, 'C'));

	FieldState winningState(Player(4,4),winningBlocks);

	

	Field f(4,4,p,blocks);
	f.setWinningState(winningState);
	f.printField();
	f.movePlayer(UP);
	f.printField();


	int x;
	cin >> x;
}


