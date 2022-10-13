/////////////////////////////////////////////////////////////////////
//
// Name: Asher Haun
// Due date: 10.12.22
// Class: CSCI 1370-03
// Semester: Fall 2022
// CSCI 1370 Instructor: Gustavo Dietrich
//
// Using your own words describe below what the program does 
// Program Description: Given an input in cents, returns the number of various coins that can be used to find compose the same value in fewer coins.
//
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <typeinfo>				// to be able to use operator typeid

inline auto _test(const char* expression, const char* file, int line) -> void{
	std::cerr << "test(" << expression << ") failed in file " << file;
	std::cerr << ", line " << line << "." << std::endl << std::endl;
}
#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))

// Function prototypes
auto coin_changer (int cents, int & c25, int & c10, int & c05, int & c01, int & coin_count) -> void;
auto print_change (int cents, int & c25, int & c10, int & c05, int & c01, int & coin_count) -> void;

auto main () -> int {
	// Declare variables amount (amount in cents), count25 (quantity of quarters), count10 (quantity of dimes),
	// count5 (quantity of nickels), count1 (quantity of pennies), and count (quantity of coins) to hold whole values
	int amount, count25, count10, count5, count1, count = 0;

	// Prompt the user to "Enter amount in cents to be returned as change: "
	std::cout << "Enter amount in cents to be returned as change: ";

	// Read the value from the keyboard and store it in the corresponding variable
	std::cin >> amount;

	// Call coin_changer() to calculate the quantity of each type of coin and the total number of coins
	// that are needed to provide a given change
	coin_changer(amount, count25, count10, count5, count1, count);

	// Call function print_change() to print the amount of change, the quantity of each type of coin and the total number of coins
	print_change(amount, count25, count10, count5, count1, count);

	// Do NOT remove or modify the following statements
	std::cout << std::endl << "Testing your solution" << std::endl << std::endl;
	test(typeid(count25) == typeid(1));						// Incorrect data type used for count25
	test(typeid(count10) == typeid(1));						// Incorrect data type used for count10
	test(typeid(count5) == typeid(1));						// Incorrect data type used for count5
	test(typeid(count1) == typeid(1));						// Incorrect data type used for count1
	test(typeid(amount) == typeid(1));						// Incorrect data type used for amount
	test(typeid(count) == typeid(1));						// Incorrect data type used for count
	coin_changer(71, count25, count10, count5, count1, count);
	test(count25 == 2 );									// Incorrect quantity of quarters
	test(count10 == 2);										// Incorrect quantity of dimes
	test(count5 == 0);										// Incorrect quantity of nickels
	test(count1 == 1);										// Incorrect quantity of pennies
	coin_changer(69, count25, count10, count5, count1, count);
	test(count25 == 2);										// Incorrect quantity of quarters
	test(count10 == 1);										// Incorrect quantity of dimes
	test(count5 == 1);										// Incorrect quantity of nickels
	test(count1 == 4);										// Incorrect quantity of pennies
	coin_changer(14, count25, count10, count5, count1, count);
	test(count25 == 0);										// Incorrect quantity of quarters
	test(count10 == 1);										// Incorrect quantity of dimes
	test(count5 == 0);										// Incorrect quantity of nickels
	test(count1 == 4);										// Incorrect quantity of pennies

	return 0;
}

//************************  Function definition  *************************

// Calculate the quantity of each type of coin and the total number of coins that are needed to provide a given change
// and return all these values along with the total number of coins that are needed for the change
auto coin_changer (int cents, int & c25, int & c10, int & c05, int & c01, int & coin_count) -> void {
    int amount = cents;
    int change;

    change = static_cast<int>(amount / 25);
    coin_count += change;
	c25 = change;
	amount %= 25;

    change = static_cast<int>(amount / 10);
	coin_count += change;
    c10 = change;
	amount %= 10;

    change = static_cast<int>(amount / 5);
    coin_count += change;
    c05 = change;
	amount %= 5;

    change = static_cast<int>(amount / 1);
    coin_count += change;
	c01 = change;

    return;
}

// Print the amount of cents, the quantity of each type of coin and the total number of coins 
// according to the format specifies on my handout
auto print_change (int cents, int & c25, int & c10, int & c05, int & c01, int & coin_count) -> void {
	std::cout << "\nYou need to use " << coin_count << " coins for a change of " << cents << " cents:\n\n";

	std::cout << c25 << " Quarters\n";
	std::cout << c10 << " Dimes\n";
	std::cout << c05 << " Nickels\n";
	std::cout << c01 << " Pennies\n";

    return;
}