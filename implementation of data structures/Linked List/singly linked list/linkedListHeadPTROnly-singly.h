


// this header file contains the generic implementation of the 
// singly linked list using head ptr only

#pragma once
#include <iostream>
using namespace std;

template <class T>
struct node {
    T data;
    node<T>* next;
};

template<class T>
class LinkedList
{
public:
    node<T>* head;      // pointer points to the 

public:

    // ---------- essential functions ---------------
    LinkedList();               // default constructor
    ~LinkedList();              // destructor
    bool isEmpty();             // check is linked list empty
    void insertAtHead(T v);     // insert value at the start of the list
    T deleteFromHead();         // delete value from the start of the list
    void display();             // displays linked list
    
    // ---------- other functions -------------------
    void insertSorted(T value);     // values adding in accending order
    bool searchByValue(T value);    // return the index of the given element
    bool deleteByValue(T value);    // deletes the nodes of given element
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
    head = nullptr;
}

template<class T>
bool LinkedList<T>::isEmpty() { return head == nullptr; }

template<class T>
void LinkedList<T>::insertAtHead(T v)
{
    node<T>* nn = new node<T>;
    nn->next = nullptr;
    nn->data = v;

    if (head == nullptr)    // case 01: empty LL
        head = nn;
    else                    // case 02: not empty LL 
    {
        nn->next = head;
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
    else if (head->next == nullptr)
    {
        T rv = head->data;
        delete head;
        head = nullptr;
        return rv;
    }
    else
    {
        T rv = head->data;
        node<T>* t = head;
        head = head->next;
        delete t;
        t = nullptr;
        return rv;
    }
}

// values adding in accending order
template<class T>
void LinkedList<T>::insertSorted(T value)
{
    node<T>* nn = new node<T>;
    nn->data = value;
    nn->next = nullptr;

    if (isEmpty())                   // case 01: empty LinkedList
        head = nn;

    else if (value <= head->data)   // case 02: single node 
    {
        nn->next = head;
        head = nn;
        return;
    }

    else                            // case 03: multiple node 
    {
        node<T>* t = head;
        while (t != nullptr)
        {
            if (t->next == nullptr)
            {
                t->next = nn;
                break;
            }
            if (value >= t->data && value < t->next->data)
            {
                nn->next = t->next;
                t->next = nn;
                break;
            }

            t = t->next;
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

    // Case 1: The value is at the Head
    if (head->data == value)
    {
        deleteFromHead();
        return true;
    }

    // Case 2: The value is somewhere else
    node<T>* temp = head;
    node<T>* prev = nullptr;

    while (temp != nullptr)
    {
        if (temp->data == value)
        {
            prev->next = temp->next;
            delete temp;
            temp = nullptr;
            return true;
        }
        prev = temp;
        temp = temp->next;
    }

    cout << "Value " << value << " not found in the list." << endl;
    return false;
}

template<class T>
void LinkedList<T>::display()
{
    node<T>* temp = head;
    int count = 0;
    while (temp != nullptr)
    {
        cout << count << ". " << temp->data << endl;
        temp = temp->next;
        count++;
    }
}