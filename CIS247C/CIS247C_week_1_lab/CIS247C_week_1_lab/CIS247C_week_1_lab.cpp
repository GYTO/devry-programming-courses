/*
Roman Kovtun
CIS247C
ATM Application
7/13/2018
*/


//Libraries
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

#include <fstream>
#include <ctime>
#include <iomanip>

// Constants 
const int EXIT_VALUE = 5;
const float DAILY_LIMIT = 400.0f;
const string FILENAME = "Account.txt";

// Balance
double balance = 0.0;

// Prototypes
void deposit(double* ptrBalance);
void withdrawal(double* ptrBalance, float dailyLimit);
void withdrawal(double* ptrBalance, float dailyLimit, float amount);

// Entry Point
int main()
{

	// Check what is the balance on the account
	ifstream iFile(FILENAME.c_str());
	if (iFile.is_open())
	{
		// check if the file open and check the balance
		iFile >> balance;
		iFile.close();
	}
	else
	{
		// if file is not open or exist, forse to create a file
		// set random number for balance
		srand(time(0));
		const int MIN = 1000;
		const int MAX = 10000;
		balance = rand() % (MAX - MIN + 1) + MIN;
	}

	cout << fixed << setprecision(2) << "Starting Balance: $" << balance << endl;

	// pointer to set balance to varialbe location
	double* ptrBalance = &balance;

	// loop variable BEFORE the loop
	short choice = 0;

	// start looping
	do {
		// ATM Menu
		system("cls");
		cout << "Menu\n" << endl;
		cout << "1) Deposit" << endl;
		cout << "2) Withdrawal" << endl;
		cout << "3) Check Balance" << endl;
		cout << "4) Quick $40" << endl;
		cout << "5) Exit" << endl;

		// get input
		cout << "\nEnter your Choice: ";
		cin >> choice;

		// user choice on the input
		switch (choice)
		{
		case 1:
			// Deposit
			deposit(ptrBalance);
			break;
		case 2:
			// Withdraw
			withdrawal(ptrBalance, DAILY_LIMIT);
			break;
		case 3:
			// Balance
			cout << fixed << setprecision(2) << "\nCurrent Balance: $" << balance << endl;
			break;
		case 4:
			// Withdraw $40
			withdrawal(ptrBalance, DAILY_LIMIT, 40.0f);
			break;
		case 5:
			// Exit ATM
			cout << "\nGoodbye" << endl;
			break;
		default:
			cout << "\nError. Please select from the menu." << endl;
			break;
		}

		cout << "\nPress any key to continue...";
		_getch();
	} while (choice != EXIT_VALUE);

	ofstream oFile(FILENAME.c_str());
	oFile << balance << endl;
	oFile.close();

	return 0;
}


//// Make Deposit
void deposit(double* ptrBalance)
{
	// check the deposit and validate it
	float deposit = 0.0f;

	do {
		cout << "\nEnter deposit amount: ";
		cin >> deposit;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT16_MAX, '\n');
			cout << "\nError. Please use numbers only.\n" << endl;
			deposit = -1;
			continue;
		}
		else if (deposit < 0.0f)
		{
			cout << "n\Error. INvalid deposit amount. \n" << endl;
		}
	} while (deposit < 0.0f);

	*ptrBalance += deposit;

	cout << fixed << setprecision(2) << "\nCurrent ptrBalance: $" << *ptrBalance << endl;
}
//// Make Withdraw
void withdrawal(double* ptrBalance, float dailyLimit)
{
	// get the withdrawal
	float amount = 0.0f;
	cout << "\nEnter withdrawal amount: ";
	cin >> amount;

	withdrawal(ptrBalance, dailyLimit, amount);
}

//// Make Withdraw with reset
void withdrawal(double* ptrBalance, float dailyLimit, float amount)
{
	// kate money from accoutn
	if (amount > dailyLimit)
	{
		cout << "\nError. Amount exceeds daily limit." << endl;
	}
	else if (amount > *ptrBalance)
	{
		cout << "\nError. Insufficient funds." << endl;
	}
	else
	{
		*ptrBalance -= amount;
		cout << "\nHere is your cashe: $" << amount << endl;
	}

	cout << fixed << setprecision(2) << "\nCurrent Balance: $" << *ptrBalance << endl;
}
