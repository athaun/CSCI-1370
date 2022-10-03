/////////////////////////////////////////////////////////////////////
//
// Name: Asher Haun
// Date: 9.16.2022
// Class: CSCI 1370-03
// Semester: Fall 2022
// CSCI 1370 Instructor: Gustavo Dietrich
//
// Using your own words describe below what the program does 
// Program Description: Takes 3 inputs, a, h and k as integers and calculates the +/- results of the quadratic formula.
// Those two values are then printed to two rounded decimal places at the end.
//
/////////////////////////////////////////////////////////////////////

#include <iomanip>				// :O
#include <iostream>				// to be able to use std I/O (cin, cout)
#include <cmath>				// to be able to use predefined functions
#include <typeinfo>				// to be able to use operator typeid
#include <string>				// to be able to use std::string type

inline void _test(const char* expression, const char* file, int line) {
	std::cerr << "test(" << expression << ") failed in file " << file;
	std::cerr << ", line " << line << "." << std::endl << std::endl;
}
#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))

int main () {
	
	std::string name; 	// Declares variable name that holds text
	int a, h, k; 		// Declares variables a, h, k that hold whole numbers
	double x1, x2; 		// Declares variables x1 and x2 that hold double precision real numbers

	// Prompts the user to "Please enter your name: "
	// Reads the name from keyboard and stores it in the corresponding variable
	std::cout << "Please enter your name: ";
	std::cin >> name;

	// Displays title "Please enter the known terms for the quadratic equation:"
	std::cout << "\nPlease enter the known terms for the quadsration equation:\n\n";

	// Prompts the user to enter a
	// Reads the value from the keyboard and stores it in the corresponding variable
	std::cout << "a: ";
	std::cin >> a;

	// Because the equation uses k / a, it is important to catch a possible divide by 0.
	// Explicitly allowed by Dr. Dietrich - asked in class
	if (a == 0) {
		std::cout << "\nWarning:\na = 0 will result in a divide by 0 which is impossible. Try inputting another value for a.\n\n";
		return 1;
	}
	// Negative k and a must be non negative

	// Prompts the user to enter h
	// Reads the value from the keyboard and stores it in the corresponding variable
	std::cout << "h: ";
	std::cin >> h;

	// Prompts the user to enter k
	// Reads the value from the keyboard and stores it in the corresponding variable
	std::cout << "k: ";
	std::cin >> k;

	// Displays "Thanks ", name
	std::cout << "\nThanks " << name << "\n\n";

	// Explicitly casting k and a to double so there is no ambiguity about what is happening in the back-end
	double root_k_div_a = sqrt(static_cast<double>(k) / static_cast<double>(a));

	// Calculates x1 using the formula -h + square root(k/a)
	x1 = -h + root_k_div_a;

	// Rounds x1 to the second decimal digit and reassigns it to x1
	x1 = round(x1 * 100.0) / 100.0;
	double _x1 = floor((x1 * 100.0) + 0.5) / 100.0;

	// Calculates x2 using the formula -h - square root(k/a)
	x2 = -h - root_k_div_a;

	// Rounds x2 to the second decimal digit and reassigns it to x2
	x2 = round(x2 * 100.0) / 100.0;
	// double _x2 = floor((x2 * 100.0) + 0.5) / 100.0;

	// Formats the output to display the solutions in fixed format with two decimal digits
	std::cout << std::fixed << std::setprecision(2);
	// Prints a message like the one below:
	// "The solutions for the equation are:"
	//                                 "x1: ", x1
	//								   "x2: ", x2
	std::cout << "The solutions for the equation are:\n\n\t\t\t\tx1: " << x1 << "\n\n\t\t\t\tx2: " << x2 << "\n"; 
	
	// Do NOT remove or modify the following statements
	std::cout << "\nTesting your solution\n\n";
	test(typeid(name) == typeid(std::string));			// Incorrect data type used for name
	test(typeid(x1) == typeid(double));				// Incorrect data type used for x1
	test(typeid(x2) == typeid(double));				// Incorrect data type used for x2
	test(typeid(a) == typeid(int));					// Incorrect data type used for a
	test(typeid(k) == typeid(int));					// Incorrect data type used for k
	test(typeid(h) == typeid(int));					// Incorrect data type used for h
	if (a == 4 && h == 2 && k == 3)					// Incorrect value of x1 (check expressions for calculating x1 and for rounding x1)
		test(fabs(fabs(x1) - 1.13) < 0.001);
	if (a == 4 && h == 2 && k == 3)					// Incorrect value of x2 (check expressions for calculating x2 and for rounding x2) 
		test(fabs(fabs(x2) - 2.87) < 0.001);

    return 0 ;								//  Successful completion
}









