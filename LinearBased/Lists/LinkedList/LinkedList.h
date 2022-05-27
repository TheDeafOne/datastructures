// -lstdc++
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
class Node {
    public:
        Node* next;
        int value;
        Node();
};

class LinkedList {
    private:
        Node* head;
        Node* tail;
        int list_size;
    public:
        LinkedList();
        int get(int idx);
        void add(int value);
        void insert(int idx, int value);
        int remove(int idx);
        int size() { return list_size; };
};


#endif