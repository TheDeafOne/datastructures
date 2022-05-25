#include <iostream>
#include "HashedArrayTree.h"
using namespace std;

int main(){
    HashedArrayTree hat;
    for (int i = 0; i < 100; i++){
        hat.add(i);
    }

    for (int i = 0; i < 100; i++){
        cout << hat.get(i) << endl;
    }

}