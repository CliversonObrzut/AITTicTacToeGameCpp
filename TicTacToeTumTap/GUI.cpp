#include "stdafx.h"
#include "GUI.h"
#include "board.h"

// Graphical User Interface constructor
Gui::Gui(string fileName, int screenWidth=0, int screenHeight=0) : FileManager (fileName)
{
	this->screen_width = screenWidth;
	this->screen_height = screenHeight;
}

int Gui::getScreenWidth()
{
	return screen_width;
}

int Gui::getScreenHeight()
{
	return screen_height;
}

void Gui::display()
{
	cout << getContent();
}

void Gui::clrscr()
{
	system("cls");
}

void Gui::resizeScreen()
{
	string w = to_string(screen_width);
	string h = to_string(screen_height);
	string first = "mode con: cols=";
	string second = " lines=";
	string winSize = first + w + second + h;
	char *resize = new char[winSize.length()];
	resize = &winSize[0];
	system(resize);
}

void Gui::findScreenPosition(int * screenX, int * screenY)
{
	bool done = false;
	string * text = new string[linesCount()];
	text = getContentLines();
	for (int y = 0; y < linesCount(); y++)
	{
		for (int x = 0; x < text[y].length(); x++)
		{
			if (text[y][x] == 'Z')
			{
				*screenX = x;
				*screenY = y;
				done = true;
				break;
			}
		}
		if (done)
			break;
	}
}

void Gui::redrawPlayScreen(Board board, bool * first_display, int boardX, int boardY)
{
	string * screen = new string[linesCount()];
	screen = getContentLines();
	if (*first_display)
	{
		cout << getContent();
		*first_display = false;
	}
	else
	{
		board.testSetBoard();
		redrawBoard(board, screen, boardX, boardY);
		updateScreen(screen);
	}
}


void Gui::redrawBoard(Board b, string* screen, int boardx, int boardy)
{
	int level = b.getSize();
	char * board = b.getBoard();
	for (int y = boardy, r = 0; r < level; y++, r++)
	{
		for (int x = boardx, c = 0; c < level; c++, x = x + 4)
		{
			screen[y][x] = board[(level*r) + c];
		}
	}
}

void Gui::redrawPlayerScreen(int nPlayer, char selectSymbol, int select_x, int select_y)
{
	string * screen = new string[linesCount()];
	screen = getContentLines();
	if(nPlayer == 1)
	{
		screen[select_y][select_x] = selectSymbol;
		screen[select_y + 1][select_x] = ' ';
	}
	if (nPlayer == 2)
	{
		screen[select_y][select_x] = ' ';
		screen[select_y + 1][select_x] = selectSymbol;
	}	
	updateScreen(screen);
}

void Gui::redrawLevelScreen(int level, char selectSymbol, int select_x, int select_y)
{
	string * screen = new string[linesCount()];
	screen = getContentLines();
	if (level == 3)
	{
		screen[select_y][select_x] = selectSymbol;
		screen[select_y + 1][select_x] = ' ';
		screen[select_y + 2][select_x] = ' ';
	}
	if (level == 5)
	{
		screen[select_y][select_x] = ' ';
		screen[select_y + 1][select_x] = selectSymbol;
		screen[select_y + 2][select_x] = ' ';
	}
	if (level == 7)
	{
		screen[select_y][select_x] = ' ';
		screen[select_y + 1][select_x] = ' ';
		screen[select_y + 2][select_x] = selectSymbol;
	}
	updateScreen(screen);
}

void Gui::updateScreen(string* screen)
{
	string newContent;
	for (int i = 0; i < linesCount(); i++)
		newContent = newContent + screen[i];
	cout << newContent;
}



// WelcomeScreen constructor
WelcomeScreen::WelcomeScreen(string fileName, int width, int height) : Gui(fileName, width, height)
{
	
}

// MenuScreen constructor
MenuScreen::MenuScreen(string fileName, int width, int height) : Gui(fileName, width, height)
{
	number_of_options = 6;
}

int MenuScreen::getNumberOfOptions()
{
	return number_of_options;
}

// PlayerScreen constructor
PlayerScreen::PlayerScreen(string fileName, int width, int height) : Gui(fileName, width, height)
{
	number_of_options = 3;
	select_x = 46;
	select_y = 13;
	selectSymbol = '>';
}

int PlayerScreen::getNumberOfOptions()
{
	return number_of_options;
}

void PlayerScreen::display(int nPlayers)
{
	redrawPlayerScreen(nPlayers, selectSymbol, select_x, select_y);
}

int PlayerScreen::getSelectX()
{
	return select_x;
}

int PlayerScreen::getSelectY()
{
	return select_y;
}

char PlayerScreen::getSelectSymbol()
{
	return selectSymbol;
}


// LevelScreen constructor
LevelScreen::LevelScreen(string fileName, int width, int height) : Gui(fileName, width, height)
{
	number_of_options = 4;
	select_x = 46;
	select_y = 13;
	selectSymbol = '>';
}

int LevelScreen::getNumberOfOptions()
{
	return number_of_options;
}

void LevelScreen::display(int level)
{
	redrawLevelScreen(level, selectSymbol, select_x, select_y);
}

int LevelScreen::getSelectX()
{
	return select_x;
}

int LevelScreen::getSelectY()
{
	return select_y;
}

char LevelScreen::getSelectSymbol()
{
	return selectSymbol;
}


// RulesScreen constructor
RulesScreen::RulesScreen(string fileName, int width, int height) : Gui(fileName, width, height)
{
	number_of_options = 1;
}

int RulesScreen::getNumberOfOptions()
{
	return number_of_options;
}

// RankingScreen constructor
RankingScreen::RankingScreen(string fileName, int width, int height) : Gui(fileName, width, height)
{
	number_of_options = 1;
}

int RankingScreen::getNumberOfOptions()
{
	return number_of_options;
}


LevelOneScreen::LevelOneScreen(string fileName, int width, int height, int level) : Gui(fileName, width, height), board(level)
{
	board_x = 54;
	board_y = 15;
	first_display = true;
	text_x = 43;
	text_y = 22;
}

void LevelOneScreen::display()
{
	redrawPlayScreen(board, &first_display, board_x, board_y);
}

int LevelOneScreen::getBoardX()
{
	return board_x;
}

int LevelOneScreen::getBoardY()
{
	return board_y;
}

LevelTwoScreen::LevelTwoScreen(string fileName, int width, int height, int level) : Gui(fileName, width, height), board(level)
{
	board_x = 50;
	board_y = 15;
	first_display = true;
	text_x = 41;
	text_y = 23;
}

void LevelTwoScreen::display()
{
	redrawPlayScreen(board, &first_display, board_x, board_y);
}

int LevelTwoScreen::getBoardX()
{
	return board_x;
}

int LevelTwoScreen::getBoardY()
{
	return board_y;
}

LevelThreeScreen::LevelThreeScreen(string fileName, int width, int height, int level) : Gui(fileName, width, height), board(level)
{
	board_x = 48;
	board_y = 15;
	first_display = true;
	text_x = 39;
	text_y = 25;
}

void LevelThreeScreen::display()
{
	redrawPlayScreen(board, &first_display, board_x, board_y);
}

int LevelThreeScreen::getBoardX()
{
	return board_x;
}

int LevelThreeScreen::getBoardY()
{
	return board_y;
}

ResultScreen::ResultScreen(string fileName) : Gui(fileName)
{
	number_of_options = 1;
}

int ResultScreen::getNumberOfOptions()
{
	return number_of_options;
}







