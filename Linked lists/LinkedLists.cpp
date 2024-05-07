#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <chrono>

using namespace std;
using namespace chrono;

struct Timer
{
    time_point<high_resolution_clock> start, end;
    duration<float> duration;
    string name_of_algorithm;

    Timer(string name)
    {
        start = high_resolution_clock::now();
        name_of_algorithm = name;
    }

    ~Timer()
    {
        end = high_resolution_clock::now();
        duration = end - start;
        float ms = duration.count()*1000.0f;

        cout << "The algorithm " << name_of_algorithm << " took " << ms << "ms to execute.";
    }
};

void bubbleSort(list<int>& unsorted)
{
    Timer("Bubble Sort");
    // Dimzog's task
}

void insertSort(list<int>& unsorted)
{
    Timer("Insert Sort");
    // Dimzog's task
}

void quickSort(list<int>& unsorted)
{
    Timer("Quick Sort");
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

    bubbleSort(elements);

    myfile.close();

    return 0;
}