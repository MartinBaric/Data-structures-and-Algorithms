/*
The implementation of a binary tree with its basic operations. This is the parent class for all other 
tree implementations in our code.
The function of all methods and attributes is self-explaining.

Author: Martin Barič,
Date: 21.08.2024
*/
#pragma once

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Node{
private:
    Node* left;
    Node* right;

// Note on Protected : same as 'private' but a derived class can access these data.
protected:
    T data;
    int height;

public:
    Node();
    Node(T value);
    ~Node();

    T getData();
    virtual Node<T>* getRight();
    virtual Node<T>* getLeft();
    virtual void setRight(Node<T>* n);
    virtual void setLeft(Node<T>* n);

    virtual void printData();
    void update_height();
        
    virtual void inorder();
    virtual void preorder();
    virtual void postorder();

    void print_tree();

    // Initialize Tree via Breadth First Search manner level by level
    virtual void insert(T datum);
    /* Auxiliary Variable Tree_Root to set the pointer of the parent after deleting child. 
    Pointer to Pointer operator Node<T>** is used in order to avoid copying data and recursively adjust the pointers. */ 
    void deleteNode(T datum, Node<T>** Tree_Root = NULL);
};