//
// Created by talha on 12/1/21.
//

#pragma once

#include "Node.h"
#include <iostream>
using namespace std;
class RBT {
private:
    Node *root;

    // declarations for recursive implementations

    // inserts a value int RBT
    bool insert_inner( int val, Node *&node, Node*& parentNode);

    // Deletes a value from RBT
    bool deleten_inner(Node *&node, int val);

    // returns true if a value exists int RBT
    bool search_inner(Node *node, int val);

    // destroys the entire RBT
    bool destroy_inner(Node *&node);

    // deletes all nodes of value greater than a give value
    bool deletegt_inner(Node *&node, int val);

    // displayes the parent node of a given value
    bool displayParent_inner(Node *node, int val);

public:
    // default constructor
    RBT();

    // declarations for wrapper functions of recursive implementations
    bool insert(int val);

    bool deleten(int val);

    bool search(int val);

    bool destroy();

    bool deletegt(int val);

    bool displayParent(int val);

    //TODO: delete this later
    void tester();//this just tests shit
};

// MISC functions required by this class
void recolour(Node*& parent, Node*& child, Node*& grandchild);
void leftRotate(Node*& root, Node*& node);
void rightRotate(Node*& root, Node*& node);