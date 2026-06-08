
/*
******************************************************************************
 * File:        subsets.cpp
 * Brief:       Generates and prints all subsets (Power Set) of an array.
 * Scenario:    Uses recursive backtracking to find all combinations, wrapped
 *              in a simplified 2-parameter user interface.
 * Complexity:  Time: O(2^N) | Space: O(N)
 ******************************************************************************
 */

#include <iostream>
using namespace std;

// Function to print the current subset
void printSubset(int subset[], int subsetSize) 
{
    cout << "{ ";
    for (int i = 0; i < subsetSize; i = i + 1) 
        cout << subset[i] << " ";
    
    cout << "}" << endl;
}

// The actual recursive function (needs 3 parameters)
void generateSubsetsRecursive(int arr[], int size, int index, int subset[], int subsetSize) 
{
    // Print the current subset at every step
    printSubset(subset, subsetSize);

    // Try adding each remaining element to create new subsets
    for (int i = index; i < size; i = i + 1) 
    {
        subset[subsetSize] = arr[i];
        generateSubsetsRecursive(arr, size, i + 1, subset, subsetSize + 1);
    }
}

// Wrapper function - only needs 2 parameters!
void generateSubsets(int arr[], int size) 
{
    int subset[100];  // Create temporary storage
    generateSubsetsRecursive(arr, size, 0, subset, 0);
}

int main() 
{
    int arr[] = { 1, 2, 3 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "The subsets are: " << endl;
    generateSubsets(arr, size);  // Only pass arr and size! Very clean!

    return 0;
}