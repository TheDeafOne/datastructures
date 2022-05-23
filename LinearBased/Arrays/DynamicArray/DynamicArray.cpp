#include <iostream>
#include "DynamicArray.h"
using namespace std;

/**
 * @brief Construct a new Dynamic Array object
 * 
 */
DynamicArray::DynamicArray() {
    array_size = 2; // actual array size
    add_index = 0; // user array size
    array = new int[array_size]();
}

/**
 * @brief gets the value from the array at the given index
 * 
 * @param idx given index 
 * @return int value gotten from array at the given index
 */
int DynamicArray::get(int idx) {
    // check for out of bounds error
    if (idx > add_index || add_index == 0) {
        throw invalid_argument("index out of bounds");
    }

    return array[idx];
}

/**
 * @brief sets the value at the given index in the array to the given value
 * 
 * @param idx given index
 * @param value int value to replace value in array
 * @return tmp int value being replaced
 */
int DynamicArray::set(int idx, int value) {
    // check for out of bounds error
    if (idx > add_index) {
        throw invalid_argument("index out of bounds");
    }
    int tmp = array[idx]; // get return value
    array[idx] = value; // set value
    return tmp;
}

/**
 * @brief adds a given value to the end of the array
 * 
 * @param value int value to be added to the array
 */
void DynamicArray::add(int value) {
    array[add_index++] = value; // set value and increment add_index

    // check index of add_index and expand accordingly
    if (add_index == array_size - 1) {
        expand();
    }
}

/**
 * @brief inserts a given value at a given index
 * 
 * @param idx index to place value
 * @param value int value to be added to the array
 */
void DynamicArray::insert(int idx, int value) {
    // check for out of bounds error
    if (idx > add_index) {
        throw invalid_argument("index out of bounds");
    }

    // check idx and expand array if necessary
    if (idx == array_size - 1) {
        expand();
    }

    // shift values to the right once and insert current value
    for (int i = idx; i < add_index; i++) {
        int tmp = array[i]; // hold current index
        array[i] = value; // set current index to current value
        value = tmp; // set new value to held index
    }

    add_index++; // increment add_index to maintain user aray
}

 /**
 * @brief removes a value from an array given an index
 * 
 * @param idx index to remove value at
 * @return int value that was removed
 */
int DynamicArray::remove(int idx) {
    // check for out of bounds eror
    if (idx > add_index) {
        throw invalid_argument("index out of bounds");
    }

    int tmp = array[idx];

    // shift values to the left, implicitly deleting the required value
    for (int i = idx; i < add_index; i++) {
        array[i] = array[i+1];
    }

    add_index--; // decrement add_index to maintain user array size
    return tmp; // return deleted value
}

/**
 * @brief expand array based on GROWTH_FACTOR once the end of the current array is reached
 * this is for easier and faster memory access
 * 
 */
void DynamicArray::expand() {
    array_size = array_size * GROWTH_FACTOR; // factor at which array is grown
    int* new_array = new int[array_size]();

    // copy old array to new array
    for (int i = 0; i < add_index; i++) {
        new_array[i] = array[i];
    }
    array = new_array;
}

