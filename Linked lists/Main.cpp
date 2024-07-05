#include <iostream>
#include <fstream> // For reading/writing files
#include <string>
#include <list>
#include <omp.h> // OpenMultiProcessing library for parallel programming
//#include <random>
#include "SortingAlgorithmsOnArrays.h"
#include "BinaryTree.h"
#include "LinkedLists.h"

using namespace std;

const int NUM_THREADS = 4;

int main()
{
    //omp_set_num_threads(NUM_THREADS);
    list<int> elementsList = initializeList<int>();
    // Convert to Array for Quicksort Efficiency
    int elementsSize = elementsList.size();
    int* elementsArray = (int*) malloc(elementsSize*sizeof(elementsList.front()));
    initializeArray(elementsList, elementsArray);

    Node<int> *root = new Node<int>(11);
    //Node<int>* root = initializeTree(elementsList);
    root->insert(10);
    root->insert(15);
    root->insert(1);
    root->insert(6);
    root->insert(12);
    root->insert(7);
    root->inorder();
    //root.insert(5);
    //root.deleteNode(4);
    //root->deleteNode(11);
    //root->inorder();
    //root->insert(13);
    //root->inorder();
    //root->insert(11);
    //root->inorder();
    //root->deleteNode(10); */
    //root->inorder();

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
