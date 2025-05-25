#include "CafeteriaQueue.h"
#include <iostream>

// Add student to the queue
void CafeteriaQueue::addStudent(const Student& s) {
    queue.enqueue(s);
}

// Check if there are students in the queue
bool CafeteriaQueue::hasStudents() const {
    return !queue.isEmpty();
}

// Check if any students have been served
bool CafeteriaQueue::hasServedStudents() const {
    return totalServed() > 0;
}

// Remove student from queue and calculate wait time
Student CafeteriaQueue::serveStudent(int currentTime) {
    if (!hasStudents()) {
        return Student(); // Return default student if the queue is empty
    }

    Student student = queue.dequeue();  // Get the student at the front
    int waitTime = currentTime - student.getArrivalTime();  // Calculate wait time
    waitTimes.push_back(waitTime); // Store the wait time

    return student;
}

// Return the number of students who were served
int CafeteriaQueue::totalServed() const {
    return waitTimes.size();
}

// Return average wait time
double CafeteriaQueue::averageWaitTime() const {
    if (!hasServedStudents()) {
        return 0;
    }

    int totalTime = 0;
    int totalStudents = totalServed(); //number of students who were served

    // Sum all individual wait times
    for (int i = 0; i < totalStudents; i++) {
        totalTime += waitTimes[i];
    }

    return totalTime / (double)totalStudents; // Return average wait time
}

// Return maximum wait time
int CafeteriaQueue::maxWaitTime() const {
    if (!hasServedStudents()) {
        return 0;
    }

    int totalStudents = totalServed();
    int maxTime = waitTimes[0];  // Initialize max with the first wait time

    // Find the maximum wait time
    for (int i = 1; i < totalStudents; i++) {
        if (waitTimes[i] > maxTime)
            maxTime = waitTimes[i];
    }

    return maxTime;
}

// Return the number of students still in the queue
int CafeteriaQueue::studentsLeftInQueue() const {
    return queue.size();
}


void CafeteriaQueue::printSummary() const {
    std::cout << "\n--- Simulation Results ---\n";
    std::cout << "Total served: " << totalServed() << std::endl;
    std::cout << "Average wait time: " << averageWaitTime() << " minutes" << std::endl;
    std::cout << "Maximum wait time: " << maxWaitTime() << " minutes" << std::endl;
    std::cout << "Students left in queue: " << studentsLeftInQueue() << std::endl;
}

