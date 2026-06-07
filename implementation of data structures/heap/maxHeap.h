

// this header file contains the generic implementation of the Maxheap using array
// note that the 1st index of the array named "data" stores the next available index, 
// the "sorted" array stores deleted values in descending order

#pragma once
#include <iostream>
using namespace std;

template<class T>
class maxHeap
{
private:
    int size;
    T* data;
    T* sorted;

public:
    maxHeap(int size);
    ~maxHeap();
    void insert(T value);
    T deleteRoot();
    void displayRoot();
    void displaySorted();
};

template<class T>
maxHeap<T>::maxHeap(int size)
{
    this->size = size;
    data = new T[size + 1];
    sorted = new T[size + 1];

    data[0] = 1;	// setting up next available index
    sorted[0] = 1;  // setting up next available index
}

template<class T>
maxHeap<T>::~maxHeap()
{
    delete[] data;
    delete[] sorted;
}

template <class T>
void maxHeap<T>::displayRoot()
{
    if (data[0] == 1)
        cout << "Heap is empty!" << endl;
    else
        cout << "Root value: " << data[1] << endl;
}

template<class T>
void maxHeap<T>::insert(T value)
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

        if (data[currentIndex] > data[parentIndex])  // if parent is smaller then child, swap
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
T maxHeap<T>::deleteRoot()
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
        int largest = currentIndex;

        // verify if left child exists and is larger than current largest
        if (leftChild < nextAvailable && data[leftChild] > data[largest])
            largest = leftChild;

        // verify if right child exists and is larger than current largest
        if (rightChild < nextAvailable && data[rightChild] > data[largest])
            largest = rightChild;

        // if the largest index is still the parent, max-heap property is restored
        if (largest == currentIndex)
            break;

        // swap parent with the largest child
        T temp = data[currentIndex];
        data[currentIndex] = data[largest];
        data[largest] = temp;

        // move the tracker down to continue validation
        currentIndex = largest;
    }

    return rootValue;
}

template<class T>
void maxHeap<T>::displaySorted()
{
    // checking is sorted array is empty 
    if (sorted[0] == 1)
    {
        cout << "Sorted array is empty! (No values have been deleted yet)." << endl;
        return;
    }

    cout << "Sorted Array (Descending order): ";
    for (int i = 1; i < sorted[0]; i++)
        cout << sorted[i] << " ";
    cout << endl;
}