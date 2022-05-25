#include <iostream>
#include <math.h> // include -lm
#include "HashedArrayTree.h"
using namespace std;

HashedArrayTree::HashedArrayTree() {
    root_size = 2;
    leaf_index = 0;
    add_index = 0;
    array_size = 0;
    root_array = new int*[root_size](); 
    newLeaf();
}

void HashedArrayTree::add(int value) {
    int root_idx = add_index / root_size; // get root index
    int leaf_idx = add_index % root_size; // get leaf index

    root_array[root_idx][leaf_idx] = value;

    if (leaf_idx == root_size - 1) {
        newLeaf();
    }

    add_index++;
    if (add_index == root_size * root_size) {
        expand();
    }
}

int HashedArrayTree::get(int idx) {
    int root_idx = idx / root_size; // get root index
    int leaf_idx = idx % root_size; // get leaf index
    return root_array[root_idx][leaf_idx];
}

void HashedArrayTree::newLeaf() {
    root_array[leaf_index] = new int[root_size]();
    leaf_index++;
    array_size += root_size;
}

void HashedArrayTree::expand() {
    int old_root_size = root_size;
    root_size *= 2;
    leaf_index = 0;
    int** old_root_array = root_array;
    root_array = new int*[root_size]();
    newLeaf();
    int end_value = add_index;
    add_index = 0;

    cout << "root_size: " << root_size << endl;

    for (int i = 0; i < end_value; i++) {
        add(old_root_array[i / old_root_size][i % old_root_size]);
    }
}
