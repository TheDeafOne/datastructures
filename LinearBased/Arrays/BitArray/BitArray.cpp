#include <iostream>
#include <cmath> // requires -lm
#include "BitArray.h"
using namespace std;

/**
 * @brief Construct a new Bit Array object
 * 
 * @param size size of array in ints
 */
BitArray::BitArray(size_t size) {
    if (size < 0) {
        throw "Negative array size";
    }
    array_size = ceil(size/32.0);
    // allocate memory for array of variable size
    array = (int*) calloc(size, sizeof(int)); 
}

/**
 * @brief Given an index, setBit finds the position in the integer array and set the bit accordingly
 * This can be shorted to:
 * array[k/32] |= 1 << (k%32)
 * However, for clarity's sake, the expanded version will be show instead
 * 
 * @param k index of bit to be set
 */
void BitArray::setBit(int k) {
    int ind = k / 32; // set ind to be the index of array in which this bit will go to
    int bit_ind = k % 32; // set bit_ind be the bit index within the integer found at array[ind]
    int bit = 1; // this is the bit to be set, currently at 000....0001
    bit = bit << bit_ind; // shift bit over to required index within an integer
    array[ind] = array[ind] | bit; // add the bit to the required array index
}

/**
 * @brief Given an index, clearBit finds the position in the integer array and clear the bit (set to 0) accordingly
 * This can be shorted to:
 * array[k/32] &= ~(1<<(K%32))
 * The expanded version is shown
 * 
 * @param k index of bit to be cleared
 */
void BitArray::clearBit(int k) {
    int ind = k / 32; // integer index in array
    int bit_ind = k % 32; // bit index in an integer
    int bit = 1;
    bit = bit << bit_ind; // shift bit over to the kth index
    bit = ~bit; // complement of bit
    array[ind] = array[ind] & bit; // set bit to - at the kth index
}

/**
 * @brief Given an index, testBit finds the position in the integer array, tests it, and returns a bool accordingly
 * This can be shorted to:
 * return (array[k/32] & (1 << (k%32))) != 0
 * 
 * @param k index of the bit to be tested
 * @return true if the bit is 1
 * @return false if the bit is 0
 */
bool BitArray::testBit(int k) {
    int ind = k / 32; // array index
    int bit_ind = k % 32; // bit index
    int bit = 1; // new bit
    bit = bit << bit_ind; // shift new bit to correct bit index
    return (array[ind] & bit) != 0; // check that bit != 0
}


