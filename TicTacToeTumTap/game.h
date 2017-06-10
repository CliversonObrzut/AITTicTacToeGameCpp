#pragma once
#include "stdafx.h"
#include "setup.h"
#include "player.h"
#include "LinkedList.h"
#include "board.h"
#include "GUI.h"

#ifndef GAME
#define GAME

class Game
{
	Setup stp;
	Player p1;
	Player p2;
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
	void updatePoints(Player * pw, Player *pl);
	void updateRanking();
	void updateLinkedListRanking(LinkedList * scores, LinkedList * players, node * head, node * new_nn, node * new_np, Player p);
	void drawTextForFile(string * screen, string text, int file_x, int file_y);
};

#endif