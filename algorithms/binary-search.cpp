/**
 * @file BinarySearch.cpp
 * @brief Template implementation of the Binary Search algorithm.
 * * Note: This algorithm requires the input array to be sorted in ascending order.
 */

#include <iostream>
using namespace std;

/**
 * @brief Performs a Binary Search on a sorted, fixed-size array.
 * * This implementation utilizes template argument deduction to handle various 
 * data types and retrieve the array size 'n' automatically at compile time.
 * * @tparam T The data type of the array elements (must support comparison operators).
 * @tparam n The size of the array, deduced by the compiler via reference.
 * @param arr A reference to the sorted array to be searched.
 * @param key The target value to locate.
 * @return int The index of the key if found; otherwise -1.
 */
template <typename T, std::size_t n>
int binarySearch(T (&arr)[n], T key)
{
    int low = 0;
    int high = n - 1;
    int mid;

    while (low <= high)
    {
        // Calculate the middle index
        mid = (low + high) / 2;

        // Check if the key is present at mid
        if (arr[mid] == key)
        {
            return mid;
        }
        // If key is greater, ignore the left half
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        // If key is smaller, ignore the right half
        else
        {
            high = mid - 1;
        }
    }

    // Target element was not found in the array
    return -1;
}

/**
 * Technical Implementation Details:
 * 1. Passing by reference 'T (&arr)[n]' ensures O(1) space for parameter passing.
 * 2. Time Complexity: O(log n).
 * 3. Space Complexity: O(1) for iterative approach.
 */