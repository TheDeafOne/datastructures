#include <iostream>
#include "DynamicArray.h"
using namespace std;

int main() {
        DynamicArray da;
        da.add(1);
        cout << da.get(0) << endl;
        da.remove(0);
        cout << da.get(0) << endl;
}