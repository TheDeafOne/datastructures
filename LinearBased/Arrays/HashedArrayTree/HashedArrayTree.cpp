#include <iostream>
#include <math.h> // include -lm
#include "HashedArrayTree.h"
using namespace std;

HashedArrayTree::HashedArrayTree() {
    power = 1;
    root_size = 2;
    leaf_index = 0;
    array_size = 0;
    add_index = 0;
    root_array = new int*[root_size](); 
    newLeaf();
}

void HashedArrayTree::add(int value) {
    int root_idx = add_index / root_size; // get root index
    int leaf_idx = add_index % root_size; // get leaf index

    root_array[root_idx][leaf_idx] = value;
    cout << "root idx: " << root_idx << endl;
    cout << "leaf idx: " << leaf_idx << endl;
    cout << "root size: " << root_size << endl;
    cout << "add index: " << add_index << endl;
    cout << "leaf index: " << leaf_index << endl;
    cout << endl;


    if (leaf_idx == root_size - 1) {
        cout << "adding leaf index\n";
        newLeaf();
    }

    add_index++;
    if (add_index == root_size * root_size) {
        cout << "expanding\n";
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
    power++;
    array_size = 0;
    leaf_index = 0;
    root_size *= 2;
    int** old_root_array = root_array;
    root_array = new int*[root_size]();
    newLeaf();
    int end_value = add_index;
    add_index = 0;

    cout << "root size: " << root_size << endl;
    cout << "end index: " << end_value << endl;
    cout << "power: " << power << endl;
    cout << "old_root_array[0]: " << old_root_array[0][0] << endl;
    cout << "old_root_array[1]: " << old_root_array[0][1] << endl;
    cout << "old_root_array[2]: " << old_root_array[1][0] << endl;
    cout << "old_root_array[3]: " << old_root_array[1][1] << endl;

    int root_idx;
    int leaf_idx;
    for (int i = 0; i < end_value; i++) {
        root_idx = i / root_size;
        leaf_idx = i % root_size;
        cout << "root_idx: " << root_idx << endl;
        cout << "leaf_idx: " << leaf_idx << endl;
        cout << endl;
        add(old_root_array[root_idx][leaf_idx]);
    }
}
