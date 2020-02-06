#include "pch.h"
#include "Player.h"
#include <iostream>


Player::Player()
{
	strcpy_s(_name, "Player");
	_highScore = 0;
}

Player::Player(char* name, int score)
{
	strcpy_s(_name, name);
	_highScore = score;
}


Player::~Player()
{

}

char* Player::getName()
{
	return _name;
}

int Player::getHighScore()
{
	return _highScore;
}

void Player::editPlayerName(char* name)
{
	name = _name;
}