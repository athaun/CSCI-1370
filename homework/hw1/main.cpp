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
void seperate_on_decimal_1 (int & left_side, int & right_side, double input);
void seperate_on_decimal_2 (int & left_side, int & right_side, double input);
void print_result (string currency, double amount, int left_side, int right_side);

int main () {
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
    
    // PESOS
    int whole_dollars_p, cent_dollars_p; // Define the variables that will hold the left and right side the double precision number pesos_converted
    seperate_on_decimal_1(whole_dollars_p, cent_dollars_p, pesos_converted); // Seperate the values and assign to whole_dollars_p and cent_dollars_p for left and right of the decimal respectivly
    print_result("Pesos", pesos, whole_dollars_p, cent_dollars_p); // Print the output

    seperate_on_decimal_2(whole_dollars_p, cent_dollars_p, pesos_converted);
    print_result("Pesos", pesos, whole_dollars_p, cent_dollars_p);

    // EUROS
    int whole_dollars_e, cent_dollars_e;
    seperate_on_decimal_1(whole_dollars_e, cent_dollars_e, euros_converted);
    print_result("Euros", euros, whole_dollars_e, cent_dollars_e);

    seperate_on_decimal_2(whole_dollars_e, cent_dollars_e, euros_converted);
    print_result("Euros", euros, whole_dollars_e, cent_dollars_e);
    
    // TOTAL
    int whole_total, cent_total;
    seperate_on_decimal_1(whole_total, cent_total, total);
    print_result("Total", total, whole_total, cent_total);

    seperate_on_decimal_2(whole_total, cent_total, total);
    print_result("Total", total, whole_total, cent_total);

    // ----------------------------- TESTS - Do NOT remove or modify the following statements -----------------------------

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
	
	if (pesos == 120.0 && euros == 120.0) {
		test(whole_dollars_p == 5 && cent_dollars_p == 89);
		test(whole_dollars_e == 115 && cent_dollars_e == 38);
		test(whole_total == 121 && cent_total == 27);
	}
	if (pesos == 190.96 && euros == 116.10) {
		test(whole_dollars_p == 9 && cent_dollars_p == 37);
		test(whole_dollars_e == 111 && cent_dollars_e == 63);
		test(whole_total == 121 && cent_total == 0);
	}
	if (pesos == 1121.72 && euros == 31.25) {
		test(whole_dollars_p == 55 && cent_dollars_p == 4);
		test(whole_dollars_e == 30 && cent_dollars_e == 5);
		test(whole_total == 85 && cent_total == 9);
	}
	if (pesos == 386.40 && euros == 42.69) {
		test(whole_dollars_p == 18 && cent_dollars_p == 96);
		test(whole_dollars_e == 41 && cent_dollars_e == 5);
		test(whole_total == 60 && cent_total == 1);
	}

	return 0;
}

/*
  Convert a double to a string while throwing away trailing 0s.
  std::to_string() keeps them, which doesn't work for our needs because $6.200000 when split would become 6 dollars with 200000 cents
  
  param 1 ( double ) num 
  returns -> std::string
*/
string to_str (double num) {
    // create a custom string output stream (similar to cout)
    std::ostringstream oss;
    // Format the output to remove trailing decimal points using iomanip output manipulators (same as cout manipulators)
    oss << std::setprecision(8) << std::noshowpoint;
    // Insert our num into the string stream
    oss << num;
    // Convert the string stream to type string and return it
    return oss.str();
}

/*
  Given a double as input, returns the left and right side as seperate integer values.

  This version converts the input to a string and takes sub-strings by splitting on the index of '.'
  It then converts those string back to integer values which are returned through reference variables.
  This method is a way around having to round the values (or multiply by 100.000001) before casting to int as in seperate_on_decimal_1()
  Although the value in that situation theoretically shouldn't be different, this method makes me feel more confident in the result. 
  In the ...decimal_1() version, certain numbers are represented by approximations, because strings are not making use of actual
  operatable digits (instead using chars), the representation of all floating point numbers is exact.
  
  param 1 ( int & ): left side
  param 2 ( int & ): right side
  param 3 ( double ): input
*/
void seperate_on_decimal_2 (int & left_side, int & right_side, double input) {
    // convert the value to a string
    string input_str = to_str(input);

    // Take a slice of the string from index 0 to the index of '.' in the string
    string s = input_str.substr(0, input_str.find('.'));
    // Convert the string into an int and assign that value to the variable representing the left side
    left_side = stoi(s);

    // Take a slice of the string from the index of '.' to the end of the string, aka the size - 1 which is the last index of the character array
    s = input_str.substr(input_str.find('.') + 1, input_str.find('0'));
    // Convert the string into an int and assign that value to the variable representing the right side
    right_side = stoi(s);

    return;
}

/*
  Given a currency, amount of said currency, and the seperated values of the U.S.D equivalent, it prints the result.
  If the currency is not "Pesos" or "Euros" the method will default to printing the total.
  
  param 1 ( std::string ): currency
  param 2 ( double ): amount 
  param 3 ( int ): left side
  param 4 ( int ): right side
*/
void print_result (string currency, double amount, int left_side, int right_side) {
    if (currency == "Euros" || currency == "Pesos")
        cout << setw(13) << amount << ":" << setw(7) << currency << setw(10) << left_side << " US dollars and " << right_side << " cents\n";
    else 
        cout << setw(20) << " Total:" << setw(10) << left_side << " US dollars and " << right_side << " cents\n";
}

/*
  Given a double as input, returns the left and right side as seperate integer values
  
  param 1 ( int & ): left side
  param 2 ( int & ): right side
  param 3 ( double ): input
*/
void seperate_on_decimal_1 (int & left_side, int & right_side, double input) {
    left_side = static_cast<int>(input);
    right_side = static_cast<int>(round((input - left_side) * 100.0));
    
    // Also works: 
    // left_side = static_cast<int>(input);
    // right_side = static_cast<int>((input - left_side) * 100.000001);

    return;
}