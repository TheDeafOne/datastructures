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
 */
void DynamicArray::set(int idx, int value) {
    if (idx > add_index) {
        throw invalid_argument("index out of bounds");
    }
    array[idx] = value;
}

/**
 * @brief adds a given value to the end of the array
 * 
 * @param value int value to be added to the array
 */
void DynamicArray::add(int value) {
    array[add_index++] = value;
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
    if (idx > add_index) {
        throw invalid_argument("index out of bounds");
    } else if (idx == array_size - 1) {
        expand();
    }
    for (int i = idx; i < add_index; i++) {
        int tmp = array[i];
        array[i] = value;
        value = tmp;
    }
    add_index++;
}

 /**
 * @brief removes a value from an array given an index
 * 
 * @param idx index to remove value at
 * @return int value that was removed
 */
int DynamicArray::remove(int idx) {
    if (idx > add_index) {
        throw invalid_argument("index out of bounds");
    }
    int tmp = array[idx];
    for (int i = idx; i < add_index; i++) {
        array[i] = array[i+1];
    }
    add_index--;
    return tmp;
}

/**
 * @brief expand array based on GROWTH_FACTOR once the end of the current array is reached
 * this is for easier and faster memory access
 * 
 */
void DynamicArray::expand() {
    array_size = array_size * GROWTH_FACTOR;
    int* new_array = new int[array_size]();
    for (int i = 0; i < add_index; i++) {
        new_array[i] = array[i];
    }
    array = new_array;
}

