#include "stdafx.h"
#include "player.h"

Player::Player(string name)
{
	this->name = name;
}

string Player::getName()
{
	return name;
}

void Player::setName(string name)
{
	this->name = name;
}

char Player::getSymbol()
{
	return symbol;
}

void Player::setSymbol(char symbol)
{
	this->symbol = symbol;
}

int Player::getCoordenates(char coordenateName)
{
	int coordenate;
	if (coordenateName == 'x')
		cout << "- Enter the coordenate of \"" << coordenateName << "\": ";
	else
		cout << "- Enter the coordenate of \"" << coordenateName << "\": ";

	cin >> coordenate;
	return coordenate;
}