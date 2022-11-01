/////////////////////////////////////////////////////////////////////
//
// Name: Asher Haun
// Due date: 10.27.22
// Class: CSCI 1370-03
// Semester: Fall 2022
// CSCI 1370 Instructor: Gustavo Dietrich
//
// Using your own words describe below what the program does 
// Given an input char (A-Z), returns which phone digit it falls under.
// 2 = ABC 4 = GHI 6 = MNO 8 = TUV
// 3 = DEF 5 = JKL 7 = PQRS 9 = WXYZ
//
/////////////////////////////////////////////////////////////////////

#include <iostream>				// to use cin and cout
#include <typeinfo>				// to be able to use operator typeid

inline auto _test(const char* expression, const char* file, int line) -> void{
	std::cerr << "test(" << expression << ") failed in file " << file;
	std::cerr << ", line " << line << "." << std::endl << std::endl;
}
#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))

// Insert here the prototypes of the functions
char letter_to_digit_a (char l);
char letter_to_digit_b (char l);

int main() {
	// declare a variable named letter to hold the letter entered by the user
	char letter;

	// declare a variable named digit to hold the digit returned by the functions
	char digit;

	std::cout << "Converts a capital letter to a digit on the telephone\n";

	// prompt the user to enter a single capital letter
	// get the value from the keyboard and store it in the corresponding variable
	std::cout << "Input a capital Letter (A-Z): ";
	std::cin >> letter;

	std::cout << "Solution A\n";

	// Get the corresponding digit for the given letter and assign it digit
	digit = letter_to_digit_a(letter);

	// if there is a matching digit for the letter entered
	if (digit >= '2' && digit <= '9') {
		std::cout << "Letter " << letter << " corresponds to digit " << digit << " on the telephone\n";
	} else {
		std::cout << "There is no matching digit for the letter " << letter << " entered\n";
	}

	std::cout << "Solution B\n";

	// Get the corresponding digit for the given letter and assign it digit
	digit = letter_to_digit_b(letter);

	// if there is a matching digit for the letter entered
	if (digit >= '2' && digit <= '9') {
		std::cout << "Letter " << letter << " corresponds to digit " << digit << " on the telephone\n";
	} else {
		std::cout << "There is no matching digit for the letter " << letter << " entered\n";
	}

	// Do NOT remove or modify the following statements
	std::cout << std::endl << "Testing your solution" << std::endl << std::endl;

	test(letter_to_digit_a('A') == '2');				// Incorrect letter to digit correlation
	test(letter_to_digit_a('B') == '2');				// Incorrect letter to digit correlation
	test(letter_to_digit_a('C') == '2');				// Incorrect letter to digit correlation
	test(letter_to_digit_a('D') == '3');				// Incorrect letter to digit correlation
	test(letter_to_digit_a('E') == '3');				// Incorrect letter to digit correlation
	test(letter_to_digit_a('F') == '3');				// Incorrect letter to digit correlation
	test(letter_to_digit_a('G') == '4');				// Incorrect letter to digit correlation
	test(letter_to_digit_a('H') == '4');				// Incorrect letter to digit correlation
	test(letter_to_digit_a('I') == '4');				// Incorrect letter to digit correlation
	test(letter_to_digit_a('J') == '5');				// Incorrect letter to digit correlation
	test(letter_to_digit_a('K') == '5');				// Incorrect letter to digit correlation
	test(letter_to_digit_a('L') == '5');				// Incorrect letter to digit correlation
	test(letter_to_digit_a('M') == '6');				// Incorrect letter to digit correlation
	test(letter_to_digit_a('N') == '6');				// Incorrect letter to digit correlation
	test(letter_to_digit_a('O') == '6');				// Incorrect letter to digit correlation
	test(letter_to_digit_a('P') == '7');				// Incorrect letter to digit correlation
	test(letter_to_digit_a('Q') == '7');				// Incorrect letter to digit correlation
	test(letter_to_digit_a('R') == '7');				// Incorrect letter to digit correlation
	test(letter_to_digit_a('S') == '7');				// Incorrect letter to digit correlation
	test(letter_to_digit_a('T') == '8');				// Incorrect letter to digit correlation
	test(letter_to_digit_a('U') == '8');				// Incorrect letter to digit correlation
	test(letter_to_digit_a('V') == '8');				// Incorrect letter to digit correlation
	test(letter_to_digit_a('W') == '9');				// Incorrect letter to digit correlation
	test(letter_to_digit_a('X') == '9');				// Incorrect letter to digit correlation
	test(letter_to_digit_a('Y') == '9');				// Incorrect letter to digit correlation
	test(letter_to_digit_a('Z') == '9');				// Incorrect letter to digit correlation
	test(letter_to_digit_a('a') == '?');				// Incorrect letter to digit correlation
	test(letter_to_digit_a('#') == '?');				// Incorrect letter to digit correlation
	test(letter_to_digit_a('1') == '?');				// Incorrect letter to digit correlation

	test(letter_to_digit_b('A') == '2');				// Incorrect letter to digit correlation
	test(letter_to_digit_b('B') == '2');				// Incorrect letter to digit correlation
	test(letter_to_digit_b('C') == '2');				// Incorrect letter to digit correlation
	test(letter_to_digit_b('D') == '3');				// Incorrect letter to digit correlation
	test(letter_to_digit_b('E') == '3');				// Incorrect letter to digit correlation
	test(letter_to_digit_b('F') == '3');				// Incorrect letter to digit correlation
	test(letter_to_digit_b('G') == '4');				// Incorrect letter to digit correlation
	test(letter_to_digit_b('H') == '4');				// Incorrect letter to digit correlation
	test(letter_to_digit_b('I') == '4');				// Incorrect letter to digit correlation
	test(letter_to_digit_b('J') == '5');				// Incorrect letter to digit correlation
	test(letter_to_digit_b('K') == '5');				// Incorrect letter to digit correlation
	test(letter_to_digit_b('L') == '5');				// Incorrect letter to digit correlation
	test(letter_to_digit_b('M') == '6');				// Incorrect letter to digit correlation
	test(letter_to_digit_b('N') == '6');				// Incorrect letter to digit correlation
	test(letter_to_digit_b('O') == '6');				// Incorrect letter to digit correlation
	test(letter_to_digit_b('P') == '7');				// Incorrect letter to digit correlation
	test(letter_to_digit_b('Q') == '7');				// Incorrect letter to digit correlation
	test(letter_to_digit_b('R') == '7');				// Incorrect letter to digit correlation
	test(letter_to_digit_b('S') == '7');				// Incorrect letter to digit correlation
	test(letter_to_digit_b('T') == '8');				// Incorrect letter to digit correlation
	test(letter_to_digit_b('U') == '8');				// Incorrect letter to digit correlation
	test(letter_to_digit_b('V') == '8');				// Incorrect letter to digit correlation
	test(letter_to_digit_b('W') == '9');				// Incorrect letter to digit correlation
	test(letter_to_digit_b('X') == '9');				// Incorrect letter to digit correlation
	test(letter_to_digit_b('Y') == '9');				// Incorrect letter to digit correlation
	test(letter_to_digit_b('Z') == '9');				// Incorrect letter to digit correlation
	test(letter_to_digit_b('a') == '?');				// Incorrect letter to digit correlation
	test(letter_to_digit_b('#') == '?');				// Incorrect letter to digit correlation
	test(letter_to_digit_b('1') == '?');				// Incorrect letter to digit correlation

	return 0;
}                                           


