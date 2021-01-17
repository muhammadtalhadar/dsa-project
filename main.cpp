#include <iostream>
#include "RBT.h"
using namespace  std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    int nums[]={33,13,53,41,61,11,21,15,31};

    RBT rbt;

    for(int i:nums){
       rbt.insert(i);
    }
    cout<<"\nTEET.";
    return 0;
}