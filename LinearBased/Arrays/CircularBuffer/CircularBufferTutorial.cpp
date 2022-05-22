#include <iostream>
#include "CircularBuffer.h"
using namespace std;

void printBuffer(CircularBuffer buffer) {
    cout << "[";
    // reading only 9 values so a comma isn't placed after the 10th 
    for (int i = 0; i < 9; i++){ 
        cout << buffer.read() << ", ";
    }
    cout << buffer.read() << "]" << endl;
}

int main() {
    CircularBuffer buffer(10);
    cout << "we can fill a buffer with the write function and print it using the read function:" << endl;
    for (int i = 0; i < 10; i++){
        buffer.write(i);
    }
    printBuffer(buffer);

    cout << "once we write another value to the buffer, the value at the first index of the buffer gets replaced with the new value:" << endl;
    buffer.write(420);
    printBuffer(buffer);
}

