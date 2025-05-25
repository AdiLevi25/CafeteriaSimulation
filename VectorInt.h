#ifndef _VECTOR_INT_H_
#define _VECTOR_INT_H_

class VectorInt {

    private:
        int* data;          // Pointer to dynamically allocated array
        int capacity;       // Maximum number of elements the array can hold
        int length;         // Current number of elements in the array

        void resize(); // Private method: doubles the capacity

    public:
    // Constructor
        VectorInt();

    // Destructor
        ~VectorInt();

    // Add element to the end of the vector
        void push_back(int value);

    // Access element by index (read-only)
        int operator[](int index) const;

    // Return the current number of elements
        int size() const;

};

#endif		// _VECTOR_INT_H_