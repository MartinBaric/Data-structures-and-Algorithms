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

template <typename T> class Node
{
private:
    Node* left;
    Node* right;
    T data;

public:
    Node(T value)
    {
        this.data = value;
        left = right = NULL;    
    }


    T get_value()
    {
        return this->data;
    }

    bool left_NULL()
    {
        if (this->left == NULL)
            return true;
        else return false;
    }
    void print_value()
        {
            cout << get_value() << "\n";
        }
    void inorder()
        {
            if(left!=NULL)
                left->inorder();
            print_value();
            if(right!=Null)
                right->inorder(); 
        }
     void preorder()
        {
            print_value();
            if(left!=NULL)
                left->preorder();
            if(right!=Null)
                right->preorder(); 
        }
     void postorder()
        {
            if(left!=NULL)
                left->postorder();
            if(right!=Null)
                right->postorder();
            print_value(); 
        }
};

/*
template <typename T> class BST
{
    private:
        Node<T>* root;
        int counter;
    
    public:
        BST(Node<T>* first_node)
        {
            this->root = first_node;
            counter = 1;
        }

    
        void add_node(T value, int index)
        {
            if(index == 0)
            {
                index = counter;
            }

            if(index == 1)
                this.left = new Node(value); 
            else if(index == 2)
                this.right = new Node(value);
            else if(index % 2 == 0)
                this->left.add_node(T value, index/2);
            else if(index % 2 == 1)
                this->right.add_node(T value, index/2);
        }
};
*/

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

// Merge two sorted arrays (todo lists as a second variant)

void merge_sorted_Array(int* unsorted,int* left_array,int* right_array, int arr_size)
    {
        int i = 0;
        int j = 0;
        int Divide_index = (arr_size)/2;
        while(i+j<arr_size&(i < Divide_index)&(j<arr_size-Divide_index)){
            if(left_array[i]>right_array[j]){
                unsorted[i+j] = right_array[j];
                j++;
            }
            else{
                unsorted[i+j] = left_array[i];
                i++;
            } 
        }
        if(i == Divide_index){
            for(int k = j;k < arr_size-Divide_index;k++){
                unsorted[i+k] = right_array[k];
            }
        }
        else if(j == arr_size-Divide_index){
            for(int k = i;k < Divide_index;k++){
                unsorted[k+j] = left_array[k];
            }
        }
    }

void mergeSort(int* unsorted,int arr_size){
    int Divide_index = (arr_size)/2;
    int size_right = arr_size-Divide_index;
    // If the unsorted array is of size 1 
    if(Divide_index == 0){
        return;
    } 
    else{
        int* left_arr = (int*) malloc(Divide_index*sizeof(int));
        int* right_arr = (int*) malloc(size_right*sizeof(int));
        for(int i = 0;i < Divide_index;i++ ){
            left_arr[i] = unsorted[i];
        }
        for(int i = Divide_index;i < arr_size;i++){
            right_arr[i-Divide_index] = unsorted[i];
        }
        mergeSort(left_arr,Divide_index);
        mergeSort(right_arr,size_right);
        merge_sorted_Array(unsorted,left_arr,right_arr,arr_size);
        free(left_arr);
        free(right_arr);
    }
}

void quickSort(int* unsorted,int left, int right,list<Swap_Pos>& Swap_List, bool firstRecursion)
{
    // makes sure the timer gets called only once for the first recursion
    if (firstRecursion)
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
    Node<int> *n = new Node(10);
    n->left = Node(5);
    //n.data = 19;


    //quickSort(&elementsArray[0], 0, elementsSize, Swap_List, true);
    //bubbleSort(elementsArray, elementsSize);
    mergeSort(elementsArray, elementsSize);
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
