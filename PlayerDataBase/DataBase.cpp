#include "pch.h"
#include "DataBase.h"


DataBase::DataBase()
{

}


DataBase::~DataBase()
{

}

//Adds another player to the list of players
Player * DataBase::Add()
{
	return nullptr;
}


//Sorts the playerlist by either alphabetical order or highest score
Player * DataBase::Sort()
{
	return nullptr;
}

//Finds a specific player in the list by high score or name
Player * DataBase::Search()
{
	return nullptr;
}

//saves the player to the save file
void DataBase::savePlayer(std::ofstream & out)
{

}

//loads players from the save file
bool DataBase::load(std::ifstream & in)
{
	return false;
}
