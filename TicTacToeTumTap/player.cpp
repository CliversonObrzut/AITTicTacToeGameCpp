#include "stdafx.h"
#include "player.h"

Player::Player()
{
	this->name = "";
	this->points = 0;
	symbol = ' ';
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

int Player::getPoints()
{
	return points;
}

void Player::addPoints(int points)
{
	this->points = this->points + points;
}

void Player::decreasePoints(int points)
{
	this->points = this->points - points;
}

void Player::resetPoints()
{
	this->points = 0;
}

void Player::maxPoints()
{
	this->points = 9999;
}