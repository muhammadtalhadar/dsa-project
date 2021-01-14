#include "Node.h"

Node::Node(int data,  char colour,Node *leftChild, Node *rightChild) : data(data), leftChild(leftChild),
                                                                       rightChild(rightChild), colour(colour) {}
