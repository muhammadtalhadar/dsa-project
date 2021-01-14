#include <iostream>
#include "RBT.h"
using namespace  std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    int nums[]={10,8,12,7,9};

    RBT rbt;

    for(int i:nums){
       rbt.insert(i);
    }

    rbt.tester();

    cout<<"TEET.";
    return 0;
}