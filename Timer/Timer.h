/*
The implementation of a struct called timer primarily focused to measure 
the execution time of the different algorithms for comparison. Alternatively, it can be used
to measure the execution time of specific code lines in order to optimize them. 

Author: Martin Barič,
Date: 10.08.2024
*/

#pragma once

#include <string>
#include <chrono>

// Note: struct not compatible for usage with template<T>; templates can only be used with classes 

struct Timer
{
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<float> elapsed_time;
    std::string name_of_algorithm;
    Timer(std::string);
    ~Timer();
};