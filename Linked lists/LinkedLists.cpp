#include <iostream>
#include <fstream> // For reading/writing files
#include <string>
#include <list>
#include <chrono> // For time measuring
#include <omp.h> // OpenMultiProcessing library for parallel programming
#include <random>

using namespace std;
using namespace chrono;

const int NUM_THREADS = 4;

struct Swap_Pos{
    int Old_pos; 
    int New_pos;  
};

struct Timer
{
    time_point<high_resolution_clock> start, end;
    duration<float> elapsed_time;
    string name_of_algorithm;

    Timer(string name)
    {
        start = high_resolution_clock::now();
        name_of_algorithm = name;
    }

    ~Timer()
    {
        end = high_resolution_clock::now();
        elapsed_time = end - start;
        float ms = elapsed_time.count()*1000.0f;

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

void quickSort(int* unsorted,int left, int right,list<Swap_Pos>& Swap_List)
{
    Timer("Quick Sort");
    // Check Length
    if(left >= right)
        return;
    // Pick a random Pivot Element within left and right range 
    int swap_temp;
    int pivot = left + rand()%(right-left);
    int pivot_el = unsorted[pivot];
    int i = left;
    int j = right;
    while(i<j){
        while(unsorted[i] < pivot_el){
            i++;
        }
        while(unsorted[j] > pivot_el){
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
    quickSort(unsorted,left,j,Swap_List);
    quickSort(unsorted,i,right,Swap_List);
}


int main()
{
    //omp_set_num_threads(NUM_THREADS);
    fstream myfile;
    myfile.open("Test 1.csv");
    string line;
    list<int> elements;
    int i = 0;
    list<Swap_Pos> Swap_List;
    while(getline(myfile, line))
        elements.push_back(stoi(line));

    // Conevert to Array for Quicksort Efficiency
    int size_l = elements.size();
    int* elements_array = (int*) malloc(size_l*sizeof(elements.front()));
    for(int element: elements){
        elements_array[i] = int(element);
        i++;
    }
    myfile.close();
    quickSort(&elements_array[0],0,elements.size(),Swap_List);
    //#pragma omp parallel
    //{
        //bubbleSort(elements);
        //insertSort(elements);
     //   quickSort(&elements_array[0],0,i);
    //}
    for(int k = 0;k < elements.size();k++){
       cout << elements_array[k] << "\n"; 
    }
    for (auto it = Swap_List.begin(); it != Swap_List.end(); ++it){
    cout <<"(" << it->New_pos << "," << it->Old_pos << ")";
    }

    return 0;
}
