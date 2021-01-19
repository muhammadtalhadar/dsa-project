#include <iostream>
#include "RBT.h"
using namespace  std;

void menu(){
    cout<<"=========================================================================="<<endl;
    cout<<"Press 1 to insert values one by one in the tree. "<<endl;
    cout<<"Press 2 to delete a value from the tree (NOT IMPLEMENTED). "<<endl;
    cout<<"Press 3 for searching a value from the tree. "<<endl;
    cout<<"Press 4 for pre-order traversal NLR"<<endl;
    cout<<"Press 5 for in-order traversal LNR "<<endl;
    cout<<"Press 6 for post-order traversal LRN "<<endl;
    cout<<"Press 7 for pre-order traversal 2 NRL "<<endl;
    cout<<"Press 8 for in-order traversal 2 RNL "<<endl;
    cout<<"Press 9 for post-order traversal 2 RLN "<<endl;
    cout<<"Press 10 to destroy the tree (all nodes must be deleted) "<<endl;
    cout<<"Press 11 to delete all values in the tree greater than X (NOT IMPLEMENTED)"<<endl;
    cout<<"Press 12 for displaying parent of a node present in Tree "<<endl;
    cout<<"Press 13 to read integer values from the file “input.txt” \n"
          "         to create a red-black tree "<<endl;
    cout<<"Press 14 to EXIT "<<endl;
    cout<<"=========================================================================="<<endl;
}

int getInput(){
    int n;
    cout<<endl<<"Enter input: ";
    cin>>n;
    return n;
}


int main() {
    int choice=0;
    RBT rbt;

    menu();
    choice=getInput();

    while(choice!=14){
        if(choice==1){
            rbt.insert(getInput());
        }
        else if(choice==3){
            rbt.search(getInput());
        }
        else if(choice==4){
            rbt.preorder();
        }
        else if(choice==5){
            rbt.inorder();
        }
        else if(choice==6){
            rbt.postorder();
        }
        else if(choice==7){
            rbt.altpreorder();
        }
        else if(choice==8){
            rbt.altinorder();
        }
        else if(choice==9){
            rbt.altpostorder();
        }
        else if(choice==10){
            rbt.destroy();
        }
        else if(choice==12){
            rbt.parent(getInput());
        }
        else if(choice==13){
            rbt.readFile("input.txt");
        }
        else {
            break;
        }

        choice=getInput();
    }
    return 0;
}