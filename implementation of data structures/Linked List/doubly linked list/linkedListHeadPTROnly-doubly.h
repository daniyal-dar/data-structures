// this header file contains the generic implementation of the 
// doubly linked list using head ptr only (non-circular)

#pragma once
#include <iostream>
using namespace std;

template <class T>
struct node 
{
    T data;
    node<T>* next;
    node<T>* prev;
};

template<class T>
class LinkedList
{
public:
    node<T>* head; // pointer points to the first node

public:
    // ---------- essential functions ---------------
    LinkedList();               // default constructor
    ~LinkedList();              // destructor
    bool isEmpty();             // check is linked list empty
    void insertAtHead(T v);     // insert value at the start of the list
    T deleteFromHead();         // delete value from the start of the list
    void display();             // displays linked list forward
    void displayReverse();      // displays linked list backward to test prev pointers

    // ---------- other functions -------------------
    void insertSorted(T value);  // values adding in ascending order
    bool searchByValue(T value); // return true if element found
    bool deleteByValue(T value); // deletes the nodes of given element
};

template<class T>
LinkedList<T>::LinkedList() { head = nullptr; }

template<class T>
LinkedList<T>::~LinkedList()
{
    if (isEmpty())
        return;

    node<T>* current = head;
    node<T>* nextNode = nullptr;

    while (current != nullptr)
    {
        nextNode = current->next; // Save the address of the next node
        delete current;           // Delete the current node
        current = nextNode;       // Move to the next node
    }
    current = nullptr;
	nextNode = nullptr;
    head = nullptr;
}

template<class T>
bool LinkedList<T>::isEmpty() { return head == nullptr; }

template<class T>
void LinkedList<T>::insertAtHead(T v)
{
    node<T>* nn = new node<T>;
    nn->data = v;
    nn->next = nullptr;
    nn->prev = nullptr;

    if (isEmpty()) // case 01: empty LL
    {
        head = nn;
    }
    else           // case 02: not empty LL 
    {
        nn->next = head;
        head->prev = nn;
        head = nn;
    }
}

template<class T>
T LinkedList<T>::deleteFromHead()
{
    if (isEmpty())
    {
        cout << "List is empty! operation terminated." << endl;
        return T();
    }

    T returnValue = head->data;
    node<T>* temp = head;

    if (head->next == nullptr) // case 01: Only one node in the list
    {
        head = nullptr;
    }
    else                       // case 02: Multiple nodes
    {
        head = head->next;
        head->prev = nullptr;
    }

    delete temp;
    return returnValue;
}

template<class T>
void LinkedList<T>::insertSorted(T value)
{
    node<T>* nn = new node<T>;
    nn->data = value;
    nn->next = nullptr;
    nn->prev = nullptr;

    if (isEmpty())                   // case 01: empty LinkedList
    {
        head = nn;
    }
    else if (value <= head->data)   // case 02: inserting before the head 
    {
        nn->next = head;
        head->prev = nn;
        head = nn;
    }
    else                            // case 03: inserting middle or end
    {
        node<T>* temp = head;
        while (temp != nullptr)
        {
            // subCase 01: reach the end of the list (insert at tail)
            if (temp->next == nullptr)
            {
                temp->next = nn;
                nn->prev = temp;
                break;
            }
            // subCase 02: reach the correct sorted position (insert in middle)
            if (value >= temp->data && value < temp->next->data)
            {
                nn->next = temp->next;
                nn->prev = temp;
                temp->next->prev = nn;
                temp->next = nn;
                break;
            }

            temp = temp->next;
        }
    }
}

template<class T>
bool LinkedList<T>::searchByValue(T value)
{
    if (isEmpty())
        return false;

    node<T>* temp = head;
    while (temp != nullptr)
    {
        if (temp->data == value)
            return true;

        temp = temp->next;
    }
    return false;
}

template<class T>
bool LinkedList<T>::deleteByValue(T value)
{
    if (isEmpty())
        return false;

    // Case 01: The value is at the Head
    if (head->data == value)
    {
        deleteFromHead();
        return true;
    }

    // Case 02: The value is somewhere else
    node<T>* temp = head;

    while (temp != nullptr)
    {
        if (temp->data == value)
        {
            temp->prev->next = temp->next;

            // if its not the last node, update next nodes prev pointer
            if (temp->next != nullptr)
                temp->next->prev = temp->prev;

            delete temp;
            return true;
        }
        temp = temp->next;
    }

    cout << "Value " << value << " not found in the list." << endl;
    return false;
}

template<class T>
void LinkedList<T>::display()
{
    node<T>* temp = head;
	int count = 1;    
    while (temp != nullptr)
    {
        cout << count << ". " << temp->data << endl;
        temp = temp->next;
        count++;
    }
}

template<class T>
void LinkedList<T>::displayReverse()
{
    if (isEmpty()) return;

    // Traversing to the end of the list
    node<T>* temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    // Traversing backward using prev pointers
    cout << "Displaying Reverse" << endl;
	int count = 1;
    while (temp != nullptr)
    {
        cout << count << ". " << temp->data << endl;
        temp = temp->prev;
		count++;   
    }
}