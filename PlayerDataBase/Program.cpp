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
		cout << "3: Search existing Players" << endl;
		cout << "4: Display Player profiles" << endl;
		cout << "5: Edit Player file" << endl;	
		cout << "6: Exit program" << endl;
		cin >> input;

		switch (input)
		{
		case '1':
			system("cls");
			cout << "What is your name?" << endl;
			char customName[30];
			cin >> customName;
			cout << "What's your score?" << endl;
			int customScore;
			cin >> customScore;
			playerList.Add(Player(customName,customScore));
			break;
		case'2':						
			playerList.Sort();
			break;
		case '3':
			system("cls");
			cout << "Who are you looking for?" << endl;
			cin >> customName;
			system("cls");
			//if search function returns an integer within the bounds of the array
			if (playerList.Search(customName) >= 0)
			{
				cout << "Player found" << endl;
				cout << playerList.getPlayer(playerList.Search(customName)).getName() << endl;
			}
			//if the search function returns -1 the player was not found
			else
			{
				cout << "Player not found." << endl;
			}
			
			system("pause");
			break;
		case'4':		
			//displays a list of the players in the data base
			playerList.Display();
			system("pause");
			break;
		case '5':
			system("cls");
			cout << "Who are you looking for?" << endl;
			cin >> customName;
			system("cls");
			//if search function returns an integer within the bounds of the array
			if (playerList.Search(customName) >= 0)
			{
				cout << "Edit name or Highscore?" << endl;
				cout << "1: Name\n2: Highscore" << endl;
				cin >> input;

				switch(input)
				{
				case'1':
					char newName[30];
					system("cls");
					cout << "Input new player name." << endl;
					cin >> newName;
					playerList.updatePlayerName(playerList.Search(customName), newName);
					cout << playerList.getPlayer(playerList.Search(customName)).getName() << endl;
					system("pause");
					break;
				case'2':
					int newScore;
					cout << "Input new player score." << endl;
					cin >> newScore;
					playerList.updatePlayerScore(playerList.Search(customName), newScore);
					break;
				}

			}
			//if the search function returns -1 the player was not found
			else
			{
				cout << "Player not found." << endl;
			}
			break;
		case '6':
			programOver = true;
			break;
		}

		playerList.savePlayers();

		
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