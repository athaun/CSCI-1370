#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>

#include "rationals.hpp"

/*
The menu options must be displayed by a void function named showMenu().
This function justshows the titleand the options, the decision whether to call add(), subtract(), 
or quit must be donein main().
The  Addition  and  Subtraction optionsmust  be implemented by  a  
couple  ofvoid functionsnamedadd()and subtract()respectively.Thesefunctions must clear the screen 
and show a title specifying the operation to be performed.
 Next, they have to showa couple of input 
prompts asking for the rational numbers and, after gettingand processing them, they have to display 
theresult.After  performing their  correspondingoperations,  the  functionsmust  ask  the  user whether  
he/she  would  like  to  do  more  operations.  If  the  user  chooses  to  do  more operations, the 
functionsrepeat the stepsdescribed in the previous paragraph (that is,  they clear  the screen,ask for
both  numbers,  and  so  forth).  This  process  is repeatedforas long as the user chooses todo more 
operations. When the user is done with anoperation, the menu must be shown again.All the letters entered
by the user as an answer to a question posted by the program must be accepted in upper or lower case.
*/

// Displays a menu to prompt the user to choose an operation
char menu () {

	system("clear");

	char choice;
	// Prompt the user to choose an operation until they choose a valid option
	do {
		std::cout << "Rational numbers calculator\n\n"
				  << "(A)ddition\n"
				  << "(S)ubtraction\n"
				  << "(Q)uit\n\n"
				  << "Enter your option: ";

		std::cin >> choice;

		// Convert the option to uppercase so that the user can enter either upper or lowercase
		choice = std::toupper(choice);

		if (choice != 'A' && choice != 'S' && choice != 'Q') {
			system("clear");
			std::cout << "[!] Invalid option, please try again.\n\n";
		}

	} while (choice != 'A' && choice != 'S' && choice != 'Q');

	system("clear");

	return choice;
}

// This function receives two integers, num and den, and reduces them to their lowest terms
void reduce_rational (int & num, int & den) {
	int a = abs(num);
	int b = abs(den);

	int r = a % b; // remainder
	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}

	int gcf = b;
	
	num /= gcf;
	den /= gcf;
}

// This number prompts the user to input a fraction and returns them through the parameters
void get_rational (int & num, int & den) {
	std::cout << "Enter the rational number (x/y): ";
	std::cin >> num;
	std::cin.ignore(1, '/');
	std::cin >> den;

	if (den == 0) {
		std::cout << "[!] Invalid rational number (contains a division by 0), please input something else.\n\n";
		get_rational(num, den);
	}
}

// This function receives two fractions and adds them together, returning the result through the parameters
void add_rational (int & num, int & den, int num1, int den1, int num2, int den2) {
	num = (num1 * den2) + (num2 * den1);
	den = den1 * den2;
	reduce_rational(num, den);
}

// This function receives two fractions and subtracts them, returning the result through the parameters
void sub_rational (int & num, int & den, int num1, int den1, int num2, int den2) {
	num = (num1 * den2) - (num2 * den1);
	den = den1 * den2;
	reduce_rational(num, den);
}

std::string print_rational (int num, int den) {
	if (num == den || den == 1)
		return "1";
	else
		return std::to_string(num) + "/" + std::to_string(den);
}

// This function pauses the execution of the program
void pause () {
	std::cout << "Press Enter to continue ...";
	std::cin.sync();
	std::cin.ignore();
	std::cin.get();
}