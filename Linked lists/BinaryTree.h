#pragma once
// C++ 11 Standard extend std library with next function 
//#include <iterator>
#include <iostream>

using namespace std;

template <typename T>
class Node{
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

    void print_value()
        {
            cout << get_value() << ",";
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

    // Initialize Tree via Breadth First Search manner level by level
    void insert(T datum)
    {
        /* Intialize two ques which saves the nodes to be explored in the current and next level
         with a First In First Out (FIFO) Data Strucutre for traversing and removing visited nodes. Therefore insread
         of using vector datastrucure which is Last In First Out (LIFO) we use a list
          with implemented push_back() -> First in (first element),pop_front() fisrt out (1 Element) */ 
        // Auxiliary Pointer to the current position within the list
        Node* Current_Node = this;
        list<Node*> Q_level;
        Q_level.push_back(Current_Node);
        //typename std::list<Node*>::iterator It = Q_level.begin();
        //(*(It))->print_value();
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
            for(typename std::list<Node*>::iterator It_2 = Q_next_level.begin();It_2 != Q_next_level.end();++It_2)
                {
                    Q_level.push_front((*It_2));
                }
            Q_next_level.clear();
        }
        Current_Node = (*Aux_Balanance.begin());
        if(Current_Node->left==NULL)
            Current_Node->left = new Node(datum);
        else
            Current_Node->right = new Node(datum);
        Aux_Balanance.clear();
        //delete(&Current_Node);
        //delete(Q_level);
        //delete(Q_next_level);
    }

   void deleteNode(T datum)
    {
        ;//DIMA
    }
};