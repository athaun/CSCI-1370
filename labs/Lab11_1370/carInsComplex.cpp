//////////////////////////////////////////////////////////////////////
//
// Christine Reilly
//
// Calculate the car insurance premium based on the following rules:
// - (Gender); (Age); (Annual Premium)
// - Male; Under 21; 1500 + 200 for every ticket on record
// - Male; 21 to 29; 1200 + 100 for every ticket on record
// - Male; 30 and older; 1000 + 100 for every ticket on record
// - Female; Under 21; 1200 + 200 for every ticket on record
// - Female; 21 and older; 1000 + 100 for every ticket on record
//
//////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

int main()
{

	char gender; // The customer's gender
	int age; // The customer's age
	int numTix; // Number of tickets the customer has had
	int premium; // Customer's insurance premium

	// Get information from the user
	// We will assume that the user always enters correct input

	// Get the user's gender
	cout << "Enter your gender (M/F): ";
	cin >> gender;

	// Get the user's age
	cout << "Enter your age as an integer: ";
	cin >> age;

	// Get the number of tickets
	cout << "How many tickets do you have: ";
	cin >> numTix;

	// Calculate the insurance premium
	if ( gender == 'M' && age < 21 )
	{
		premium = 1500 + 200 * numTix;
	}
	else if ( gender == 'M' && age >= 21 && age < 30 )
	{
		premium = 1200 + 100 * numTix;
	}
	else if ( gender == 'M' && age >= 30 )
	{
		premium = 1000 + 100 * numTix;
	}
	else if ( gender == 'F' && age < 21 )
	{
		premium = 1200 + 200 * numTix;
	}
	else
	{
		premium = 1000 + 100 * numTix;
	}

	// Print the result
	cout << "Your premium is $" << premium << endl << endl;

	return 0;
}
