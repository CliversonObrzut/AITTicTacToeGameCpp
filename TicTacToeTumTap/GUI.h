#pragma once
#include "stdafx.h"
#include "file_manager.h"
#include "board.h"
#include "player.h"

#ifndef GUI
#define GUI

class ResultScreen;

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
	void redrawPlayScreen(Board b, Player p1, Player p2, int turn, bool *first_display, int board_x, int board_y, int text_x, int text_y);
	void redrawBoard(Board b, string * screen, int x, int y);
	void redrawPlayerScreen(int nPlayer, char selectSymbol, int select_x, int select_y);
	void redrawLevelScreen(int level, char selectSymbol, int select_x, int select_y);
	void drawResultScreen(ResultScreen rs, Board board, string name, int points, int board_x, int board_y);
	void drawTextInScreen(string * screen, string text, int screen_x, int screen_y);
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
};


class LevelOneScreen : public Gui
{
	Player p1;
	Player p2;
	int board_x;
	int board_y;
	int text_x;
	int text_y;
	bool first_display = true;
	int number_of_options;
public:
	LevelOneScreen(string fileName, int width, int height, int n_player, Board board, Player p1, Player p2);
	void display(int turn, Board board);
	void displayResult(ResultScreen rs, Board board, int turn, int points);
	int getNumberOfOptions();
	int getBoardX();
	int getBoardY();
	int getTextX();
	int getTextY();
};


class LevelTwoScreen : public Gui
{
	Player p1;
	Player p2;
	int board_x;
	int board_y;
	int text_x;
	int text_y;
	bool first_display = true;
	int number_of_options;
public:
	LevelTwoScreen(string fileName, int width, int height, int n_player, Board board, Player p1, Player p2);
	void display(int turn, Board board);
	void displayResult(ResultScreen rs, Board board, int turn, int points);
	int getNumberOfOptions();
	int getBoardX();
	int getBoardY();
	int getTextX();
	int getTextY();
};


class LevelThreeScreen : public Gui
{
	Player p1;
	Player p2;
	int board_x;
	int board_y;
	int text_x;
	int text_y;
	bool first_display = true;
	int number_of_options;
public:
	LevelThreeScreen(string fileName, int width, int height, int n_player, Board board, Player p1, Player p2);
	void display(int turn, Board board);
	void displayResult(ResultScreen rs, Board board, int turn, int points);
	int getNumberOfOptions();
	int getBoardX();
	int getBoardY();
	int getTextX();
	int getTextY();
};


class ResultScreen : public Gui
{
	int number_of_options;
	int name_x;
	int name_y;
	int points_x;
	int points_y;
	int text_x;
	int text_y;
public:
	ResultScreen(string fileName);
	int getNumberOfOptions();
	int getNameX();
	int getNameY();
	int getPointX();
	int getPointY();
	int getTextX();
	int getTextY();
};

#endif