// ---------------------------------------------------
// Programming Assignment:  LAB1A
// Developer:				Roman Kovtun
// Date Written:			03/02/2018
// Purpose:					Ticket Calculation Program
// ---------------------------------------------------

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Roman Kovtun ticket program\n";

	int childTkts, adultTkts, totalTkts;
	cout << "Please enter the number of child tickets: ";
	cin >> childTkts;
	cout << "Please enter the number of adult tickets: ";
	cin >> adultTkts;
	totalTkts = childTkts + adultTkts;

	cout << "The total tickets are: " << totalTkts << endl;

	system("pause");
}