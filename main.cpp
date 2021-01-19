#include <iostream>
#include "RBT.h"
using namespace  std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    char path[]={"input.txt"};

    RBT rbt;
    rbt.readFile(path);

    rbt.inorder();


    return 0;
}