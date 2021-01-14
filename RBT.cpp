//
// Created by talha on 12/1/21.
//

#include "RBT.h"

bool RBT::insert_inner(int val, Node *&node, Node*& parentNode) {

    // base case

    if(node==nullptr){

        // insert node
        node=new Node(val);

        // if node inserted was at root position, set its color to black
        // then return, since there's no balancing to be done
        if(&node==&root){
            node->colour='r';
            return true;
        }

        //now, for the balancing part.
        //TODO: implement this

        return true;
    }

    // general case
    if(val<node->data){
        return insert_inner( val, node->leftChild, node);
    }
    else if(val>node->data){
        return insert_inner( val, node->rightChild,node);
    }

    //if value was a duplicate, no no recursion will occur, and we will return without having inserted anything
    return false;
}

bool RBT::deleten_inner(Node *&node, int val) {
    return false;
}

bool RBT::search_inner(Node *node, int val) {
    return false;
}

bool RBT::destroy_inner(Node *&node) {
    return false;
}

bool RBT::deletegt_inner(Node *&node, int val) {
    return false;
}

bool RBT::displayParent_inner(Node *node, int val) {
    return false;
}

RBT::RBT() {
    root=nullptr;
}

bool RBT::insert(int val) {
    // here, third parameter, parentNode=root, is essentially meaningless and
    // for the sake of implementation design only(
    // since third argument is a references and references cant be null.
    return insert_inner( val,root, root);
}

bool RBT::deleten(int val) {
    return deleten_inner(root, val);
}

bool RBT::search(int val) {
    return search_inner(root, val);
}

bool RBT::destroy() {
    return destroy_inner(root);
}

bool RBT::deletegt(int val) {
    return deletegt_inner(root, val);
}

bool RBT::displayParent(int val) {
    return displayParent_inner(root, val);
}

void RBT::tester() {
    cout<<"Testing left rotate, then right rotate. JEBAIT.";
}

void recolour(Node *&parent, Node *&child, Node *&grandchild) {

}

void leftRotate(Node*& root, Node *&node) {
    Node* node_rightChild=node->rightChild;
    Node* temp=node->rightChild->leftChild;
    node->rightChild= temp;
    node_rightChild->leftChild=node;
    node=node_rightChild;
}

void rightRotate(Node *&root, Node *&node) {
    Node* node_leftChild=node->leftChild;
    node->leftChild=node_leftChild->rightChild;
    node_leftChild->rightChild=node;
    node=node_leftChild;
}
