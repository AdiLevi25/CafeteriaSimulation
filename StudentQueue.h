#ifndef _STUDENT_QUEUE_H_
#define _STUDENT_QUEUE_H_

#include "Student.h"

class StudentQueue {

    private:
        Student* data;      // Pointer to dynamically allocated array of Students
        int capacity;       // Maximum number of students the queue can hold
        int front;          // Index of the front of the queue
        int rear;           // Index of the rear of the queue
        int count;          // Current number of students in the queue

    public:
    // Constructor (default capacity 100)
        StudentQueue(int cap = 100);

    // Destructor
        ~StudentQueue();

    // Add student to the queue
        void enqueue(const Student& s);

    // Remove and return student from the queue
        Student dequeue();

    // Check if the queue is empty
        bool isEmpty() const;

    // Return the number of students in the queue
        int size() const;
};

#endif  // _STUDENT_QUEUE_H_

