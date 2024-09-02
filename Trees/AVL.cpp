#include "AVL.h" 

template <class T>
AVL<T> :: AVL(T value)
{
    this->data = value;
    this->left = this->right = NULL;
    this->height = 0;  
}

template <class T>
void AVL<T>::printData()
{
    cout <<  this->data <<  ",";
    cout << "Height: "   << this->height << "\n";
}

template <class T>
void AVL<T>::Rotate(AVL<T>* Root_Node,bool dir)
{
    if(dir == false)
    {
        BST<T>::Rotate_R(&Root_Node);
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
        BST<T>::Rotate_L(&Root_Node);
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

template <class T>
AVL<T>* AVL<T>::getRight()
{
    return this->right;
}

template <class T>
AVL<T>* AVL<T>::getLeft()
{
    return this->left;
}
template <class T>
void AVL<T>::setRight(AVL<T>** n)
{
    this->right = *n;
}   

template <class T>
void AVL<T>::setLeft(AVL<T>** n)
{
    this->left = *n;
}

template <class T>
void AVL<T>:: create_new(T datum,bool right)
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
    balancing each left and right subtree after insert is called 
*/

template <class T>
void AVL<T>::insert(T datum)
{
    int height_left,height_right;
    if (this->data < datum)
    {
        if(this->getRight() != NULL)
        {
            this->getRight()->insert(datum);
            if(this->getLeft() != NULL)
                this->height = int(max(this->getLeft()->height+1,this->getRight()->height+1));
            else
                this->height = this->getRight()->height+1;
        }
        else{
            this->create_new(datum,true);
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
        //Rotate(this)
        
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

template <class T>
void AVL<T>::deleteNode(T datum, AVL<T>* Parent, bool is_root, bool Parent_Pos)
{
    if (this->data == datum)
    {
        if (this->right == NULL)
        {
            if(this->left == NULL)
            {
                if(is_root == true)
                {    
                    delete this;
                    cout << "The tree is completely destroyed";
                }
                else
                    {
                        // If the left child was called
                        if(Parent_Pos == true)
                            Parent->left = NULL;
                        else 
                            Parent->right = NULL;
                    }
            }
            else
            {
                this->data = this->left->data;
                this->right = this->left->right;
                this->left = this->left->left;
                this->height = int(max(this->left->height,this->right->height));
            }
        }
        else
        {
            AVL<T>* Pt_parent = this;
            AVL<T>* Pt_successor = this->right; 
            while(Pt_successor->left!=NULL) 
            {   
                Pt_parent = Pt_successor;
                Pt_successor = Pt_successor->left;
            }
            this->data = Pt_successor->data;
            if(Pt_successor->right != NULL)
            {
                Pt_parent->left = Pt_successor->right;
                Pt_parent->height = int(max(Pt_parent->left->height,Pt_parent->right->height));
            }
            else
            {
                Pt_parent->left = NULL;
                Pt_parent->height -=1; 
            }
            Pt_successor->data = datum;
            delete Pt_successor;
        }

    }
    else if (this->data > datum)
    {
        if(this->left != NULL)
            this->left->deleteNode(datum,this,false,true);    
        else
            cout << "Das gewünschte Datum existiert nicht.\n";
    }
    else if (this->data < datum)
    {
        if(this->right != NULL)
            this->right->deleteNode(datum,this,false,false);
        else
            cout << "Das gewünschte Datum existiert nicht.\n";
    }
}

//template class AVL<int>;