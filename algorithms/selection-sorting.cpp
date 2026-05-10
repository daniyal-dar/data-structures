/**
 * @file SelectionSort.cpp
 * @brief Template implementation of the Selection Sort algorithm.
 * * Selection sort works by repeatedly finding the minimum element from the 
 * unsorted part and putting it at the beginning.
 */

#include <iostream>
using namespace std;

/**
 * @brief Sorts a fixed-size array using the Selection Sort algorithm.
 * * This implementation utilizes template argument deduction to handle 
 * various data types and retrieve the array size 'n' automatically.
 * * @tparam T The data type of the array elements (must support comparison operators).
 * @tparam n The size of the array, deduced by the compiler via reference.
 * @param arr A reference to the array to be sorted.
 */
template <typename T, size_t n>
void selectionSort(T (&arr)[n])
{
    // One by one move the boundary of the unsorted subarray
    for (size_t i = 0; i < n - 1; i++)
    {
        // Find the minimum element in the unsorted part
        size_t min_idx = i;
        for (size_t j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        if (min_idx != i)
        {
            swap(arr[i], arr[min_idx]);
        }
    }
}

/**
 * Technical Implementation Details:
 * 1. Pass-by-reference 'T (&arr)[n]' prevents array-to-pointer decay.
 * 2. Time Complexity: O(n^2) for all cases (Best, Average, Worst).
 * 3. Space Complexity: O(1) as it is an in-place sorting algorithm.
 * 4. Stability: Selection sort is generally unstable.
 */