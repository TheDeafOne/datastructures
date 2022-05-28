#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
    LinkedList list;
    for (int i = 0; i < 100; i++) {
        list.add(i+1);
    }
    for (int i = 0; i < list.size(); i++) {
        cout << list.get(i) << endl;
    }

    list.insert(99, 100);
    for (int i = 0; i < list.size(); i++) {
        cout << list.get(i) << endl;
    }

    cout << "item removed: " << list.remove(99) << endl;

    for (int i = 0; i < list.size(); i++) {
        cout << list.get(i) << endl;
    }


}