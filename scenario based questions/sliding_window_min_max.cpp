/* * SCENARIO: SLIDING WINDOW MIN-MAX SUM
 * ------------------------------------
 * Problem Statement:
 * Given an array of integers and an integer K, compute the sum of the minimum
 * and maximum elements of all subarrays (sliding windows) of size K.
 * * Your program must efficiently process these subarrays using a queue-based
 * approach.
 * * Example:
 * Input: arr = [2, 5, -1, 7, -3, -1, -2], K = 4
 * * Subarrays of size 4:
 * 1. [2, 5, -1, 7]   -> Min: -1, Max: 7 -> Sum: 6
 * 2. [5, -1, 7, -3]  -> Min: -3, Max: 7 -> Sum: 4
 * 3. [-1, 7, -3, -1] -> Min: -3, Max: 7 -> Sum: 4
 * 4. [7, -3, -1, -2] -> Min: -3, Max: 7 -> Sum: 4
 * * Final Answer (Total Sum): 6 + 4 + 4 + 4 = 18
 */


#include "queueCircular-array.h"
#include <iostream>
using namespace std;

// Function to find sum of min and max element in the current window
template <typename T>
T getMinMaxSumOfWindow(Queue<T>& window, int k)
{
    if (window.isEmpty()) return 0;

    // Peek at the first element to initialize min and max
    T minVal = window.peek();
    T maxVal = window.peek();

    /* * Since a queue is FIFO, we "Rotate" the queue k times.
     * We dequeue an element, check it, then enqueue it back immediately.
     * This allows us to traverse the whole window without destroying it.
     */
    for (int i = 0; i < k; i++)
    {
        T current = window.dequeue();

        if (current < minVal) minVal = current;
        if (current > maxVal) maxVal = current;

        // Rotation: Move front to back to preserve the window for the next call
        window.enqueue(current);
    }
    return (minVal + maxVal);
}

// Main processing function to handle the sliding window
template <typename T>
T resultantSum(Queue<T>& mainData, int k)
{
    Queue<T> window(k); // This queue holds exactly K elements at a time
    T totalFinalSum = 0;

    // Process the entire main queue until it's empty
    while (!mainData.isEmpty())
    {
        // Add the next value from the main data into our sliding window
        window.enqueue(mainData.dequeue());

        // Once the window reaches size K, we process it
        if (window.showCurrent_size() == k)
        {
            // Calculate min+max for the current window and add to total
            totalFinalSum += getMinMaxSumOfWindow<T>(window, k);

            /* * To "slide" the window, we remove the oldest element (Front)
             * so that the next iteration can add one new element.
             */
            window.dequeue();
        }
    }
    return totalFinalSum;
}

int main()
{
    const int size = 7;
    int k = 4;
    int arr[size] = { 2, 5, -1, 7, -3, -1, -2 };

    // Initializing the main queue with our dataset
    Queue<int> myData(size);

    // Filling the queue from the array
    for (int x : arr)
        myData.enqueue(x);

    // Processing the data to get the final sum based on scenario
    int result = resultantSum(myData, k);

    cout << "Final Answer: " << result << endl;

    return 0;
}