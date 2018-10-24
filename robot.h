//header file
//function declarations

//include guard
#ifndef ROBOT_H
#define ROBOT_H

//include dependencies
#include <iostream>
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
	double get_speed() const;
	std::string get_message() const;
	char get_grade() const;

	/*----mutator functions----*/
	void set_ID(long);
	void set_speed(double);
	void set_message(std::string);
	void set_grade(char);

	//calculate robot utilization method
	//does not change members
	float calculate_utilization(int, int);

//members: class member variables 
//private access modifier
private:
	long robot_ID;
	double robot_speed;
	std::string robot_message;
	char robot_grade;
};

#endif // ROBOT_H
