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
}

int PlayerScreen::getNumberOfOptions()
{
	return number_of_options;
}


// LevelScreen constructor
LevelScreen::LevelScreen(string fileName, int width, int height) : Gui(fileName, width, height)
{
	number_of_options = 4;
}

int LevelScreen::getNumberOfOptions()
{
	return number_of_options;
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


LevelOneScreen::LevelOneScreen(string fileName, int width, int height) : Gui(fileName, width, height)
{

}

void LevelOneScreen::display(Board b)
{
	bool done = false;
	int boardX=-1, boardY=-1;
	int level = b.getSize();
	char * board = b.getBoard();
	string * text = new string[linesCount()];
	text = getContentLines();
	for (int y = 0; y < linesCount(); y++)
	{
		for (int x = 0; x < text[y].length(); x++)
		{
			if (text[y][x] == '_')
			{
				boardX = x + 1;
				boardY = y;
				done = true;
				break;
			}
		}
		if (done)
			break;
	}
	for (int y = boardY, r=0; r < level; y++,r++)
	{
		for (int x = boardX, c = 0; c < level; c++, x = x + 4)
		{
			text[y][x] = board[(level*r) + c];
		}
	}

	if (boardX != -1 && boardY != -1)
	{
		string newContent;
		for (int i = 0; i < linesCount(); i++)
			newContent = newContent + text[i];
		cout << newContent;
	}
	else
		cout << getContent();
}


LevelTwoScreen::LevelTwoScreen(string fileName, int width, int height) : Gui(fileName, width, height)
{

}

void LevelTwoScreen::display(Board b)
{
	bool done = false;
	int boardX = -1, boardY = -1;
	int level = b.getSize();
	char * board = b.getBoard();
	string * text = new string[linesCount()];
	text = getContentLines();
	for (int y = 0; y < linesCount(); y++)
	{
		for (int x = 0; x < text[y].length(); x++)
		{
			if (text[y][x] == '_')
			{
				boardX = x + 1;
				boardY = y;
				done = true;
				break;
			}
		}
		if (done)
			break;
	}
	for (int y = boardY, r = 0; r < level; y++, r++)
	{
		for (int x = boardX, c = 0; c < level; c++, x = x + 4)
		{
			text[y][x] = board[(level*r) + c];
		}
	}

	if (boardX != -1 && boardY != -1)
	{
		string newContent;
		for (int i = 0; i < linesCount(); i++)
			newContent = newContent + text[i];
		cout << newContent;
	}
	else
		cout << getContent();
}
LevelThreeScreen::LevelThreeScreen(string fileName, int width, int height) : Gui(fileName, width, height)
{
	
}

void LevelThreeScreen::display(Board b)
{
	bool done = false;
	int boardX = -1, boardY = -1;
	int level = b.getSize();
	char * board = b.getBoard();
	string * text = new string[linesCount()];
	text = getContentLines();
	for (int y = 0; y < linesCount(); y++)
	{
		for (int x = 0; x < text[y].length(); x++)
		{
			if (text[y][x] == '_')
			{
				boardX = x + 1;
				boardY = y;
				done = true;
				break;
			}
		}
		if (done)
			break;
	}
	for (int y = boardY, r = 0; r < level; y++, r++)
	{
		for (int x = boardX, c = 0; c < level; c++, x = x + 4)
		{
			text[y][x] = board[(level*r) + c];
		}
	}

	if (boardX != -1 && boardY != -1)
	{
		string newContent;
		for (int i = 0; i < linesCount(); i++)
			newContent = newContent + text[i];
		cout << newContent;
	}
	else
		cout << getContent();
}

ResultScreen::ResultScreen(string fileName) : Gui(fileName)
{
	number_of_options = 1;
}

int ResultScreen::getNumberOfOptions()
{
	return number_of_options;
}







