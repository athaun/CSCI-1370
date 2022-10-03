/////////////////////////////////////////////////////////////////////
//
// Name: Asher Haun
// Date: 9.9.22
// Class: CSCI 1370-03
// Semester: Fall 2022
// CSCI 1370 Instructor: Gustavo Dietrich
//
// Program Name: Magic Number
// Program Description: Calculate a person's magic number based on
//      their birthday.
//
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <typeinfo>   // operator typeid

// Ignore this; it's a little function used for making tests
inline void _test(const char* expression, const char* file, int line) {
	std::cerr << "test(" << expression << ") failed in file " << file;
	std::cerr << ", line " << line << ".\n\n";
	//abort();
}
// This goes along with the above function...don't worry about it
#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))


int main() {
	// Declare variables called day, month, year, and magicNum that hold whole numbers. Initialize them with data 
	// corresponding to January 31, 1970. Do not initialize magicNum
	int day = 31, month = 1, year = 1970;
	int magicNumber;

	// Using the provided equation , calculate the magic number for the given birthday and store the result in  magicNum
	magicNumber = (month * year) % day;

	test(magicNumber == 17); // Do NOT remove or modify this statement

	// Using the variables, print out the given initial birthday and its corresponding magic number.
	std::cout << "Birthday 1: " << month << "/" << day << "/" << year << "\n";
	std::cout << "Birthday 1's magic number is: " << magicNumber << "\n";

	// Prompt the user to enter her/his birthdate as 3 whole numbers
	// Get the values from the keyboard and store them in the corresponding variables
	std::cout << "\nInput your birthday\nMonth: ";
	std::cin >> month;

	std::cout << "Day: ";
	std::cin >> day;

	std::cout << "Year: ";
	std::cin >> year;

	// Using the provided equation , calculate the magic number for the entered birthdate and store the result in  magicNum
	magicNumber = (month * year) % day;

	// Using the variables, print out the entered birthdate and its corresponding magic number.
	std::cout << "\nBirthday input: " << month << "/" << day << "/" << year << "\n";
	std::cout << "User's Birthday magic number is: " << magicNumber << "\n";


	// Do NOT remove or modify the following statements
	std::cout << "\nTesting your solution\n\n";
	test(typeid(day) == typeid(int));		// Incorrect data type used for day
	test(typeid(month) == typeid(int));		// Incorrect data type used for month
	test(typeid(year) == typeid(int));		// Incorrect data type used for year
	test(typeid(magicNumber) == typeid(int));	// Incorrect data type used for magicNum

	return 0;
}