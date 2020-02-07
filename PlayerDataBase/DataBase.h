#pragma once
#include "Player.h"
class DataBase
{
public:
	DataBase();
	~DataBase();
	void Add(Player newPlayer);
	void Sort();
	void Display();
	int Search(char* name);
	void savePlayers();
	bool load();
	Player getPlayer(int i);
	int getLength();
	Player updatePlayerName(int i, char newName[30]);
	Player updatePlayerScore(int i, int newScore);
private:
	Player* _playerList;
	int _arrayLength;
};