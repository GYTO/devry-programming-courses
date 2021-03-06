// ---------------------------------------------------
// Programming Assignment:  LAB6
// Developer:				Roman Kovtun
// Date Written:			04/06/2018
// Purpose:					Menu-Driven Application 
// ---------------------------------------------------



#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>

#include "RetailItem.hpp"
//using std::cout;

using namespace std;



int main()
{
	// Init the Class from RetailItem.HPP - builing contracttor
	RetailItem Items[3];

	// Welcome Message
	cout << "Welcome to the Retail store!" << endl;

	// Build new Item for first one
	string newItem;
	double newPrice;
	int newQTY;

	// make total on invetory
	double totalINV;

	cout << "---------------------------------" << endl;

	// check if the price is greater then 0 
	do
	{
		cout << "Price must be greater than 0." << endl;
		cout << "Please enter the price for item 1: $";
		cin >> newPrice;
	} while (newPrice < 1);

	cout << "---------------------------------" << endl;

	// check if the invetory is greater then 0
	do
	{
		cout << "Inventory must be greater than 0." << endl;
		cout << "Please enter the units on hand for item 1: ";
		cin >> newQTY;
	} while (newQTY < 1);

	cout << "---------------------------------" << endl;

	// create new item
	cout << "Please enter the description for item 1: ";
	cin >> newItem;

	// Build Items
	Items[0].SetDescribtion(newItem);
	Items[0].SetPrice(newPrice);
	Items[0].SetUnits(newQTY);

	Items[1].SetDescribtion("Jeans");
	Items[1].SetPrice(34.95);
	Items[1].SetUnits(40);

	Items[2].SetDescribtion("Long sleve shirt");
	Items[2].SetPrice(24.95);
	Items[2].SetUnits(20);

	cout << "\n\nDisplay all items " << endl;
	cout << "----------------- \n\n";

	for (int i = 0; i <= 2; i++)
	{
		cout << "Describtion: " << Items[i].getDescription() << endl;
		cout << "Unit on Hand: " << Items[i].getUnits() << endl;
		cout << "Price: $" << Items[i].getPrice() << endl;
		cout << "\n";
	}

	totalINV = Items[0].getUnits() + Items[1].getUnits() + Items[2].getUnits();

	cout << "Display the total inventory" << endl;
	cout << "The total invetory is " << totalINV << endl;

	system("pause");
}

