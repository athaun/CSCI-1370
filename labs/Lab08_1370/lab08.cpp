/////////////////////////////////////////////////////////////////////
//
// Name: Asher Haun
// Due date: 10.5.22
// Class: CSCI 1370-03
// Semester: Fall 2022
// CSCI 1370 Instructor: Gustavo Dietrich
//
// Using your own words describe below what the program does 
// Program Description: Given input radius and height, calculates and prints the volume of a cone.
//
/////////////////////////////////////////////////////////////////////

#include <ios>
#include <iostream>
#include <typeinfo>
#include <cmath>
#include <iomanip>

// Ignore this; it's a little function used for making tests
inline void _test(const char* expression, const char* file, int line) {
	std::cerr << "test(" << expression << ") failed in file " << file;
	std::cerr << ", line " << line << "." << std::endl << std::endl;
}
// This goes along with the above function...don't worry about it
#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))

// Insert here the prototypes of the functions

double square (double n); // Calculate the square of the value received
double volume_cone (int radius, int height); // Calculates the volume of the cone using the formula 1 / 3 x Pi x radius^2 x height
double round_off (double value, int dec_digits); // Rounds the value received in the first parameter to the number of digits received in the second parameter
void print_data (std::string name, int radius, int height, double volume); // Prints the volume of the cone

// Declare a global constant variable called PI above main() that holds value 3.141592
const double PI = 3.141592;

int main () {
	// Declare a variable named name that holds text
	std::string name;

	// Declares variables named height and radius that hold whole numbers
	int height, radius;

	// Declare a variable named volume that holds double precision real numbers
	double volume;

	// Prompts the user "May I get your first name please?: "
	// Read the value from the keyboard and stores it in name
	std::cout << "May I get your first name please?: ";
	std::cin >> name;

	// Prompt the user "Thanks ", name, ", now enter radius and height of the cone please: "
	// Read the values from the keyboard and stores them in radius and height respectively
	std::cout << "Thanks " << name << ", now enter radius and height of the cone please.\nRadius: ";
	std::cin >> radius;
	std::cout << "Height: ";
	std::cin >> height;

	// Call function volume_cone() to calculate the volume of the cone and assign the result to volume 
	volume = volume_cone(radius, height);

	// Round to 3 decimal places
	volume = round_off(volume, 3);

	// Call function print_data() to print the values entered by the user and the volume of the cone
	print_data(name, radius, height, volume);

	// Do NOT remove or modify the following statements
	std::cout << std::endl << "Testing your solution" << std::endl << std::endl;
	test(typeid(PI) == typeid(1.));							// Incorrect data type used for PI
	test(PI == 3.141592);									// Incorrect value used for PI
	test(typeid(name) == typeid(std::string));				// Incorrect data type used for name
	test(typeid(height) == typeid(1));						// Incorrect data type used for height
	test(typeid(radius) == typeid(1));						// Incorrect data type used for radius
	test(typeid(volume) == typeid(1.));						// Incorrect data type used for volume
	test(fabs(volume_cone(3,5) - 47.124) < 0.0001);			// Incorrect rounding of volume
	test(fabs(volume_cone(3, 4) - 37.699) < 0.0001);		// Incorrect rounding of volume

	return 0;
}


//************************  Function definition  *************************
// Read the handout carefully for detailed description of the functions that you have to implement

// Calculate the square of the value received
double square (double n) {
	return n * n;
}

// Calculates the volume of the cone using the formula 1 / 3 x Pi x radius^2 x height
double volume_cone (int radius, int height) {
	return round_off((1.0 / 3.0) * PI * square(static_cast<double>(radius)) * static_cast<double>(height), 3);
}

// Rounds the value received in the first parameter to the number of digits received in the second parameter
double round_off (double value, int dec_digits) {
	dec_digits = pow(10, dec_digits);
	return round(value * static_cast<double>(dec_digits)) / static_cast<double>(dec_digits);
}

// Prints the volume of the cone
void print_data (std::string name, int radius, int height, double volume) {
	std::cout << std::fixed << std::setprecision(3);
	std::cout << "\nOk " << name << "\n" <<
				   "For a radius: " << radius << " and a height: " << height << " the cones volume is " << volume << "\n";
}