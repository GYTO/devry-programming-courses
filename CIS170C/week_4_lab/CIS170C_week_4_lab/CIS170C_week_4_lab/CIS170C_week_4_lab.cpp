// ---------------------------------------------------
// Programming Assignment:  LAB4
// Developer:				Roman Kovtun
// Date Written:			03/25/2018
// Purpose:					Random value Generator
// ---------------------------------------------------

#include "stdafx.h"
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

string flipCoin()
{
	int flipTimes = 1 + rand() % 2;

	if (flipTimes == 1)
	{
		return "Heads";
	}
	else
	{
		return "Tails";
	}
}

int rollDice(int rolledTimes)
{
	int rolls = 1 + rand() % rolledTimes;
	
	return rolls;
}

int main()
{
	unsigned seed = time(0);
	srand(seed);

	string gameType;

	cout << "Welcome to the Random Value Generator \n";

	while (gameType != "E" || gameType != "e")
	{
		cout << "Would you like to flip a coin (C) or roll a dice (D) or Exit (E): ";
		cin >> gameType;

		if (gameType == "C" || gameType == "c")
		{
			double numFlip, count = 0;

			cout << "How many times do you want to flip the coin: ";
			cin >> numFlip;

			for (int i = 1; i <= numFlip; i++)
			{
				cout << "Flip " << i << ": " << flipCoin() << endl;
			}
		}

		if (gameType == "D" || gameType == "d")
		{
			int dieSide, dieRoll;

			cout << "How many sides does your die have: ";
			cin >> dieSide;
			
			cout << "How many times do you want to roll the die: ";
			cin >> dieRoll;

			for (int i = 1; i <= dieRoll; i++)
			{
				cout << "Roll " << i << ": " << rollDice(dieSide) << endl;
			}
		}

		if (gameType == "E" || gameType == "e")
		{
			cout << "Thanks of playing! \n";
			system("pause");
		}

	}

    return 0;
}