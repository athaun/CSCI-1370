#include <iostream>

#include "tests.hpp"
#include "rationals.hpp"
#include <typeinfo>

inline void _test(const char* expression, const char* file, int line) {
	std::cerr << "test(" << expression << ") failed in file " << file;
	std::cerr << ", line " << line << "." << std::endl << std::endl;
}

#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))

void run_tests () {
    std::cout << std::endl;
	pause();

	std::cout << std::endl << "Testing your solution" << std::endl << std::endl;
	int num, den;
	num = 4; den = 3;
	reduce_rational(num, den);
	test(num == 4 && den == 3);								// Incorrect reducing of the fraction
	num = 12; den = 3;
	reduce_rational(num, den);
	test(num == 4 && den == 1);								// Incorrect reducing of the fraction
	num = 3; den = 12;
	reduce_rational(num, den);
	test(num == 1 && den == 4);								// Incorrect reducing of the fraction
	num = -3; den = 12;
	reduce_rational(num, den);
	test(num == -1 && den == 4);							// Incorrect reducing of the fraction
	num = -63; den = 15;
	reduce_rational(num, den);
	test(num == -21 && den == 5);							// Incorrect reducing of the fraction
	num = -1024; den = 127;
	reduce_rational(num, den);
	test(num == -1024 && den == 127);						// Incorrect reducing of the fraction

	add_rational(num, den, 1, 2, 2, 4);
	test(num == 1 && den == 1);								// Incorrect addition of the fractions
	add_rational(num, den, 1, 3, 3, 4);
	test(num == 13 && den == 12);							// Incorrect addition of the fractions
	add_rational(num, den, 9, 5, 2, 5);
	test(num == 11 && den == 5);							// Incorrect addition of the fractions
	add_rational(num, den, 1, 3, 3, 18);
	test(num == 1 && den == 2);								// Incorrect addition of the fractions
	add_rational(num, den, 1, 7, 3, 9);
	test(num == 10 && den == 21);							// Incorrect addition of the fractions
	add_rational(num, den, 3, 7, 6, 9);
	test(num == 23 && den == 21);							// Incorrect addition of the fractions

	sub_rational(num, den, 1, 2, 2, 4);
	test(num == 0 && den == 1);								// Incorrect subtraction of the fractions
	sub_rational(num, den, 1, 3, 3, 4);
	test(num == -5 && den == 12);							// Incorrect subtraction of the fractions
	sub_rational(num, den, 9, 5, 2, 5);
	test(num == 7 && den == 5);								// Incorrect subtraction of the fractions
	sub_rational(num, den, 1, 3, 3, 18);
	test(num == 1 && den == 6);								// Incorrect subtraction of the fractions
	sub_rational(num, den, 1, 1, 75, 12);
	test(num == -21 && den == 4);							// Incorrect subtraction of the fractions
	sub_rational(num, den, 6, 9, 3, 7);
	test(num == 5 && den == 21);							// Incorrect subtraction of the fractions
}