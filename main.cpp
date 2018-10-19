#include <iostream>
#include <string>

#include "robot.h"

//namespace: groups of identifiers
//using namespace std;

int main() {
	int number_of_robots, system_capacity;
	number_of_robots = 0;

	std::cout << "Enter maximum robot capacity of system: " << std::endl;
	std::cin >> system_capacity;

	std::cout << "Creating robot..." << std::endl;
	//create robot object Optimus Prime
	robot Optimus_Prime(0, 2.00, "Autobots, Roll Out!", 'A');
	number_of_robots++;

	std::cout << "Robot created." << std::endl <<
		"ID: " << Optimus_Prime.get_ID() << std::endl <<
		"Speed: " << Optimus_Prime.get_speed() << std::endl <<
		"Message: " << Optimus_Prime.get_message() << std::endl <<
		"Grade: " << Optimus_Prime.get_grade() << std::endl <<
		"Utilization: " << Optimus_Prime.calculate_utilization(number_of_robots, system_capacity) << "%" <<std::endl;

	std::cout << "System capacity: " << system_capacity << std::endl <<
		"Number of robots in system: " << number_of_robots << std::endl;
	
	return 0;
}