#pragma once

#include <list>
#include "Timer.h"
#include "SwapPosition.h"

using namespace std;

void bubbleSort(int*,int);
void insertSort(list<int>&);
void merge_sorted_Array(int*, int*, int*, int);
void mergeSort(int*, int);
void quickSort(int*, int, int, list<Swap_Pos>, bool);