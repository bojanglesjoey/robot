/*
	File: mission_scheduler.cpp

	Author: Joey Yang

	Description: mission scheduler class file; contains function definitions.
	Implementation of a mission schedule using a linked list.
	Contains all fundemental functions of a linked list; however, for the purpose of this project, only FIFO queue functions will be used.
*/

#include "mission_scheduler.h"

schedule::schedule() {
	head = nullptr;
	tail = nullptr;
}

/* rule of 3*/
schedule::schedule(const schedule& other_schedule) {
	if (other_schedule.head == nullptr) {
		head == nullptr;
	}
}

schedule& schedule::operator=(const schedule& other_schedule) {
	return;
}	

schedule::~schedule() {
	mission* current = head;
	while (current != nullptr) {
		head = head->next;
		delete current;
		current = head;
	}
}

/* methods */
bool schedule::schedule_empty() const {
	return head == nullptr;
}

int schedule::get_schedule_size() const {
	if (schedule_empty()) {
		return 0;
	}
	else {
		mission* current = head;
		int queue_size = 0;
		while (current != nullptr) {
			current = current->next;
			queue_size++;
		}
		return queue_size;
	}
}

void schedule::append_new_mission(const int ID, const double distance) {
	mission* current = new mission(ID, distance);

	if (schedule_empty()) {
		std::cout << "Adding first mission to empty mission schedule: " << "mission ID: " << current->ID << " & mission distance: " << current->distance << std::endl;
		head = current;
		tail = current;
	}
	else {
		std::cout << "Adding new mission to end of mission schedule: " << "mission ID: " << current->ID << " & mission distance: " << current->distance << std::endl;
		tail->next = current;
		tail = tail->next;
	}
}

void schedule::prepend_new_mission(const int ID, const double distance) {
	mission* current = new mission(ID, distance);

	if (schedule_empty()) {
		std::cout << "Adding first mission to empty mission schedule: " << "mission ID: " << current->ID << " & mission distance: " << current->distance << std::endl;
		head = current;
		tail = current;
	}
	else {
		std::cout << "Adding new mission to beginning of mission schedule: " << "mission ID: " << current->ID << " & mission distance: " << current->distance << std::endl;
		current->next = head;
		head = current;
	}
}

void schedule::insert_new_mission(const int ID, const double distance, int insert_position) {
	if (insert_position == 1) {
		prepend_new_mission(ID, distance);
	}
	else if (insert_position == get_schedule_size() + 1) {
		append_new_mission(ID, distance);
	}
	else if (insert_position > get_schedule_size() + 1) {
		std::cout << "Error: the position to insert the new mission is invalid." << std::endl;
	}
	else {
		mission* current = new mission(ID, distance);
		mission* trail = head;
		for (int current_position = 1; current_position < insert_position - 1; current_position++) {
			trail = trail->next;
		}
		std::cout << "Inserting new mission to mission schedule: " << "mission ID: " << current->ID << " & mission distance: " << current->distance << "at position: " << insert_position << std::endl;
		current->next = trail->next;
		trail->next = current;
	}
}

void schedule::remove_completed_mission(const int ID) {
	if (schedule_empty()) {
		std::cout << "Error: the mission schedule is empty; there are no missions to remove." << std::endl;
	}
	else {
		if (head->ID == ID) {
			std::cout << "Removing completed mission from beginning of mission schedule: " << "mission ID: " << head->ID << " & mission distance: " << head->distance << std::endl;
			mission* current = head;
			head = head->next;
			delete current;
		}
		else if (tail->ID == ID) {
			std::cout << "Removing completed mission from end of mission schedule: " << "mission ID: " << tail->ID << " & mission distance: " << tail->distance << std::endl;
			mission* current = head;
			while (current->next != tail) {
				current = current->next;
			}
			tail = current;
			tail->next = nullptr;
			current = current->next;
			delete current;
		}
		else {
			mission* current = head->next;
			mission* trail = head;
			while (current != nullptr) {
				if (current->ID == ID) {
					std::cout << "Removing completed mission from mission schedule: " << "mission ID: " << current->ID << " & mission distance: " << current->distance << std::endl;
					trail->next = current->next;
					current->next = nullptr;
					delete current;
					return;
				}
				else {
					trail = current;
					current = current->next;
				}
			}
			std::cout << "Error: could not find completed mission in mission schedule." << std::endl;
		}
	}
}

void schedule::print_schedule() const {
	if (schedule_empty()) {
		std::cout << "The mission schedule is empty." << std::endl;
	}
	else {
		mission* current = head;

		std::cout << "Displaying current mission schedule: " << std::endl;

		while (current != nullptr) {
			std::cout << "mission ID: " << current->ID << " & mission distance: " << current->distance << std::endl;
			current = current->next;
		}
		std::cout << "End of mission schedule." << std::endl;
	}
}

void schedule::load_missions(std::ifstream& missions_infile) {
	if (!missions_infile.is_open()) {
		std::cout << "Error: failed to open csv file containing missions to load." << std::endl;
	}
	else {
		std::string line;
		std::string field_ID;
		std::string field_distance;
		while (std::getline(missions_infile, field_ID, ',')) {
			std::getline(missions_infile, field_distance);
			try {
				append_new_mission(stoi(field_ID), stod(field_distance));
			}
			catch (const std::invalid_argument& ex) {
				std::cout << "Error: the mission ID or mission distance is invalid and could not be converted into a number." << std::endl;
			}
			catch (const std::out_of_range& ex) {
				std::cout << "Error: the mission ID or mission distance is out of range." << std::endl;
			}
		}
	}
}
