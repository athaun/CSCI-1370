//******************************************************************************
// Team # 24          CSCI 1370      Fall 2022                    Homework # 1
// Erick Valencia
// Asher Haun
//
// Takes input for number of Pesos and Euros, converts each to equivalent number of dollars.
// It then splits the dollars and cents and displays them seperately.
// The total of euros and pesos in dollars is calculated by addition of the two and then displayed using the same method as the individual converted values.
//******************************************************************************

#include <iostream>				// to be able to use cout
#include <typeinfo>				// to be able to use operator typeid
#include <cmath>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

// Ignore this; it's a little function used for making tests
inline void _test(const char* expression, const char* file, int line) {
	cerr << "test(" << expression << ") failed in file " << file;
	cerr << ", line " << line << "." << endl << endl;
}
// This goes along with the above function...don't worry about it
#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))

// Function prototypes
void seperate_on_decimal (int & left_side, int & right_side, double input);

int main () {
    // Enter here your algorithm as a series of MEANINGFUL steps.
    // Write below EACH step of the algorithm the C++ statement that implements it.

    // Conversion factors for currencies
    const double DOL2MEX = 20.38;
    const double DOL2EURO = 1.04;

    // Input currencies
    double pesos, euros;

    // Converted amounts in dollars
    double pesos_converted, euros_converted;

    // Get the amounts in pesos and euros
    cout << "Please enter number of pesos: ";
    cin >> pesos;

    cout << "Please enter number of euros: ";
    cin >> euros;

    cout << "\nMexican Pesos and Euro to U.S. Dollar converter\n\n";

    // Calculate dollar amounts
    pesos_converted = pesos / DOL2MEX;
    euros_converted = euros / DOL2EURO;

    // Round the converted values to 2 decimal places
    pesos_converted = round(pesos_converted * 100.0) / 100.0;
    euros_converted = round(euros_converted * 100.0) / 100.0;
    
    double total = pesos_converted + euros_converted;

    // Format output to always show 2 decimal places
    cout << fixed << setprecision(2);
    
    // Define the variables that will hold the left and right side of each double precision number from above (pesos_converted, euros_converted and total)
    int whole_dollars_p, cent_dollars_p;
    int whole_dollars_e, cent_dollars_e;
    int whole_total, cent_total;
    
    seperate_on_decimal(whole_dollars_p, cent_dollars_p, pesos_converted);
    cout << setw(13) << pesos << setw(7) << " Pesos:" << setw(10) << whole_dollars_p << " US dollars and " << cent_dollars_p << " cents\n";

    seperate_on_decimal(whole_dollars_e, cent_dollars_e, euros_converted);
    cout << setw(13) << euros << setw(7) << " Euros:" << setw(10) << whole_dollars_e << " US dollars and " << cent_dollars_e << " cents\n";

    seperate_on_decimal(whole_total, cent_total, total);
    cout << setw(20) << " Total:" << setw(10) << whole_total << " US dollars and " << cent_total << " cents\n";
    
    // ----------------------------- Your code ends here -----------------------------
    
    // Do NOT remove or modify the following statements

	cout << endl << "Testing your solution" << endl << endl;

	test(typeid(DOL2MEX) == typeid(1.));			// Incorrect data type used for DOL2MEX
	test(typeid(DOL2EURO) == typeid(1.));			// Incorrect data type used for DOL2EURO
	test(typeid(pesos) == typeid(1.));				// Incorrect data type used for pesos
	test(typeid(euros) == typeid(1.));				// Incorrect data type used for euros
	test(typeid(whole_dollars_p) == typeid(1));		// Incorrect data type used for whole_dollars_p
	test(typeid(cent_dollars_p) == typeid(1));		// Incorrect data type used for cent_dollars_p
	test(typeid(whole_dollars_e) == typeid(1));		// Incorrect data type used for whole_dollars_e
	test(typeid(cent_dollars_e) == typeid(1));		// Incorrect data type used for cent_dollars_e
	test(typeid(whole_total) == typeid(1));			// Incorrect data type used for whole_total
	test(typeid(cent_total) == typeid(1));			// Incorrect data type used for cent_total
	
	if (pesos == 120.0 && euros == 120.0)			// Does not pass test 1
	{
		test(whole_dollars_p == 5 && cent_dollars_p == 89);
		test(whole_dollars_e == 115 && cent_dollars_e == 38);
		test(whole_total == 121 && cent_total == 27);
	}
	if (pesos == 190.96 && euros == 116.10)			// Does not pass test 2
	{
		test(whole_dollars_p == 9 && cent_dollars_p == 37);
		test(whole_dollars_e == 111 && cent_dollars_e == 63);
		test(whole_total == 121 && cent_total == 0);
	}
	if (pesos == 1121.72 && euros == 31.25)			// Does not pass test 3
	{
		test(whole_dollars_p == 55 && cent_dollars_p == 4);
		test(whole_dollars_e == 30 && cent_dollars_e == 5);
		test(whole_total == 85 && cent_total == 9);
	}
	if (pesos == 386.40 && euros == 42.69)			// Does not pass test 4
	{
		test(whole_dollars_p == 18 && cent_dollars_p == 96);
		test(whole_dollars_e == 41 && cent_dollars_e == 5);
		test(whole_total == 60 && cent_total == 1);
	}
	return 0;
}

void seperate_on_decimal (int & left_side, int & right_side, double input) {
    left_side = static_cast<int>(input);
    right_side = static_cast<int>(round((input - left_side) * 100.0));
    // .000001
    return;
}