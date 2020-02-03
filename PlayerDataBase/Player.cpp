#include "pch.h"
#include "Player.h"
#include <iostream>


Player::Player()
{
	strcpy_s(_name, "Player");
	_highScore = 0;
}

Player::Player(const char name[])
{
	strcpy_s(_name, name);
	_highScore = 0;
}


Player::~Player()
{

}

char* Player::getName()
{
	return _name;
}

int Player::gethighScore()
{
	return _highScore;
}