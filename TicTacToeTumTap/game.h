#pragma once
#include "stdafx.h"
#include "setup.h"
#include "player.h"
#include "LinkedList.h"
#include "board.h"

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
	int defineWhoStart(int number_of_options, char symbol_x, char symbol_o);
	void enterCoordX(Board * board);
	void enterCoordY(Board * board);
	int getValidCoordenate(int number_of_options);
	bool checkVictory(Board &board);
	bool checkTie(Board &board);
	void resultUpdates(Board board, int turn);
	void updatePoints(Player * pw, Player *pl);
	void updateRanking();
	void resetRanking();
	void updateLinkedListRanking(LinkedList * scores, LinkedList * players, node * new_nn, node * new_np, Player p);
	void drawTextForFile(string * screen, string text, int file_x, int file_y);
};

#endif