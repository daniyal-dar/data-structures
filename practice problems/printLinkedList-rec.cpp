
/*
    In linked lists, traversal is often done using loops, but recursion can also be used 
    effectively to visit each node. Your task is to implement a recursive function in C++ 
    that prints all elements of a singly linked list using only the head pointer. The idea is 
    \simple: if the list is empty (base case), stop. Otherwise, print the current node’s data 
    and recursively call the function on the next node. This problem strengthens understanding 
    of recursion with linked structures, as each recursive call reduces the problem size by 
    moving one step ahead in the list.
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void printLinkedList(Node* head) 
{
    // Base Case: If the current node pointer is NULL
    if (head == NULL) 
        return;

    // Print the data of the current node
    cout << head->data << " -> ";

    // Recursive Logic: Shrink the problem by moving to the next node
    printLinkedList(head->next);
}

int main() 
{
    Node* head = new Node{ 10, nullptr   };
    head->next = new Node{ 20, nullptr };
    head->next->next = new Node{ 30, nullptr};

    cout << "Linked List elements: " << endl;
    printLinkedList(head);
    cout << "nullptr" << endl;

   
    Node* current = head;
    while (current != nullptr) 
    {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
	current = nullptr; 
    return 0;
}