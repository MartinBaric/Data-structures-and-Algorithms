#include "BST.h"

template <typename T>
class RBtree : public BST<T>
{
    private:
    RBtree* left;
    ARBtreeVL* right;
    bool color; //true = black, red = false;
    
    public:
    
    RBtree(T value, bool col)
    {
        this->data = value;
        this->left = this->right = NULL;
        this->height = 0;
        this->color = col;
    }

    using BST<T>::BST; 
    RBtree(T value)
    {
        this->data = value;
        this->left = this->right = NULL;
        this->height = 0;
        this->color = true; 
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
    RBtree<T>* getRight() override
    {
        return this->right;
    }

    RBtree<T>* getLeft() override
    {
        return this->left;
    }

    void setRight(RBtree<T> n)
    {
        this->right = n;
    }

    void setLeft(RBtree<T> n)
    {
        this->left = n;
    }
    void create_new(T datum,bool right) override
    {
        AVL<T>* n = new AVL(datum);
        if(right == true)
            this->right = n;
        else
            this->left = n;
    }
};