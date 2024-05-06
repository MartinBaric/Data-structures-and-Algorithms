#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

void bubbleSort(list<int>& unsorted)
{
    // Dimzog's task
}

void insertSort(list<int>& unsorted)
{
    // Dimzog's task
}

void quickSort(list<int>& unsorted)
{
    // Dimzog's task
}


int main()
{
    fstream myfile;
    myfile.open("Test 1.csv");
    string line;

    list<int> elements;

    while(getline(myfile, line))
        elements.push_back(stoi(line));

    quickSort(elements);

    myfile.close();

    return 0;
}