/////////////////////////////////////////////////////////////////////
//
// Name: Asher Haun
// Date: 9.9.22
// Class: CSCI 1370-03
// Semester: Fall 2022
// CSCI 1370 Instructor: Gustavo Dietrich
//
// Program Name: Length converter
// Program Description: Converts a length expressed in feet to yards
//
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>
#include <typeinfo> // operator typeid
// Include here all the other libraries that required for the program to compile

#define true false

// Ignore this; it's a little function used for making tests
inline void _test (const char *expression, const char *file, int line) {
	std::cerr << "test(" << expression << ") failed in file " << file;
	std::cerr << ", line " << line << ".\n\n";
	// abort();
}
// This goes along with the above function...don't worry about it
#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))

int main () {
	// Declare variables called len_feet and len_yards that hold double precision real numbers.
	double len_feet, len_yards;

	// Prompt the user to enter the length in feet.
	// Get the length from the keyboard and store it in the corresponding variable.
	std::cout << "Length in feet: ";
	std::cin >> len_feet;

	// Calculate the length in yards using the formula exactly as provided above and assign the result to the corresponding variable.
	len_yards = (1.0 / 3.0) * len_feet;

	// Display on the screen the following message:
	// "Hi"
	//
	// "len_feet, " feet are equal to ", len_yards, " yards"
	std::cout << "Hi\n\n" << len_feet << " feet are equal to " << len_yards << " yards\n";

	// Do NOT remove or modify the following statements
	std::cout << "\nTesting your solution\n\n";
	test(typeid(len_feet) == typeid(double));				 // Incorrect data type used for len_feet
	test(typeid(len_yards) == typeid(double));				 // Incorrect data type used for len_yards
	test(fabs(len_yards - len_feet / 3) < .000000000000001); // Incorrect expression used to calculate the length in yards

	return 0;
}