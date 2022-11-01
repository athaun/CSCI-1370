#include <iostream>

int main () {
    std::string day;
    std::string day_type = "Weekday :("; // Most days of the week are weekdays, so set the default type to "Weekday :(")

    int input;

    std::cout << "Input day of week: ";
    std::cin >> input;

    switch (input) {
        case 1:
            day = "Saturday";
            day_type = "Weekend :)";
            break;
        case 7:
            day = "Sunday";
            day_type = "Weekend :)";
            break;
        case 2: day = "Monday";     break;
        case 3: day = "Tuesday";    break;
        case 4: day = "Wednesday";  break;
        case 5: day = "Thursday";   break;
        case 6: day = "Friday";     break;
        default: 
            day = "a day of the week that doesn't exist";
            day_type = "You are being overworked! :(";
            if (input < 1) day_type = "You need to get a job :O"; // Working 0 or negative days a week
            break;
    } 

    std::cout << "You input " << input << " wich corresponds to " << day << " ( " << day_type << " )\n";


    return 0;
}