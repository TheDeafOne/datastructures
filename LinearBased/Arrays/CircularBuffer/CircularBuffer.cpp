#include <iostream>
#include "CircularBuffer.h"
using namespace std;

/**
 * @brief Construct a new Circular Buffer object
 * 
 * @param size size of buffer
 */
CircularBuffer::CircularBuffer(size_t size) {
     if (size < 0) {
        throw "Negative array size";
    }
    buffer_size = size;
    // allocate memory for array of variable size
    buffer = (int*) calloc(size, sizeof(int)); 
}

void CircularBuffer::write(int value) {
    buffer[writer++] = value; // set position at writer index to value and increment writer
    writer %= buffer_size; // set writer to wrap around to first index once it reaches the end of the buffer
}

int CircularBuffer::read() {
    int value = buffer[reader++]; // get value in a temp variable and increment reader
    reader %= buffer_size; // set reader to wrap around to first index once it reaches the end of the buffer
    return value;
}