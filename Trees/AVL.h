#pragma once
#include "BST.h"
#include <algorithm>

template <typename T>
class AVL : public BST<T>
{
    private:
    AVL* left;
    AVL* right;
    
    protected:

    // long long int to be compatible with the max function below
    long long int height = 0;

    public:
    
    using BST<T>::BST;
    AVL(T value)
    {
        this->data = value;
        this->left = this->right = NULL;
        this->height = 0;  
    }

    void printData() 
        {
            cout <<  this->data <<  ",";
            cout << "Height: "   << this->height << "\n";
        }

    void inorder()
        {
            if(getLeft()!=NULL)
                getLeft()->inorder();
            printData();
            if(getRight()!=NULL)
                getRight()->inorder(); 
        }

    void Rotate(AVL<T>* Root_Node,bool dir = false)
    {
        if(dir == false)
        {
            /*
            if(Root_Node->left->height - Root_Node->right->height == 1)
            {
                AVL<T>* Node_Aux = Root_Node->left->left;
                Root_Node->right = Root_Node->left:
                Root->right->right = Node_Aux;
                Root_Node->data = 
            }
            else:
            {
            */
            AVL<T>* Node_Aux = Root_Node->left->right;
            T Val_Aux = Root_Node->left->data;
            Root_Node->left->right = Root_Node->right;
            Root_Node->right = Root_Node->left;
            Root_Node->left = Root_Node->left->left;
            Root_Node->right->left = Node_Aux;
            Root_Node->right->data = Root_Node->data;
            Root_Node->data = Val_Aux;
            // Update Heigth
            Root_Node->height -= 1; 
            if(Root_Node->right->left != NULL & Root_Node->right->right != NULL)
                Root_Node->right->height = max(Root_Node->right->left->height+1,Root_Node->right->right->height+1);
            else if (Root_Node->right->left == NULL and Root_Node->right->right != NULL)
                Root_Node->right->height = Root_Node->right->right->height+1;
            else if (Root_Node->right->right == NULL and Root_Node->right->left != NULL)
                Root_Node->right->height = Root_Node->right->left->height+1;
            else 
                Root_Node->right->height = 0; 
        }
        else if (dir == true)
        {    
            T Val_Aux = Root_Node->right->data;
            AVL<T>* Node_Aux = Root_Node->right->left;     
            Root_Node->right->left = Root_Node->left;
            Root_Node->left = Root_Node->right;
            Root_Node->right = Root_Node->right->right;
            Root_Node->left->right = Node_Aux;
            Root_Node->left->data = Root_Node->data;
            Root_Node->data = Val_Aux;
            // Update Heigth 
            Root_Node->height -= 1;
            if(Root_Node->left->right != NULL & Root_Node->left->left != NULL)
                Root_Node->left->height = max(Root_Node->left->left->height+1,Root_Node->left->right->height+1);
            else if (Root_Node->left->left == NULL & Root_Node->left->right != NULL)
                Root_Node->left->height = Root_Node->right->right->height+1;
            else if (Root_Node->left->right == NULL & Root_Node->left->left != NULL)
                Root_Node->left->height = Root_Node->left->left->height+1;
            else 
                Root_Node->left->height = 0; 
        }
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

    /*
    Comment: Dmitrij Sitenko 
    Modify Insert Function from inherited BST class by including left-right rotation after
    each insert. This yields a balanced BST after each insertion call by recursivaly
     balancing each subtree where insert is called 
    */

    void insert(T datum) override
    {
        long long int height_left,height_right;
        if (this->data < datum)
        {
            if(this->getRight() != NULL)
            {
                this->getRight()->insert(datum);
                if(this->getLeft() != NULL)
                    this->height = max(this->getLeft()->height+1,this->getRight()->height+1);
                else
                    this->height = this->getRight()->height+1;

            }
            else{
                create_new(datum,true);
                if(this->getLeft() == NULL)
                    this->height +=1; 
            }

        }
        else if (this->data > datum)
        {
            if(this->getLeft() != NULL)
            {
                this->getLeft()->insert(datum);
                if(this->getRight() != NULL)
                    this->height = max(this->getLeft()->height+1,this->getRight()->height+1);
                else
                    this->height = this->getLeft()->height+1;
            }
            else
            {
                create_new(datum,false);
                if(this->getRight() == NULL)
                    this->height+= 1;
            }
        }
        /*
         If the height of the left subtree is 2 levels
         bigger then the right subtree perform right or left right rotation
        */
       
        if(this->right == NULL)
            height_right = -1;
        else
            height_right = this->right->height;
        if(this->left == NULL)
            height_left = -1;
        else
            {
            height_left = this->left->height;
            }
        if (height_left-height_right >1)
        {
            if(this->left->left == NULL)
            {
                Rotate(this->left,true); //Left Rotate 
                Rotate(this); 
            }
            else if(this->left->right == NULL)
                Rotate(this); //Right Rotate 
            else if(this->left->right->height-this->left->left->height==1)
            {
                Rotate(this->left,true); //Left Rotate 
                Rotate(this); // Right Rotate
            }
            else
                Rotate(this); // Right Rotate

        }
        // Else perform left or right left rotation 
        else if (height_right-height_left> 1)
        {
            if(this->right->right == NULL)
            {
                Rotate(this->right); //Right Rotate 
                Rotate(this,true);
            }
            else if(this->right->left == NULL)
                Rotate(this,true); //Left Rotate 
            else if(this->right->left->height-this->right->right->height==1)
            {
                Rotate(this->right); //Right Rotate 
                Rotate(this,true); //Left Rotate 
            }
            else
                Rotate(this,true); //Left Rotate        
        }
    }
};