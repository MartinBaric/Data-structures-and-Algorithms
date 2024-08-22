#pragma once

#include "Input.h"
#include "../Trees/BinaryTree.h"

//"Test 1.csv"
template <class T>
list<T> initializeList(string input_file)
{
    fstream myfile;
    myfile.open(input_file);
    string line;
    list<T> elements;
    
    while(getline(myfile, line))
        elements.push_back(stoi(line));

    myfile.close();

    return elements;
}

template <class T>
Node<T>* initializeTree(list<T>& elementsList)
{
    Node<T>* root = new Node<T>(*(elementsList.begin()));
    for(auto it = elementsList.begin();it!= --(--elementsList.end());++it ){
        root->insert(*it);
    }
    return root;
}

template <class T>
void initializeArray(list<T>& elementsList, int* elementsArray)
{
    int i = 0;

    for(T element: elementsList){
        elementsArray[i] = int(element);
        i++;
    }
}