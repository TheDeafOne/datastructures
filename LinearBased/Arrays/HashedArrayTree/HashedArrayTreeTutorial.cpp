#include <iostream>
#include "HashedArrayTree.h"
using namespace std;

int main(){
    HashedArrayTree hat;
    for (int i = 0; i < 10; i++){
        hat.add(i);
    }

    for (int i = 0; i < 10; i++){
        cout << hat.get(i) << endl;
    }
    hat.insert(0, -1);
    for (int i = 0; i < 11; i++){
        cout << hat.get(i) << endl;
    }
    hat.remove(0);
    for (int i = 0; i < 11; i++){
        cout << hat.get(i) << endl;
    }
}