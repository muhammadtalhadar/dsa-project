//
// Created by talha on 12/1/21.
//

#pragma once

#include "Node.h"
#include <iostream>
#include <fstream>
using namespace std;
class RBT {
private:
    Node *root;

    /*
     * Declarations for recursive implementations
     * postfix '_inner': implies that a method is a private method.
     * parameter name '_root': implies that the root of the (sub)tree must be passed to the method as argument here.
     * '_root' parameter generally implies that the method is a recursive one.
     * */

    /* inserts a value int RBT
     * FIXME: Implemented without balancing.*/
    bool insert_inner(Node *&root_, int val);

    /*
     * Deletes a root_ from the RBT.
     * FIXME: implmenented without balancing.
     * */
    bool deleten_inner(Node *&root_, int val);

    // returns true if a value exists int RBT
    bool search_inner(Node *root_, int val)const;

    // destroys the entire RBT
    bool destroy_inner(Node *&root_);

    // deletes all nodes of value greater than a give value
    bool deletegt_inner(Node *&root_, int val);


    /* *
     * Traversals
     * */

    // The usual traversals
    void preorder_inner(Node* root_)const; // NLR
    void inorder_inner(Node* root_)const; // LNR
    void postorder_inner(Node* root_)const; // LRN

    // Alternate forms of usual traversals
    void altpreorder_inner(Node* root_)const; // NRL
    void altinorder_inner(Node* root_)const; // RNL
    void altpostorder_inner(Node* root_)const; // RLN

    /* *
     * Utility Functions
    * */

    Node* parent_inner(Node *root_, int val)const;
    Node* parent(int val)const;
    Node* successor(Node *root_, int);

    // Utility functions for balancing trees

    /*
     * 'node' is the focus of our recolouring, whose elderly and sibibling nodes will be checked for colouring.
     * */
    void recolour(Node* node);

    /*
     * For either rotation methods
     * parameter 'node' is the pivot of the rotation.
     * In parent-child relation of rotation, 'node' is the parent.
     * */
    void lrotate(Node* node); // left rotation
    void rrotate(Node* node); // right rotation

    // Tree balancing algorithms
    void ibalance(Node* node); // balance tree after insertion
    void dbalance(Node* node); // balance tree after deletion

    /*
     * File I/O
     * */

    bool readFile(const char* fpath);


public:
    // default constructor
    RBT();

    // declarations for wrapper functions of recursive implementations
    bool insert(int val);

    bool deleten(int val);

    bool search(int val)const;

    bool destroy();

    bool deletegt(int val);

    bool displayParent(int val)const;

    void preorder()const;
    void inorder()const;
    void postorder()const;

    void altpreorder()const;
    void altinorder()const;
    void altpostorder()const;

    //TODO: delete this later
    void tester();//this just tests shit
};
