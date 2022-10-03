#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

void allEven (int num) {
    int count = 1;
    while (count < num) {
        if (count % 2 == 0) {
            std::cout << count << std::endl;
        }
        count ++;
    }
}

int main () {
    allEven(25);
    return 0;
}