/////////////////////////////////////////////////////////////////////
//
// Name: Asher Haun
// Date: 9.16.2022
// Class: CSCI 1370-03
// Semester: Fall 2022
// CSCI 1370 Instructor: Gustavo Dietrich
//
// Program Description: 
// Given an input of price and tax as a percentage, the total price
// is calulated.
//
/////////////////////////////////////////////////////////////////////

#include <iostream>				// to be able to use cin  and cout
#include <typeinfo>				// to be able to use operator typeid
#include <cmath>				// to be able to use predefined functions
#include <iomanip> 				// output stream maniuplators


inline void _test(const char* expression, const char* file, int line) {
	std::cerr << "test(" << expression << ") failed in file " << file;
	std::cerr << ", line " << line << "." << std::endl << std::endl;
}
#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))

int main() {
	
	// Declare variables named price, tax, and total that hold single precision real numbers.
	float price, tax, total;

	// Prompt the user to "Enter the price and tax (%) please: ".
	// Read the values from the keyboard and store them in price and tax respectively.
	std::cout << "Enter the price and tax (as a %) please:\nPrice: ";
	std::cin >> price;

	std::cout << "tax (%): ";
	std::cin >> tax;

	// Calculate the total cost using the expression Price * (1 + Taxes/100) and assign the resulting value to total.
	total = price * (1 + tax / 100.0f);

	// Round the value of total to ONE decimal digit and reassign the rounded value to total 
	total = round(total * 10.0f) / 10.0f;

	// Format the output to display the values in fixed format with two decimal digits.
	std::cout << std::fixed << std::setprecision(2); 

	// Print a message like the one below:
	//
	//		�For a price $�, P, �and �, X �% tax, the total cost of the product is $�, T
	//
	// where P, X, and T are the values corresponding to variables price, tax, and total respectively.
	std::cout << "\nFor a price $" << price << ", and " << tax << "% tax, the total cost of the product is $" << total << "\n";

	// Do NOT remove or modify the following statements
	std::cout << "\nTesting your solution\n";
	test(typeid(price) == typeid(float));		// Incorrect data type used for price
	test(typeid(tax) == typeid(float));			// Incorrect data type used for tax
	test(typeid(total) == typeid(float));		// Incorrect data type used for total
	if (price == 100.0 && tax == 8.25)			// Incorrect rounding of total
		test(fabs(total - 108.30) < 0.001);

	return 0;
}
