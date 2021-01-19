//
// Created by talha on 12/1/21.
//
#include "RBT.h"

bool RBT::insert_inner(Node *&root_, int val) {

    // base case
    if (root_==nullptr) {

        // insert root_
        root_=new Node(val, 'r');
        // call balancing method at point of insertion
        ibalance(root_);

        return true;
    }

    // general case
    if (val < root_->data) {
        return insert_inner(root_->leftChild, val);
    } else if (val > root_->data) {
        return insert_inner(root_->rightChild, val);
    }

    //if value was a duplicate, no no recursion will occur, and we will return without having inserted anything
    return false;
}

bool RBT::deleten_inner(Node *&root_, int val) {
    // base case
    if (root_ == nullptr) return false;

    Node *temp = nullptr;
    char originalColor;

    //positive result case
    if (root_->data == val) {
        originalColor = root_->colour;
        // when both subtrees are empty
        if (root_->leftChild == nullptr && root_->rightChild == nullptr) {
            delete root_;
            root_ = nullptr;
        }
            //where left subtree is empty
        else if (root_->leftChild == nullptr) {
            temp = root_->rightChild;
            delete root_;
            root_ = temp;
        }
            //when right subtree is empty
        else if (root_->rightChild == nullptr) {
            temp = root_->leftChild;
            delete root_;
            root_ = temp;
        }
            // when neither subtree is empty
        else {
            Node *predecessor = root_->leftChild;
            temp = nullptr;

            // locate the predecessor to root_ to be deleted
            while (predecessor->rightChild != nullptr) {
                temp = predecessor;
                predecessor = predecessor->rightChild;
            }

            //update root_ to delete's data with predecessor's data and set propper color
            root_->data = predecessor->data;
            root_->colour = originalColor;

            // update predecessor's original parent and delete predecessor from it's original position.
            if (temp == nullptr) { // incase, predecessor was root_->lnode and no iteration was done
                root_->leftChild = predecessor->leftChild;
            } else {
                temp->rightChild = predecessor->leftChild;
            }
            delete predecessor;
        }

        // now balance stuff
//        if (originalColor == 'b') {
//            dbalance(root_);
//        }
        return true;
    }

    // general case
    if (val < root_->data) {
        return deleten_inner(root_->leftChild, val);
    } else if (val > root_->data) {
        return deleten_inner(root->rightChild, val);
    }
}

bool RBT::search_inner(Node *root_, int val) const {
    if (root_ == nullptr) return false;

    if (root_->data == val) return true;

    if (val < root_->data) {
        return search_inner(root_->leftChild, val);
    } else if (val > root_->data) {
        return search_inner(root_->rightChild, val);
    }
}

bool RBT::destroy_inner(Node *&root_) {
    if (root_ == nullptr) return false;

    destroy_inner(root_->leftChild);
    destroy_inner(root_->rightChild);

    delete root_;
    root_ = nullptr;
}

bool RBT::deletegt_inner(Node *node) {

    if (node == nullptr) return false;

    // TODO: Implement this
    // locate nodes greated than node->data
    // call deleten_inner() on each.
    return false;
}

Node *RBT::parent_inner(Node *root_, int val) const {
    // base case
    if (root_ == nullptr || val==root->data) return nullptr;

    // positive result case
    if (root_->rightChild && root_->rightChild->data == val || root_->leftChild && root_->leftChild->data == val) return root_;

    //general case
    if (val < root_->data) {
        return parent_inner(root_->leftChild, val);
    } else if (val > root_->data) {
        return parent_inner(root_->rightChild, val);
    }
}

// The usual traversals

void RBT::preorder_inner(Node *root_) const {
    if (root_) {
        cout << *root_ << " ";
        preorder_inner(root_->leftChild);
        preorder_inner(root_->rightChild);
    }
}

void RBT::inorder_inner(Node *root_) const {
    if (root_ ) {
        inorder_inner(root_->leftChild);
        cout << *root_ << " ";
        inorder_inner(root_->rightChild);
    }
}

void RBT::postorder_inner(Node *root_) const {
    if (root_ ) {
        postorder_inner(root_->leftChild);
        postorder_inner(root_->rightChild);
        cout << *root_ << " ";
    }
}

// Alternate forms of usual traversalssss

void RBT::altpreorder_inner(Node *root_) const {
    if (root_) {
        cout << *root_ << " ";
        altpreorder_inner(root_->rightChild);
        altpreorder_inner(root_->leftChild);
    }
}

void RBT::altinorder_inner(Node *root_) const {
    if (root_ ) {
        altinorder_inner(root_->rightChild);
        cout << *root_ << " ";
        altinorder_inner(root_->leftChild);
    }
}

void RBT::altpostorder_inner(Node *root_) const {
    if (root_) {
        altpostorder_inner(root_->rightChild);
        altpostorder_inner(root_->leftChild);
        cout << *root_ << " ";
    }
}

