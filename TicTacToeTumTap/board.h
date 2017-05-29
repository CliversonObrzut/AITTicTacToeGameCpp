#pragma once
#include "stdafx.h"

#ifndef BOARD
#define BOARD

class Board
{
	char *board;
	char symbol_x;
	char symbol_o;
	int size;
public:
	Board(int level);
	char * getBoard();
	void setBoard(int x, int y, char symbol);
	char getSymbolO();
	char getSymbolX();
	int getSize();
};

#endif