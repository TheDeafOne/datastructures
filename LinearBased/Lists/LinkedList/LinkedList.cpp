#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() {
    list_size = 0;
    head = NULL;
    tail = NULL;
}

void LinkedList::add(int value) {
    if (list_size == 0) {
        head = tail = new Node();
        (*head).value = value;
    } else {
        (*tail).next = new Node();
        tail = (*tail).next;
        (*tail).value = value;
    }

    list_size++;
}

int LinkedList::get(int idx) {
    Node tmp = *head;
    for (int i = 0; i < idx; i++) {
        tmp = *(tmp.next);
    }
    return tmp.value;
}

Node::Node() {
    next = NULL;
    value = 0;
}