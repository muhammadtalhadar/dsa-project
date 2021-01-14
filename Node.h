#pragma once

struct Node
{
    int data;
    Node* leftChild;
    Node* rightChild;
    char colour;

    Node(int data=0, char colour='r',Node *leftChild=nullptr, Node *rightChild=nullptr);
};