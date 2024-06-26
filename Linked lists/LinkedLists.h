#pragma once

#include <iostream>
#include <fstream> // For reading/writing files
#include <string>
#include <list>
//#include <random>
#include "BinaryTree.h"
#include "SwapPosition.h"

using namespace std;

void initializeArray(list<int>& elementsList, int* elementsArray);

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
Node<T> initializeTree(list<int>& elementsList)
{
    
}

void printElements(int* elementsArray, int elementsSize, list<Swap_Pos>& Swap_List);