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
public:
	PlayerScreen(string fileName, int width, int height);
	int getNumberOfOptions();
};

class LevelScreen : public Gui
{
	int number_of_options;
public:
	LevelScreen(string fileName, int width, int height);
	int getNumberOfOptions();
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
public:
	LevelOneScreen(string fileName, int width, int height);
	void display(Board b);
};

class LevelTwoScreen : public Gui
{
public:
	LevelTwoScreen(string fileName, int width, int height);
	void display(Board b);
};

class LevelThreeScreen : public Gui
{
public:
	LevelThreeScreen(string fileName, int width, int height);
	void display(Board b);
};

class ResultScreen : public Gui
{
	int number_of_options;
public:
	ResultScreen(string fileName);
	int getNumberOfOptions();
};

#endif