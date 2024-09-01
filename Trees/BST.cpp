#include "BST.h"
#include <memory>

/* Note: This means. We define the constructor of BST using the definition 
of the constructor of Node BST(T value)::Node<T>(value);*/


template <class T>
BST<T>::BST(T value)
{
    this->data = value;
    this->left = this->right = NULL;
    this->height = 0;
}

/*template <class T>
BST<T>::BST()
{
    this->left = this->right = NULL;
    this->height = 0;
}*/

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
void BST<T>:: setRight(BST<T>** n)
{
    this->right = *n;
}

template <class T>
void BST<T>::setLeft(BST<T>** n)
{
    this->left = *n;
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
template <typename S>
void BST<T>::Rotate_R(S** Root_Node)
{
    S* Node_Aux = (*Root_Node)->getLeft()->getRight();
    T Val_Aux = (*Root_Node)->getLeft()->getData();
    S* Node_Aux_1 = (*Root_Node)->getRight();
    S* Node_Aux_2 = (*Root_Node)->getLeft();
    (*Root_Node)->getLeft()->setRight(&Node_Aux_1); 
    (*Root_Node)->setRight(&Node_Aux_2);
    Node_Aux_2 = Node_Aux_2->getLeft();
    (*Root_Node)->setLeft(&Node_Aux_2);
    (*Root_Node)->getRight()->setLeft(&Node_Aux);
    (*Root_Node)->getRight()->data = (*Root_Node)->getData();
    (*Root_Node)->data = Val_Aux;
};

template <class T>
template <typename S>
void BST<T>::Rotate_L(S** Root_Node)
{
    T Val_Aux = (*Root_Node)->getRight()->getData();
    S* Node_Aux = ((*Root_Node)->getRight())->getLeft();      
    S* Node_Aux_1 = (*Root_Node)->getLeft();   
    S* Node_Aux_2 = (*Root_Node)->getRight();
    (*Root_Node)->getRight()->setLeft(&Node_Aux_1);
    (*Root_Node)->setLeft(&Node_Aux_2);
    Node_Aux_2 = Node_Aux_2->getRight();
    (*Root_Node)->setRight(&Node_Aux_2);
    (*Root_Node)->getLeft()->setRight(&Node_Aux);    
    (*Root_Node)->getLeft()->data = (*Root_Node)->getData();
    (*Root_Node)->data = Val_Aux;
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
    if (this == NULL)
    {
        //this->BST<T>(datum);      
        //this->data = datum;
    }
    else {
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
}

template <class T>
void BST<T>::deleteNode(T datum, bool isRoot)
{
    if (this->data == datum)
    {
        if (this->right == NULL)
        {
            if(this->left == NULL)
            {
                if(!isRoot)
                    delete this;
                    // Return NULL pointer to parent to avoid memory issues
                if (isRoot)
                    //this->BST();
                    cout << "Tree has been destroyed.\n";
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
            this->left->deleteNode(datum, false);
        else{
            cout << "Das gewünschte Datum existiert nicht.\n";
        }
    }
    else if (this->data < datum)
    {
        if(this->right != NULL)
            this->right->deleteNode(datum, false);
        else{
            cout << "Das gewünschte Datum existiert nicht.\n";
        }
    }
}

template class BST<int>;