// ---------------------------------------------------
// Programming Assignment:  LAB1C
// Developer:				Roman Kovtun
// Date Written:			03/02/2018
// Purpose:					Payroll Program
// ---------------------------------------------------


#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout << "Box Office Program\n";

	double totalChild, totalAdult, grossProfit, netProfit, distributorAmt;
	int childTicket, adultTicket;
	
	cout << "Please enter the nubmer of child tickets: ";
	cin >> childTicket;
	cout << "Please enter the nubmer of adult tickets: ";
	cin >> adultTicket;

	totalChild = 6 * childTicket;
	totalAdult = 10 * adultTicket;

	grossProfit = totalAdult + totalChild;
	netProfit = grossProfit * 0.2;
	distributorAmt = grossProfit - netProfit;

	cout << "\n\n";
	cout << fixed << setprecision(2);

	cout << "Gross Box Office Profit:\t $" << setw(8) << grossProfit << endl;
	cout << "Net Box Office Profit:\t $" << setw(8) << netProfit << endl;
	cout << "Amount Paid to Distributor:\t $" << setw(8) << distributorAmt << endl;
	
	system("pause");
}

