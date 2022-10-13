/////////////////////////////////////////////////////////////////////
//
// Name: Asher Haun
// Due date: 10.5.22
// Class: CSCI 1370-03
// Semester: Fall 2022
// CSCI 1370 Instructor: Gustavo Dietrich
//
// Using your own words describe below what the program does 
// Program Description: Given inputs side and radius, calculates and prints the surface area of a cube and sphere respectively.
//
/////////////////////////////////////////////////////////////////////

#include <iomanip>
#include <iostream>				// to use cin and cout
#include <typeinfo>				// to be able to use operator typeid
#include <cmath>
#include <cstdlib>

// Ignore this; it's a little function used for making tests
inline void _test(const char* expression, const char* file, int line) {
	std::cerr << "test(" << expression << ") failed in file " << file;
	std::cerr << ", line " << line << "." << std::endl << std::endl;
}
// This goes along with the above function...don't worry about it
#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))

// Insert here the prototypes of the functions
double square (double n); // Calculate the square of the value received
double cube_surf (double s);// Calculate the surface area of the cube using the formula 6 x side^2 (six times the square of the side of the cube)
double sphere_surf (double r); // Calculate the surface area of the sphere using the formula 4 x Pi x radius^2 (four times Pi times the square of the radius of the sphere)
double round_off (double value, int dec_digits); // Rounds the value received in the first parameter to the number of digits received in the second parameter

// Declare a global constant variable named PI above main() that holds value 3.141592
const double PI = 3.141592;

int main () {
	// Declare variables named side, radius, s_cube, and s_sphere that hold double precision real numbers
	double side;
	double radius;
	double s_cube, s_sphere;

	// Prompt the user to "Enter side of cube : "
	// Read from keyboard the value entered by the user and assign it to side
	std::cout << "Enter side of cube: ";
	std::cin >> side;

	// Prompt the user to "Enter radius of sphere : "
	// Read from keyboard the value entered by the user and assign it to radius
	std::cout << "Enter radius of sphere: ";
	std::cin >> radius;

	// Call cube_surf() to calculate the surface of the cube and assign the result to s_cube
	s_cube = cube_surf(side);

	// Call sphere_surf() to calculate the surface of the sphere and assign the result to s_sphere
	s_sphere = sphere_surf(radius);

	// Clear the screen
	system("clear || cls");

	// Format the output to display the numbers in fixed format with two decimal digits
	std::cout << std::fixed << std::setprecision(2);

	// Display on the screen the message
	//	   "The surface area of a cube of sides ", side,   " is ", s_cube
	//	"The surface area of a sphere of radius ", radius, " is ", s_sphere
	// Use 39 columns for text and 6 columns for the values.
	std::cout << std::setw(39) << "The surface area of a cube of sides " << std::setw(6) << side << " is " << s_cube << "\n";
	std::cout << std::setw(39) << "The surface area of a sphere of radius " << std::setw(6) << radius << " is " << s_sphere << "\n";

	// Do NOT remove or modify the following statements
	std::cout << std::endl << "Testing your solution" << std::endl << std::endl;
	test(typeid(side) == typeid(1.));						// Incorrect data type used for side
	test(typeid(radius) == typeid(1.));						// Incorrect data type used for radius
	test(typeid(s_cube) == typeid(1.));						// Incorrect data type used for s_cube
	test(typeid(s_sphere) == typeid(1.));					// Incorrect data type used for s_sphere
	test(fabs(cube_surf(3.36) - 67.74) < 0.001);			// Incorrect rounding of value returned by cube_surf() 
	test(fabs(cube_surf(3.37) - 68.14) < 0.001);			// Incorrect rounding of value returned by cube_surf()
	test(fabs(sphere_surf(4.23) - 224.85) < 0.001);			// Incorrect rounding of value returned by sphere_surf()
	test(fabs(sphere_surf(4.29) - 231.27) < 0.001);			// Incorrect rounding of value returned by sphere_surf()

	
	return 0;
}

//************************  Function definition  *************************
// Read the handout carefully for detailed description of the functions that you have to implement


// Calculate the square of the value received
double square (double n) {
	return n * n;
}

// Calculate the surface area of the cube using the formula 6 x side^2 (six times the square of the side of the cube)
double cube_surf (double s) {
	return round_off(6.0 * square(s), 2);
}

// Calculate the surface area of the sphere using the formula 4 x Pi x radius^2 (four times Pi times the square of the radius of the sphere)
double sphere_surf (double r) {
	return round_off(4.0* PI * square(r), 2);
}

// Rounds the value received in the first parameter to the number of digits received in the second parameter
double round_off (double value, int dec_digits) {
	dec_digits = pow(10, dec_digits);
	return round(value * dec_digits) / dec_digits;
}
