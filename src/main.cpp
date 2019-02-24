#include <vector>
#include <ctime>

#include "robot.h"
#include "mission_scheduler.h"

//using namespace std;

const std::string missions_inpath = "C:/Users/jyang/source/repos/system/system/missions.csv";
const std::string missions_outpath = " ";

/*----function declarations (prototypes)----*/

void fill_fleet_vector(std::vector<robot>& fleet, int number_of_robots);

void print_fleet_vector(const std::vector<robot>& fleet, int number_of_robots, int optimal_fleet_size);

int calculate_optimal_fleet_size(int minimum_fleet_size, int system_capacity);

float calculate_fleet_utilization(int number_of_robots, int optimal_fleet_size);

int main(int argc, char* argv[]) {

	schedule mission_schedule;

	std::ifstream missions_infile(missions_inpath);

	mission_schedule.load_missions(missions_infile);

	mission_schedule.print_schedule();
	mission_schedule.reverse_schedule();
	mission_schedule.print_schedule();

	int number_of_robots, optimal_fleet_size, system_capacity, minimum_fleet_size;
	float fleet_utilization;

	std::vector<robot> fleet;

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
