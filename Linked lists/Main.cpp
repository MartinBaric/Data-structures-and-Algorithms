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
    Node<T> *root = new Node<T>();

    return root;
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

int main()
{
    //omp_set_num_threads(NUM_THREADS);
    list<int> elementsList = initializeList<int>();
    // Convert to Array for Quicksort Efficiency
    int elementsSize = elementsList.size();
    int* elementsArray = (int*) malloc(elementsSize*sizeof(elementsList.front()));
    initializeArray(elementsList, elementsArray);

    Node<int> *root = new Node<int>(11);//initializeTree(elementsList);//
    root->insert(10);
    root->insert(12);
    root->insert(7);
    root->insert(5);
    root->deleteNode(4);
    root->inorder();
    root->deleteNode(11);
    root->inorder();
    root->insert(13);
    root->inorder();
    root->insert(11);
    root->inorder();
    root->deleteNode(10);
    root->inorder();

    //list<Swap_Pos> Swap_List;
    //quickSort(&elementsArray[0], 0, elementsSize, Swap_List, true);
    //bubbleSort(elementsArray, elementsSize);
    //mergeSort(elementsArray, elementsSize);
    //#pragma omp parallel
    /*{
        bubbleSort(elementsList);
        insertSort(elementsList);
        quickSort(&elementsList_array[0],0,i);
    }*/
    //printElements(elementsArray, elementsSize, Swap_List);

    free(elementsArray);
    
    return 0;
}
