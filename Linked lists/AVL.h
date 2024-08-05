#include "BST.h"

template <typename T>
class AVL : public BST<T>
{
    void insert(T datum)
    {
        BST::insert(datum);
        rotationL();
    }
    void rotationL()
    {

    }
};