//////////////////////////////////////////////////////////////////////
//
// Author: Emmett Tomai
// Revised by: Christine Reilly
//
// Large Joe's Drive Through
// Demonstrate conditional expressions 
//
//////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

int main()
{
	int order; // The customer's order
	char fries; // Their fry order
	char bacon; // Their bacon order

	// We can initilaize a variable when we declare it.
	// We are going to use this variable to keep track of how much
	// money the customer owes so we want to initilaize it to zero.
	double total = 0; // The amount the customer owes
	
	
	// Print the order menu
	cout << "== Welcome to Large Joe's, can I take your order? ==" << endl;
	cout << "For a triple burger, press 1" << endl;
	cout << "For a heap of fried chicken, press 2" << endl;
	cout << "For a jumbo hot dog, press 3" << endl;
	
	// Read the order
	cout << "Your order: ";
	cin >> order;
	
	// Use if statements to figure out what they ordered and add the order
	// amount to the total
	
	// Start a series of if - else if - else statements with an if statement
	// Use the if statment to see if they entered the value 1
	// Remember to use the equality operator (==) not the assignment operator (=)
	// When the expression following the word "if" evaulates to true, the code
	// insde the block immediately under the if statement is executed.
	if ( order == 1 )
	{
		// Here we use the compound assignment statement.
		// This line is equivalent to: total = total + 4.99;
		total += 4.99;
	}
	
	// If they entered the value 1 the program execution skips the remaining else if
	// and else statements. Similarly, when any of the conditions in the following
	// else if statements are true, the statements within that else if block
	// are executed and the program execution skits the remaining else if and else
	// statements.
	
	else if ( order == 2 )
	{
		total += 6.99;
	}
	else if ( order == 3 )
	{
		total += 2.99;
	}
	
	// We've covered all the options we gave the user. But what if they entered 
	// a number other than 1, 2, or 3? Lets use an else statement to print a 
	// message to inform the user they entered a wrong number.
	// By placing an else statement following the series of if, else if statements 
	// we ensure that some action is always taken.
	else 
	{
		cout << "That isn't a valid number. I guess you're not very hungry" << endl;	
	}

	// Ask if they want fries
	cout << endl;
	cout << "Would you like fries with that? (y/n): ";
	cin >> fries;
	
	// Add fry amount to total if they want fries
	// Now we are comapring a char variable to a literal character. Remember to
	// place literal characters inside single quotation marks.
	// In this case we only want to take an action if the user enters 'y'. 
	// We don't need an else statement because we don't want to do anything
	// if the user enters anything other than 'y'.
	if(fries == 'y')
	{
		total += 2.29;
	}
	
	// Print total
	cout << endl;
	cout << "Your total is $" << total << ", please drive through." << endl;
	
	return 0;
}