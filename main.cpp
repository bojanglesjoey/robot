#include <vector>
#include <ctime>

//Fnote: header file already includes iostream and string libraries
#include "robot.h"
#include "mission_scheduler.h"

//namespace: groups of identifiers
//using namespace std;

//mission log file paths
const std::string missions_inpath = "C:/Users/jyang/Documents/missions.csv";
const std::string missions_outpath = " ";

/*----function declarations (prototypes)----*/

//pass in vector argument by reference
//note: vectors take up large amounts of memory
//rather than creating duplicates of the same vector through passing in by value
//pass the vector in by reference instead to access the original vector
//this will also change the original vector passed in to be used later, without needing to return the changed vector
void fill_fleet_vector(std::vector<robot>&, int);
//fills the fleet vector with robot class type objects
//@param1 vector<robot>& - robots of fleet
//@param2 int - number of robots deployed
//@return - none

//pass in vector argument by const-reference
//this function will not change the original vector passed in, therefore use const
//passing in by reference is still required for vector for efficiency, compared to passing in by value
void print_fleet_vector(const std::vector<robot>&, int, int);
//prints robots of the fleet
//@param1 vector<robot>& - robots of fleet
//@param2 int - number of robots deployed
//@param3 int - optimal number of robots for system
//@return - none

int calculate_optimal_fleet_size(int, int);
//randomly calculates the optimal number of robots for the system
//based on the minimum number of robots allowed in system and the maximum number of robots allowed in system
//@param1 int - minimum number of robots allowed in system
//@param2 int - maximum number of robots allowed in system

float calculate_fleet_utilization(int, int);
//calculates new fleet utilization based on number of robots deployed and the optimal number of robots for system
//@param1 int - number of robots deployed
//@param2 int - optimal number of robots for system
//@return - none

int main(int argc, char* argv[]) {

	schedule mission_schedule;

	std::ifstream missions_infile(missions_inpath);

	mission_schedule.load_missions(missions_infile);

	mission_schedule.print_schedule();

	int number_of_robots, optimal_fleet_size, system_capacity, minimum_fleet_size;
	float fleet_utilization;

	//initialize vector of robot class type to store fleet of robot objects
	//vector fleet will need to be changed (appended with robot objects) by local functions
	//therefore, it must be passed in by reference to the local functions
	std::vector<robot> fleet;

	//the default value of the minimum fleet size
	minimum_fleet_size = 1;

	//seed the random number generator based on current time
	srand((unsigned int)time(NULL));

	std::cout << "Enter maximum number of robots allowed in system: ";
	std::cin >> system_capacity;

	std::cout << "Enter the number of robots to deploy: ";
	std::cin >> number_of_robots;

	//check to make sure number of robots does not exceed system capacity
	if (number_of_robots > system_capacity) {
		std::cout << "Error: number of robots to deploy exceeds the maximum number of robots allowed in system." << std::endl;
		//ends program (conditional statement must be in main function)
		return -1;
	}
	//check to make sure robots are actually deployed
	if (number_of_robots == 0) {
		std::cout << "Error: no robots to be deployed." << std::endl;
		return -1;
	}

	//generate optimal number of robots for system
	optimal_fleet_size = calculate_optimal_fleet_size(minimum_fleet_size, system_capacity);
	std::cout << "The optimal number of robots for the system is: " << optimal_fleet_size << std::endl;

	//deploy robot fleet
	fill_fleet_vector(fleet, number_of_robots);

	//print robot fleet
	print_fleet_vector(fleet, number_of_robots, optimal_fleet_size);

	//calculate fleet utilization
	fleet_utilization = calculate_fleet_utilization(number_of_robots, optimal_fleet_size);

	std::cout << "The overall fleet utilization is: " << fleet_utilization << "%" << std::endl;
	std::cout << std::endl;

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

void print_fleet_vector(const std::vector<robot>& fleet, int number_of_robots, int optimal_fleet_size) {
	int i;
	int fleet_size = fleet.size();

	if (fleet_size == 0) {
		std::cout << "There are no robots in the fleet." << std::endl;
	}

	else {
		for (i = 0; i < fleet_size; i++) {
			std::cout << "Robot ID: " << fleet[i].get_ID() << std::endl;
			std::cout << "Robot speed: " << fleet[i].get_speed() << std::endl;
			std::cout << "Robot message: " << fleet[i].get_message() << std::endl;
			std::cout << "Robot grade: " << fleet[i].get_grade() << std::endl;
			std::cout << "Robot fleet utilization: " << fleet[i].calculate_robot_utilization(number_of_robots, optimal_fleet_size) << "%" << std::endl;
			std::cout << std::endl;
		}
	}
}

int calculate_optimal_fleet_size(int minimum_fleet_size, int system_capacity) {
	return rand() % system_capacity + minimum_fleet_size;
}

float calculate_fleet_utilization(int number_of_robots, int optimal_fleet_size) {
	float fleet_utilization;

	if (number_of_robots <= optimal_fleet_size) {
		return fleet_utilization = 100;
	}

	else {
		return fleet_utilization = static_cast<float>(optimal_fleet_size) / static_cast<float>(number_of_robots) * 100;
	}
}
