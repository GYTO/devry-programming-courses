#include <iostream>

using namespace std;

int main()
{
	const int MONTHS = 12;
	int count = 0;
	string name[MONTHS] =
	{ "January", "February", "March", "April", "May", "June", "July",
		"August", "September", "October", "November", "December"
	};
	double rain[MONTHS], avg, year = 0, highest, lowest;
	string highMonth, lowMonth;

	for (count = 0; count < MONTHS; count++)
	{
		cout « "Enter rainfall for " « name[count] « ": ";
		cin » rain[count];
		while (rain[count] < 0)
		{
			cout « "Please enter a number greater than 0." « endl;
			cin » rain[count];
		}
	}


	//   highest = rain[0];
	//   lowest = rain[0];

	for (count = 1; count < MONTHS; count++)
	{
		if (rain[count] > highest)
		{
			highMonth = name[count];
			highest = rain[count];
		}
		else if (rain[count] < lowest)
		{
			lowMonth = name[count];
			lowest = rain[count];
		}
	}


	for (count = 0; count < MONTHS; count++)
	{
		year += rain[count];
	}

	avg = year / MONTHS;

	cout « "Total rainfall: " « year « endl;
	cout « "Average rainfall: " « avg « endl;
	cout « "Least rainfall in: " « lowMonth « endl;
	cout « "Most rainfall in: " « highMonth « endl;
}