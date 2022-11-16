//******************************************************************************
// Team:          CSCI 1370 Spring 2022 Homework # 3
// Asher Haun
// First and Last Name
// Using your own words, write here a description of what the program does.
//
//******************************************************************************

#include <cstdlib>
#include <iostream>	

#include "rationals.hpp"
#include "tests.hpp"

int main() {

	// Display the menu to the user and save their choice
	int choice = menu();

	// Numerators and denominators for the two rationals
	int num1, den1; // Input 1
	int num2, den2; // Input 2

	int num, den; // Result

	switch (choice) {
		case 'A':
			system("clear");
			std::cout << "Addition\n\n";

			get_rational(num1, den1);
			get_rational(num2, den2);

			add_rational(num, den, num1, den1, num2, den2);

			std::cout << "The result of " 
					  << print_rational(num1, den1)
					  << " + "
					  << print_rational(num2, den2)
					  << " is "
					  << print_rational(num, den)
					  << ".\n";			

			break;
		case 'S':
			// Subtract
			system("clear\"");
			std::cout << "Subtraction\n\n";

			get_rational(num1, den1);
			get_rational(num2, den2);

			sub_rational(num, den, num1, den1, num2, den2);


			std::cout << "The result of " 
					  << print_rational(num1, den1)
					  << " - "
					  << print_rational(num2, den2)
					  << " is "
					  << print_rational(num, den)
					  << ".\n";

			break;
		case 'Q':
			std::cout << "Goodbye.\n";
			return 0;
		default:
			std::cout << "Invalid choice given, exiting...\n";
			return 1;
	}

	run_tests();

	pause();
	std::cout << "\n";
	return 0;
}