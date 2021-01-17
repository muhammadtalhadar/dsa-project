//
// Created by talha on 12/1/21.
//
#include "RBT.h"

bool RBT::insert_inner(Node *&root_, int val) {

    // base case
  if(root_->data==0) {

        // insert root_
        root_->data=val;
        root_->colour='r';
        root_->rightChild=new Node(0,'b');
        root_->leftChild=new Node(0,'b');

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
    if(val<root_->data){
        return deleten_inner(root_->leftChild, val);
    }
    else if(val>root_->data){
        return deleten_inner(root->rightChild, val);
    }
}

bool RBT::search_inner(Node *root_, int val) const{
    if (root_->data == 0) return false;

    if (root_->data == val) return true;

    if (val < root_->data) {
        return search_inner(root_->leftChild, val);
    } else if (val > root_->data) {
        return search_inner(root_->rightChild, val);
    }
}

bool RBT::destroy_inner(Node *&root_) {
    if(root_==nullptr) return false;

    destroy_inner(root_->leftChild);
    destroy_inner(root_->rightChild);

    delete root_;
    root_=nullptr;
}

bool RBT::deletegt_inner(Node *node) {

    if(node==nullptr || node->data==0) return false;

    return destroy_inner(node->rightChild);
}

Node *RBT::parent_inner(Node *root_, int val) const{
    // base case
    if (root_ ==nullptr || root_->data==0) return nullptr;

    // positive result case
    if(root_->rightChild->data==val || root_->leftChild->data==val) return root_;

    //general case
    if (val < root_->data) {
        return parent_inner(root_->leftChild, val);
    } else if (val > root_->data) {
        return parent_inner(root_->rightChild, val);
    }
}

// The usual traversals

void RBT::preorder_inner(Node *root_) const{
    if (root_ && root_->data!=0) {
        std::cout << "("<<root_->data << ","<<root_->colour<<") ";
        preorder_inner(root_->leftChild);
        preorder_inner(root_->rightChild);
    }
}

void RBT::inorder_inner(Node *root_)const {
    if (root_ && root_->data!=0) {
        inorder_inner(root_->leftChild);
        std::cout << "("<<root_->data << ","<<root_->colour<<") ";
        inorder_inner(root_->rightChild);
    }
}

void RBT::postorder_inner(Node *root_) const{
    if (root_ && root_->data!=0) {
        postorder_inner(root_->leftChild);
        postorder_inner(root_->rightChild);
        std::cout << "("<<root_->data << ","<<root_->colour<<") ";
    }
}

// Alternate forms of usual traversalssss

void RBT::altpreorder_inner(Node *root_) const{
    if (root_ && root_->data!=0) {
        std::cout << "("<<root_->data << ","<<root_->colour<<") ";
        altpreorder_inner(root_->rightChild);
        altpreorder_inner(root_->leftChild);
    }
}

void RBT::altinorder_inner(Node *root_) const{
    if (root_ && root_->data!=0) {
        altinorder_inner(root_->rightChild);
        std::cout << "("<<root_->data << ","<<root_->colour<<") ";
        altinorder_inner(root_->leftChild);
    }
}

void RBT::altpostorder_inner(Node *root_) const{
    if (root_ && root_->data!=0) {
        altpostorder_inner(root_->rightChild);
        altpostorder_inner(root_->leftChild);
        std::cout << "("<<root_->data << ","<<root_->colour<<") ";
    }
}

// UTILITY FUNCTIONS

Node *RBT::locate_inner(Node *root_, int key) {
    if(root_->data==0) return nullptr;

    if(root_->data== key) return root_;

    if(key<root_->data){
        locate_inner(root_->leftChild, key);
    }
    else if(key>root_->data){
        locate_inner(root_->rightChild, key);
    }
}

Node* RBT::max_inner(Node *root_) {

    if(root_==nullptr) return nullptr;

    if(root_->rightChild->data==0) return root_;

    return max_inner(root_->rightChild);
}

Node *RBT::min_inner(Node *root_) {

    if(root_==nullptr) return nullptr;

    if(root_->leftChild->data==0) return root_;

    return min_inner(root_->leftChild);
}

Node *RBT::successor_inner(Node* node) {
    if(node==nullptr || node->data==0) return nullptr;

    return max_inner(node->leftChild);
}

Node *RBT::predecessor_inner(Node* node) {
    if(node==nullptr || node->data==0) return nullptr;

    return min_inner(node->rightChild);
}

void RBT::lrotate(Node *node) {
    if(node){
        Node* nodeParent=parent(node->data);
        Node* nodeRightChild=node->rightChild;

        if(nodeRightChild){
            node->rightChild=nodeRightChild->leftChild;

            if(node!=root){
                if(node==nodeParent->leftChild){
                    nodeParent->leftChild=nodeRightChild;
                }
                else{
                    nodeParent->rightChild=nodeRightChild;
                }
            }
            else{
                root=nodeRightChild;
            }

            nodeRightChild->leftChild=node;
        }
    }
}

void RBT::rrotate(Node *node) {
    if(node){
        Node* nodeParent=parent(node->data);
        Node* nodeLeftChild=node->leftChild;

        if(nodeLeftChild){
            node->leftChild=nodeLeftChild->rightChild;

            if(node!=root){
                if(node==nodeParent->leftChild){
                    nodeParent->leftChild=nodeLeftChild;
                }
                else{
                    nodeParent->rightChild=nodeLeftChild;
                }
            }
            else{
                root=nodeLeftChild;
            }
            nodeLeftChild->rightChild=node;
        }
    }
}

void RBT::ibalance(Node *node) {

    if(node==root){
        root->colour='b';
        return;
    }

    Node* currentNode=node;
    Node* tempParent=parent(currentNode->data);

    if(tempParent==root) return;

    Node* tempGrandParent=parent(tempParent->data);
    Node* tempUncle=nullptr;

    while(tempParent->colour == 'r'){
        if(tempParent == tempGrandParent->leftChild){
            tempUncle=tempGrandParent->rightChild;

            if(tempUncle->colour == 'r'){
                tempParent->colour='b';
                tempUncle->colour='b';
                tempGrandParent->colour='r';

                currentNode=tempGrandParent;
            }
            else if(currentNode == tempParent->rightChild){
                currentNode=parent(currentNode->data);
                lrotate(currentNode);
            }
            else{
                tempParent=parent(currentNode->data);
                tempGrandParent=parent(tempParent->data);

                tempParent->colour='b';
                tempGrandParent->colour='r';

                rrotate(tempGrandParent);
            }
        }
        else{
            tempUncle=tempGrandParent->leftChild;

            if(tempUncle->colour == 'r'){
                tempParent->colour='b';
                tempUncle->colour='b';
                tempGrandParent->colour='r';

                currentNode=tempGrandParent;
            }
            else if(currentNode == tempParent->leftChild){
                currentNode=parent(currentNode->data);
                rrotate(currentNode);
            }
            else{
                tempParent=parent(currentNode->data);
                tempGrandParent=parent(tempParent->data);

                tempParent->colour='b';
                tempGrandParent->colour='r';

                lrotate(tempGrandParent);
            }
        }
    }
    root->colour='b';
}

void RBT::dbalance(Node *node) {

}

// DEFAULT CONSTRUCTOR

RBT::RBT() {
    root = new Node(0, 'b');
}


// WRAPPER FUNCTIONS

bool RBT::insert(int val) {
    return insert_inner(root, val);
}

bool RBT::deleten(int val) {
    return deleten_inner(root, val);
}

bool RBT::search(int val) const{
    return search_inner(root, val);
}

bool RBT::destroy() {
    return destroy_inner(root);
}

bool RBT::deletegt(int val) {
    return deletegt_inner(locate_inner(root, val));
}

Node *RBT::parent(int val) const {
    return parent_inner(root, val);
}

bool RBT::displayParent(int val)const{
    Node* parent= parent_inner(root, val);
    if(parent){
        cout<<parent->data;
        return true;
    }
    return false;
}

void RBT::inorder() const{
    inorder_inner(root);
}

void RBT::preorder() const{
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
    Node* temp=nullptr;
    temp= max_inner(root);
    cout<<"Max: "<<temp->data<<endl;
    temp=successor_inner(root);
    cout<<"Successor of Root: "<<temp->data<<endl;
}

/*
 * File I/O
 * */

bool RBT::readFile(const char *fpath) {

    if(fpath){
        //open file
        ifstream fin(fpath);
        if(!fin.is_open()) return false;

        int num;
        while(!fin.eof()){
            fin>>num;
            insert_inner(root, num);
        }

        //close file
        fin.close();

        return true;
    }
    return false;
}
