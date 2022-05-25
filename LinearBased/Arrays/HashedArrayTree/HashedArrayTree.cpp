#include <iostream>
#include <math.h> // include -lm
#include "HashedArrayTree.h"
using namespace std;

/**
 * @brief Construct a new Hashed Array Tree object and initialize all variables necessary
 * 
 */
HashedArrayTree::HashedArrayTree() {
    // initialize variables
    root_size = 2;
    leaf_index = 0;
    add_index = 0;
    root_array = new int*[root_size](); 
    newLeaf();
}

/**
 * @brief add a given value to the next empty point in the array
 * 
 * @param value to be added to the array
 */
void HashedArrayTree::add(int value) {
    int root_idx = add_index / root_size; // get root index
    int leaf_idx = add_index % root_size; // get leaf index

    root_array[root_idx][leaf_idx] = value; // add value to array

    // check if add_index has reached the end of allocated memory, and expand as necessary
    // check if add_index has reached the end of a leaf, and add a new leaf as necessary
    add_index++;
    if (add_index == root_size * root_size) {
        expand();
    } else if (leaf_idx == root_size - 1) {
        newLeaf();
    }
}

/**
 * @brief get a value from the array using the given index
 * 
 * @param idx the given index at which to find the value
 * @return int the value found in the array at idx
 */
int HashedArrayTree::get(int idx) {
    int root_idx = idx / root_size; // get root index
    int leaf_idx = idx % root_size; // get leaf index
    return root_array[root_idx][leaf_idx]; 
}

/**
 * @brief set the old value at the given index in the array to the new given value
 * 
 * @param idx index at which to change the value
 * @param value new value to replace the old one
 * @return int old value that was replaced
 */
int HashedArrayTree::set(int idx, int value) {
    int root_idx = idx / root_size; // get root index
    int leaf_idx = idx % root_size; // get leaf index
    int tmp = root_array[root_idx][leaf_idx];
    root_array[root_idx][leaf_idx] = value; 
    return tmp;
}

/**
 * @brief insert the given value at the given index
 * 
 * @param idx index at which to insert the given value
 * @param value being inserted
 */
void HashedArrayTree::insert(int idx, int value) {
    int tmp = root_array[idx / root_size][idx % root_size]; // store value at given index 
    int end_index = add_index; // get old add_index value to stop loop at
    add_index = idx; 

    // copy previous value to the next one over
    for (int i = add_index; i <= end_index; i++) {
        set(i, value); // use set instead of add so no checks have to be done for adding leafs or expansion
        add_index++; // manually handle add_index incrementation
        value = tmp; // set new value with tmp
        tmp = root_array[(i+1) / root_size][(i+1) % root_size]; // find next tmp value in array
    }
}

/**
 * @brief remove the value at the given index
 * 
 * @param idx index in the array at which the value should be removed
 * @return int value being removed
 */
int HashedArrayTree::remove(int idx) {
    int value = root_array[idx / root_size][idx % root_size]; // get value being removed
    int end_index = add_index; // get old add_index value to stop loop at
    add_index = idx; 

    // copy next value onto the current index, implicitly removing the value at the given index
    for (int i = add_index; i < end_index; i++) {
        int next_val = root_array[(i+1) / root_size][(i+1) % root_size]; // get the next value
        set(i, next_val); // use set instead of add so no checks have to be done for adding leafs or expansion
        add_index++; // manually handle add_index incrementation
    }
    return value;
}

/**
 * @brief make a new leaf array and set the next open spot in the root array the new leaf array
 * 
 */
void HashedArrayTree::newLeaf() {
    root_array[leaf_index] = new int[root_size](); // make a new leaf
    leaf_index++; // increment leaf index to maintain position of the next leaf
}

/**
 * @brief multiply the size of the root array and leaf arrays by 2.
 * make a new root array and copy the information from the old array to the new array
 * 
 */
void HashedArrayTree::expand() {
    int old_root_size = root_size; // keep old root size for indexing the HAT
    int end_index = add_index; // get end point to stop copying old array to new array
    root_size *= 2; // *2 to maintain 2^n requirements of HAT (this could be some other number)
    add_index = 0; // prep add index for copying old array to new array
    leaf_index = 0; // prep leaf index

    // swap the old array out for a new array
    int** old_root_array = root_array;
    root_array = new int*[root_size]();
    newLeaf();
    
    // copy data from old array to the new array
    for (int i = 0; i < end_index; i++) {
        add(old_root_array[i / old_root_size][i % old_root_size]); // use same indexing as add
    }
}
