#include <iostream>
#include <cstdlib>   // for std::rand
#include <ctime>     // for time()

#include "Student.h"
#include "VectorInt.h"
#include "StudentQueue.h"
#include "CafeteriaQueue.h"
#include "Simulation.h"

// ---- Test 1 - Student class ---- //
void testStudentClass() {
    std::cout << "\n=== Testing Student class ===\n" << std::endl;

    // default constructor
    Student s1;
    s1.print();  // Student ID: 0, Arrival Time: 0

    // specific values
    Student s2(123, 15);
    s2.print();  // Student ID: 123, Arrival Time: 15

    // Test getter methods
    std::cout << "Student 2 ID: " << s2.getId() << std::endl;
    std::cout << "Student 2 Arrival Time: " << s2.getArrivalTime() << std::endl;

    std::cout << "\n=== Student test passed successfully ===\n" << std::endl;
}

// ---- Test 2 - VectorInt class ---- //
void testVectorInt() {
    std::cout << "\n=== Testing VectorInt ===\n" << std::endl;

    VectorInt vec;

    // Add values 1 to 10
    for (int i = 1; i <= 10; i++) {
        vec.push_back(i);
        std::cout << "Added: " << i << ", Size: " << vec.size() << std::endl;
    }

    // Check values
    std::cout << "Stored values: ";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // Test out-of-bounds access
    std::cout << "Accessing invalid index (-1): " << vec[-1] << std::endl;
    std::cout << "Accessing invalid index (100): " << vec[100] << std::endl;

    std::cout << "\n=== VectorInt test passed successfully ===\n" << std::endl;
}

// ---- Test 3 - StudentQueue class ---- //
void testStudentQueue() {
    std::cout << "=== Testing StudentQueue ===\n" << std::endl;

    StudentQueue queue(3);  // Create queue with capacity 3

    // Create and enqueue 5 students, test circular behavior
    for (int i = 1; i <= 5; i++) {
        Student s(i, i * 10);  // id = i, arrivalTime = i * 10
        queue.enqueue(s);      // Enqueue student into the queue
        std::cout << "Enqueued Student ID: " << s.getId()
            << ", Arrival: " << s.getArrivalTime()
            << ", Queue Size: " << queue.size() << std::endl;
    }

    std::cout << "\nDequeuing students:\n";

    // Dequeue all students and print their data
    while (!queue.isEmpty()) {
        Student s = queue.dequeue();  // Remove from queue
        std::cout << "Dequeued Student ID: " << s.getId()
            << ", Arrival: " << s.getArrivalTime()
            << ", Remaining: " << queue.size() << std::endl;
    }

    std::cout << "\n=== StudentQueue test passed successfully ===\n" << std::endl;
}

// ---- Test 4 - CafeteriaQueue class ---- //
void testCafeteriaQueue() {
    std::cout << "\n=== Testing CafeteriaQueue ===\n" << std::endl;

    CafeteriaQueue cq;  // Create cafeteria queue

    // Initial check - should be empty
    std::cout << "Initial state - students in queue? "
        << (cq.hasStudents() ? "Yes" : "No") << std::endl;
    std::cout << "Trying to serve from empty queue..." << std::endl;

    Student emptyStudent = cq.serveStudent(0);  // Serve when queue is empty
    std::cout << "Served Student ID: " << emptyStudent.getId()
        << ", Arrival Time: " << emptyStudent.getArrivalTime() << std::endl;

    // Add students to the queue
    cq.addStudent(Student(5, 5));    // First student
    cq.addStudent(Student(1, 10));   // Second student
    cq.addStudent(Student(3, 15));   // Third student

    std::cout << "\nTotal in queue: " << cq.studentsLeftInQueue() << std::endl;

    // Serve all students at time 20 - example
    std::cout << "\nServing students...\n" << std::endl;
    while (cq.hasStudents()) {
        Student s = cq.serveStudent(20);  // Serve next student
        std::cout << "Served Student ID: " << s.getId()
            << ", Wait Time: " << (20 - s.getArrivalTime()) << std::endl;
    }

    // Final statistics
    cq.printSummary();  // Print statistics using the new summary function

    std::cout << "\n=== CafeteriaQueue test passed successfully ===\n" << std::endl;
}



int main() {

    {
        // Run selected test functions or the full simulation
        /*
        testStudentClass();
        testVectorInt();
        testStudentQueue();
        testCafeteriaQueue();
        */

        std::srand(time(nullptr));  // Seed the random number generator
        Simulation sim;             // Initialize the simulation object
        sim.run();                  // Execute the simulation loop
    }

    // Detect memory leaks after simulation complete
    int leaks = _CrtDumpMemoryLeaks();
    std::cout << "\nMemory leaks detected: "
        << (leaks == 0 ? "None" : "Yes") << std::endl;

    return 0;
}
