#pragma once

#include <iostream>
#include <fstream> // For reading/writing files
#include <string>
#include <list>
//#include <random>
#include "BinaryTree.h"
//#include "SortingAlgorithmsOnArrays.h"

using namespace std;

template <class T>
list<T> initializeList()
{
    fstream myfile;
    myfile.open("Test 1.csv");
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

void printElements(int*, int, list<Swap_Pos>&);