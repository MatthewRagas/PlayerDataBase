#pragma once
#include <string>
class Player
{
public:
	Player();
	Player(const char name[]);
	~Player();
	char* getName();
	int gethighScore();
	

private:
	char _name[30];
	int _highScore;
};