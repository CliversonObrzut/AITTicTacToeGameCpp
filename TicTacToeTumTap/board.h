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
	int coord_x;
	int coord_y;
	bool winner;
	bool tie;
public:
	Board();
	Board(int level);
	char * getBoard();
	void setBoardOnPlay(char symbol);
	void setBoardResult();
	char getSymbolO();
	char getSymbolX();
	int getSize();
	int getCoordX();
	void setCoordX(int x);
	int getCoordY();
	void setCoordY(int y);
	bool coordIsValid();
	bool getWinner();
	void setWinner();
	bool getTie();
	void setTie();
};

#endif