#include "stdafx.h"
#include "board.h"

Board::Board(int level)
{
	int lenght = level*level;
	board = new char[lenght];
	int lastLine = lenght - level - 1;
	for (int i = 0; i < lenght; i++)
	{
		if (i > lastLine)
			board[i] = ' ';
		else
			board[i] = '_';
	}		
	symbol_x = 'X';
	symbol_o = 'O';
	size = level;
}

char * Board::getBoard()
{
	return board;
}

void Board::setBoard(int x, int y, char symbol)
{
	if (symbol == 'X')
		board[(size*y)+x] = symbol_x;
	else
		board[(size*y)+x] = symbol_o;
}

int Board::getSize()
{
	return size;
}

char Board::getSymbolX()
{
	return symbol_x;
}

char Board::getSymbolO()
{
	return symbol_o;
}


