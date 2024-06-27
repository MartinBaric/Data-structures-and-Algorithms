#pragma once

#include <list>
#include "Timer.h"
#include "Swap_Position.h"

using namespace std;

void bubbleSort(int* elementsArray, int size);
void insertSort(list<int>& unsorted);
void merge_sorted_Array(int* unsorted, int* left_array, int* right_array, int arr_size);
void mergeSort(int* unsorted, int arr_size);
void quickSort(int* unsorted, int left, int right, list<Swap_Pos>& Swap_List, bool firstRecursion);