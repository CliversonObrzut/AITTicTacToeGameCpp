#pragma once
#include "stdafx.h"
#include "file_manager.h"
#include "board.h"

#ifndef GUI
#define GUI

class Gui : public FileManager
{
	int screen_width;
	int screen_height;
public:
	Gui(string fileName, int width, int height);
	virtual void display();
	void clrscr();
	void resizeScreen();
	int getScreenWidth();
	int getScreenHeight();
	void findScreenPosition(int * screenX, int *screenY);
	void redrawPlayScreen(Board b, bool *first_display, int x, int y);
	void redrawBoard(Board b, string * screen, int x, int y);
	void redrawPlayerScreen(int nPlayer, char selectSymbol, int select_x, int select_y);
	void redrawLevelScreen(int level, char selectSymbol, int select_x, int select_y);
	void updateScreen(string * screen);
};

class WelcomeScreen : public Gui
{	
public:
	WelcomeScreen(string fileName, int width, int height);
};

class MenuScreen : public Gui
{
	int number_of_options;
public:
	MenuScreen(string fileName, int width, int height);
	int getNumberOfOptions();
};

class PlayerScreen : public Gui
{
	int number_of_options;
	int select_x;
	int select_y;
	char selectSymbol;
public:
	PlayerScreen(string fileName, int width, int height);
	int getNumberOfOptions();
	void display(int nPlayers);
	int getSelectX();
	int getSelectY();
	char getSelectSymbol();
};

class LevelScreen : public Gui
{
	int number_of_options;
	int select_x;
	int select_y;
	char selectSymbol;
public:
	LevelScreen(string fileName, int width, int height);
	int getNumberOfOptions();
	void display(int level);
	int getSelectX();
	int getSelectY();
	char getSelectSymbol();
};

class RulesScreen : public Gui
{
	int number_of_options;
public:
	RulesScreen(string fileName, int width, int height);
	int getNumberOfOptions();
};

class RankingScreen : public Gui
{
	int number_of_options;
public:
	RankingScreen(string fileName, int width, int height);
	int getNumberOfOptions();
	//void updateRanking(); TODO
};

class LevelOneScreen : public Gui
{
	Board board;
	int board_x;
	int board_y;
	int text_x;
	int text_y;
	bool first_display = true;
public:
	LevelOneScreen(string fileName, int width, int height, int level);
	void display() override;
	int getBoardX();
	int getBoardY();
};

class LevelTwoScreen : public Gui
{
	Board board;
	int board_x;
	int board_y;
	int text_x;
	int text_y;
	bool first_display = true;
public:
	LevelTwoScreen(string fileName, int width, int height, int level);
	void display() override;
	int getBoardX();
	int getBoardY();
};

class LevelThreeScreen : public Gui
{
	Board board;
	int board_x;
	int board_y;
	int text_x;
	int text_y;
	bool first_display = true;
public:
	LevelThreeScreen(string fileName, int width, int height, int level);
	void display() override;
	int getBoardX();
	int getBoardY();
};

class ResultScreen : public Gui
{
	int number_of_options;
public:
	ResultScreen(string fileName);
	int getNumberOfOptions();
};

#endif