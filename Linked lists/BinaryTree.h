#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Node
{
private:
    Node* left;
    Node* right;
    T data;

public:
    Node(T value)
    {
        this->data = value;
        left = right = NULL;    
    }

    ~Node()
    {
        cout << "Das gewünschte Datum wurde gelöscht\n";
    }


    T get_value()
    {
        return this->data;
    }

    void print_value()
        {
            cout << get_value() << ",";
        }
    void inorder()
        {
            if(left!=NULL)
                left->inorder();
            print_value();
            if(right!=NULL)
                right->inorder(); 
        }
     void preorder()
        {
            print_value();
            if(left!=NULL)
                left->preorder();
            if(right!=NULL)
                right->preorder(); 
        }
     void postorder()
        {
            if(left!=NULL)
                left->postorder();
            if(right!=NULL)
                right->postorder();
            print_value(); 
        }

    void insert(T datum)
    {
        ;//DIMA
    }

   void deleteNode(T datum)
    {
        ;//DIMA
    }
};