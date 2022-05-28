#include <iostream>
#include "LinkedList.h"
using namespace std;


LinkedList::LinkedList() {
    list_size = 0;
    head = NULL;
    tail = NULL;
}

 /**
 * @brief get value from list using given index
 * 
 * @param idx index at which to get the node from the list
 * @return int value found in the array at given index
 */
int LinkedList::get(int idx) {
    Node* current_node = head;

    // cycle through list until required node is reached
    for (int i = 0; i < idx; i++) {
        current_node = (*current_node).next;
    }
    return (*current_node).value;
}

/**
 * @brief make a node with the given value and add it to the end of the list
 * 
 * @param value value to be added to the list
 */
void LinkedList::add(int value) {
    // handle the case where the list is empty
    if (list_size == 0) {
        head = tail = new Node(); 
        (*head).value = value;
    } else {
        (*tail).next = new Node();
        tail = (*tail).next; // move tail to next node
        (*tail).value = value;
    }

    list_size++;
}

/**
 * @brief set the node at the given index to the given value
 * 
 * @param idx index to set node value at
 * @param value value to be set
 * @return int value being replaced
 */
int LinkedList::set(int idx, int value) {
    Node* current_node = head;

    // cycle through list until the required node is found
    for (int i = 0; i < idx; i++) {
        current_node = (*current_node).next;
    }

    int val = (*current_node).value; // return value
    (*current_node).value = value; // set new value
    return val;
}

/**
 * @brief insert given value at the given index in the list
 * 
 * @param idx index at which the given value should be inserted
 * @param value to be inserted
 */
void LinkedList::insert(int idx, int value) {
    Node* current_node = head;
    if (idx == 0) {
        head = new Node();
        (*head).next =  current_node;
        (*head).value = value;
    } else {
        // cycle through list until the node leading up to the required node is found
        for (int i = 0; i < idx - 1; i++) {
            current_node = (*current_node).next;
        }
        
        // initialize the new node
        Node* new_node = new Node();
        (*new_node).value = value;

        // set new node and previous node pointers to insert new node into the list
        (*new_node).next = (*current_node).next; 
        (*current_node).next = new_node;  
    }
    list_size++;
}

/**
 * @brief remove node from list at given index
 * 
 * @param idx index of node to be removed
 * @return int value removed from array
 */
int LinkedList::remove(int idx) {
    Node* current_node = (*head).next; // current node pointer
    Node* previous_node = head; // previous node pointer
    list_size--; // decrement list size

    // handle the case where required index to be removed is the  head
    if (idx == 0) {
        head = current_node; // move the head pointer to the next node up from the previous head
        (*previous_node).next = NULL; // set the previous head
        return (*previous_node).value; // return the value in the previous head node
    }

    // cycle to the node before the node being removed
    for (int i = 0; i < idx-1; i++) {
        previous_node = (*previous_node).next;
        current_node = (*current_node).next;
    }
    
    // set the node pointers to pass over the required node, effectively removing it from the list
    (*previous_node).next = (*current_node).next;
    (*current_node).next =  NULL;

    return (*current_node).value; // return value of node removed
}

/**
 * @brief Construct a new Node object
 * 
 */
Node::Node() {
    next = NULL;
    value = 0;
}