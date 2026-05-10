/**
 * @file LinearSearch.cpp
 * @brief Template implementation of the Linear Search algorithm.
 */

#include <iostream>
using namespace std;

/**
 * @brief Searches for a target key within a fixed-size array.
 * * This implementation uses template argument deduction to automatically determine 
 * the array size at compile time, eliminating the need to pass the size manually.
 * * @tparam T The data type of the array elements (must support the == operator).
 * @tparam n The size of the array, deduced by the compiler.
 * @param data A reference to the array to be searched.
 * @param key The target value to find.
 * @return int The zero-based index of the key if found; otherwise -1.
 */

template <typename T, std::size_t n>
int linearSearch(T (&data)[n], T key)
{
    // Iterate through the array to find the first occurrence of the key
    for (int i = 0; i < n; i++)
    {
        if (data[i] == key)
        {
            return i; // Key found at index i
        }
    }
    return -1; // Key not found in the array
}

/* * Technical Note: 
 * Using 'T (&data)[n]' passes the array by reference. This prevents the creation 
 * of a local copy, saving memory and ensuring that the compiler can deduce 
 * the size 'n' directly from the array declaration.
 */