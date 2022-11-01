/////////////////////////////////////////////////////////////////////
//
// Name: <Put your name here>
// Due date:
// Class: <Your class number and section number, like: CSCI 1370.02>
// Semester: <This semester, like: Spring 2012>
// CSCI 1370 Instructor: <Your lecture instructor's name>
//
// Using your own words describe below what the program does 
// Program Description: 
//
/////////////////////////////////////////////////////////////////////

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

	// Declare variable age (whole number) to hold the user's age

	// Declare variable correct (boolean value) to implement the flag


	// Note: Use a FLAG-CONTROLLED LOOP to ensure the response to the question below is either 'y' or 'n' 
	//  Set correct to false so the loop is entered at least once.

	// While answer is not correct

	{
		// Ask the user "Do you like ice cream [y/n]?: 

		// Get the answer and save it in the corresponding variable

		// If the answer is not right

			// Display the message "Incorrect answer"

		// Otherwise


		// Set correct to true

			// Display "Thanks!"


	} // End of the while loop for getting the correct answer

	// Note: Use a FLAG-CONTROLLED LOOP to ensure the user enters a correct value when prompted to enter the age
	// Set correct to false so the loop is entered at least once.

	// While value is not correct

	{
		// Ask the user to "Enter your age as a number: "

		// Get the value and save it in the corresponding variable

		// If cin is in the fail state (It will be in the fail state if the user entered anything other than a number)


			//  Display the message "You must enter an number"

			// Reset the input stream.

			// Ignore the next 1000 characters, or until end of line is reached, in case
			// the user has entered more than 1 but less than 1000 incorrect characters


		// Otherwise

			// Set correct to true

			//  Display "Got it!"


	} // end of the loop for getting a correct number

	std::cout << "\n";

}

// This function uses a mix of counter-controlled and flag-controlled loops to implement a guessing game.
// It generates a random number (1..100) and gives the user five chances to guess it. The user receives
// feedback from the program regarding whether the guessed number is too high or too low, if it is
// incorrect. If the guess is correct, they get a message indicating they win.
// The loop is exited when the user guesses correctly or when they have gone over the five attempts.
void counter_n_flag_controlled_loop () {
	// Declare variable number to hold a random (whole) number

	// Declare variable guess to hold the (whole) number guessed by the user

	// Declare variable correct that holds boolean values and initialize it to false

	// Declare variable numGuesses to hold the (whole) number used to keep track of the
	// number of guesses made by the user and initialize it to zero

	// Seed the random generator

	// Call function random() to generate a random number between 1 and 100 and
	// assign the value returned to number

	// Note: Implement a WHILE-LOOP that gives the user five chances to guess the number generated above.
	// While the guess is not correct and the user has not used her/his five chances

	{
		// Prompt the user to "guess the number the computer randomly picked between 1 - 100: "

		// Get the number from the user and save it in the corresponding variable

		// Update quantity of guesses

		// If the guess is smaller than the number

			// Display "sorry, your guess is too low"

		// Otherwise, if the guess is bigger than the number

			// Display "sorry, your guess is too high"

		// Otherwise

			// Display "you guessed right, you win!"

			// set correct to true (to stop the loop)


	}   // End of the loop for the guessing game

	// If the guess is not correct


		// Display "Sorry, you lost. The number is: ", number


}

// This function uses a sentinel-controlled loop to get whole numbers greater than or equal to zero in
// order to calculate their average. It keeps asking for a grade until the user enters a negative value
// Then, it calculates and displays the average.
void sentinel_controlled_loop () {
	// Declare variable grade (whole number) to hold the grade entered by the user 

	// Declare and initialize variable sum (whole number) to accumulate the grades entered by the user

	// Declare and initialize variable count (whole number) to count the grades entered by the user

	// Declare variable avg (real number) to hold the calculated average


	// Note: Loop until the user enters a negative value. Each time through the loop, accumulate the number
	//  input by the user in sum. Make sure to NOT include the sentinel value in the sum or count!

	// Prompt the user to "Enter a grade, or a negative number to stop: " to get the first value

	// Get the value and save it in the corresponding variable

	// While the grade is zero or positive

	{
		// Accumulate the grade

		// Update the counter

		// 
		// Prompt the user to "Enter a grade, or a negative number to stop: " to get the next value

		// Get the value and save it in the corresponding variable

	} // end of while loop

	// Note: Avoid division by zero when determining the average.
	// If the count is zero

		// Set the average to zero

	// Otherwise
	
		// calculate the average of the grades as a double precision real number

	// Format the output to print the result in fixed format with 1 decimal digit

	// Display "The average is: ", avg

}