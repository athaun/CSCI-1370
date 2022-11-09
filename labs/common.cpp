/*

Contains commonly re-used blocks of code in the labs/hw assignments.

*/

#include <cmath>
#include <iostream>


// Ignore this; it's a little function used for making tests
inline void _test(const char* expression, const char* file, int line) {
	std::cerr << "test(" << expression << ") failed in file " << file;
	std::cerr << ", line " << line << "." << std::endl << std::endl;
}
// This goes along with the above function...don't worry about it
#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))


// This function generates a random number within a specified range.
// It receives two whole numbers : the minumum and maximum bounds of the randomly generated number
int random (int min, int max) {
	return (rand() % (max - min + 1)) + min;
}


// Rounds the value received in the first parameter to the number of digits received in the second parameter
double round_off (double value, int dec_digits) {
	dec_digits = pow(10, dec_digits);
	return round(value * dec_digits) / dec_digits;
}

int main () {

    return 0;
}