#include <iostream>
#include "RBT.h"
using namespace  std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    char path[]={"input.txt"};
    int nums[]={10,16,2,-5,0,22,1024};
    RBT rbt;

    for(int i:nums){
        rbt.insert(i);
        cout<<"Inserted "<<i<<endl;
    }

    //rbt.tester();
    rbt.inorder();

    return 0;
}