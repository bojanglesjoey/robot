#include <cstdlib>
#include <iostream>

#include "mission.h"

schedule::schedule() {
    head = NULL;
    tail = NULL;
}

bool schedule::queue_empty() {
    return head = NULL;
}

//append new mission to end of schedule (FIFO queue)
void schedule::append_mission(int mission_ID, double distance) {
    mission *current = new mission();
    current->mission_ID = mission_ID;
    current->distance = distance;
    current->next = NULL;
    //if first node
    if (queue_empty()) {
        head = current;
        tail = current;
        return;
    }
    tail->next = current;
    tail = tail->next;
}

void schedule::print_schedule() const {
    mission *current = head;
    while (current != NULL) {
        std::cout << current->mission_ID << std::endl;
        current = current->next;
    }
    std::cout << "End of mission schedule." << std::endl;
}

schedule::~schedule() {

}
