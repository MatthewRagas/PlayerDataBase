#pragma once
#include <string>
class Player
{
public:
	Player();
	Player(char* name, int score);
	~Player();
	char* getName();
	int getHighScore();
	void editPlayerName(char* name);
	

private:
	char _name[30];
	int _highScore;
};