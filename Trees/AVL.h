#pragma once

#include "BST.h"
#include <algorithm>

template <typename T>
class AVL : public BST<T>
{
    private:
    AVL* left;
    AVL* right;
    
    protected:

    // long long int to be compatible with the max function below
    long long int height = 0;

    public:
    using BST<T>::BST;
    AVL(T value);
    void printData(); 
    void inorder();
    void Rotate(AVL<T>* Root_Node,bool dir = false);
    AVL<T>* getRight() override;
    AVL<T>* getLeft() override;
    void setRight(AVL<T> n);
    void setLeft(AVL<T> n);
    void create_new(T datum,bool right);
    /*
    Comment: Dmitrij Sitenko 
    Modify Insert Function from inherited BST class by including left-right rotation after
    each insert. This yields a balanced BST after each insertion call by recursivaly
     balancing each subtree where insert is called 
    */
    void insert(T datum) override;
    void deleteNode(T datum) override;
};