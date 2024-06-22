template <typename T> class Node
{
private:
    Node* left;
    Node* right;
    T data;

public:
    Node(T value)
    {
        this->data = value;
        left = right = NULL;    
    }

    ~Node()
    {
        cout << "Das gewünschte Datum wurde gelöscht\n";
    }


    T get_value()
    {
        return this->data;
    }

    bool left_NULL()
    {
        if (this->left == NULL)
            return true;
        else return false;
    }
    void print_value()
        {
            cout << get_value() << "\n";
        }
    void inorder()
        {
            if(left!=NULL)
                left->inorder();
            print_value();
            if(right!=NULL)
                right->inorder(); 
        }
     void preorder()
        {
            print_value();
            if(left!=NULL)
                left->preorder();
            if(right!=NULL)
                right->preorder(); 
        }
     void postorder()
        {
            if(left!=NULL)
                left->postorder();
            if(right!=NULL)
                right->postorder();
            print_value(); 
        }

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