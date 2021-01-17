#pragma once

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* leftChild;
    Node* rightChild;
    char colour;

    explicit Node(int data=0, char colour='r',Node *leftChild=nullptr, Node *rightChild=nullptr);
    friend ostream& operator<<(ostream &out, const Node& node);
};