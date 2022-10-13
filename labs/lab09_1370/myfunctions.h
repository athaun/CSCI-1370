/////////////////////////////////////////////////////////////////////
//
// Name: Asher Haun
// Due date: 10.12.22
// Class: CSCI 1370-03
// Semester: Fall 2022
// CSCI 1370 Instructor: Gustavo Dietrich
//
/////////////////////////////////////////////////////////////////////
#pragma once 

#include <cmath>
#include <fstream>
#include <ios>
#include <iostream>

//************************  Function definitions  *************************
// Read the handout carefully for detailed description of the functions that you have to implement

// Declare a global constant named PI equal to 3.141592
const double PI = 3.141592;

// round_off(): Rounds the value received in the first parameter to the number of digits received in the second parameter
// Rounds the value received in the first parameter to the number of digits received in the second parameter
inline auto round_off (double value, int dec_digits) -> double {
	double _dec_digits = static_cast<double>(pow(10, dec_digits));
	return round(value * _dec_digits) / _dec_digits;
}

// getData(): Gets two lengths from the keyboard and returns them to the caller
auto get_data (double & p1, double & p2) -> void {
    std::cout << "Please input two lengths: ";
    std::cin >> p1 >> p2;
    std::cout << "\n";
}

// printData(): Receives the output file, base of the rectangle, height of the rectangle, area of the rectangle,
// radius a of the ellipse, radius b of the ellipse, and area of the ellipse and prints the output to the file
auto print_data (std::ofstream & out_file, double base, double height, double area_rec, double rad_a, double rad_b, double area_ellipse) -> void {
    out_file << std::fixed << std::setprecision(2);
    out_file << "The area of the rectangle with base " << std::setw(6) << base << " and height " << std::setw(6) << height << " is " << std::setw(6) << area_rec << "\n";
    out_file << "The area of the ellipse with radius " << std::setw(6) << rad_a << " and radius " << std::setw(6) << rad_b << " is " << std::setw(6) << area_ellipse << "\n";
}

// area_rectangle(): Calculates the area of the rectangle and returns it rounded to 1 decimal digit to the caller
inline auto area_rectangle (double base, double height) -> double {
    return round_off(base * height, 1);
}

// area_ellipse(): Calculates the area of the area_ellipse and returns it rounded to 1 decimal digit to the caller
inline auto area_ellipse (double radius_a, double radius_b) -> double {
    return round_off(PI * radius_a * radius_b, 1);
}


