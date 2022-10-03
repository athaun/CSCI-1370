#include <ios>
#include <iostream>

int main () {
    std::cout << "(14.5 % 2)\tnot possible" << "\n";
    std::cout << std::showpoint;
    std::cout << "C++ :\t\t" << (1 / 2 * 3.0) << "\n";

    std::cout << "C style cast:\t" << (int)0.5 << "\n";
    std::cout << "C++ cast:\t" << static_cast<int>(0.5) << "\n";

    std::cout << std::noshowpoint;
    return 0;
}