#pragma once

#include <string>

// Displays a menu to prompt the user to choose an operation
char menu ();

// This function pauses the execution of the program
void pause ();

// This function receives two integers, num and den, and reduces them to their lowest terms
void reduce_rational (int & num, int & den);

// This number prompts the user to input a fraction and returns them through the parameters
void get_rational (int & num, int & den);

// This function receives two fractions and adds them together, returning the result through the parameters
void add_rational (int & num, int & den, int num1, int den1, int num2, int den2);

// This function receives two fractions and subtracts them, returning the result through the parameters
void sub_rational (int & num, int & den, int num1, int den1, int num2, int den2);

std::string print_rational (int num, int den);
