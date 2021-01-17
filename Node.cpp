#include "Node.h"

Node::Node(int data,  char colour,Node *leftChild, Node *rightChild) : data(data), leftChild(leftChild),
                                                                       rightChild(rightChild), colour(colour) {}

ostream &operator<<(ostream &out, const Node &node) {
    out<<"("<<node.data<<","<<node.colour<<")";
    return out;
}
