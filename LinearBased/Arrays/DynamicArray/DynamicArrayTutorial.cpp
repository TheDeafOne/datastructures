#include <iostream>
#include "DynamicArray.h"
using namespace std;

int main() {
        DynamicArray da;
        
        for (int i = 0; i < 10; i++){
                da.add(i);
        }

        cout << da.size() << endl;

}