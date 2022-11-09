/////////////////////////////////////////////////////////////////////
//
// Name: Asher Haun
// Date: 11.9.22
// Class: CSCI 1170.03
// Semester: Fall 2022
// CSCI/CMPE 1370 Instructor: Gustavo Dietrich
//
// 
// 
//
/////////////////////////////////////////////////////////////////////

#include <iomanip>
#include <ios>
#include <iostream>
#include <fstream>
#include <cmath>

void print_occupancy (std::ifstream & in_file);

int main () {
	std::ifstream in_file;
	in_file.open("occupants.txt");
	if (!in_file) {
		std::cout << "Unable to open file!\n";
		return 1;
	}

	print_occupancy(in_file);

	in_file.close();

	return 0;
}

//************************  Function definitions  *************************
// Read the handout carefully for detailed description of the functions that you have to implement

// This function calculates the occupancy rate given number of rooms and occupied rooms (rounded to nearest 10th)
double calc_occupancy_rate (int occupied_rooms, int num_rooms) {
	double occupancy_rate = static_cast<double>(occupied_rooms) / static_cast<double>(num_rooms) * 100.0;
	return round(occupancy_rate * 10.0) / 10.0;
}

// This function receives an input file with data about rooms in a hotel.
// Each row of the file represents a floor in the hotel. You do not know ahead of time how many floors there are in the hotel.
// Each room is represented by a single digit: 1 (the room is occupied) or 0 (the room is not occupied).
// Because each floor can have a different number of rooms, the value -1 is used to indicate that the end of data for that floor has been reached.
// The function must print the header of the table followed by the floor number, the number of rooms occupied in that floor, and the occupancy
// rate (percentage of rooms occupied) for that floor. Below this information it must display the 
// overall occupancy rate (total number of occupied rooms/total number of rooms) for the whole hotel.
// The rates must be displayed real numbers with a single decimal digit.
void print_occupancy (std::ifstream & in_file) {
	int total_rooms = 0, total_occupied_rooms = 0;

	int floor_number = 1, floor_rooms = 0, floor_occupied_rooms = 0;

	double floor_occupancy_rate = 0.0, overall_occupancy_rate = 0.0;

	// Print the header of the table
	std::cout << std::setw(7) << "Floor |"
			  << std::setw(10) << "Occupied"
			  << std::setw(12) << "Rate (%)\n"
			  << "----------------------------\n";
	std::cout << std::fixed << std::setprecision(1);

	while (!in_file.eof()) {
		int rm; // Current room
		
		// Read the rooms in the floor until a -1 is found
		do {
			// Read room from file
			in_file >> rm;

			if (rm != -1) {
				// Found another room, so add to the current floor room count
				++floor_rooms;

				// Found an occupied room, so add to the floor's occupied room count
				if (rm == 1) ++floor_occupied_rooms;				
			}
		} while (rm != -1);

		// Calculate the occupancy rate for the floor
		floor_occupancy_rate = calc_occupancy_rate(floor_occupied_rooms, floor_rooms);

		// Accumulate the total number of rooms and occupied rooms
		total_rooms += floor_rooms;
		total_occupied_rooms += floor_occupied_rooms;

		// Print the floor information
		std::cout << std::setw(5) << floor_number
				  << std::setw(12) << floor_occupied_rooms
				  << std::setw(9) <<  floor_occupancy_rate << "%\n";

 		// Increment the floor number
		++floor_number;

		// Reset the floor room information
		floor_rooms = 0;
		floor_occupied_rooms = 0;
	}

	// Calculate the overall occupancy rate from accumulated totals
	overall_occupancy_rate = calc_occupancy_rate(total_occupied_rooms, total_rooms);

	std::cout << "----------------------------\n";
	std::cout << "The overall occupancy rate is " << overall_occupancy_rate << "%.\n";
}