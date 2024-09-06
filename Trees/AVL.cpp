#include "AVL.h" 

template <class T>
AVL<T> :: AVL(T value)
{
    this->data = value;
    this->left = this->right = NULL;
    this->height = 0;  
    this->parent = NULL;
}

template <class T>
void AVL<T>::printData()
{
    cout <<  this->data <<  ",";
    cout << "Height: "   << this->height << "\n";
}

template <class T>
void AVL<T>::Rotate(AVL<T>* Root_Node)
{
    int height_left,height_right;
    if(Root_Node->right == NULL)
        height_right = -1;
    else
        height_right = Root_Node->right->height;
    if(Root_Node->left == NULL)
        height_left = -1;
    else
        {
        height_left = Root_Node->left->height;
        }
    if (height_left-height_right >1)
    {
        if(Root_Node->left->left == NULL)
        {
            BST<T>::Rotate_L(&(Root_Node->left)); //Left Rotate
            Update_Height(Root_Node->left,true); 
            BST<T>::Rotate_R(&Root_Node); 
            Update_Height(Root_Node); 
        }
        else if(Root_Node->left->right == NULL)
        {
            BST<T>::Rotate_R(&Root_Node); //Right Rotate 
            Update_Height(Root_Node);
        }
        else if(Root_Node->left->right->height-Root_Node->left->left->height==1)
        {
            BST<T>::Rotate_L(&(Root_Node->left)); //Left Rotate 
            Update_Height(Root_Node->left,true);
            BST<T>::Rotate_R(&Root_Node); // Right Rotate
            Update_Height(Root_Node);
        }
        else
        {
            BST<T>::Rotate_R(&Root_Node); // Right Rotate
            Update_Height(Root_Node);
        }
    }
    // Else perform left or right left rotation 
    else if (height_right-height_left> 1)
    {
        if(Root_Node->right->right == NULL)
        {
            BST<T>::Rotate_R(&(Root_Node->right)); //Right Rotate 
            Update_Height(Root_Node->right);
            BST<T>::Rotate_L(&Root_Node);
            Update_Height(Root_Node,true);
        }
        else if(Root_Node->right->left == NULL)
        {
            BST<T>::Rotate_L(&Root_Node); //Left Rotate
            Update_Height(Root_Node,true); 
        }
        else if(Root_Node->right->left->height-Root_Node->right->right->height==1)
        {
            BST<T>::Rotate_R(&(Root_Node->right)); //Right Rotate 
            Update_Height(Root_Node->right);
            BST<T>::Rotate_L(&Root_Node); //Left Rotate
            Update_Height(Root_Node,true); 
        }
        else
        {
            BST<T>::Rotate_L(&Root_Node); //Left Rotate
            Update_Height(Root_Node,true);        
        }
    }
}

template <class T>
void AVL<T>::Update_Height(AVL<T>* Root_Node,bool dir)
{
    if(dir == false)
    {
        // Update Heigth after right Rotation
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
        // Update Heigth after left Rotation
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
    if(*n != NULL)   
        this->right->parent = this;
}   

template <class T>
void AVL<T>::setLeft(AVL<T>** n)
{
    this->left = *n;
    if(*n != NULL)   
        this->left->parent = this;
}

template <class T>
void AVL<T>::create_new(T datum,bool right)
{
    AVL<T>* n = new AVL(datum);
    n->parent = this;
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
            this->create_new(datum,false);
            if(this->getRight() == NULL)
                this->height+= 1;
        }
    }
    Rotate(this);
}

template <class T>
void AVL<T>::deleteNode(T datum, bool is_root, bool Parent_Pos)
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
                    cout << "The tree is completely destroyed \n";
                }
                else
                {
                    if(Parent_Pos == true)
                    {
                        this->parent->left = NULL;
                        if (this->parent->right != NULL)
                            this->parent->height = this->parent->right->height+1;
                        else
                            this->parent->height = 0; 
                    }
                    else
                    {   
                        this->parent->right = NULL;
                        if (this->parent->left != NULL)
                            this->parent->height = this->parent->left->height+1;
                        else
                            this->parent->height = 0;
                    }
                    delete this;
                }

            }
            else
            {
                // Remains balanced 
                this->data = this->left->data;
                this->height = this->left->height;
                this->right = this->left->right;
                this->left = this->left->left;
                if (is_root == false)
                {
                    if(Parent_Pos == true)
                    {
                        if(this->parent->right != NULL)
                            this->parent->height = int(max(this->height,this->parent->right->height))+1;
                        else
                            this->parent->height = this->height+1;
                    }
                    else
                    {
                        if(this->parent->left != NULL)
                            this->parent->height = int(max(this->height,this->parent->left->height))+1;
                        else
                            this->parent->height = this->height+1;
                    }
                }
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
                if(Pt_parent->right != NULL)
                    Pt_parent->height = int(max(Pt_parent->left->height,Pt_parent->right->height))+1;
                else
                    Pt_parent->height = Pt_parent->left->height+1;  
                while(Pt_parent != this)
                {
                    Rotate(Pt_parent);
                    Pt_parent = Pt_parent->parent;
                    if(Pt_parent->right != NULL)
                        Pt_parent->height = int(max(Pt_parent->left->height,Pt_parent->right->height))+1;
                    else
                        Pt_parent->height = Pt_parent->left->height+1; 
                }
                Rotate(Pt_parent);
            }
            else
            {
                Pt_parent->left = NULL;
                if(Pt_parent->right != NULL)
                    Pt_parent->height = Pt_parent->right->height+1;
                else
                    Pt_parent->height = 0;  
                while(Pt_parent != this)
                {
                    Rotate(Pt_parent);
                    Pt_parent = Pt_parent->parent;
                }
                Rotate(Pt_parent); 
            }
            Pt_successor->data = datum;
            delete Pt_successor;
        }
        /*
        if(is_root == false & this != NULL)
        {
            if(this->parent->left == NULL)
                this->parent->height = this->right->height;
            else if(this->parent->right == NULL)
                this->parent->height = this->height;
            else
                this->parent->height = int(max(this->parent->right->height,this->parent->left->height));
        }
        */

    }
    else if (this->data > datum)
    {
        if(this->left != NULL)
        {
            this->left->deleteNode(datum,false,true);    
            Rotate(this);
            if(Parent_Pos == true)
                    {
                        if(this->parent->right != NULL)
                            this->parent->height = int(max(this->height,this->parent->right->height))+1;
                        else
                            this->parent->height = this->height+1;
                    }
                    else
                    {
                        if(this->parent->left != NULL)
                            this->parent->height = int(max(this->height,this->parent->left->height))+1;
                        else
                            this->parent->height = this->height+1;
                    }
        }
        else
            cout << "Das gewünschte Datum existiert nicht.\n";
    }
    else if (this->data < datum)
    {
        if(this->right != NULL)
        {
            this->right->deleteNode(datum,false,false);
            Rotate(this);
            if(this->parent != NULL)
            {
                if(Parent_Pos == true)
                        {
                            if(this->parent->right != NULL)
                                this->parent->height = int(max(this->height,this->parent->right->height))+1;
                            else
                                this->parent->height = this->height+1;
                        }
                else
                {
                    if(this->parent->left != NULL)
                        this->parent->height = int(max(this->height,this->parent->left->height))+1;
                    else
                        this->parent->height = this->height+1;
                        }
            }
        }
        else
            cout << "Das gewünschte Datum existiert nicht.\n";
    }
}

//template class AVL<int>;