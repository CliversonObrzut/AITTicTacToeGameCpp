#include "stdafx.h"
#include "setup.h"
#include "Windows.h"

// Setup constructor
Setup::Setup()
{
	player_one_name = "PL1";
	player_two_name = "PL2";
	n_players = 1;
	level = 3;
	winner_points = 3;
	loser_points = 2;
	welcome_file = "gameWelcome.txt";
	menu_file = "gameMenu.txt";
	players_file = "gamePlayer.txt";
	level_file = "gameLevel.txt";
	rules_file = "gameRules.txt";
	ranking_file = "gameRanking.txt";
	original_ranking_file = "gameRankingOriginal.txt";
	result_file = "gameResult.txt";
	level_one_file = "gameBoardLevel1.txt";
	level_two_file = "gameBoardLevel2.txt";
	level_three_file = "gameBoardLevel3.txt";
	default_width = 115;
	welcome_height = 32;
	menu_height = 25;
	players_height = 22;
	level_height = 23;
	rules_height = 32;
	ranking_height = 28;
	level_one_height = 28;
	level_two_height = 29;
	level_three_height = 31;
}

// get and set number of players
int Setup::getNPlayers()
{
	return n_players;
}

void Setup::setNPlayers(int n_players)
{
	this->n_players = n_players;
}

// get and set game level
int Setup::getLevel()
{
	return level;
}

void Setup::setLevel(int level)
{
	this->level = level;
}

// get points for the winner and looser
int Setup::getWinnerPoints()
{
	if (level == 3)
		return winner_points * 1;
	else if (level == 5)
		return winner_points * 2;
	else
		return winner_points * 3;
}

int Setup::getLoserPoints()
{
	if (level == 3)
		return loser_points * 1;
	else if (level == 5)
		return loser_points * 2;
	else
		return loser_points * 3;
}

string Setup::getPlayerOneName()
{
	return player_one_name;
}

string Setup::getPlayerTwoName()
{
	return player_two_name;
}


// get content from files
string Setup::getWelcomeFile()
{
	return welcome_file;
}

string Setup::getMenuFile()
{
	return menu_file;
}

string Setup::getPlayerFile()
{
	return players_file;
}

string Setup::getLevelFile()
{
	return level_file;
}

string Setup::getRulesFile()
{
	return rules_file;
}

string Setup::getRankingFile()
{
	return ranking_file;
}

string Setup::getOriginalRankingFile()
{
	return original_ranking_file;
}


string Setup::getResultFile()
{
	return result_file;
}

string Setup::getLeveOneFile()
{
	return level_one_file;
}
string Setup::getLevelTwoFile()
{
	return level_two_file;
}
string Setup::getLevelThreeFile()
{
	return level_three_file;
}

// returns the correct dimensions to resize the console based on each gui screen.
int Setup::getWidth()
{
	return default_width;
}

int Setup::getWelcomeHeight()
{
	return welcome_height;
}

int Setup::getMenuHeight()
{
	return menu_height;
}

int Setup::getPlayerHeight()
{
	return players_height;
}

int Setup::getLevelHeight()
{
	return level_height;
}

int Setup::getRulesHeight()
{
	return rules_height;
}

int Setup::getRankingHeight()
{
	return ranking_height;
}

int Setup::getLevelOneHeight()
{
	return level_one_height;
}

int Setup::getLevelTwoHeight()
{
	return level_two_height;
}

int Setup::getLevelThreeHeight()
{
	return level_three_height;
}

void Setup::setConsoleColor(string color)
{
	if(color == "blue-green")
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x3F);
	}
	if(color == "green-yellow")
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x6F);
	}
	if (color == "pink")
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x5F);
	}
	if (color == "red")
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x4F);
	}
}


