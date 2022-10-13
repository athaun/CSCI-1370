/////////////////////////////////////////////////////////////////////
//
// Name: Asher Haun
// Due date: 10.12.22
// Class: CSCI 1370-03
// Semester: Fall 2022
// CSCI 1370 Instructor: Gustavo Dietrich
//
// Using your own words describe below what the program does 
// Program Description: Given 4 inputs, calculates the area of a rectangle and of an ellipse and prints them out.
//
/////////////////////////////////////////////////////////////////////

#include <fstream>				// To work with files
#include <typeinfo>				// to be able to use operator typeid
#include <iostream>	
#include "myfunctions.h"

inline auto _test(const char* expression, const char* file, int line) -> void{
	std::cerr << "test(" << expression << ") failed in file " << file;
	std::cerr << ", line " << line << "." << std::endl << std::endl;
}
#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))

// Pi constant moved to header since it is a nicer place for it, it is only used there.

int main () {
	// Declare variable named outFile to represent the output file
	std::ofstream out_file;

	// Declare variables named base, height, radiusa, and radiusb that hold doble precision numbers
	double base, height;
	double radius_a, radius_b;

	// Declare variables named rec_area, and elli_area that hold double precision real numbers
	double rec_area, elli_area;

	// Open output file "output9.txt" and relate it to outFile
	out_file.open("output9.txt");
	if (!out_file) return 1; // File didn't open correctly

	// Print on the screen "For the rectangle"
	// Call void function getData() and receive in base and height the two lengths read from the keyboard
	std::cout << "For the rectangle\n";
	get_data(base, height);

	// Call function area_rectangle() to calculate the area of a rectangle and assign the returned value to rec_area
	rec_area = area_rectangle(base, height);
	
	// Print on the screen "For the ellipse"
	// Call void function getData() and receive in radiusa and radiusb the two lengths read from the keyboard
	std::cout << "For the ellipse\n";
	get_data(radius_a, radius_b);	

	// Call function area_ellipse() to calculate the area of an ellipse and assign the returned value to elli_area
	elli_area = area_ellipse(radius_a, radius_b);

	// Call function printData() to print the output to the output file
	print_data(out_file, base, height, rec_area, radius_a, radius_b, elli_area);

	// Close the file
	out_file.close();

	// Do NOT remove or modify the following statements
	std::cout << std::endl << "Testing your solution" << std::endl << std::endl;
	test(typeid(PI) == typeid(1.));							// Incorrect data type used for PI
	test(PI == 3.141592);									// Incorrect value used for PI
	test(typeid(base) == typeid(1.));						// Incorrect data type used for base
	test(typeid(height) == typeid(1.));						// Incorrect data type used for height
	test(typeid(radius_a) == typeid(1.));					// Incorrect data type used for radiusa
	test(typeid(radius_b) == typeid(1.));					// Incorrect data type used for radiusb
	test(typeid(rec_area) == typeid(1.));					// Incorrect data type used for rec_area
	test(typeid(elli_area) == typeid(1.));					// Incorrect data type used for elli_area
	test(fabs(area_rectangle(2.33, 3.61) - 8.4) < 0.001);	// Incorrect rounding of area of rectangle
	test(fabs(area_rectangle(2.42, 3.7) - 9.0) < 0.001);	// Incorrect rounding of area of rectangle
	test(fabs(area_ellipse(4.55, 5.95) - 85.1) < 0.001);	// Incorrect rounding of area of ellipse
	test(fabs(area_ellipse(4.61, 6.01) - 87.0) < 0.001);	// Incorrect rounding of area of ellipse

	return 0 ;
}

