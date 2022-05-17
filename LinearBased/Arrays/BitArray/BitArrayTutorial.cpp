#include <iostream>
#include "BitArray.h"
using namespace std;

int main(){
    BitArray bit1(1);
    cout << "bit1 has length: " << bit1.size() << endl;

    BitArray bit2(31);
    cout << "bit2 has length: " << bit2.size() << endl;

    cout << "bit1 and bit2 have the same length, because they both use one int, which has 32 bits" << endl;

    BitArray bit3(1000);
    cout << "set a bit with the setBit function" << endl;
    bit3.setBit(69);

    cout << "we can see the entire bit array with a for loop and the testBit function:" << endl;
    for (size_t i = 0; i < bit3.size(); i++){
        cout << bit3.testBit(i);
    }
    cout << endl;

    cout << "we can clear this bit with the clearBit function, and then show that it worked with a call to the testBit function:" << endl;
    bit3.clearBit(69);
    cout << bit3.testBit(69) << endl;



    
}