//******************************************************************************
// Team # 24          CSCI 1370      Fall 2022                    Homework # 2
// Erick Valencia
// Asher Haun
//
// Using your own words, write here a description of what the program does.
//
//******************************************************************************

#include <iomanip>
#include <ios>
#include <iostream>				// to use cin and cout
#include <typeinfo>				// to be able to use operator typeid
#include <fstream>
#include <cmath>
#include <utility>

inline auto _test(const char* expression, const char* file, int line) -> void{
	std::cerr << "test(" << expression << ") failed in file " << file;
	std::cerr << ", line " << line << "." << std::endl << std::endl;
}
#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))

// Get data from a file
void get_point (std::ifstream & in_file, double & x, double & y);

// Print data to a file
void print_distance (std::ofstream & out_file, double x_1, double y_1, double x_2, double y_2, double distance);

// Helper functions
double semi_perimeter (double len_ab, double len_bc, double len_ca);
double square (double num);
double round_off(double value, int dec_digits);

// Calculate things
double calc_length (double x_1, double y_1, double x_2, double y_2);
double calc_area (double len_ab, double len_bc, double len_ca);

int main() {
	// Define and open input and output files
	std::ifstream in_file;
	std::ofstream out_file;

	in_file.open("inputhw2.txt");
	if (!in_file) return 1;

	out_file.open("outputhw2.txt");
	if (!out_file) return 1;

	// Get the points from the file
	double x_a, y_a;
	double x_b, y_b;
	double x_c, y_c;

	get_point(in_file, x_a, y_a);
	get_point(in_file, x_b, y_b);
	get_point(in_file, x_c, y_c);

	// Calculate distances of each side
	double len_ab = calc_length(x_a, y_a, x_b, y_b);
	double len_bc = calc_length(x_b, y_b, x_c, y_c);
	double len_ca = calc_length(x_c, y_c, x_a, y_a);

	// Print distances
	print_distance(out_file, x_a, y_a, x_b, y_b, len_ab);
	print_distance(out_file, x_b, y_b, x_c, y_c, len_bc);
	print_distance(out_file, x_c, y_c, x_a, y_a, len_ca);

	// Calculate the area and print it to the out_file
	out_file << "The area is " << std::setprecision(2) << calc_area(len_ab, len_bc, len_ca) << "\n";

	// Close the input and output files
	in_file.close();
	out_file.close();

	// Do NOT remove or modify the following statements
	std::cout << std::endl << "Testing your solution" << std::endl << std::endl;

	test(fabs(round_off(calc_length(1.0, 1.2, 6.0, 6.1), 2) - 7.00) < .001);			// Incorrect calculation of length
	test(fabs(round_off(calc_length(6.0, 6.1, 3.2, 6.5), 2) - 2.83) < .001);			// Incorrect calculation of length
	test(fabs(round_off(calc_length(1.0, 1.2, 3.2, 6.5), 2) - 5.74) < .001);			// Incorrect calculation of length
	test(fabs(calc_area(calc_length(1.0, 1.2, 6.0, 6.1), calc_length(6.0, 6.1, 3.2, 6.5), calc_length(1.0, 1.2, 3.2, 6.5)) - 7.86) < .001);			// Incorrect calculation of area

	test(fabs(round_off(calc_length(1.2, 1.2, 7.6, 4.3), 2) - 7.11) < .001);			// Incorrect calculation of length
	test(fabs(round_off(calc_length(7.6, 4.3, 9.2, 3.4), 2) - 1.84) < .001);			// Incorrect calculation of length
	test(fabs(round_off(calc_length(1.2, 1.2, 9.2, 3.4), 2) - 8.30) < .001);			// Incorrect calculation of length
	test(fabs(calc_area(calc_length(1.2, 1.2, 7.6, 4.3), calc_length(7.6, 4.3, 9.2, 3.4), calc_length(1.2, 1.2, 9.2, 3.4)) - 5.36) < .001);			// Incorrect calculation of area

	test(fabs(round_off(calc_length(1.0, 1.0, 5.0, 5.0), 2) - 5.66) < .001);			// Incorrect calculation of length
	test(fabs(round_off(calc_length(5.0, 5.0, 9.0, 9.0), 2) - 5.66) < .001);			// Incorrect calculation of length
	test(fabs(round_off(calc_length(1.0, 1.0, 9.0, 9.0), 2) - 11.31) < .001);			// Incorrect calculation of length
	test(fabs(calc_area(calc_length(1.0, 1.0, 5.0, 5.0), calc_length(5.0, 5.0, 9.0, 9.0), calc_length(1.0, 1.0, 9.0, 9.0)) - 0.00) < .001);			// Incorrect calculation of area

	return 0;		
}

//************************  Function definitions  *************************
// Read the handout carefully for detailed description of the functions that you have to implement

/*
Get points from a file, rounds each part to one decimal point, and returns them through reference parameters 
*/
void get_point (std::ifstream & in_file, double & x, double & y) {
	in_file >> x >> y;
	x = round_off(x, 1);
	y = round_off(y, 1);
}

// Print data to a file
void print_distance (std::ofstream & out_file, double x_1, double y_1, double x_2, double y_2, double distance) {
	out_file << std::fixed << std::setprecision(1);
	out_file << "The distance between (" << x_1 << ", " << y_1 << ") and (" << x_2 << ", " << y_2 << ") is " << std::setprecision(2) << distance << "\n";
}

/*
Receives three lengths and returns the value of the semi perimeter rounded to ten decimal places.
*/
double semi_perimeter (double len_ab, double len_bc, double len_ca) {
	return (1.0 / 2.0) * (len_ab + len_bc + len_ca);
}

double square (double num) {
	return num * num;
}

double round_off (double value, int dec_digits) {
	double _dec_digits = static_cast<double>(pow(10, dec_digits));
	return round(value * _dec_digits) / _dec_digits;
}

/*
Receives the coordinates of two points and returns the distance
between them rounded to ten decimal places.
*/
double calc_length (double x_1, double y_1, double x_2, double y_2) {
	return round_off(sqrt(
		square(x_2 - x_1) + square(y_2 - y_1)
	), 10);
}

/* 
Receives three lengths and returns the area of the triangle rounded to two decimal places.
*/
double calc_area (double len_ab, double len_bc, double len_ca) {
	double s = semi_perimeter(len_ab, len_bc, len_ca);
	return round_off(sqrt(
		s * (s - len_ab) * (s - len_bc) * (s - len_ca)
	), 2);
}