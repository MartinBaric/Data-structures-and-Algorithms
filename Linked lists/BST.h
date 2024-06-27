#include "BinaryTree.h"

template <typename T>
class BST : public Node
{
    void insert(T datum)
    {
        if (this->data < datum)
        {
            if(this->right != NULL)
                this->right->insert(datum);
            else{
                Node<T>* n = new Node(datum);
                this->right = n;
            }
        }
        else if (this->data > datum)
        {
            if(this->left != NULL)
                this->left->insert(datum);
            else{
                Node<T>* n = new Node(datum);
                this->left = n;
            }
        }
    }

   void deleteNode(T datum)
    {
        if (this->data == datum)
        {
            if (this->right == NULL)
                {
                Node<T>* Aux = this->left;
                if(Aux == NULL)
                {
                    // Return NULL pointer to parent to avoid memory error 
                    // TODO Check other cases (May be not elegant solution)
                    delete this;
                    //this->data = NULL;
                }
                else{
                    this->data = Aux->data;
                    this->left = Aux->left;
                    this->right = Aux->right;
                }
                delete Aux;
                }
            else if (this->right != NULL)
                {
                Node<T>* Pt_parent = this;
                Node<T>* Pt_successor = this->right; 
                // Aux Variable set true if next succassor is in the right node
                bool If_Root = true; 
                while(Pt_successor->left!=NULL) 
                    {   
                        If_Root = false; //set to false if next successor is the left branch of the right node
                        Pt_parent = Pt_successor;
                        Pt_successor = Pt_successor->left;
                    }
                // Overwrite data to be deleted with next leftmost successor
                this->data = Pt_successor->data;
                // Reset Pointer to avoid memory issues
                if(If_Root == false)
                    Pt_parent->left = Pt_successor->right;
                else
                    Pt_parent->right = NULL;
                // Delete Leaf
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
};