#include "VectorInt.h"
#include <iostream>


// Constructor
VectorInt::VectorInt() {
	data = nullptr;
	capacity = 0;
	length = 0;
}

// Destructor
VectorInt::~VectorInt() {

	// Free the dynamically allocated array
	delete[] data;  
}

// Add element to end
void VectorInt::push_back(int value) {

	if (length == capacity) {

		resize();  // Expand if full
	}
	// add the value
	data[length] = value;
	length++;
}

// Read-only access by index
int VectorInt::operator[](int index) const {

	if (index < 0 || index >= length) {
		// Optional debug print for testing purposes only
		std::cout << "Error: Index out of bounds" << std::endl;
		return -1; 
	}
	return data[index];

}

// Return number of elements
int VectorInt::size() const {

	return length;
}


// Private Methode : Double array capacity 
void VectorInt::resize() {

	int newCapacity = (capacity == 0) ? 1 : capacity * 2;

	// Allocate a new array with the new capacity
	int* newData = new int[newCapacity];

	// copy data 
	for (int i = 0; i < length; i++) {
		newData[i] = data[i];
	}

	// Free the old allocated array
	delete[] data;

	data = newData; // Update pointer to the new array
	capacity = newCapacity; // Update the capacity value

}
