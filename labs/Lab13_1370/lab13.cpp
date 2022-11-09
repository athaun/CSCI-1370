/////////////////////////////////////////////////////////////////////
//
// Name: Asher Haun
// Due date: 11.2.22
// Class: CSCI 1370.03
// Semester: Fall 2022
// CSCI 1370 Instructor: Gustavo Dietrich
//
// Using your own words describe below what the program does 
// Program Description: Uses a number of various control systems for while loops to ask for inputs, make a number guessing game and calculate the average of a number of inputs.
//
/////////////////////////////////////////////////////////////////////

#include <cstdlib>
#include <iostream>
#include <iomanip>

// Enter here the prototypes
void next (bool clear);
int random (int min, int max);
void flag_controlled_loop ();
void counter_n_flag_controlled_loop ();
void sentinel_controlled_loop ();

int main () {
    // Call the flag controlled loop
	flag_controlled_loop();
    next(true);

    // Call the counter controlled controlled loop
	counter_n_flag_controlled_loop();
    next(true);

    // Call the sentinel controlled controlled loop
	sentinel_controlled_loop();
    next(false);

    return 0;
}

// This function generates a random number within a specified range.
// It receives two whole numbers : the minumum and maximum bounds of the randomly generated number
int random (int min, int max) {
	return (rand() % (max - min + 1)) + min;
}

// Move the repetitive cleanup code into a single function to avoid repitition and improve readability.
void next (bool clear) {
	// Pause the execution of the program
    std::cout << "Press Enter to continue ...";
    std::cin.sync();
    std::cin.ignore();
    std::cin.get();
    // Clear the screen
    if (clear) system("clear");
}

// This function uses a couple of flag-controlled loop to ensure the answer to a question is
// entered correctly. It keeps asking the question as long as the answer is not correct.
// Next, it uses another flag-controlled loop to ensure a number is entered at the keyboard.
// It keeps asking for a number as long as the value entered is invalid (not a number).
void flag_controlled_loop () {
	// Declare variable ans (single character) to hold the user's answer to the question
	char answer;

	// Declare variable age (whole number) to hold the user's age
	int age;

	// Declare variable correct (boolean value) to implement the flag
	bool correct_input = false;

	// While answer is not correct
	while (!correct_input) {
		// Ask the user "Do you like ice cream [y/n]?: 
		// Get the answer and save it in the corresponding variable
		std::cout << "Do you like ice cream [y/n]?: ";
		std::cin >> answer;

		// If the answer is not right
		if (answer != 'y' && answer != 'n') {
			std::cout << "Incorrect answer\n";
		} else {
			correct_input = true;
			std::cout << "Thanks!\n";
		}
	}

	// Note: Use a FLAG-CONTROLLED LOOP to ensure the user enters a correct value when prompted to enter the age
	correct_input = false;

	// While value is not correct
	while (!correct_input) {
		// Ask the user to "Enter your age as a number: "
		// Get the value and save it in the corresponding variable
		std::cout << "Enter your age as a number: ";
		std::cin >> age;

		// If cin is in the fail state (It will be in the fail state if the user entered anything other than a number)
		if (!std::cin){
			std::cout << "You must enter an number\n";
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		} else {
			correct_input = true;
			std::cout << "Got it!\n";
		}
	}

	std::cout << "\n";

}

// This function uses a mix of counter-controlled and flag-controlled loops to implement a guessing game.
// It generates a random number (1..100) and gives the user five chances to guess it. The user receives
// feedback from the program regarding whether the guessed number is too high or too low, if it is
// incorrect. If the guess is correct, they get a message indicating they win.
// The loop is exited when the user guesses correctly or when they have gone over the five attempts.
void counter_n_flag_controlled_loop () {

	// Declare variable guess to hold the (whole) number guessed by the user
	int guess;

	// Declare variable correct that holds boolean values and initialize it to false
	bool correct = false;

	// Declare variable numGuesses to hold the (whole) number used to keep track of the
	// number of guesses made by the user and initialize it to zero
	int guess_count = 0;

	// Seed the random generator
	srand(time(NULL));

	// Declare variable number to hold a random (whole) number
	// Call function random() to generate a random number between 1 and 100 and
	// assign the value returned to number
	int rand_num = random(1, 100);

	// Note: Implement a WHILE-LOOP that gives the user five chances to guess the number generated above.
	// While the guess is not correct and the user has not used her/his five chances
	while (guess_count < 5 && !correct) {
		// Prompt the user to "guess the number the computer randomly picked between 1 - 100: "
		// Get the number from the user and save it in the corresponding variable
		std::cout << "guess the number the computer randomly picked between 1 - 100: ";
		std::cin >> guess;

		// Update quantity of guesses
		++guess_count;

		// If the guess is smaller than the number
		if (guess < rand_num) {
			std::cout << "sorry, your guess is too low\n";
		} else if (guess > rand_num) {
			std::cout << "sorry, your guess is too high\n";
		} else {
			std::cout << "you guessed right, you win!\n";
			correct = true;
		}
	}

	if (guess != rand_num) std::cout << "Sorry, you lost. The number is: " << rand_num << "\n";
}

// This function uses a sentinel-controlled loop to get whole numbers greater than or equal to zero in
// order to calculate their average. It keeps asking for a grade until the user enters a negative value
// Then, it calculates and displays the average.
void sentinel_controlled_loop () {
	// Declare variable grade (whole number) to hold the grade entered by the user 
	// Declare and initialize variable sum (whole number) to accumulate the grades entered by the user
	// Declare and initialize variable count (whole number) to count the grades entered by the user
	int grade;
	int sum = 0;
	int count = 0;

	// Declare variable avg (real number) to hold the calculated average
	double avg;

	// Note: Loop until the user enters a negative value. Each time through the loop, accumulate the number
	//  input by the user in sum. Make sure to NOT include the sentinel value in the sum or count!

	// Prompt the user to "Enter a grade, or a negative number to stop: " to get the first value
	// Get the value and save it in the corresponding variable
	std::cout << "Enter a grade, or a negative number to stop: ";
	std::cin >> grade;

	// While the grade is zero or positive
	while (grade >= 0) {
		// Accumulate the grade
		sum += grade;

		// Update the count
		++count;

		// Prompt the user to "Enter a grade, or a negative number to stop: " to get the next value
		// Get the value and save it in the corresponding variable
		std::cout << "Enter a grade, or a negative number to stop: ";
		std::cin >> grade;
	}

	// Note: Avoid division by zero when determining the average.
	// If the count is zero
	if (count == 0)
		avg = 0;
	else 
		avg = static_cast<double>(sum) / static_cast<double>(count);

	// Format the output to print the result in fixed format with 1 decimal digit
	std::cout << std::fixed << std::setprecision(1);

	std::cout << "The average is: " << avg << "\n";
}
