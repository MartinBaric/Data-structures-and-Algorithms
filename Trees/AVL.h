#include "BST.h"

template <typename T>
class AVL : public BST<T>
{
    private:
    AVL* left;
    AVL* right;
    
    public:
    
    using BST<T>::BST; 
    AVL(T value)
    {
        this->data = value;
        this->left = this->right = NULL;
        this->height = 0;  
    }

    //void insert(T datum)
    //{
     //   BST<T>::insert(datum);
        //rotationL();
    //}

    void rotationL()
    {
        ;
    }
    AVL<T>* getRight() override
    {
        return this->right;
    }

    AVL<T>* getLeft() override
    {
        return this->left;
    }

    void setRight(AVL<T> n)
    {
        this->right = n;
    }

    void setLeft(AVL<T> n)
    {
        this->left = n;
    }
    void create_new(T datum,bool right)
    {
        AVL<T>* n = new AVL(datum);
        if(right == true)
            this->right = n;
        else
            this->left = n;
    }
};