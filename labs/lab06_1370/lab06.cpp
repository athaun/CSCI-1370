/////////////////////////////////////////////////////////////////////
//
// Name: Asher Haun
// Due date: 9.28.22
// Class: CSCI 1370-03
// Semester: Fall 2022
// CSCI 1370 Instructor: Gustavo Dietrich
//
// Using your own words describe below what the program does
// Program Description: Takes a value and a number of decimal digits, passes
// those to a method that rounds the first value to number of decimal places
// specified by the second input value. Outputs the initial value and the
// rounded value in fixed form.
//
/////////////////////////////////////////////////////////////////////``

#include <iomanip>
#include <iostream>				// to use cin and cout
#include <typeinfo>				// to be able to use operator typeid
#include <cmath>
#include <iomanip>

// Ignore this; it's a little function used for making tests
inline void _test(const char* expression, const char* file, int line) {
	std::cerr << "test(" << expression << ") failed in file " << file;
	std::cerr << ", line " << line << "." << std::endl << std::endl;
}
// This goes along with the above function...don't worry about it
#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))

// Insert the prototype of the function here
double round_off (double value, int dec_digits);

int main () {
	// Declare variable value, valuero that hold double precision real numbers
	double value, value_ro;

	// Declare variable decdig that holds whole numbers
	int dec_digits;

	// Prompt the user to "Enter the real number: "
	// Read from keyboard the value entered by the user and assign it to value
	std::cout << "Enter a real number: ";
	std::cin >> value;

	// Prompt the user to "Enter number of digits: "
	// Read from keyboard the value entered by the user and assign it to decdig
	std::cout << "Enter number of digits: ";
	std::cin >> dec_digits;

	// Round the real number to the number of decimal digits specified and assign the result to valuero
	value_ro = round_off(value, dec_digits);

	// Format the output to display the numbers in fixed format with ten decimal digits
	std::cout << std::fixed << std::setprecision(10);

	// Display on the screen, using 23 columns, the message
	//	   "The original number is ", value
	std::cout << std::setw(23) << "The original number is " << value << "\n";

	// Format the output to display the numbers in fixed format with the number of decimal digits specified plus 2
	std::cout << std::fixed << std::setprecision(dec_digits + 2);

	// Display on the screen, using 23 columns, the message
	//	   "The rounded number is ", valuero
	std::cout << std::setw(23) << "The rounded number is " << value_ro << "\n";

	// Do NOT remove or modify the following statements
	std::cout << std::endl << "Testing your solution" << std::endl << std::endl;
	test(typeid(value) == typeid(1.));										// Incorrect data type used for value
	test(typeid(value_ro) == typeid(1.));									// Incorrect data type used for valuero
	test(typeid(dec_digits) == typeid(1));										// Incorrect data type used for decdig
	
	//IMPORTANT!!!  Include these tests once the function has been implemented

	test(fabs(round_off(125.123456789,2) - 125.12 ) < 0.001);				// Incorrect rounding to two decimal digits 
	test(fabs(round_off(125.123456789,4) - 125.1235) < 0.00001);			// Incorrect rounding to four decimal digits 
	test(fabs(round_off(125.987654321,0) - 126.) < 0.001);					// Incorrect rounding to no decimal digits 
	test(fabs(round_off(125.987654321, 5) - 125.98765) < 0.000001);			// Incorrect rounding to five decimal digits 
	 
	return 0;
}

//************************  Function definition  *************************
// Read the handout carefully for detailed description of the functions that you have to implement

// Rounds the value received in the first parameter to the number of digits received in the second parameter
double round_off (double value, int dec_digits) {
	dec_digits = pow(10, dec_digits);
	return round(value * dec_digits) / dec_digits;
}