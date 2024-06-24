#pragma once

template <typename T>
class Node
{
private:
    Node* left;
    Node* right;
    T data;

public:
    Node(T value);
    ~Node();
    T get_value();
    void print_value();
    void inorder();
    void preorder();
    void postorder();
    void insert(T datum);
    void deleteNode(T datum);
};