//************************  Function definition  *************************
// Read the handout carefully for detailed description of the functions that you have to implement

// This function receives a character. If the character corresponds to any capital letter of the English
// alphabet it returns the corresponding telephone digit as a character; otherwise, it returns character
// '?' to indicate that an invalid character has been entered.
// Works with range of letters to determine the digit
// This function uses COMPLEX CONDITIONAL EXPRESSIONS to determine the matching digit for the letter entered
char letter_to_digit_a (char l) {
	char ret = '?';
	if (l >= 65 && l <= 67) ret = '2'; 	 	// ABC 
	else if (l >= 68 && l <= 70) ret = '3'; // DEF 
	else if (l >= 71 && l <= 73) ret = '4'; // GHI 
	else if (l >= 74 && l <= 76) ret = '5'; // JKL 
	else if (l >= 77 && l <= 79) ret = '6'; // MNO 
	else if (l >= 80 && l <= 83) ret = '7'; // PQRoftS 
	else if (l >= 84 && l <= 86) ret = '8'; // TUV 
	else if (l >= 87 && l <= 90) ret = '9'; // WXYZ 
	return ret;
}


// This function receives a character. If the character corresponds to any capital letter of the English
// alphabet it returns the corresponding telephone digit as a character; otherwise, it returns character
// '?' to indicate that an invalid character has been entered.
// This function uses MULTI-BRANCH IF-ELSE STATEMENTS to determine the matching digit for the letter entered
// Works with range of letters to determine the digit
char letter_to_digit_b (char l) {
	char ret = '?';
	if (l >= 65) { // >= A
		if (l <= 90) { // <= Z
			if (l <= 67) ret = '2'; 	 // ABC 
			else if (l <= 70) ret = '3'; // DEF 
			else if (l <= 73) ret = '4'; // GHI 
			else if (l <= 76) ret = '5'; // JKL 
			else if (l <= 79) ret = '6'; // MNO 
			else if (l <= 83) ret = '7'; // PQRS 
			else if (l <= 86) ret = '8'; // TUV 
			else if (l <= 90) ret = '9'; // WXYZ 
		}
	}
	return ret;
}