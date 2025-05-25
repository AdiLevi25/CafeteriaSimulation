#include "Simulation.h"
#include <cstdlib>  // for std::rand
#include <iostream>



// Constructor
Simulation::Simulation()
    : DURATION(60) {             // Simulation duration 60 seconds

    currentTime = 0;            // Initialize simulation clock to 0
    nextStudentId = 1;         // ID to assign to the next arriving student
    serviceTimeLeft = 0;       // No service in progress initially
    isServing = false;         // No student is currently being served
}


// Run the simulation
void Simulation::run() {
    std::cout << "- - - Cafeteria Simulation - - -\n" << std::endl;
    
    for (currentTime = 0; currentTime < DURATION; currentTime++) {

        // Check if a student is currently being served
        if (isServing) {
            serviceTimeLeft--; //decrement remaining service time
            if (serviceTimeLeft == 0) {
                // Finished serving current student
                std::cout << "Time " << currentTime << 
                    ": Finished serving student #"
                    << currentStudent.getId() << "." << std::endl;
                isServing = false;
            }
        }

        // Check if a new student arrives
        if (studentArrives()) {
            // Assign ID and arrival time
            Student newStudent(nextStudentId++, currentTime); 
            cafeteria.addStudent(newStudent);   // Add to cafeteria queue

            std::cout << "Time " << currentTime << ": Student #"
                << newStudent.getId() << " joined queue." << std::endl;
        }

        // Start serving a new student if no one is being
        //served and the queue is not empty
        if (!isServing && cafeteria.hasStudents()) {
            // Get next student
            currentStudent = cafeteria.serveStudent(currentTime); 
            serviceTimeLeft = generateServiceTime();  // random service time

            isServing = true;  // Mark that a student is now being served

            std::cout << "Time " << currentTime << 
                ": Started serving student #"
                << currentStudent.getId() << " (service: "
                << serviceTimeLeft << " minutes)." << std::endl;
        }
    }
    
    // Print summary statistics at the end of the simulation
    cafeteria.printSummary();

}



bool Simulation::studentArrives() {
    int chance = std::rand() % 100; // Generate random number between 0 and 99
    return (chance < 30);          // 30% chance that a student arrives
}

// Generate random service time (2 - 5)
int Simulation::generateServiceTime() {
    return (std::rand() % 4) + 2; 
}



