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
	Player Search(char* name);
	void savePlayers();
	bool load();
	Player getPlayer(int i);
	int getLength();	

private:
	Player* _playerList;
	int _arrayLength;
};