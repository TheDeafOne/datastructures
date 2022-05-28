#include <iostream>
#include "LinkedList.h"
using namespace std;

/**
 * @brief Construct a new Linked List object
 * 
 */
LinkedList::LinkedList() {
    list_size = 0;
    head = NULL;
    tail = NULL;
}

/**
 * @brief 
 * 
 * @param value 
 */
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

/**
 * @brief 
 * 
 * @param idx 
 * @return int 
 */
int LinkedList::get(int idx) {
    Node tmp = *head;
    for (int i = 0; i < idx; i++) {
        tmp = *(tmp.next);
    }
    return tmp.value;
}

int LinkedList::set(int idx, int value) {
    Node* tmp = head;
    for (int i = 0; i < idx; i++) {
        tmp = (*tmp).next;
    }
    int val = (*tmp).value;
    (*tmp).value = value;
    return val;
}

void LinkedList::insert(int idx, int value) {
    Node* tmp = head;
    if (idx == 0) {
        head = new Node();
        (*head).next =  tmp;
        (*head).value = value;
    } else {
        for (int i = 0; i < idx - 1; i++) {
            tmp = (*tmp).next;
            cout << "tmp value: " << (*tmp).value << endl;
        }
        Node* new_node = new Node();
        (*new_node).next = (*tmp).next;
        (*new_node).value = value;
        (*tmp).next = new_node;  
    }
    list_size++;
}

/**
 * @brief Construct a new Node object
 * 
 */
Node::Node() {
    next = NULL;
    value = 0;
}