// UTILITY FUNCTIONS

Node *RBT::locate_inner(Node *root_, int key) {
    if (root_== nullptr) return nullptr;

    if (root_->data == key) return root_;

    if (key < root_->data) {
        locate_inner(root_->leftChild, key);
    } else if (key > root_->data) {
        locate_inner(root_->rightChild, key);
    }
}

Node *RBT::max_inner(Node *root_) {

    if (root_ == nullptr) return nullptr;

    if (root_->rightChild == nullptr   ) return root_;

    return max_inner(root_->rightChild);
}

Node *RBT::min_inner(Node *root_) {

    if (root_ == nullptr) return nullptr;

    if (root_->leftChild == nullptr) return root_;

    return min_inner(root_->leftChild);
}

Node *RBT::successor_inner(Node *node) {
    if (node == nullptr) return nullptr;

    return max_inner(node->leftChild);
}

Node *RBT::predecessor_inner(Node *node) {
    if (node == nullptr) return nullptr;

    return min_inner(node->rightChild);
}

void RBT::lrotate(Node *node) {
    if(node){
        Node* parent=parent_inner(root, node->data);
        Node* rightChild=node->rightChild;

        if(rightChild){
            node->rightChild=rightChild->leftChild;
            rightChild->leftChild=node;

            if(node==root){
                root=rightChild;
            }
            else{
                if(node==parent->rightChild){
                    parent->rightChild=rightChild;
                }
                else{
                    parent->leftChild=rightChild;
                }
            }
        }
    }
}

void RBT::rrotate(Node *node) {
    if(node){
        Node* parent=parent_inner(root, node->data);
        Node* leftChild=node->leftChild;

        if(leftChild){
            node->leftChild=leftChild->rightChild;
            leftChild->rightChild=node;

            if(node==root){
                root=leftChild;
            }
            else{
                if(node==parent->leftChild){
                    parent->leftChild=leftChild;
                }
                else{
                    parent->rightChild=leftChild;
                }
            }
        }
    }
}

void RBT::ibalance(Node *node) {

    Node *parent = parent_inner(root, node->data);
    Node *grandParent=nullptr;
    Node *uncle = nullptr;

    while (parent && parent->colour == 'r') {

        grandParent = parent_inner(root, parent->data);

        if (parent == grandParent->leftChild) {
            uncle = grandParent->rightChild;

            if (uncle && uncle->colour == 'r') {
                parent->colour = 'b';
                uncle->colour = 'b';
                grandParent->colour = 'r';

                node = grandParent;
            } else {
                if (node == parent->rightChild) {
                    node=parent;
                    lrotate(node);
                }

                parent=parent_inner(root, node->data);
                parent->colour='b';
                grandParent->colour = 'r';

                rrotate(grandParent);
            }
        } else {
            uncle = grandParent->leftChild;

            if (uncle && uncle->colour == 'r') {
                parent->colour = 'b';
                uncle->colour = 'b';
                grandParent->colour = 'r';

                node = grandParent;
            }
            else {
                if (node == parent->leftChild) {
                    node = parent;
                    rrotate(node);
                }

                parent=parent_inner(root, node->data);
                parent->colour='b';
                grandParent->colour='r';
                lrotate(grandParent);

            }
        }
        if(node==root) break;
    }
    root->colour = 'b';
}

void RBT::dbalance(Node *node) {

}

// DEFAULT CONSTRUCTOR

RBT::RBT() {
    root = nullptr;
}


// WRAPPER FUNCTIONS

bool RBT::insert(int val) {
    return insert_inner(root, val);
}

bool RBT::deleten(int val) {
    return deleten_inner(root, val);
}

bool RBT::search(int val) const {
    return search_inner(root, val);
}

bool RBT::destroy() {
    return destroy_inner(root);
}

bool RBT::deletegt(int val) {
    return deletegt_inner(locate_inner(root, val));
}


bool RBT::parent(int val) const {
    Node *parent = parent_inner(root, val);
    if (parent) {
        cout << *parent;
        return true;
    }
    return false;
}

void RBT::inorder() const {
    inorder_inner(root);
}

void RBT::preorder() const {
    preorder_inner(root);
}

void RBT::postorder() const {
    postorder_inner(root);
}

void RBT::altpreorder() const {
    altpreorder_inner(root);
}

void RBT::altinorder() const {
    altinorder_inner(root);
}

void RBT::altpostorder() const {
    altpostorder_inner(root);
}

void RBT::tester() {
    rrotate(root->leftChild);
}

/*
 * File I/O
 * */

bool RBT::readFile(const char *fpath) {

    if (fpath) {
        //open file
        ifstream fin(fpath);

        if (!fin.is_open())
            return false;

        int num;
        while (!fin.eof()) {
            fin >> num;
            insert_inner(root, num);
        }

        //close file
        fin.close();

        return true;
    }
    return false;
}
