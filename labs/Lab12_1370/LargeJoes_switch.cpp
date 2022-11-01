//////////////////////////////////////////////////////////////////////
//
// Author: Christine Reilly (Based on a program by Emmett Tomai)
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
	
    // Use a switch structure to figure out what they ordered and add the order
    // amount to the total.
    
    // The variable inside the parentheses following the word "switch" is the 
    // variable that we are testing the value of. This variable must be an 
    // integer or character.
    
    switch (order)
    {
        // case 1: is equivalent to: if ( order == 1 )
        // So if the value of order is 1 the statements all of the statments
        // following case 1: will be executed, until a break statement is found.
    case 1:
        total += 4.99;
        
        // If the value of order is 1 we want to skip the remaining parts of
        // the switch structure. We use a break statement to skip to the
        // end of the switch structure. If we didn't use a break statement, 
        // the following statements in the switch structure (those under 
        // different cases) will be executed.
        // See Example 4-25 (p 206-208) in the 5th edition of Malik to see
        // what happens when you don't use a break statement under each
        // case.
        break;

        // If order was not equivalent to 1, we now test to see if it is 
        // equivalent to 2.
    case 2:
        total += 6.99;
        
        // Just like in case 1, we want to exit the switch structure at
        // this point so we use a break statement.
        break;

        // If order was not equivalent to 1 or 2, we now test to see if
        // it is equivalent to 3
    case 3:
    	total += 2.99;
        break;
	
	// We've covered all the options we gave the user. But what if they entered 
	// a number other than 1, 2, or 3? Lets use a default statement to print a 
	// message to inform the user they entered a wrong number.
	// By placing a default statement following all possible cases 
	// we ensure that some action is always taken.
    default: 
        cout << "That isn't a valid number. I guess you're not very hungry" << endl;	
    }

    
    
    // The rest of the program is the same as in the if Statements example.
    
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