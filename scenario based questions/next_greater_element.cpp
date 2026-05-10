/*
 * PROBLEM SCENARIO: "Next Greater Element"
 * ---------------------------------------
 * Given an array of integers, find the "Next Greater Element" (NGE) for every element.
 * The Next Greater Element for an element x is the first greater element on the
 * right side of x in the array.
 *
 * If no greater element exists to the right, the NGE for that element should be -1.
 *
 * Example:
 * Input:  { 4, 5, 2, 10, 8 }
 * Output: { 5, 10, 10, -1, -1 }
 */

#include <iostream>
#include "stack-array.h"

using namespace std;

int main()
{
    const int size = 5;
    int input[size] = { 4, 5, 2, 10, 8 };

    // This stack will store the Next Greater Element for each index
    Stack<int> arr(size);

    // Outer loop to pick each element of the array one by one
    for (int i = 0; i < size; i++)
    {
        bool isFound = false;
        int currentElement = input[i];

        // Inner loop to find the first greater element to the right
        for (int j = i + 1; j < size; j++)
        {
            // If an element greater than the current element is found
            if (input[j] > currentElement)
            {
                arr.push(input[j]); // Store the NGE in the stack
                isFound = true;
                break; // Stop searching once the first NGE is found
            }
        }

        // If no greater element was found in the remaining array
        if (!isFound)
        {
            arr.push(-1);
        }
    }

    // Displaying the results stored in the stack
    cout << "Array of Next Greater Elements:" << endl;
    arr.display();

    return 0;
}