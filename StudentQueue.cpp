#include "StudentQueue.h"
#include <iostream>

// Constructor
StudentQueue::StudentQueue(int cap) {
	
	capacity = cap;
	data = new Student[cap]; // Allocate memory for student queue 
    count = 0;  // Initialize student count to 0
    front = 0;  // Initialize front index
    rear = 0;   // Initialize rear index

}

// Destructor
StudentQueue::~StudentQueue() {

	delete[] data; // Free dynamically allocated memory
	count = 0;     // No student in the queue 
	front = 0;     //  Reset ptr front 
	rear = 0;      // Reset ptr rear 
}

// Add student to the queue
void StudentQueue::enqueue(const Student& s) {
    // Resize if full
    if (count == capacity) {
        // Double the capacity (or set to 1 if 0)
        int newCapacity = (capacity == 0) ? 1 : capacity * 2;
        Student* newData = new Student[newCapacity]; // Allocate new array

        // Copy existing data in correct order
        for (int i = 0; i < count; i++) {
            newData[i] = data[(front + i) % capacity];
        }

        delete[] data;  // Free old memory
        data = newData; // Update pointer to new array
        capacity = newCapacity;
        front = 0;     // Reset front index
        rear = count;  // Rear becomes end of the copied data
    }
   
    // Insert new student
    data[rear] = s;  // Add the new student at rear
    rear = (rear + 1) % capacity; // Advance rear index (circularly)
    count++;
}

// Remove and return student from the queue
Student StudentQueue::dequeue() {
    if (isEmpty()) {
        return Student();  // Return default student if queue is empty
    }

    Student student = data[front];        // Get student at the front of the queue
    front = (front + 1) % capacity;       // Move front index forward (circularly)
    count--;                              // Decrease the number of students in the queue
    return student;                       // Return the dequeued student
}


// Check if the queue is empty
bool StudentQueue::isEmpty() const {

    if (count == 0) {
         // Optional debug print for testing purposes only
        //std::cout << "\nQueue is empty!" << std::endl;
        return true;  
    }

	return false;
}

// Return the number of students in the queue
int StudentQueue::size() const {

	return count;
}
