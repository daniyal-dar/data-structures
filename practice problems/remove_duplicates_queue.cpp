/*******************************************************************************
 * File: remove_duplicates_queue.cpp
 * Question: Remove Duplicates from Queue
 * * Problem Statement:
 * Given a queue of integers, remove all duplicate values while preserving the
 * order of their first occurrences.
 * * Constraints:
 * - Use only standard queue operations (e.g., push, pop, empty, front) and
 * basic data structures.
 * - Avoid using complex inbuilt functions/algorithms for duplicate removal.
 * * Input Example:
 * Q = [3, 1, 4, 3, 4, 2, 1]
 * * Output Example:
 * Q = [3, 1, 4, 2]
 *******************************************************************************/


#include"Queue.h"
 // NOTE: This solution requires the dependency 'Queue.h'. 
 // Please download and include the 'Queue.h' header file from the 
 // implementation section to successfully compile this code.

template<class T>
bool removeDublication(Queue<T>& original, int size)
{
    if (original.isEmpty())
        return false;

    int currentSize = size;

    for (int i = 0; i < currentSize; i++)
    {
        T target = original.dequeue();
        int remaining = currentSize - 1;

        for (int j = 0; j < remaining; j++)
        {
            T currentVal = original.dequeue();

            if (currentVal == target)
                currentSize--;
            else
                original.enqueue(currentVal);
        }
        original.enqueue(target);
    }

    return true;
}

int main()
{
	const int size = 10;
	Queue<int> obj(size);

	obj.enqueue(15);
	obj.enqueue(16);
	obj.enqueue(7);
	obj.enqueue(15);
	obj.enqueue(7);
	obj.enqueue(16);
    obj.enqueue(55);
    obj.enqueue(77);
    obj.enqueue(94);
    obj.enqueue(55);
	cout << "Original Queue: ";
	obj.display();

	removeDublication(obj, size);

	cout << "updated Queue: ";
	obj.display();


	return 0;
}

