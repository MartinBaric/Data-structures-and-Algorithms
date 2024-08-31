#include "RBtree.h"


template <class T>
RBtree<T>::RBtree(T value, bool col)
{
    this->data = value;
    this->left = this->right = NULL;
    this->height = 0;
    this->black = col;
}

template <class T>
RBtree<T>::RBtree(T value)
{
    this->data = value;
    this->left = this->right = NULL;
    this->height = 0;
    this->black = true; 
}

template <class T>
void RBtree<T>::insert(T datum)
{
    BST<T>::insert(datum);
    //rotationL();
}

template <class T>
void RBtree<T>::rotationL()
{
    ;
}
template <class T>
RBtree<T>* RBtree<T>::getRight()
{
    return this->right;
}

template <class T>
RBtree<T>* RBtree<T>::getLeft()
{
    return this->left;
}

template <class T>
void RBtree<T>::setRight(RBtree<T>* n)
{
    this->right = n;
}

template <class T>
void RBtree<T>::setLeft(RBtree<T>* n)
{
    this->left = n;
}
template <class T>
void RBtree<T>::create_new(T datum,bool right)
{
    RBtree<T>* n = new RBtree(datum, false);
    if(right == true)
        this->right = n;
    else
        this->left = n;
}

template class RBtree<int>;