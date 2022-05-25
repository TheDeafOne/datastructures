#include <iostream>
#include "HashedArrayTree.h"
using namespace std;

int main(){
    HashedArrayTree hat;
    hat.add(1);
    cout << hat.get(0) << endl;
}