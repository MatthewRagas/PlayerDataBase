// PlayerDataBase.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Player.h"
#include "DataBase.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{	
	DataBase playerList;
	bool programOver = false;

	char input;
	playerList.load();
	while (!programOver)
	{
		//playerList.Add(Player());
		system("cls");

		cout << "Welcome to the Player Data Base." << endl;
		cout << endl;
		cout << "1: Create New Player Profile" << endl;
		cout << "2: Sort Existing Players" << endl;
		cout << "3: Search from existing Players" << endl;
		cout << "4: Save Player Files" << endl;
		cout << "Player Data Base will save automatically when closing." << endl;
		cin >> input;

		switch (input)
		{
		case '1':
			system("cls");
			cout << "What is your name?" << endl;
			char customName[30];
			cin >> customName;
			playerList.Add(Player(customName));
			break;
		case'2':
			break;
		case '3':
			break;
		case'4':
			break;
		}

		playerList.savePlayers();

		programOver = true;
	}

	/*out.open("test.txt", std::ios::out);
	out << playerList.getPlayer(5).getName() << std::endl;
	out.close();*/
	system("pause");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file