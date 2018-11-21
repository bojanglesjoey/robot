/*
	File: robot.h

	Author: Joey Yang
*/

//header file
/*----function declarations (prototypes)----*/

//guard
#ifndef ROBOT_H
#define ROBOT_H

#include <string>

class robot {
	//methods: class member functions
	//public access modifier
public:
	//default constructor
	robot();

	//overload constructor
	robot(long, double, std::string, char);

	//destructor
	~robot();

	/*----accessor functions----*/
	long get_ID() const;
	//gets ID of robot
	//@param - none
	//@return long - ID of robot

	double get_speed() const;
	//gets speed of robot
	//@param - none
	//@return double - speed of robot

	std::string get_message() const;
	//gets message of robot
	//@param - none
	//@return string - message of robot

	char get_grade() const;
	//gets grade of robot
	//@param - none
	//@return char - grade of robot

	/*----mutator functions----*/
	void set_ID(long);
	//sets ID of robot
	//@param long - ID of robot
	//@return - none

	void set_speed(double);
	//sets speed of robot
	//@param double - speed of robot
	//@return - none

	void set_message(std::string);
	//sets message of robot
	//@param string - message of robot
	//@return - none

	void set_grade(char);
	//sets grade of robot
	//@param char - grade of robot
	//@return - none

	float calculate_robot_utilization(int, int) const;
	//calculates utilization of robot and effectively the entire fleet
	//@param1 int - number of robots in system
	//@param2 int - maximum number of robots allowed in system
	//@return float - robot/fleet utilization

//members: class member variables 
//private access modifier
private:
	long robot_ID;
	double robot_speed;
	std::string robot_message;
	char robot_grade;
};

#endif // ROBOT_H
