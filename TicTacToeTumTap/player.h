#pragma once
#include "stdafx.h"

#ifndef PLAYER
#define PLAYER

class Player
{ 
	string name;
	char symbol;
	int points;
public:
	Player(string name);
	string getName();
	void setName(string name);
	char getSymbol();
	void setSymbol(char symbol);
	int getPoints();
	void addPoints(int points);
	void resetPoints();
	int getCoordenates(char coordenate);
};

#endif