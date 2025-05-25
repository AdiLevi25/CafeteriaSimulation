#include <iostream>
#include "Student.h"

// Default constructor - initializes id and arrivalTime to 0
Student::Student() {
    id = 0;
    arrivalTime = 0;
}

// Constructor - sets id and arrivalTime to given values
Student::Student(int id, int arrivalTime) {
    this->id = id;
    this->arrivalTime = arrivalTime;
}

// Getter for student ID
int Student::getId() const {
    return id;
}

// Getter for student arrival time
int Student::getArrivalTime() const {
    return arrivalTime;
}

// Print student details
void Student::print() const {
    std::cout << "Student ID: " << id << ", Arrival Time: " << arrivalTime << std::endl;
}
