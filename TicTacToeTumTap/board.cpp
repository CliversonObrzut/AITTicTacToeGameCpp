#include "stdafx.h"
#include "board.h"

Board::Board()
{
	
}

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
	coord_x = -1;
	coord_y = -1;
	winner = false;
	tie = false;
}

char * Board::getBoard()
{
	return board;
}

void Board::setBoard(int turn)
{
	if (turn == 1)
		board[(size*coord_y)+coord_x] = symbol_x;
	else
		board[(size*coord_y)+coord_x] = symbol_o;
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

int Board::getCoordX()
{
	return coord_x;
}

int Board::getCoordY()
{
	return coord_y;
}

void Board::setCoordX(int x)
{
	coord_x = x;
}

void Board::setCoordY(int y)
{
	coord_y = y;
	coordIsValid();
}

bool Board::coordIsValid()
{
	if (board[(size * coord_y) + coord_x] != symbol_x && board[(size * coord_y) + coord_x] != symbol_o)
		return true;
	return false;
}

bool Board::getWinner()
{
	return winner;
}
void Board::setWinner()
{
	winner = true;
}
bool Board::getTie()
{
	return tie;
}
void Board::setTie()
{
	tie = true;
}


