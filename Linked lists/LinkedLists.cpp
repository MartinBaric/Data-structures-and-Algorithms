#include <iostream>
#include <fstream> // For reading/writing files
#include <string>
#include <list>
#include <omp.h> // OpenMultiProcessing library for parallel programming
//#include <random>
#include "SortingAlgorithmsOnArrays.cpp"
#include "BinaryTree.h"

using namespace std;

const int NUM_THREADS = 4;

void initializeArray(list<int>& elementsList, int* elementsArray)
{
    int i = 0;

    for(int element: elementsList){
        elementsArray[i] = int(element);
        i++;
    }
}

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

void printElements(int* elementsArray, int elementsSize, list<Swap_Pos>& Swap_List)
{
    for(int k = 0; k < elementsSize; k++) {
       cout << elementsArray[k] << "\n";
    }

        for (auto it = Swap_List.begin(); it != Swap_List.end(); ++it) {
    cout <<"(" << it->New_pos << "," << it->Old_pos << ")";
    }
}
