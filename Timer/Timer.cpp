/*The implementation of a struct called timer to measure the execution time
of the different algorithms. Alternatively, it can be used to measure 
the execution time of specific code lines in order to optimize it. */

#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace chrono;

struct Timer
{
    time_point<high_resolution_clock> start, end;
    duration<float> elapsed_time;
    string name_of_algorithm;

    /* The constructor creates a time stamp. Thus, a timer should be created
    immediately before the execution of an algorithm. */
    Timer(string name)
    {
        start = high_resolution_clock::now();
        name_of_algorithm = name;
    }

    /* The destructor creates another time stamp, and prints out the difference
    in milliseconds. Thus, the destructor of a timer should be called right after the execution
    of an algorithm. */
    ~Timer()
    {
        end = high_resolution_clock::now();
        elapsed_time = end - start;
        float ms = elapsed_time.count()*1000.0f;

        cout << "The algorithm " << name_of_algorithm << " took " << ms << "ms to execute.\n";
    }
};