/////////////////////////////////////////////////////////////////////
//
// Name: Asher Haun
// Due date:
// Class: CSCI 1370-03
// Semester: Fall 2022
// CSCI 1370 Instructor: Gustavo Dietrich
//
// Using your own words describe below what the program does
// Program Description: Given two variables, computes the sin and cos of two
// inputs, rounds them and adds them together. The result is displayed at the
// end in the form of an elementary addition setup.
//
/////////////////////////////////////////////////////////////////////

#include <cmath>
#include <iomanip>
#include <iostream> // for std I/O (cin, cout)
#include <string>
#include <sys/resource.h>
#include <typeinfo> // to be able to use operator typeid

// Ignore this; it's a little function used for making tests
inline void _test(const char *expression, const char *file, int line) {
  std::cerr << "test(" << expression << ") failed in file " << file;
  std::cerr << ", line " << line << "." << std::endl << std::endl;
}
// This goes along with the above function...don't worry about it
#define test(EXPRESSION)                                                       \
  ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))

int main() {
  // Declares constant PI:3.141592
  const double PI = 3.141592;

  // Declares variable name that holds text
  std::string name;

  // Declares variables alpha,beta,sina,cosb, and total that hold double
  // precision real numbers
  double alpha, beta;
  double sin_a, cos_b;
  double total;

  // Prompts the user to "Please enter your full name: "
  // Reads the full name from keyboard and stores it in the corresponding
  // variable
  std::cout << "Please enter your full name: ";
  std::getline(std::cin, name);

  // Prompts the user to "Please enter angle alpha: "
  // Reads the value from the keyboard and stores it in the corresponding
  // variable
  std::cout << "Please enter angle alpha: ";
  std::cin >> alpha;

  // Prompts the user to "Please enter angle beta: "
  // Reads the value from the keyboard and stores it in the corresponding
  // variable
  std::cout << "Please enter angle beta: ";
  std::cin >> beta;

  // Displays "Thanks ", name
  std::cout << "\nThanks " << name << "\n\n";

  // Calculates the sine of alpha and the cosine of beta, and stores the results
  // in the corresponding variables
  sin_a = sin(alpha * (PI / 180.0));
  cos_b = cos(beta * (PI / 180.0));

  // Round to three decimal places
  sin_a = round(sin_a * 1000.0) / 1000.0;
  cos_b = round(cos_b * 1000.0) / 1000.0;

  // Calculates the total as the addition of the sine and the cosine and stores
  // it in the corresponding variable
  total = sin_a + cos_b;

  // Formats the output to display the values in fixed format with three decimal
  // digits
  std::cout << std::fixed << std::setprecision(3);

  // Prints a message like the one below:
  // Using 23 columns displays "sine of alpha: ", using 6 columns displays sina
  std::cout << std::setw(23) << "sine of alpha:" << std::setw(6) << sin_a << "\n";

  // Using 23 columns displays "+ cosine of beta: " , using 6 columns displays
  // cosb
  std::cout << std::setw(23) << "+ cosine of beta:" << std::setw(6) << cos_b << "\n";

  // Using 30 columns displays "-------"
  std::cout << std::setw(30) << "-------\n";

  // Using 23 columns displays "total: ",  using 6 columns displays total
  std::cout << std::setw(23) << "Total:" << std::setw(6) << total << "\n";

  // Do NOT remove or modify the following statements
  std::cout << std::endl << "Testing your solution" << std::endl << std::endl;
  test(typeid(name) ==
       typeid(std::string));         // Incorrect data type used for name
  test(typeid(alpha) == typeid(1.)); // Incorrect data type used for alpha
  test(typeid(beta) == typeid(1.));  // Incorrect data type used for beta
  test(typeid(sin_a) == typeid(1.)); // Incorrect data type used for sina
  test(typeid(cos_b) == typeid(1.)); // Incorrect data type used for cosb
  test(typeid(total) == typeid(1.)); // Incorrect data type used for total
  if (alpha == 33. && beta == 33.)
    test(fabs(total - 1.384) < 0.0001); // Incorrect rounding
  if (alpha == 66.45 && beta == 66.45)
    test(fabs(total - 1.317) < 0.0001); // Incorrect rounding
  if (alpha == 87.33 && beta == 87.33)
    test(fabs(total - 1.046) < 0.0001); // Incorrect rounding
  if (alpha == 25.76 && beta == 25.76)
    test(fabs(total - 1.336) < 0.0001); // Incorrect rounding
  if (alpha == 25.89 && beta == 25.89)
    test(fabs(total - 1.337) < 0.0001); // Incorrect rounding

  return 0; //  Successful completion
}