#include <ios>
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip> // output stream maniuplators

int main () {
    std::cout << std::showpoint;
    std::cout << std::fixed << std::setprecision(2); // setprecision() without std::fixed will cut off sig figs rather than decimal places
    
    std::cout << "C++ float int char int\n";

    float float1;
    int whole2;
    char char3;
    int whole4;

    std::cin >> float1 >> whole2 >> char3 >> whole4;
    std::cout << "float: " << float1 << " int: " << whole2 << " char: '" << char3 << "' int: " << whole4 << "\n";

    std::cout << "\n";

    // std::cout << "4.493 rounded to 2 decimals = " << round(4.495 * 100.0) / 100.0 << "\n";

    return 0;
}
/*
Test inputs:
4.5 61 a 7
4 61 a 7
4 6.9 a 7
10 10 10 10
4 61 7 8
4.5 a 61 7
4.5 61 a 7
*/





