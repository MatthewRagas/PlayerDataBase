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


//Sorts the playerlist by alphabetical order
void DataBase::Sort()
{
	bool sorted = false;

	while (!sorted)
	{
		int swaps = 0;
		//loop counting through the list of players
		for (int i = 0; i < _arrayLength - 1; i++)
		{
			int p = i + 1;
			
			//loop counting through the letters in names of players and comparing
			for (int n = 0; n < 30; n++)
			{
				if (_playerList[i].getName()[n] > _playerList[p].getName()[n])
				{
					Player tempPlayer = _playerList[p];
					_playerList[p] = _playerList[i];
					_playerList[i] = tempPlayer;
					swaps++;
					break;
				}
				else if(_playerList[i].getName()[n] == _playerList[p].getName()[n])
				{

				}
				else
				{
					break;
				}
			}			
		}
		//if swaps is greater than 0 the function should continue the loop until no swaps happen
		if (swaps <= 0)
		{
			sorted = true;
		}
	}	
	//savePlayers();
}

//Displays the list of players and their scores to the console
void DataBase::Display()
{
	system("cls");

	//print out players and high scores
	for (int i = 0; i < _arrayLength; i++)
	{
		std::cout << _playerList[i].getName() << ": " << _playerList[i].getHighScore() << std::endl;
	}

	if (_arrayLength <= 0)
	{
		std::cout << "There are no players in the data base." << std::endl;
	}
}

//Finds a specific player in the list by high score or name
int  DataBase::Search(char* name)
{

	Player player;

	int i  = 0;
	int max = _arrayLength - 1;
	

	while (i <= max)
	{
		int searchSpot = (i + max) / 2;

		if (strcmp(_playerList[searchSpot].getName(), name) == 0)
		{
			return searchSpot;
		}
		else if (strcmp(_playerList[searchSpot].getName(), name) < 0)
		{
			i = searchSpot + 1;
		}
		else if (strcmp(_playerList[searchSpot].getName(), name) > 0)
		{
			max--;
		}									
	}
	return NULL;
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