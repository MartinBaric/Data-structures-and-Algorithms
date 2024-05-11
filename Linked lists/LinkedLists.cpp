#include <iostream>
#include <fstream> // For reading/writing files
#include <string>
#include <list>
#include <chrono> // For time measuring
#include <omp.h> // OpenMultiProcessing library for parallel programming

using namespace std;
using namespace chrono;

const int NUM_THREADS = 4;

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
    omp_set_num_threads(NUM_THREADS);
    fstream myfile;
    myfile.open("Test 1.csv");
    string line;

    list<int> elements;

    while(getline(myfile, line))
        elements.push_back(stoi(line));

    #pragma omp parallel
    {
        bubbleSort(elements);
        insertSort(elements);
        quickSort(elements);
    }

    myfile.close();

    return 0;
}