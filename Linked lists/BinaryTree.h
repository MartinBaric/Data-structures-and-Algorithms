#pragma once
// C++ 11 Standard extend std library with next function 
//#include <iterator>
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Node{
private:
    Node* left;
    Node* right;    

//Protected : a derived class can access these data.
protected:
    T data;
    int height;

public:
    Node(){
        height = 0;
    }
    Node(T value)
    {
        this->data = value;
        left = right = NULL;
        height = 0;    
    }
    ~Node()
    {
        cout << "Data " << this->data << " removed from the tree\n";
    }
    T get_value()
    {
        return this->data;
    }

    void print_value()
        {
            cout <<  get_value() <<  ",";
        }
    void update_height()
    {
        this->height = 0;
        Node<T>* Currrent_Node = this;
        while(Currrent_Node->left != NULL)
        {
            this->height +=1;
            Currrent_Node = Currrent_Node->left;
        }
    }

    void print_tree()
        {   
        Node* Current_Node = this;
        int height = this->height+1;
        int num_child = 2;
        int k = 0;
        cout << "Current heigth: " << this->height<< "\n";
        cout << string(height*3,' ') << Current_Node-> get_value()<<string(height,' ') <<"\n";
        cout << string((height-1)*3+1,' ') << "/"; 
        cout << string(height,' ') << "\\"<< "\n"; 
        cout << string((height-1)*3,' ') << "/"; 
        cout << string((height+2),' ') << "\\"<< "\n"; 
        list<Node*> Q_level;
        Q_level.push_back(Current_Node);
        list<Node*> Q_next_level;
        while(Q_level.size() != 0 && height != 1)
        {
            height -= 1;
            k += 1; 
            if(k<= (height-1)*3)
                cout << string((height-1)*3-k,' ');
            for(typename std::list<Node*>::iterator It = Q_level.begin();It != Q_level.end();)
            {   
                if((*(It))->left != NULL)
                {   
                    cout << string(height*k,' ')  << ((*It)->left)->get_value() << string(1,' ');
                    Q_next_level.push_back((*(It))->left);
                }
                if((*(It))->right != NULL )
                {    
                    cout << string((height-1)*3,' ')  << ((*It)->right)->get_value();
                    Q_next_level.push_back((*(It))->right);
                }
                ++It;
                Q_level.pop_front();
            }
            if(height>2)
            {   
                cout << "\n";
                cout << string((height-1)*3,' ') << "/"; 
                cout << string(height-1,' ') << "\\"<< " "; 
                for(int i = 1;i<num_child;i++)
                {
                    cout << string(height*2-1,' ') << "/"; 
                    cout << string(height-1,' ') << "\\";    
                }
            }
            else if (height == 2)
            {
                cout << "\n";
                cout << string((height-1)*3+1,' ') << "/"; 
                cout << string(height-1,' ') << "\\"<< string(1,' '); 
                for(int i = 1;i<num_child;i++)
                {
                    cout << string(height/k,' ') << "/"; 
                    cout << string(height-1,' ') << "\\"<< " ";    
                }
            }
            num_child = num_child*2;
            cout << "\n";
            Q_level.assign(Q_next_level.begin(),Q_next_level.end());
            Q_next_level.clear();
        }
        }
    void inorder()
        {
            if(this->left!=NULL)
                this->left->inorder();
            print_value();
            if(this->right!=NULL)
                this->right->inorder(); 
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

    // Initialize Tree via Breadth First Search manner level by level
    void insert(T datum)
    {
        /* Intialize two queues which save the nodes to be explored in the current and next level
         with a First In First Out (FIFO) Data Strucutre for traversing and removing visited nodes. Therefore instead
         of using vector datastrucure which is Last In First Out (LIFO) we use a list
          with implemented push_back() -> First in (first element),pop_front() fisrt out (1 Element) */ 
        // Auxiliary Pointer to the current position within the list
        Node* Current_Node = this;
        list<Node*> Q_level;
        Q_level.push_back(Current_Node);
        list<Node*> Q_next_level;
        // Auxiliary list that stores the adresses where new datum can be inserted --> sorted level by level from left to right. Inserting new element at begin() makes the binary tree balanced
        list<Node*> Aux_Balanance;
        while(Q_level.size() != 0)
        {
            for(typename std::list<Node*>::iterator It = Q_level.begin();It != Q_level.end();)
            {  
                // Increase the pointer before removing first element from the list. This avoids memory errors due to pointer of iterator to the beginning of the list
                if((*(It))->left == NULL)
                {
                    Current_Node = (*(It));
                    Aux_Balanance.push_back((*(It)));
                }
                else if((*(It))->right == NULL )
                {
                    Current_Node = (*(It));
                    Aux_Balanance.push_back((*(It)));
                }
                else
                {
                    Q_next_level.push_back((*(It))->left);
                    Q_next_level.push_back((*(It))->right);
                }
                ++It;
                Q_level.pop_front();
            }
            Q_level.assign(Q_next_level.begin(),Q_next_level.end());
            Q_next_level.clear();
        }
        Current_Node = (*Aux_Balanance.begin());
        if(Current_Node->left==NULL)
            Current_Node->left = new Node(datum);
        else
            Current_Node->right = new Node(datum);
        Aux_Balanance.clear();
        this->update_height();
    }

    // Auxiliary Variable Tree_Root to set the pointer of the parent after deleting child. Pointer to Pointer operator Node<T>** is used in order to avoid copying data and recursively adjust the pointers 
   void deleteNode(T datum,Node<T>** Tree_Root = NULL)
    {   
        if (this->data == datum)
        {
            if (this->right == NULL)
            {    
                // If left and right node are NULL then delete NODE ( No problem with parent pointers due to root node) 
                if(this->left == NULL)
                {   
                    // If deleted node is tree root then delete 
                    if(Tree_Root == NULL)
                    {   
                        delete this;
                        cout<< "Empty Binary Tree";
                    }
                    // If not Tree Root then move Pointer of parent to chile->left
                    else
                    {
                        *Tree_Root = this->left;
                        delete this;
                    }
                }
                // If Left Node is not NULL then make left node as root 
                else
                {
                    // Copy data to root node
                    Node<T>* Aux = this->left;
                    T value = this->data;
                    this->data = Aux->data;
                    this->left = Aux->left;
                    Aux->data = value;
                    delete Aux;
                    // Set pointer to adress of node to be deleted to NUll

                }
            }
            else if (this->right != NULL)
            {
                Node<T>* Aux_root = this;
                Node<T>* Aux_right = this->right;
                while(Aux_root->right->left != NULL & Aux_root->right->right != NULL)
                {
                    Aux_root = Aux_right;
                    Aux_right = Aux_root->right;
                }
                // If the left node is NULL then right node is NULL by construction
                if(Aux_right->left == NULL)
                {
                    T value = this->data;
                    this->data = Aux_right->data;
                    Aux_right->data =  value;
                    Aux_root->right = NULL;
                    delete(Aux_right);
                }
                else
                {   
                    this->data = Aux_right->left->data;
                    Aux_root->right = NULL;
                    Aux_right = Aux_right->left;
                    delete(Aux_right);
                }

            }
        }
        else
        {
            if(this->left != NULL)
                this->left->deleteNode(datum,Tree_Root = &(this->left));
            if(this->right != NULL)
                this->right->deleteNode(datum,Tree_Root = &(this->right));
        }
    }
};