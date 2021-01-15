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
        Node* parent=parent_inner(root, node->data);
        if(parent->colour=='b' && parent!=root){
            ibalance();
        }

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
    // base case
    if(node==nullptr) return false;

    Node* temp=nullptr;
    char originalColor;
    //positive result case
        if(node->data==val){
            originalColor=node->colour;
            // when both subtrees are empty
            if(node->leftChild==nullptr && node->rightChild== nullptr){
                delete node;
                node= nullptr;
            }
                //where left subtree is empty
            else if(node->leftChild==nullptr){
                temp=node->rightChild;
                delete node;
                node=temp;
            }
                //when right subtree is empty
            else if(node->rightChild==nullptr){
                temp=node->leftChild;
                delete node;
                node=temp;
            }
                // when neither subtree is empty
            else{
                Node* predecessor=node->leftChild;
                temp=nullptr;

                // locate the predecessor to node to be deleted
                while(predecessor->rightChild!= nullptr){
                    temp=predecessor;
                    predecessor=predecessor->rightChild;
                }

                //update node to delete's data with predecessor's data and set propper color
                node->data=predecessor->data;
                node->data=originalColor;

                // update predecessor's original parent and delete predecessor from it's original position.
                if(temp==nullptr){ // incase, predecessor was node->lnode and no iteration was done
                    node->leftChild=predecessor->leftChild;
                }
                else{
                    temp->rightChild=predecessor->leftChild;
                }
                delete predecessor;
            }

            // now balance stuff
            if(originalColor=='b'){
                dbalance();
            }
            return true;
        }
    return false;
}

bool RBT::search_inner(Node *node, int val) {
    if (node==nullptr) return false;

    if(node->data==val) return true;

    if(val<node->data){
        return search_inner(node->leftChild, val);
    }
    else if(val>node->data) {
        return search_inner(node->rightChild, val);
    }
}

bool RBT::destroy_inner(Node *&node) {
    return false;
}

bool RBT::deletegt_inner(Node *&node, int val) {
    return false;
}

Node* RBT::parent_inner(Node *node, int val) {
    // base case
    if(root==nullptr) return nullptr;

    // positive result case
    if(root->rightChild!= nullptr && root->rightChild->data==val){
        return root->rightChild;
    }
    else if(root->leftChild!= nullptr && root->leftChild->data==val){
        return root->leftChild;
    }

    //general case
    if(val<root->data){
        return parent_inner(root->leftChild, val);
    }
    else if(val>root->data){
        return parent_inner(root->rightChild, val);
    }
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
    return parent_inner(root, val);
}

void RBT::recolour(Node *&parent, Node *&child, Node *&grandchild) {

}

void RBT::lrotate(Node *&node) {
    Node* node_rightChild=node->rightChild;
    Node* temp=node->rightChild->leftChild;
    node->rightChild= temp;
    node_rightChild->leftChild=node;
    node=node_rightChild;
}

void RBT::rrotate(Node *&node) {
    Node* node_leftChild=node->leftChild;
    node->leftChild=node_leftChild->rightChild;
    node_leftChild->rightChild=node;
    node=node_leftChild;
}

void RBT::tester() {
    cout<<"Testing left rotate, then right rotate. JEBAIT.";
}

/* *
 * The usual traversals
 * */

void RBT::preorder_inner(Node *node) {
    if (node) {
        std::cout << node->data << " ";
        preorder_inner(node->leftChild);
        preorder_inner(node->rightChild);
    }
}

void RBT::inorder_inner(Node *node) {
    if (node) {
        inorder_inner(node->leftChild);
        std::cout << node->data << " ";
        inorder_inner(node->rightChild);
    }
}

void RBT::postorder_inner(Node *node) {
    if (node) {
        postorder_inner(node->leftChild);
        postorder_inner(node->rightChild);
        std::cout << node->data << " ";
    }
}

/* *
 * Alternate forms of usual traversalssss
 * */
void RBT::altpreorder_inner(Node *node) {

}

void RBT::altinorder_inner(Node *node) {

}

void RBT::atlpostorder_inner(Node *node) {

}

Node *RBT::successor(Node *node, int) {
    return nullptr;
}
