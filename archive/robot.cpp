/*
	File: robot.cpp

	Author: Joey Yang
*/

//class file
/*----function definitions----*/

#include "robot.h"

//default constructor
robot::robot() {
	robot_ID = 0;
	robot_speed = 0.0;
	robot_message = "offline";
	robot_grade = 'F';
}

//overload constructor
robot::robot(long ID, double speed, std::string message, char grade) {
	robot_ID = ID;
	robot_speed = speed;
	robot_message = message;
	robot_grade = grade;
}

//destructor
robot::~robot() {

}

/*----accessor functions----*/
long robot::get_ID() const {
	return robot_ID;
}

double robot::get_speed() const {
	return robot_speed;
}

std::string robot::get_message() const {
	return robot_message;
}

char robot::get_grade() const {
	return robot_grade;
}

/*----mutator functions----*/
void robot::set_ID(long ID) {
	robot_ID = ID;
}

void robot::set_speed(double speed) {
	robot_speed = speed;
}

void robot::set_message(std::string message) {
	robot_message = message;
}

void robot::set_grade(char grade) {
	robot_grade = grade;
}

//calculate robot/fleet utilization method
float robot::calculate_robot_utilization(int number_of_robots, int system_capacity) const {
	if(number_of_robots <= system_capacity) {
		return(static_cast <float>(100));
	}

	else {
		return(static_cast<float>(system_capacity) / static_cast<float>(number_of_robots) * 100);
	}
}
