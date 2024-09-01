#include "BST.h"

template <typename T>
class RBtree : public BST<T>
{
    private:

    RBtree* left;
    RBtree* right;
    bool black; //true = black, red = false;
    
    public:
    
    RBtree(T value, bool col);

    using BST<T>::BST; 
    RBtree(T value);

    //void insert(T datum)
    //{
     //   BST<T>::insert(datum);
        //rotationL();
    //}

    void rotationL();
    RBtree<T>* getRight() override;
    RBtree<T>* getLeft() override;
    void setRight(RBtree<T>* n);
    void setLeft(RBtree<T>* n);

    void insert(T datum) override;
    void create_new(T datum,bool right) override;
};