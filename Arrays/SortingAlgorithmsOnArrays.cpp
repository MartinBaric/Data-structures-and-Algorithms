#include <list>
#include "Timer.cpp"
#include "Swap_Position.h"
//#include "SortingAlgorithmsOnArrays.h"

using namespace std;
using namespace chrono;

void bubbleSort(int* elementsArray, int size)
{
    Timer t = Timer("Bubble Sort");

    for (int k = 1; k < size; k++)
    {
        for (int j = size - 1; j >= k; j--)
        {
            if (elementsArray[j - 1] > elementsArray[j])
            {
                int value = elementsArray[j - 1];
                elementsArray[j - 1] = elementsArray[j];
                elementsArray[j] = value;
            }
        }
    }
}





void insertSort(list<int>* unsorted)
{
    Timer("Insert Sort");
    int Aux;
    std::list<int>::iterator Next;
    for(std::list<int>::iterator it = (*unsorted).begin();it!=(*unsorted).end();++it)
    {
        Next = it;
        for(std::list<int>::iterator it_next = Next;it_next!=(*unsorted).end();++it_next)
        {   
            // If unsorted move rearenge values
            if((*it) > (*it_next))
            {   
                Aux = (*it);
                (*it) = (*it_next);
                (*it_next) = Aux;
            }
        }
    }
}

// Idea pass a pointer to iterator of the real reference and overwrite

void Bucket_Sort(list<int>* unsorted, int min, int max,int Bucket_num)
{
    // Create array that contain pointers to Buckets
    int Scaling = max/Bucket_num; 
    int Bucket_ind;
    // Allocate Memory for an array of Pointers to Bucket lists 
    list<int>** Bucket_Array = (list<int>**) malloc(Bucket_num*sizeof(list<int>*));
    // Initialize Buckets
    for(int i = 0;i<Bucket_num;i++)
        Bucket_Array[i] = new list<int>;//(list<int>*) malloc(sizeof(list<int>*));
    // Move Elements into BUckets 
    
    for(std::list<int>::iterator it = (*unsorted).begin();it!=(*unsorted).end();++it)
    {
        Bucket_ind = int((*it)/Scaling);
        (*Bucket_Array[Bucket_ind]).push_back((*it));
    }
    // Sort Buckets 
    for(int i = 0;i<Bucket_num;++i)
        insertSort(Bucket_Array[i]);

    // Insert Buckets into the list by itereating over original list iterator and overwrite  

    std::list<int>::iterator it_copy = (*unsorted).begin();
    for(int i = 0;i<Bucket_num;++i)
    {
        if((*Bucket_Array[i]).empty() != true)
        {
            for(std::list<int>::iterator it = (*Bucket_Array[i]).begin();it!=(*Bucket_Array[i]).end();++it)
            {    
                //cout << (*it_copy);
                (*it_copy) = *it;
                ++it_copy;
            }   
        }
    
    }
    // Print Buckets 
    
    //for(int i = 0;i<Bucket_num;++i)
    //{
    //    cout << " Elements in Bucket: " << i << "\n";
    //    for(std::list<int>::iterator bucket_element = (*Bucket_Array[i]).begin();bucket_element != (*Bucket_Array[i]).end();++bucket_element)
    //    {
     //       cout <<*bucket_element << "," << "\n";
     //   }
    //}
    free(Bucket_Array);
}

// Merge two sorted arrays (todo lists as a second variant)

void merge_sorted_Array(int* unsorted, int* left_array, int* right_array, int arr_size)
{
    int i = 0;
    int j = 0;
    int Divide_index = (arr_size) / 2;
    while (i + j < arr_size & (i < Divide_index) & (j < arr_size - Divide_index)) {
        if (left_array[i] > right_array[j]) {
            unsorted[i + j] = right_array[j];
            j++;
        }
        else {
            unsorted[i + j] = left_array[i];
            i++;
        }
    }
    if (i == Divide_index) {
        for (int k = j; k < arr_size - Divide_index; k++) {
            unsorted[i + k] = right_array[k];
        }
    }
    else if (j == arr_size - Divide_index) {
        for (int k = i; k < Divide_index; k++) {
            unsorted[k + j] = left_array[k];
        }
    }
}

void mergeSort(int* unsorted, int arr_size) {
    int Divide_index = (arr_size) / 2;
    int size_right = arr_size - Divide_index;
    // If the unsorted array is of size 1 
    if (Divide_index == 0) {
        return;
    }
    else {
        int* left_arr = (int*)malloc(Divide_index * sizeof(int));
        int* right_arr = (int*)malloc(size_right * sizeof(int));
        for (int i = 0; i < Divide_index; i++) {
            left_arr[i] = unsorted[i];
        }
        for (int i = Divide_index; i < arr_size; i++) {
            right_arr[i - Divide_index] = unsorted[i];
        }
        mergeSort(left_arr, Divide_index);
        mergeSort(right_arr, size_right);
        merge_sorted_Array(unsorted, left_arr, right_arr, arr_size);
        free(left_arr);
        free(right_arr);
    }
}

void quickSort(int* unsorted, int left, int right, list<Swap_Pos>& Swap_List, bool firstRecursion)
{
    // makes sure the timer gets called only once for the first recursion
    if (firstRecursion)
        Timer t = Timer("Quick Sort");

    // Check Length
    if (left >= right)
        return;
    // Pick a random Pivot Element within left and right range 
    int swap_temp;
    int pivot = left + rand() % (right - left);
    int pivot_el = unsorted[pivot];
    int i = left;
    int j = right;
    while (i < j) {
        while (unsorted[i] < pivot_el) {
            i++;
        }
        while (unsorted[j] > pivot_el) {
            j--;
        }
        if (i <= j)
        {
            swap_temp = unsorted[i];
            unsorted[i] = unsorted[j];
            unsorted[j] = swap_temp;
            Swap_Pos Pos;
            Pos.Old_pos = i;
            Pos.New_pos = j;
            Swap_List.push_back(Pos);
            // Continue with next index
            i++;
            j--;
        }
    }
    quickSort(unsorted, left, j, Swap_List, false);
    quickSort(unsorted, i, right, Swap_List, false);
}