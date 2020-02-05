#include "pch.h"
#include "DataBase.h"
#include <iostream>
#include <fstream>
#include <string>


DataBase::DataBase()
{
	_arrayLength = 0;
}


DataBase::~DataBase()
{

}

//Adds another player to the list of players
void DataBase::Add(Player newPlayer)
{
	Player* newList = new Player[_arrayLength + 1];
	
	for (int i = 0; i < _arrayLength; i++)
	{
		newList[i] = _playerList[i];
	}

	newList[_arrayLength] = newPlayer;	

	_arrayLength++;

	_playerList = newList;
}


//Sorts the playerlist by either alphabetical order or highest score
void DataBase::Sort()
{
	
}

//Finds a specific player in the list by high score or name
Player * DataBase::Search()
{
	return nullptr;
}

//saves player names and high scores to the save file
void DataBase::savePlayers()
{
	std::ofstream file;
	file.open("PlayerStats.txt",std::ios::out);	

	//saves arraylength variable
	file << _arrayLength << std::endl;

	//saves player and high scores
	for (int i = 0; i < _arrayLength; i++)
	{
		file << getPlayer(i).getName() << std::endl;
		file << getPlayer(i).getHighScore() <<std::endl;
	}

	file.close();
}

//loads players from the save file
bool DataBase::load()
{

	char* name = new char[30];
	int temphighscore;
	int tempArrayLength;

	std::ifstream file;

	file.open("PlayerStats.txt", std::ios::in);

	//checks if file is open
	if (!file.is_open())
		return false;

	//loads in the array length from the file
	//file.read((char*)&_arrayLength, sizeof(int));
	file >> tempArrayLength;

	//loads in player and player score
	for (int i = 0; i < tempArrayLength; i++)
	{
		file >> name;
		file >> temphighscore;

		//creates player and adds player with loaded name to the list
		Player newPlayer(name, temphighscore);
		Add(newPlayer);
	}

	//checks to see if loads correctly
	if (file.rdstate())
		return false;		
	
	return true;
}

//grabs the player variable out of the Array of players
Player DataBase::getPlayer(int i)
{
	return _playerList[i];
}

int DataBase::getLength()
{
	return _arrayLength;
}