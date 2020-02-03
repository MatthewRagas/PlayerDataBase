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
	void savePlayer(std::ofstream& out);
	bool load(std::ifstream& in);

private:
	Player _playerList[];
};

