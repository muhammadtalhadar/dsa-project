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

    /* inserts a value int RBT
     * FIXME: Implemented without balancing.*/
    bool insert_inner( int val, Node *&node, Node*& parentNode);

    /*
     * Deletes a node from the RBT.
     * FIXME: implmenented without balancing.*/
    bool deleten_inner(Node *&node, int val);

    // returns true if a value exists int RBT
    bool search_inner(Node *node, int val);

    // destroys the entire RBT
    bool destroy_inner(Node *&node);

    // deletes all nodes of value greater than a give value
    bool deletegt_inner(Node *&node, int val);


    /* *
     * Traversals
     * */

    // The usual traversals
    void preorder_inner(Node* node); // NLR
    void inorder_inner(Node* node); // LNR
    void postorder_inner(Node* node); // LRN

    // Alternate forms of usual traversals
    void altpreorder_inner(Node* node); // NRL
    void altinorder_inner(Node* node); // RNL
    void atlpostorder_inner(Node* node); // RLN

    /* *
     * Utility Functions
    * */

    Node* parent_inner(Node *node, int val);
    Node* successor(Node *node, int);

    // Utility functions for balancing trees
    void recolour(Node*& parent, Node*& child, Node*& grandchild);
    void lrotate(Node*& node); // left rotation
    void rrotate(Node*& node); // right rotation

    // Tree balancing algorithms
    void ibalance(); // balance tree after insertion
    void dbalance(); // balance tree after deletion


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
