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


	// Use nested if statements to calculate the insurance premium

	// Outer if statement: Test the gender
	if (gender == 'M')
	{
		// The inner series of if, else if, and else statements tests
		// the age and determines the premium.
		if (age < 21)
		{
			premium = 1500 + 200 * numTix;
		}
		else if (age >= 21)
		{
			if (age < 30)
			{
				premium = 1200 + 100 * numTix;
			}
			else // Only other option is 30 or older
			{
				premium = 1000 + 100 * numTix;
			}
		}
	} // end if gender is male

	// Matching else for the outer if statement
	else // Use else because the only other option is gender == 'F'
	{
		// The inner series of if, else if, and else statements tests
		// the age and determines the premium.
		if (age < 21)
		{
			premium = 1200 + 200 * numTix;
		}
		else // Only other option is 21 or older
		{
			premium = 1000 + 100 * numTix;
		}
	} // end gender else

	// Print the result
	cout << "Your premium is $" << premium << endl;

	return 0;
}

/*
  Think about the two solutions. Which do you prefer? I prefer Solution 2
  because the conditions within the if and else-if statments are much
  shorter and easier to read.

  Another consideration is to write a fast running program. Solution 1
  may require testing many conditions. With solution 2 we first
  decide if gender is M or F, the only test the conditions that apply
  to that gender. Consider the case where we have a female who is over 30.
  In Solution 1, we have 4 if/else-if statments to test before we get to
  the correct condition. In Solution 2 we have two statements to test.
*/

//******************************************************************
// This is an example of how to use COMPLEX CONDITIONAL (LOGICAL) EXPRESSIONS
//******************************************************************
#include <iostream>

using namespace std;

int main()
{
	int num;

	cout << "Please, enter number: ";
	cin >> num;

	// Determine the range using COMPLEX CONDITIONAL (LOGICAL) EXPRESSIONS
	if (num >= 5 && num <= 10)
		cout << num << " is within the range 5-10" << endl;			// show a message
	else if (num >= 11 && num <= 15)
		cout << num << " is within the range 11-15" << endl;			// show a message
	else if (num >= 16 && num <= 20)
		cout << num << " is within the range 16-20" << endl;			// show a message
	else
		cout << num << " is outside of the range 5-20" << endl;			// show a message

	cout << endl << endl;

	// Determine the range using MULTI-BRANCH IF-ELSE statements
	cout << endl;
	if (num >= 5)
		if (num <= 10)
			cout << num << " is within the range 5-10" << endl;			// show a message
		else if (num <= 15)
			cout << num << " is within the range 11-15" << endl;		// show a message
		else if (num <= 20)
			cout << num << " is within the range 16-20" << endl;		// show a message
		else
			cout << num << " is outside of the range 5-20" << endl;		// show a message
	else
		cout << num << " is outside of the range 5-20" << endl;			// show a message

	cout << endl << endl;

	return 0;
}