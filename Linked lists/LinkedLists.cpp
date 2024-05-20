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

        cout << "The algorithm " << name_of_algorithm << " took " << ms << "ms to execute.\n";
    }
};

void bubbleSort(int* elementsArray, int size)
{
    Timer t = Timer("Bubble Sort");
    
    for(int k = 1; k < size; k++)
    {
        for(int j = size-1; j >= k; j--)
        {
            if(elementsArray[j-1] > elementsArray[j])
            {
                int value = elementsArray[j-1];
                elementsArray[j-1] = elementsArray[j];
                elementsArray[j] = value;
            }
        }
    }
}

void insertSort(list<int>& unsorted)
{
    Timer("Insert Sort");
    // Dimzog's task
}

void quickSort(int* unsorted,int left, int right,list<Swap_Pos>& Swap_List, bool firstTime)
{
    // makes sure the timer gets called only once for the first recursion
    if (firstTime)
        Timer t = Timer("Quick Sort");

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
    quickSort(unsorted,left,j,Swap_List, false);
    quickSort(unsorted,i,right,Swap_List, false);
}

void initializeArray(list<int>& elementsList, int* elementsArray)
{
    int i = 0;

    for(int element: elementsList){
        elementsArray[i] = int(element);
        i++;
    }
}

list<int> initializeList()
{
    fstream myfile;
    myfile.open("Test 1.csv");
    string line;
    list<int> elements;
    
    while(getline(myfile, line))
        elements.push_back(stoi(line));

    myfile.close();

    return elements;
}

void printElements(int* elementsArray, int elementsSize, list<Swap_Pos>& Swap_List)
{
    for(int k = 0; k < elementsSize; k++) {
       cout << elementsArray[k] << "\n";
    }

        for (auto it = Swap_List.begin(); it != Swap_List.end(); ++it) {
    cout <<"(" << it->New_pos << "," << it->Old_pos << ")";
    }
}

int main()
{
    //omp_set_num_threads(NUM_THREADS);
    list<int> elementsList = initializeList();
    // Convert to Array for Quicksort Efficiency
    int elementsSize = elementsList.size();
    int* elementsArray = (int*) malloc(elementsSize*sizeof(elementsList.front()));
    initializeArray(elementsList, elementsArray);

    list<Swap_Pos> Swap_List;

    //quickSort(&elementsArray[0], 0, elementsSize, Swap_List, true);
    bubbleSort(elementsArray, elementsSize);

    //#pragma omp parallel
    /*{
        bubbleSort(elementsList);
        insertSort(elementsList);
        quickSort(&elementsList_array[0],0,i);
    }*/
    printElements(elementsArray, elementsSize, Swap_List);

    free(elementsArray);
    
    return 0;
}
