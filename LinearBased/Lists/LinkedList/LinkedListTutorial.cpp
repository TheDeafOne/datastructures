#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
    LinkedList list;
    for (int i = 0; i < 100; i++) {
        list.add(i+1);
    }
    for (int i = 0; i < 100; i++) {
        cout << list.get(i) << endl;
    }
}