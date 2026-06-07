

// this header file contains the generic implementation of the Minheap using array
// note that the 1st index of the array named "data" stores the next available index, 
// the "sorted" array stores deleted values in ascending order

#pragma once
#include <iostream>
using namespace std;

template<class T>
class minHeap
{
private:
    int size;
    T* data;
    T* sorted;

public:
    minHeap(int size);
    ~minHeap();
    void insert(T value);
    T deleteRoot();
    void displayRoot();
    void displaySorted();
};

template<class T>
minHeap<T>::minHeap(int size)
{
    this->size = size;
    data = new T[size + 1];
    sorted = new T[size + 1];

    data[0] = 1;	// setting up next available index
    sorted[0] = 1;  // setting up next available index
}

template<class T>
minHeap<T>::~minHeap()
{
    delete[] data;
    delete[] sorted;
}

template <class T>
void minHeap<T>::displayRoot()
{
    if (data[0] == 1)
        cout << "Heap is empty!" << endl;
    else
        cout << "Root value: " << data[1] << endl;
}

template<class T>
void minHeap<T>::insert(T value)
{
    int nextIndex = data[0];        // storing nextAvailable index

    if (nextIndex > size)           // Check if the heap is full
    {
        cout << "heap overflow! cannot insert " << value << endl;
        return;
    }

    data[nextIndex] = value;        // placing value at next available slot
    data[0] = nextIndex + 1;        // increment nextAvailable slot ptr

    // heapifying up
    int currentIndex = nextIndex;   // storing index of latest value added
    while (currentIndex > 1)
    {
        int parentIndex = currentIndex / 2;

        if (data[currentIndex] < data[parentIndex])  // if parent is greater than child, swap
        {
            T temp = data[currentIndex];
            data[currentIndex] = data[parentIndex];
            data[parentIndex] = temp;

            currentIndex = parentIndex;              // updating iterator with parent index
        }
        else
            break;
    }
}

template<class T>
T minHeap<T>::deleteRoot()
{
    if (data[0] == 1)               // check if the heap is empty
    {
        cout << "Heap underflow! Nothing to delete." << endl;
        return T();                 // returns dummy value
    }

    T rootValue = data[1];          // saving root value
    int lastIndex = data[0] - 1;    // extract the last entered element in the array
    int indexStorage = sorted[0];
    sorted[indexStorage] = rootValue;
    sorted[0]++;                    // incrementing index

    data[1] = data[lastIndex];      // overwriting root with last element
    data[0] = lastIndex;            // decrementing next available index

    // heapify down
    int currentIndex = 1;
    int nextAvailable = data[0];    // bound limit for child existence checking

    while (true)
    {
        int leftChild = 2 * currentIndex;
        int rightChild = 2 * currentIndex + 1;
        int smallest = currentIndex;

        // verify if left child exists and is smaller than current smallest
        if (leftChild < nextAvailable && data[leftChild] < data[smallest])
            smallest = leftChild;

        // verify if right child exists and is smaller than current smallest
        if (rightChild < nextAvailable && data[rightChild] < data[smallest])
            smallest = rightChild;

        // if the smallest index is still the parent, min-heap property is restored
        if (smallest == currentIndex)
            break;

        // swap parent with the smallest child
        T temp = data[currentIndex];
        data[currentIndex] = data[smallest];
        data[smallest] = temp;

        // move the tracker down to continue validation
        currentIndex = smallest;
    }

    return rootValue;
}

template<class T>
void minHeap<T>::displaySorted()
{
    // If sorted[0] is 1, it means no items have been deleted/sorted yet
    if (sorted[0] == 1)
    {
        cout << "Sorted array is empty! (No values have been deleted yet)." << endl;
        return;
    }

    cout << "Sorted Array (Ascending order): ";
    for (int i = 1; i < sorted[0]; i++)
        cout << sorted[i] << " ";
    cout << endl;
}