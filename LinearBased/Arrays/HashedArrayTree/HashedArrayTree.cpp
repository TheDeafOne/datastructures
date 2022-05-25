#include <iostream>
#include <math.h> // include -lm
#include "HashedArrayTree.h"
using namespace std;

HashedArrayTree::HashedArrayTree() {
    // initialize values
    root_size = 2;
    leaf_index = 0;
    add_index = 0;
    root_array = new int*[root_size](); 
    newLeaf();
}

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

int HashedArrayTree::get(int idx) {
    int root_idx = idx / root_size; // get root index
    int leaf_idx = idx % root_size; // get leaf index
    return root_array[root_idx][leaf_idx]; 
}

void HashedArrayTree::newLeaf() {
    root_array[leaf_index] = new int[root_size](); // make a new leaf
    leaf_index++; // increment leaf index to maintain position of the next leaf
}

void HashedArrayTree::expand() {
    int old_root_size = root_size; // keep old root size for indexing the HAT
    int end_value = add_index; // get end point to stop copying old array to new array
    root_size *= 2; // *2 to maintain 2^n requirements of HAT (this could be some other number)
    add_index = 0; // prep add index for copying old array to new array
    leaf_index = 0; // prep leaf index

    // swap the old array out for a new array
    int** old_root_array = root_array;
    root_array = new int*[root_size]();
    newLeaf();
    
    // copy data from old array to the new array
    for (int i = 0; i < end_value; i++) {
        add(old_root_array[i / old_root_size][i % old_root_size]); // use same indexing as add
    }
}
