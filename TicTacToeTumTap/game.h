#pragma once
#include "stdafx.h"
#include "setup.h"
#include "player.h"
#include "board.h"

#ifndef GAME
#define GAME

class Game
{
	Setup setup;
public:
	Game();
	void Start();
	void getWelcomeScreen();
	void getMenuScreen();
	void getPlayerScreen();
	void getLevelScreen();
	void getRulesScreen();
	void getRankingScreen();
	void getLevelOneScreen();
	void getLevelTwoScreen();
	void getLevelThreeScreen();
	int getUserOption(int number_of_options);
};

#endif