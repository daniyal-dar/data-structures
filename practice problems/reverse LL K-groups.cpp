/*
 * ======================================================================================
 * PROBLEM SCENARIO: Reverse Nodes in k-Group (Singly Linked List)
 * ======================================================================================
 * Description:
 * Given a singly linked list, reverse the nodes of the list 'k' at a time and return 
 * the modified list. 'k' is a positive integer and is less than or equal to the length 
 * of the linked list. 
 *
 * Constraints & Instructions:
 * 1. If the number of nodes left is smaller than 'k', leave them as they are in their
 * original order.
 * 2. You must modify the actual pointer links (`next`) of the nodes directly.
 * Do not modify or swap the data values inside the nodes.
 * 3. Only constant extra memory ($O(1)$ auxiliary space) is allowed.
 *
 * Example (with k = 2):
 * Input:  1 -> 2 -> 3 -> 4 -> 5
 * Output: 2 -> 1 -> 4 -> 3 -> 5
 *
 * Example (with k = 3):
 * Input:  1 -> 2 -> 3 -> 4 -> 5
 * Output: 3 -> 2 -> 1 -> 4 -> 5
 * ======================================================================================
 */

// Note: The required header file (linkedList-singly.h) is not included in this source package. 
// Please download it from the Implementation section of the repository and place it directly into 
// your project's root folder to resolve the pre-linked dependencies.


#include "linkedList-singly.h"
#include <iostream>
using namespace std;

template <typename T>
void reverse(LinkedList<T>& list, int k) 
{
    node<T>* head = list.getHead();

    // Edge cases: list is empty, has 1 node, or k is invalid
    if (head == nullptr || head->next == nullptr || k <= 1) 
        return;

    // A dummy node simplifies tracking the new head of the entire list
    node<T>* dummy = new node<T>();
    dummy->next = head;

    node<T>* groupPrev = dummy; // The node right before the group we are currently reversing

    while (true) 
    {
        // Step 1: Check if there are at least 'k' nodes left from groupPrev
        node<T>* kth = groupPrev;
        for (int i = 0; i < k && kth != nullptr; i++)
            kth = kth->next;

        // If we have fewer than 'k' nodes left, we are completely done!
        if (kth == nullptr)
            break;

        // Keep track of the node right after this k-group
        node<T>* groupNext = kth->next;

        // Step 2: Reverse the current k-group
        node<T>* prev = kth->next; // Pointing to groupNext initially hooks the tail up correctly
        node<T>* current = groupPrev->next;

        while (current != groupNext) 
        {
            node<T>* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        // Step 3: Fix the connections.
        // groupPrev->next originally pointed to the old head of the group (which is now the tail).
        // Save it so we can jump to it as our new groupPrev for the next iteration.
        node<T>* temp = groupPrev->next;

        // Connect the previous group's tail to the new head of this reversed group (which is 'kth')
        groupPrev->next = kth;

        // Move groupPrev down the line to the tail of our newly reversed group
        groupPrev = temp;
    }

    // Step 4: Update your custom linked list class's internal head pointer
    list.setHead(dummy->next);

    // Clean up memory used by the temporary dummy node
    delete dummy;
}


int main() 
{
    LinkedList<int> list;

    // 1. Insert initial values into our custom linked list
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.insertAtTail(5);

    // 2. Display the original list to verify insertion
    cout << "Original List: ";
    list.display();

    // 3. Get the k-group size from the user
    int k;
    cout << "Enter value of K: ";
    cin >> k;

    // 4. Run the iterative reverse function
    reverse(list, k);

    // 5. Display the final modified list
    cout << "Modified List: ";
    list.display();

    return 0;
}