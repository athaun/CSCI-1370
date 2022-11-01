#include <iomanip>
#include <iostream>
using namespace std;

// Enter here the prototypes
int randNumGen(int upper, int lower);
void flag_controlled_loop();
void counterNflag_controlled_loop();

int main() {
  // Call the flag controlled loop
  flag_controlled_loop();
  // Pause the execution of the program
  cout << "Press Enter to continue ...";
  cin.sync();
  cin.ignore();
  cin.get();
  // Clear the screen
  system("clear");
  // Call the counter controlled controlled loop
  counterNflag_controlled_loop();
  // Pause the execution of the program
  cout << "Press Enter to continue ...";
  cin.sync();
  cin.ignore();
  cin.get();
  // Clear the screen
  system("clear");
  // Call the sentinel controlled controlled loop

  // Pause the execution of the program
  cout << "Press Enter to continue ...";
  cin.sync();
  cin.ignore();
  cin.get();

  return 0;
}

// This function uses a couple of flag-controlled loop to ensure the answer to a
// question is entered correctly. It keeps asking the question as long as the
// answer is not correct. Next, it uses another flag-controlled loop to ensure a
// number is entered at the keyboard. It keeps asking for a number as long as
// the value entered is invalid (not a number).

void flag_controlled_loop() {
  // Declare variable ans (single character) to hold the user's answer to the
  // question
  char ans;
  // Declare variable age (whole number) to hold the user's age
  int age;
  // Declare variable correct (boolean value) to implement the flag
  bool correct;

  // Note: Use a FLAG-CONTROLLED LOOP to ensure the response to the question
  // below is either 'y' or 'n'
  //  Set correct to false so the loop is entered at least once.
  correct = false;
  // While answer is not correct
  while (!correct) {
    // Ask the user "Do you like ice cream [y/n]?:
    cout << "Do you like ice cream [y/n]?: " << endl;
    // Get the answer and save it in the corresponding variable
    cin >> ans;
    // If the answer is not right
    if (!(ans == 'y' || ans == 'n'))
      // Display the message "Incorrect answer"
      cout << "Incorrect answer" << endl;
    // Otherwise
    else {
      // Set correct to true
      correct = true;
      // Display "Thanks!"
      cout << "Thanks!" << endl;
    }
  } // End of the while loop for getting the correct answer

  // Note: Use a FLAG-CONTROLLED LOOP to ensure the user enters a correct value
  // when prompted to enter the age Set correct to false so the loop is entered
  // at least once.
  correct = false;
  // While value is not correct
  while (!correct) {
    // Ask the user to "Enter your age as a number: "
    cout << "Enter your age as a number: ";
    // Get the value and save it in the corresponding variable
    cin >> age;
    // If cin is in the fail state (It will be in the fail state if the user
    // entered anything other than a number)
    if (!cin) {
      //  Display the message "You must enter an number"
      cout << "You must enter a number";
      // Reset the input stream.
      cin.clear();
      // Ignore the next 1000 characters, or until end of line is reached, in
      // case the user has entered more than 1 but less than 1000 incorrect
      // characters
      cin.ignore(1000, '\n');
    }
    // Otherwise
    else {
      // Set correct to true
      correct = true;
      //  Display "Got it!"
      cout << "Got it!";
    }

  } // end of the loop for getting a correct number

  cout << endl;
}

// This function uses a mix of counter-controlled and flag-controlled loops to
// implement a guessing game. It generates a random number (1..100) and gives
// the user five chances to guess it. The user receives feedback from the
// program regarding whether the guessed number is too high or too low, if it is
// incorrect. If the guess is correct, they get a message indicating they win.
// The loop is exited when the user guesses correctly or when they have gone
// over the five attempts.

void counterNflag_controlled_loop() {
  // Declare variable number to hold a random (whole) number
  int number;
  // Declare variable guess to hold the (whole) number guessed by the user
  int guess;
  // Declare variable correct that holds boolean values and initialize it to
  // false
  bool correct = false;
  // Declare variable numGuesses to hold the (whole) number used to keep track
  // of the number of guesses made by the user and initialize it to zero
  int numGuesses = 0;
  // Seed the random generator
  srand(static_cast<int>(time(NULL)));
  // Call function randNumGen() to generate a random number between 1 and 100
  // and assign the value returned to number
  number = randNumGen(100, 1);
  cout << "Random num: " << number << endl;
  // Note: Implement a WHILE-LOOP that gives the user five chances to guess the
  // number generated above. While the guess is not correct and the user has not
  // used her/his five chances
  while (!guess && numGuesses < 5) {
    // Prompt the user to "guess the number the computer randomly picked between
    // 1 - 100: "
    cout << "guess the number the computer randomly picked between 1 - 100: ";
    // Get the number from the user and save it in the corresponding variable
    cin >> number;
    // Update quantity of guesses
    ++numGuesses;
    // If the guess is smaller than the number
    if (guess < number)
      // Display "sorry, your guess is too low"
      cout << "sorry, your guess is too low";
    // Otherwise, if the guess is bigger than the number
    else if (guess > number)
      // Display "sorry, your guess is too high"
      cout << "sorry, your guess is too high";
    // Otherwise
    else
      // Display "you guessed right, you win!"
      cout << "you guessed right, you win!";
    // set correct to true (to stop the loop)
    correct = true;

  } // End of the loop for the guessing game

  // If the guess is not correct
  if (!guess)

    // Display "Sorry, you lost. The number is: ", number
    cout << "Sorry, you lost. The number is: " << number;
}

// This function generates a random number within a specified range.
// It receives two whole numbers : the first one is the upper boundary and
// the second one is the lower boundary used to generate the random number.
// Returns the random number generated using the expression:
//             rand() % (upper - lower + 1)) + lower

int randNumGen(int upper, int lower) // function heading
{                                    // function body
  return (rand() % (upper - lower + 1)) + lower;
}

// This function uses a sentinel-controlled loop to get whole numbers greater
// than or equal to zero in order to calculate their average. It keeps asking
// for a grade until the user enters a negative value Then, it calculates and
// displays the average.

void sentinel_controlled_loop() {
  // Declare variable grade (whole number) to hold the grade entered by the user
  int grade;
  // Declare and initialize variable sum (whole number) to accumulate the grades
  // entered by the user
  int sum = 0;
  // Declare and initialize variable count (whole number) to count the grades
  // entered by the user
  int count = 0;
  // Declare variable avg (real number) to hold the calculated average

  double avg;
  // Note: Loop until the user enters a negative value. Each time through the
  // loop, accumulate the number
  //  input by the user in sum. Make sure to NOT include the sentinel value in
  //  the sum or count!

  // Prompt the user to "Enter a grade, or a negative number to stop: " to get
  // the first value
  cout << "Enter a grade, or a negative number to stop: ";
  // Get the value and save it in the corresponding variable
  cin >> grade;
  // While the grade is zero or positive

  {
    // Accumulate the grade

    // Update the counter

    //
    // Prompt the user to "Enter a grade, or a negative number to stop: " to get
    // the next value
    cout << "Enter a grade, or a negative number to stop: ";
    // Get the value and save it in the corresponding variable
    cin >> grade;
  } // end of while loop

  // Note: Avoid division by zero when determining the average.
  // If the count is zero
  if (count == 0)
    // Set the average to zero
    avg = 0;
  // Otherwise
  else
    // calculate the average of the grades as a double precision real number

    // Format the output to print the result in fixed format with 1 decimal
    // digit

    // Display "The average is: ", avg
    cout << "The average is: " << avg;
}