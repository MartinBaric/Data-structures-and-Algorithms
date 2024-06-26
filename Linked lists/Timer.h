#pragma once

#include <string>
#include <chrono>

// struct not compatible for usage with template<T>, only for class definitions 

struct Timer
{
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<float> elapsed_time;
    std::string name_of_algorithm;
    Timer(std::string);
    ~Timer();
};