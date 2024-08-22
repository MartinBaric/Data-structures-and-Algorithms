#include "LinkedLists.h"

#include <iostream>

using namespace std;

void printElements(int* elementsArray, int elementsSize, list<Swap_Pos>& Swap_List)
{
    for(int k = 0; k < elementsSize; k++) {
       cout << elementsArray[k] << "\n";
    }

        for (auto it = Swap_List.begin(); it != Swap_List.end(); ++it) {
    cout <<"(" << it->New_pos << "," << it->Old_pos << ")";
    }
}
