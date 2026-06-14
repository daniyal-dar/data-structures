/*******************************************************************************
 * File: sort_linked_list.cpp
 * Question: Sort an Unsorted Singly Linked List
 * * Problem Statement:
 * Given an unsorted singly linked list, sort it using any sorting algorithm of
 * your choice (e.g., bubble sort, selection sort, merge sort, etc.).
 * * Constraints:
 * - You cannot use insertSorted or any built-in sorting functions.
 * - You may define helper functions if needed.
 * * Input Example:
 * List = 5 -> 1 -> 4 -> 2 -> 3
 * * Output Example:
 * List = 1 -> 2 -> 3 -> 4 -> 5
 *******************************************************************************/

#include"linkedList.h"
 // NOTE: This solution requires the dependency 'linkedList.h'. 
 // Please download and include the 'linkedList.h' header file from the 
 // implementation section to successfully compile this code.

template<class T>
void sortList(LinkedList<T>& original)
{
    if (original.isEmpty()) 
        return;

    LinkedList<T> temp;
    int currentSize = original.getSize();

    for (int i = 0; i < currentSize; i++)
    {
        T minVal = original.deleteFromHead();
        original.insertAtTail(minVal);

        int size = original.getSize();

        // finding min value in linked list
        for (int j = 0; j < size - 1; j++)
        {
            T current = original.deleteFromHead();
            if (current < minVal)
                minVal = current;
            original.insertAtTail(current);
        }

        // removing the min value from original linked list and 
        // storing it in temp lined list
        bool removed = false;
        for (int j = 0; j < size; j++)
        {
            T val = original.deleteFromHead();
            if (val == minVal && !removed)
            {
                temp.insertAtTail(val);
                removed = true;
            }
            else
            {
                original.insertAtTail(val);
            }
        }
    }

    // copying temp linked list into original linked list
    while (!temp.isEmpty())
        original.insertAtTail(temp.deleteFromHead());
}

int main()
{
	LinkedList<int> obj;

    obj.insertAtTail(76);
    obj.insertAtTail(33);
	obj.insertAtTail(20);
	obj.insertAtTail(15);
	obj.insertAtTail(25);
	obj.insertAtTail(4);
	obj.insertAtTail(2);
	obj.insertAtTail(19);
    obj.insertAtTail(15);
    obj.insertAtTail(25);
	obj.insertAtTail(76);
	obj.insertAtTail(33);

    cout << "Original list: " << endl;
	obj.display();

	sortList(obj);

    cout << "Sorted List: " << endl;
	obj.display();
	return 0;
}

