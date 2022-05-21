#include <iostream>
#include "DynamicArray.h"
using namespace std;

DynamicArray::DynamicArray() {
    array_size = 2;
    add_index = 0;
    array = new int[array_size]();
}

int DynamicArray::get(int idx) {
    if (idx > add_index || add_index == 0) {
        throw invalid_argument("index out of bounds");
    }
    return array[idx];
}

void DynamicArray::set(int idx, int value) {
    if (idx > add_index) {
        throw invalid_argument("index out of bounds");
    }
    array[idx] = value;
}

void DynamicArray::add(int value) {
    array[add_index++] = value;
    if (add_index == array_size - 1) {
        expand();
    }
}

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

void DynamicArray::expand() {
    array_size = array_size * GROWTH_FACTOR;
    int* new_array = new int[array_size]();
    for (int i = 0; i < add_index; i++) {
        new_array[i] = array[i];
    }
    array = new_array;
}

