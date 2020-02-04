#pragma once
#include "Player.h"
class DataBase
{
public:
	DataBase();
	~DataBase();
	Player* Add();
	Player* Sort();
	Player* Search();
	void savePlayer();
	bool load(std::ifstream& in);
	Player getPlayer(int i);

private:
	Player _playerList[30];
};