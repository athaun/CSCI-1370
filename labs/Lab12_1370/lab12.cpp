/////////////////////////////////////////////////////////////////////
//
// Name: Asher Haun
// Due date: 10.27.22
// Class: CSCI 1370-03
// Semester: Fall 2022
// CSCI 1370 Instructor: Gustavo Dietrich
//
// Using your own words describe below what the program does 
// Magic eight ball using random numbers.
//
/////////////////////////////////////////////////////////////////////

#include <iostream>				// to use cin and cout
#include <typeinfo>				// to be able to use operator typeid
#include <cstdio>
#include <time.h>

inline auto _test(const char* expression, const char* file, int line) -> void{
	std::cerr << "test(" << expression << ") failed in file " << file;
	std::cerr << ", line " << line << "." << std::endl << std::endl;
}
#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))

int random (int min, int max);
std::string fortune_teller_a (int rn);
std::string fortune_teller_b (int rn);

int main() {
	// Declare a variable named randomNumber that holds whole numbers
	// Declare a variable named lowRange that holds whole numbers and initializes it to 0
	// Declare a variable named highRange that holds whole numbers and initializes it to 4
	int random_number;
	int low_range = 0, high_range = 4;
	
	// Seed the random number generator using expression 1) on my handout
	srand(static_cast<int>(time(NULL)));

	// Prompt the user to enter a question
	std::cout << "Enter a question: ";

	// Ignore the user input
	std::cin.ignore(256, '\n');

	// Call function randNumGen() to generate a random number and assign it to randomNumber
	random_number = random(low_range, high_range);

	// Display title "Part A solution"
	std::cout << "\nPart A solution\n";

	// Display the message shown below
	//	"Answer: �, call function fortune_teller_a() to get the answer
	std::cout << "Answer: " << fortune_teller_a(random_number);

	// Display title "Part B solution"
	std::cout << "\n\nPart B solution\n";

	//Displays the message shown below
	//	"Answer: �, call function fortune_teller_b() to get the answer
	std::cout << "Answer: " << fortune_teller_b(random_number);

	// Do NOT remove or modify the following statements
	std::cout << std::endl << std::endl << "Testing your solution" << std::endl << std::endl;

	test(random_number >= 0 && random_number <= 4);			// Incorrect random number (out of range)

	test(fortune_teller_a(0) == "Yes");						// Incorrect answer
	test(fortune_teller_a(1) == "Maybe");						// Incorrect answer
	test(fortune_teller_a(2) == "No");						// Incorrect answer
	test(fortune_teller_a(3) == "Ask again later");			// Incorrect answer
	test(fortune_teller_a(4) == "I don't know");				// Incorrect answer
	test(fortune_teller_a(14) == "I don't know");				// Incorrect answer

	test(fortune_teller_b(0) == "Yes");						// Incorrect answer
	test(fortune_teller_b(1) == "Maybe");						// Incorrect answer
	test(fortune_teller_b(2) == "No");						// Incorrect answer
	test(fortune_teller_b(3) == "Ask again later");			// Incorrect answer
	test(fortune_teller_b(4) == "I don't know");				// Incorrect answer
	test(fortune_teller_b(14) == "I don't know");				// Incorrect answer

	return 0;
}

//************************  Function definitions  *************************
// Read the handout carefully for detailed description of the functions that you have to implement

// This function generates a random number within a specified range.
// It receives two whole numbers : the first one is the upper boundary and
// the second one is the lower boundary used to generate the random number.
// Returns the random number generated using expression 2) on my handout
int random (int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Thisfunction uses multi - branch if - else statements to determine the answer to be 
// returned based on the number received.
// It receives the random number(whole number) and returns the corresponding answer
// based on the table shown on my handout
//
// Important: in this solution make your function directly return the answer in each
// branch of the multi - branch if - else statements.
std::string fortune_teller_a (int rn) {
	if (rn == 0) return "Yes";
	else if (rn == 1) return "Maybe";
	else if (rn == 2) return "No";
	else if (rn == 3) return "Ask again later";
	else return "I don't know"; 
}

// Thisfunction uses switch statements to determine the answer to be 
// returned based on the number received.
// It receives the random number(whole number) and returns the corresponding answer
// based on the table shown on my handout
//
// Important: in this solution declare a local variable that holds text and assign
// the corresponding answer in each case of the switch statement. Upon exiting the
// switch return the value in the local variable.
std::string fortune_teller_b (int rn) {
	switch (rn) {
		case 0:
			return "Yes";
		case 1:
			return "Maybe";
		case 2:
			return "No";
		case 3:
			return "Ask again later";
		default:
			return "I don't know";
	}
}