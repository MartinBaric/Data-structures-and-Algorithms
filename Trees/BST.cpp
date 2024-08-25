#include "BST.h"

/* Note: This means. We define the constructor of BST using the definition 
of the constructor of Node BST(T value)::Node<T>(value);*/


template <class T>
BST<T>::BST(T value)
{
    this->data = value;
    this->left = this->right = NULL;
    //this->height = 0;  
}

template <class T>
BST<T>* BST<T>::getRight()
{
    return this->right;
}

template <class T>
BST<T>* BST<T>::getLeft()
{
    return this->left;
}

template <class T>
void BST<T>::setRight(BST<T> n)
{
    this->right = n;
}

template <class T>
void BST<T>::setLeft(BST<T> n)
{
    this->left = n;
}

template <class T>
void BST<T>::create_new(T datum,bool right)
{
    BST<T>* n = new BST(datum);
    if(right == true)
        this->right = n;
    else
        this->left = n;
}

template <class T>
void BST<T>::inorder()
{
    if(this->getLeft()!=NULL)
        this->getLeft()->inorder();
    this->printData();
    if(this->getRight()!=NULL)
        this->getRight()->inorder(); 
}

template <class T>
void BST<T>::insert(T datum)
{
    if (this->data < datum)
    {
        if(this->getRight() != NULL)
            this->getRight()->insert(datum);
        else{
            create_new(datum,true);
        }
    }
    else if (this->data > datum)
    {
        if(this->getLeft() != NULL)
            this->getLeft()->insert(datum);
        else{
            create_new(datum,false);
        }
    }
}

template <class T>
void BST<T>::deleteNode(T datum)
{
    if (this->data == datum)
    {
        if (this->right == NULL)
        {
            if(this->left == NULL)
            {
                // Return NULL pointer to parent to avoid memory issues
                delete this;
            }
            else
            {
                this->data = this->left->data;
                this->right = this->left->right;
                this->left = this->left->left;
            }
        }
        else
        {
            BST<T>* Pt_parent = this;
            BST<T>* Pt_successor = this->right; 
            while(Pt_successor->left!=NULL) 
            {   
                Pt_parent = Pt_successor;
                Pt_successor = Pt_successor->left;
            }
            // Overwrite data to be deleted with next leftmost successor
            this->data = Pt_successor->data;
            // Link Pointer at the most bottom leaf to avoid memory issues
            if(Pt_successor->right != NULL)
                Pt_parent->left = Pt_successor->right;
            else
                Pt_parent->right = NULL;
            // Delete Leaf
            Pt_successor->data = datum;
            delete Pt_successor;
        }

    }
    else if (this->data > datum)
    {
        if(this->left != NULL)
            this->left->deleteNode(datum);
        else{
            cout << "Das gewünschte Datum existiert nicht.\n";
        }
    }
    else if (this->data < datum)
    {
        if(this->right != NULL)
            this->right->deleteNode(datum);
        else{
            cout << "Das gewünschte Datum existiert nicht.\n";
        }
    }
}