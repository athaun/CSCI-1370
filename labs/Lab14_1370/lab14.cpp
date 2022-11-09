/////////////////////////////////////////////////////////////////////
//
// Name: Asher Haun
// Due date: 11.2.22
// Class: CSCI 1370.03
// Semester: Fall 2022
// CSCI 1370 Instructor: Gustavo Dietrich
//
// Using your own words describe below what the program does 
// Loops through a file searching for the word given as input. If found, prints the line it is on in the dictionary file, otherwise prints that the word wasn't found.
//
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <fstream>

int main () {
	// Declare variable search_word to store the word to be searched for
	std::string search_word;

	// Declare variable file_word to store the word read from the file
	std::string file_word;

	// Declare variable counter to keep track of the file line being visited and initialize it to zero
	int counter = 0;

	// Declare variable found to keep track of whether the word was found or not and initialize it to false
	bool found = false;

	// Declare input file variable inFile (represents the input stream)
	std::ifstream in_file;
	
	//open the dictionary file.
	in_file.open("dictionary.txt");
	if (!in_file) {
		std::cout << "Unable to open file!\n";
		return 1;
	}

	//Prompt the user to "Enter a word to search in dictionary: "
	// Get it and save it in the corresponding variable
	std::cout << "Enter a word to search in dictionary: ";
	std::cin >> search_word;

	//Note: Loop through the whole file, but if the word is found jump out of the loop
	// Get the first word from the file
	in_file >> file_word;

	// While the input stream is in working conditions
	while (in_file) {
		// Update the counter
		++counter;

		// If the word from the file is the one we are searching for
		if (file_word == search_word) {
			// Display "word ", search_word, " found in line ", counter
			std::cout << "Word " << search_word << " found in line " << counter << "\n";

			// Set found to true (to indicate the word was found)
			found = true;

			// We don't need to keep searching, so jump out of the loop
			break;
		}

		// Get the next word from the file
		in_file >> file_word;
	}

	if (file_word != search_word)
		std::cout << "word " << search_word << " is not in the dictionary\n";

    // Close the file
	in_file.close();

	// Exit main() indicating the program finished successfully
	return 0;
}