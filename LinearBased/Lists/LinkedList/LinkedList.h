// -lstdc++
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
class Node {
    public:
        Node* next; // pointer to next node
        int value; // value that node contains

        /**
         * @brief Construct a new Node object
         * 
         */
        Node(); 
};

class LinkedList {
    private:
        Node* head; // pointer to head node
        Node* tail; // pointer to tail node
        int list_size;

    public:
        /**
         * @brief Construct a new Linked List object
         * 
         */
        LinkedList();

        /**
         * @brief get value from list using given index
         * 
         * @param idx index at which to get the node from the list
         * @return int value found in the array at given index
         */
        int get(int idx);

        /**
         * @brief make a node with the given value and add it to the end of the list
         * 
         * @param value value to be added to the list
         */
        void add(int value);

        /**
         * @brief set the node at the given index to the given value
         * 
         * @param idx index to set node value at
         * @param value value to be set
         * @return int value being replaced
         */
        int set(int idx, int value);

        /**
         * @brief insert given value at the given index in the list
         * 
         * @param idx index at which the given value should be inserted
         * @param value to be inserted
         */
        void insert(int idx, int value);

        /**
         * @brief remove node from list at given index
         * 
         * @param idx index of node to be removed
         * @return int value removed from array
         */
        int remove(int idx);

        /**
         * @brief return size of list
         * 
         * @return int size of list
         */
        int size() { return list_size; };
};


#endif