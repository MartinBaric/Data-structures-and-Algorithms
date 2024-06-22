#include <chrono>
#include <iostream>

using namespace std;
using namespace chrono;

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