#include "BinaryTree.h"

template <typename T>
class BST : public Node<T>
{
    private:
    BST* left;
    BST* right;


    public:
    /* Note: This means. We define the constructor of BST using the definition 
    of the constructor of Node BST(T value)::Node<T>(value);*/
    using Node<T>::Node;
    BST(T value);
    /* Since the C++ 11 Standard constructors can be inherited;
    it takes all the constructors of the parent class BinaryTree*/ 

    BST<T>* getRight() override;
    BST<T>* getLeft() override;
    void setRight(BST<T> n);
    void setLeft(BST<T> n);

    virtual void create_new(T datum,bool right);

    void inorder() override;
    void insert(T datum) override;
    void deleteNode(T datum);
};