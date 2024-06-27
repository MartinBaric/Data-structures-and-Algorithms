#pragma once

#include <list>
#include "Timer.h"
#include "Swap_Position.h"

using namespace std;

void bubbleSort(int*,int);
void insertSort(list<int>&);
void merge_sorted_Array(int*, int*, int*, int);
void mergeSort(int*, int);
void quickSort(int*, int, int, list<Swap_Pos>, bool);