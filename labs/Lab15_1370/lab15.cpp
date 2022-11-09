/////////////////////////////////////////////////////////////////////
//
// Name: Asher Haun
// Date: 11.9.22
// Class: CSCI 1170.03
// Semester: Fall 2022
// CSCI/CMPE 1370 Instructor: Gustavo Dietrich
//
// Play a number guessing game that allows the user to guess a number between 1 and 100.
// Then watch the computer play pig. 
//
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

int random (int upper, int lower);
int get_seed ();
void guess_number ();
void pig_roll ();

int main () {
	// guess_number();

	// Pause the execution of the program
	std::cout << "Press Enter to continue ...";
	std::cin.sync();
	std::cin.ignore();
	std::cin.get();
	
	// Clear the screen
	system("clear");

	pig_roll();
	return 0;
}

// This function generates a random number within a specified range.
// It receives two whole numbers : the minumum and maximum bounds of the randomly generated number
int random (int min, int max) {
	return (rand() % (max - min + 1)) + min;
}

// This function prompts the user to enter a seed (a whole number) equal to zero (0) or 
// within the range 1000..4000. If the user enters a valid value the function returns 
// the value. Otherwise it keeps asking for the seed.
// Use a DO-WHILE-LOOP to implement this function
int get_seed () {
	int seed;

	// Use a Do-While-Loop to ensure the user enters a valid seed
	// Prompt the user for a int until they input one
	do {
		std::cout << "Enter a seed (0 or 1000..4000): ";
		std::cin >> seed;
		// print seed
		std::cout << "Seed: " << seed << std::endl;
	} while ((seed < 1000 || seed > 4000) && seed != 0);

	// Return the seed
	return seed;
}

// This function generates a number and gives the user five chances to guess it.
// As the user provides a guess the program indicates whether the guess was correct
// or if it was too low or too high to help her/him.
// If the user runs out of guesses it shows her/him the number
// MUST use a FOR-LOOP to implement this function
void guess_number () {

	// Display the title with the instructions for the guessing game
	std::cout << "Thank you for participating in the Guessing Game\n\n";
	std::cout << "If you want me to create a real random number enter 0 when prompted for the seed please.\n";
	std::cout << "Otherwise enter a number within the specified range please.\n\n";

	// Declare variable seed to get the seed specified by the user
	// Call function get_seed() to get the seed from the user and assign it to the corresponding variable
	int seed = get_seed();

	// If the user entered a zero (0) use srand(static_cast<int> (time(NULL))) to seed the random number generator. 
	// Otherwise use srand(seed) where seed represents the value entered by the user
	if (seed == 0)
		srand(static_cast<int>(time(NULL)));
	else
		srand(seed);
	
	// Declare variable num to hold the random number generated by the program
	// Call function randNumGen() to generate a random number within the range 1..100
	int rand_num = random(0, 100);

	// Declare variable guess to hold the user's guess
	int guess;

	// Use a For-Loop to give the user five (5) chances to guess the number
	for (int i = 0; i < 5; ++i) {

		// Prompt the user for a guess
		std::cout << "Enter your guess: ";
		std::cin >> guess;

		// If the guess is smaller than the number
		if (guess < rand_num) {
			std::cout << "Sorry, your guess is too low\n";
		} else if (guess > rand_num) {
			// Otherwise, if the guess is bigger than the number
			std::cout << "Sorry, your guess is too high\n";
		} else {
			// Otherwise, if the guess is equal to the number
			std::cout << "Congratulations, you guessed the number\n";
			break;
		}
		
	}

	// If the user lost
	if (guess != rand_num) std::cout << "Sorry, you lost. The number is: " << rand_num << "\n";
}

// This function simulates the pig dice game. Version 1.2
// It simulates a computer controlled player by rolling a die
// numbered 1 through 6 until the total_turn number is greater
// than 20 or until it rolls a 1. Once the computer finishes its
// turn, the function terminates.
void pig_roll () {
	// Declare variable roll to hold the die roll
	int roll;

	// Declare variable total_turn to hold the player's score for this turn and initialize it to zero
	int total_turn = 0;

	// Declare variable lowRange to hold the lower boundary of the range for the die roll and initialize it to 1
	int low_range = 1;

	// Declare variable highRange to hold the upper boundary of the range for the die roll and initialize it to 6
	int high_range = 6;

	// Seed the random number generator
	srand(static_cast<int>(time(NULL)));

	// Display title "Welcome to the Pig Roll game"
	std::cout << "Welcome to the Pig Roll game\n\n";

	/*
	the computer rolls the dice until the total turn number is
	20 or greater than 20 or it rolls a 1. if a 1 is rolled the
	computer gets a 0 for the turn.
	*/
	//While the player's score for this turn is below 20
	while (total_turn < 20) {
		std::cout << "it's the computer's turn to roll . . . \n";

		//Simulate the single die roll between 1 and 6:
		// Generate a random number between 1 and 6 and assign it to roll
		roll = random(low_range, high_range);

		//If roll is a 1
		if (roll == 1) {
			std::cout << "computer rolled a 1, it's turn is over.\n\n";
			total_turn = 0;
			break;
		} else {
			std::cout << "computer rolled a " << roll << "\n";

			total_turn += roll;

			std::cout << "Current total for the turn = " << total_turn << "\n\n";
		}

	}
	std::cout << "\ncomputer has completed its turn.\n";
	std::cout << "computer got " << total_turn << " points for the turn.\n\n\n";

}