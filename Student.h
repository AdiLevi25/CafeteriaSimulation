#ifndef _STUDENT_H_
#define _STUDENT_H_


class Student {
	private:
        int id;             // Student ID
        int arrivalTime;    // Time of arrival

	public:
        
        Student();// Default constructor
        Student(int id, int arrivalTime);// Constructor
        
        //methods
        int getId() const;// Getter for student ID
        int getArrivalTime() const; // Getter for arrival time
        void print() const;// Print student information
};

#endif		// _STUDENT_H_

