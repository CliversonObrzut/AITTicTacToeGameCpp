#pragma once
#include "stdafx.h"
#include "player.h"

#ifndef SETUP
#define SETUP

class Setup
{
	string player_one_name;
	string player_two_name;
	int n_players;
	int level;
	int winner_points;
	int loser_points;
	string welcome_file;
	string menu_file;
	string players_file;
	string level_file;
	string rules_file;
	string ranking_file;
	string original_ranking_file;
	string result_file;
	string level_one_file;
	string level_two_file;
	string level_three_file;
	int default_width;
	int welcome_height;	
	int menu_height;
	int players_height;
	int level_height;
	int rules_height;
	int ranking_height;
	int level_one_height;
	int level_two_height;
	int level_three_height;

public:
	Setup();
	int getNPlayers();
	void setNPlayers(int n_players);
	int getLevel();
	void setLevel(int level);
	int getWinnerPoints();
	int getLoserPoints();
	string getPlayerOneName();
	string getPlayerTwoName();
	string getWelcomeFile();
	string getMenuFile();
	string getPlayerFile();
	string getLevelFile();
	string getRulesFile();
	string getRankingFile();
	string getOriginalRankingFile();
	string getResultFile();
	string getLeveOneFile();
	string getLevelTwoFile();
	string getLevelThreeFile();

	int getWidth();
	int getWelcomeHeight();
	int getMenuHeight();
	int getPlayerHeight();
	int getLevelHeight();
	int getRulesHeight();
	int getRankingHeight();
	int getLevelOneHeight();
	int getLevelTwoHeight();
	int getLevelThreeHeight();

	void setConsoleColor(string color);
};

#endif