#pragma once
#include "stdafx.h"

#ifndef PLAYER
#define PLAYER

class Player
{ 
	string name;
	char symbol;
public:
	Player(string name);
	string getName();
	void setName(string name);
	char getSymbol();
	void setSymbol(char symbol);
	int getCoordenates(char coordenate);
};

#endif