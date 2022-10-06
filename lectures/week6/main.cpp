/*

Header files - method implementations were in the header itself





*/

#include <iostream>
#include <string>
#include <fstream>

int main () {
    std::ifstream inFile;
    std::ofstream outFile;

    std::string name;
    int num, result;
    float num2;
    char letter;

    inFile.open("/Users/asher/Documents/code/CSCI-1370/lectures/week6/input_1.txt");
    if (!inFile) return 1; 
    outFile.open("/Users/asher/Documents/code/CSCI-1370/lectures/week6/output_1.txt");
    if (!outFile) return 1; 

    inFile >> name;
    inFile >> num >> num2 >> letter;

    result = num * 2;

    std::cout << "\nGreetings " << name << "\n\n";
    std::cout << num << " * 2 = " << result << "\n";
    std::cout << "the other number is " << num2 << "\n\n";
    std::cout << "and the letter is " << letter << "\n\n";

    outFile << "\nGreetings " << name << "\n\n";
    outFile << num << " * 2 = " << result << "\n";
    outFile << "the other number is " << num2 << "\n\n";
    outFile << "and the letter is " << letter << "\n\n";

    inFile.close();
    outFile.close();
    
    return 0;
}