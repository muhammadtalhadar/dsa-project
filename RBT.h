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
     * '_root' parameter and '_inner' postfix generally implies that the method is a recursive one.
     * */

    // Insert a value into RBT and balance it.
    bool insert_inner(Node *&root_, int val);

    // Delete a key from RBT and balance it.
    bool deleten_inner(Node *&root_, int val);

    // returns true if a value exists int RBT
    bool search_inner(Node *root_, int val) const;

    // destroys the entire RBT
    bool destroy_inner(Node *&root_);

    // deletes all nodes of value greater than a give value
    bool deletegt_inner(Node *node);

    // The usual traversals

    void preorder_inner(Node *root_) const; // NLR
    void inorder_inner(Node *root_) const; // LNR
    void postorder_inner(Node *root_) const; // LRN

    // Alternate forms of usual traversals

    void altpreorder_inner(Node *root_) const; // NRL
    void altinorder_inner(Node *root_) const; // RNL
    void altpostorder_inner(Node *root_) const; // RLN


    // Locating nodes

    Node *locate_inner(Node *root_, int key);
    Node *parent_inner(Node *root_, int val) const;
    Node *successor_inner(Node *node);
    Node *predecessor_inner(Node* node);
    Node *max_inner(Node *root_);
    Node *min_inner(Node* root_);

    // Rotaitons

    void lrotate(Node *node); // left rotation
    void rrotate(Node *node); // right rotation

    // Tree balancing algorithms

    void ibalance(Node *node); // balance tree after insertion
    void dbalance(Node *node); // balance tree after deletion

public:
    // default constructor
    RBT();

    // declarations for wrapper functions of recursive implementations
    bool insert(int val);

    bool deleten(int val);

    bool search(int val) const;

    bool destroy();

    bool deletegt(int val);

    bool parent(int val) const;

    void preorder() const;

    void inorder() const;

    void postorder() const;

    void altpreorder() const;

    void altinorder() const;

    void altpostorder() const;

    // File IO
    bool readFile(const char *fpath);

    //TODO: delete this later
    void tester();//this just tests shit
};
