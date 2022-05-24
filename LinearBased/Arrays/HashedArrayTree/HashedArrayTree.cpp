#include <iostream>
#include <math.h> // include -lm
#include "HashedArrayTree.h"
using namespace std;

HashedArrayTree::HashedArrayTree() {
    power = 0;
    leaf_size = 1;
    leaf_index = 0;
    root_array = new int*[power](); 
    newLeaf(root_array);
}

int HashedArrayTree::get(int idx) {
    int root_index = add_index / power; // get root index
    int leaf_index = add_index % power; // get leaf index
    return root_array[root_index][leaf_index];
}

void HashedArrayTree::add(int value) {
    int root_index = add_index / power; // get root index
    int leaf_index = add_index % power; // get leaf index
    root_array[root_index][leaf_index] = value;
    add_index++;
    if (add_index == pow(2,power)) {
        expand();
    }
}

void HashedArrayTree::newLeaf(int** array, int* array_values = {}, int array_size = 0) {
    array[leaf_index] = new int[power]();
    for (int i = 0; i < array_size; i++) {
        array[leaf_index][i] = array_values[i];
    }
    leaf_index++;
}

void HashedArrayTree::expand() {
    power++;
    int end_index = leaf_index/2;
    leaf_index = 0;
    int** new_root_array = new int*[leaf_size]();
    for (int i = 0; i < end_index; i++) {
        newLeaf(new_root_array, root_array[i], leaf_size);
    }
    leaf_size *= 2;
}
