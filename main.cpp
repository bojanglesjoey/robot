#include <iostream>
#include <string>
#include <vector>

#include "robot.h"

//namespace: groups of identifiers
//using namespace std;

/*----function declarations (prototypes)----*/

//pass in vector argument by reference
//note: vectors take up large amounts of memory
//rather than creating duplicates of the same vector through passing in by value, pass vector in by reference instead to access the original vector
void fill_fleet_vector(std::vector<robot>&, int);
//fills fleet vector with robot class type objects
//@param1 vector<robot>& - robots of fleet
//@param2 int - number of robots to deploy
//@return - none

//pass in vector argument by reference
void print_fleet_vector(const std::vector<robot>&, int, int);
//prints robots of fleet
//@param1 int - number of robots in system
//@param2 int - maximum number of robots allowed in system
//@return - none

int main() {
	int number_of_robots, system_capacity;

	//initialize vector of robot class type to store fleet of robot objects
	std::vector<robot> fleet;

	std::cout << "Enter maximum number robots allowed in system: ";
	std::cin >> system_capacity;
	std::cout << std::endl;

	std::cout << "Enter number of robots to deploy: ";
	std::cin >> number_of_robots;
	std::cout << std::endl;

	//deploy robot fleet
	fill_fleet_vector(fleet, number_of_robots);

	//print robot fleet
	print_fleet_vector(fleet, number_of_robots, system_capacity);

	return 0;
}

/*----function definitions----*/

void fill_fleet_vector(std::vector<robot>& fleet, int number_of_robots) {
	int i;
	long id;
	double speed;
	std::string message;
	char grade;

	for (i = 0; i < number_of_robots; i++) {
		std::cout << "Enter robot ID: ";
		std::cin >> id;
		std::cout << "Enter robot speed: ";
		std::cin >> speed;
		std::cout << "Enter robot message: ";
		std::cin >> message;
		std::cout << "Enter robot grade: ";
		std::cin >> grade;

		//create robot object
		robot new_robot(id, speed, message, grade);

		//add robot object to fleet vector
		fleet.push_back(new_robot);

		std::cout << std::endl;
	}
}

void print_fleet_vector(const std::vector<robot>& fleet, int number_of_robots, int system_capacity) {
	int i;
	int fleet_size = fleet.size();

	for (i = 0; i < fleet_size; i++) {
		std::cout << "Robot ID: " << fleet[i].get_ID() << std::endl;
		std::cout << "Robot speed: " << fleet[i].get_speed() << std::endl;
		std::cout << "Robot message: " << fleet[i].get_message() << std::endl;
		std::cout << "Robot grade: " << fleet[i].get_grade() << std::endl;
		std::cout << "Robot fleet utilization: " << fleet[i].calculate_utilization(number_of_robots, system_capacity) << std::endl;
		std::cout << std::endl;
	}
}
