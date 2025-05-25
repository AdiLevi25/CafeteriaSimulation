#ifndef _CAFETERIA_QUEUE_H_
#define _CAFETERIA_QUEUE_H_

#include "StudentQueue.h"
#include "VectorInt.h"

class CafeteriaQueue {

private:
    StudentQueue queue;        // The queue of students
    VectorInt waitTimes;       // Waiting times of served students

public:
    // Add student to the queue
    void addStudent(const Student& s);

    // Check if there are students in the queue
    bool hasStudents() const; //extra

    // Remove student from queue and calculate wait time
    Student serveStudent(int currentTime);

    // Return total number of students served
    int totalServed() const;

    // Return average wait time
    double averageWaitTime() const;

    // Return maximum wait time
    int maxWaitTime() const;

    // Return number of students left in the queue
    int studentsLeftInQueue() const;

    // Check if any students have been served
    bool hasServedStudents() const;

    // Print summary statistics for the cafeteria queue
    void printSummary() const;

};

#endif    //_CAFETERIA_QUEUE_H_
