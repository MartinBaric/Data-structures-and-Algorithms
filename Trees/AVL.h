#pragma once

#include "BST.h"
#include <algorithm>

template <typename T>
class AVL : public BST<T>
{
    private:
    AVL* left;
    AVL* right;
    AVL* parent;

    public:
    using BST<T>::BST;
    AVL(T value);
    void printData() override; 
    void Rotate(AVL<T>* Root_Node);
    void Update_Height(AVL<T>* Root_Node,bool dir = false);
    AVL<T>* getRight() override;
    AVL<T>* getLeft() override;
    void setRight(AVL<T>** Root_Node);
    void setLeft(AVL<T>** Root_Node);
    void create_new(T datum,bool right) override;
    /*
    Comment: Dmitrij Sitenko 
    Modify Insert Function from inherited BST class by including left-right rotation after
    each insert. This yields a balanced BST after each insertion call by recursivaly
     balancing each subtree where insert is called 
    */
    void insert(T datum) override;
    void deleteNode(T datum,bool is_root = true,bool Parent_Pos = true);
};