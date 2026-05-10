/**
 * @file BubbleSort.cpp
 * @brief Template implementation of the Bubble Sort algorithm.
 * * Bubble sort works by repeatedly stepping through the list, comparing 
 * adjacent elements and swapping them if they are in the wrong order.
 */

#include <iostream>
using namespace std;

/**
 * @brief Sorts a fixed-size array using the optimized Bubble Sort algorithm.
 * * This implementation utilizes a 'swapped' flag to optimize the best-case 
 * scenario. If no elements are swapped during a pass, the array is already 
 * sorted, and the function terminates early.
 * * @tparam T The data type of the array elements (must support comparison operators).
 * @tparam n The size of the array, deduced by the compiler via reference.
 * @param arr A reference to the array to be sorted.
 */
template <typename T, size_t n>
void bubbleSort(T (&arr)[n])
{
    bool swapped;
    // Outer loop for number of passes
    for (size_t i = 0; i < n - 1; i++)
    {
        swapped = false;
        // Inner loop for comparing adjacent elements
        for (size_t j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[arr[j + 1]]);
                swapped = true; // Mark that a swap occurred
            }
        }

        // Optimization: If no two elements were swapped, array is sorted
        if (!swapped)
        {
            break;
        }
    }
}

/**
 * Technical Implementation Details:
 * 1. Pass-by-reference 'T (&arr)[n]' allows the compiler to handle size deduction.
 * 2. Time Complexity: 
 * - Best Case: O(n) (when array is already sorted).
 * - Average/Worst Case: O(n^2).
 * 3. Space Complexity: O(1) as it is an in-place sorting algorithm.
 * 4. Stability: Bubble Sort is a stable sorting algorithm.
 */