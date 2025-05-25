#ifndef _SIMULATION_H_
#define _SIMULATION_H_

#include "Student.h"
#include "CafeteriaQueue.h"

class Simulation {

    private:
        const int DURATION;    // Total simulation time
        int currentTime;           // Current time in the simulation
        int nextStudentId;        // ID of the next arriving student

        int serviceTimeLeft;      // Remaining service time for current student
        Student currentStudent;   // The student currently being served
        bool isServing = false;   // Is there a student being served
        CafeteriaQueue cafeteria; // The cafeteria queue

        // Private methods
        
        // Simulate a student's arrival
        bool studentArrives();

        // Generate a random service time between 2 and 5 seconds
        int generateServiceTime();

    public:
        Simulation();     // Constructor
        void run();      // Run the simulation
        


    
};

#endif   //_SIMULATION_H_
