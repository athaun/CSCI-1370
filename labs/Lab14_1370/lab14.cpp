/////////////////////////////////////////////////////////////////////
//
// Name: <Put your name here>
// Date: <Today's date>
// Class: <Your class number and section number, like: CSCI 1370.02>
// Semester: <This semester, like: Spring 2012>
// CSCI 1370 Instructor: <Your lecture instructor's name>
//
// Program Description: Enter here your description of what the program does
//
/////////////////////////////////////////////////////////////////////

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main()
{
	// Declare variable search_word to store the word to be searched for

	// Declare variable file_word to store the word read from the file

	// Declare variable counter to keep track of the file line being visited and initialize it to zero

	// Declare variable found to keep track of whether the word was found or not and initialize it to false

	// Declare input file variable inFile (represents the input stream)
	
	//open the dictionary file.

	// If the dictionary file was not found

		// Display "File not found!"

		// Exit main() indicating the program did not finish successfully


	//Prompt the user to "Enter a word to search in dictionary: "

	// Get it and save it in the corresponding variable


	//Note: Loop through the whole file, but if the word is found jump out of the loop
	// Get the first word from the file

	// While the input stream is in working conditions
	
	{
		// Update the counter

		// If the word from the file is the one we are searching for


			// Display "word ", search_word, " found in line ", counter

			// Set found to true (to indicate the word was found)

			// We don't need to keep searching, so jump out of the loop


		// Get the next word from the file
	}
	//if the word was not found
	
		// Display the message "word ", search_word, " is not in the dictionary"

    // Close the file

	// Exit main() indicating the program finished successfully
	return 0;
}