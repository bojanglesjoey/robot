#ifndef MISSION_H
#define MISSION_H

class schedule {
public:
    schedule();
    bool queue_empty();
    void append_mission(int mission_ID, double distance);
    //void complete_mission(int mission_ID);
    void print_schedule() const;
    ~schedule();

private:
    struct mission {
        int mission_ID;
        double distance;
        mission* next;
    };

    mission *head;
    mission *tail;

};

#endif // MISSION_H
