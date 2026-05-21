// this header file contains the implementation of the doubly circular LL list using 
// tail pointer only

#pragma once
#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    node<T>* next;
    node<T>* prev;
};

template<class T>
class LinkedList
{
private:
    node<T>* tail;     // pointer points to the last node of the linked list

public:
    // ---------- essential functions ---------------
    LinkedList();                    // default constructor
    ~LinkedList();                   // destructor
    void insertAtHead(T value);      // adds element at the start of the list
    void insertAtTail(T value);      // adds element at the end of the list
    T deleteFromHead();              // removes element from the start of the list 
    T deleteFromTail();              // removes element from the end of the list
    void display();                  // displays the list forward
    void displayReverse();           // Added: displays the list backward to verify prev links
    bool isEmpty();                  // check is list empty

    // ---------- other functions -------------------
    int searchByValue(T value);     // search value and return index
    bool deleteByValue(T value);    // delete value and return bool
};

template <class T>
LinkedList<T>::LinkedList() { tail = nullptr; }

template<class T>
LinkedList<T>::~LinkedList()
{
    if (isEmpty())
        return;

    node<T>* current = tail->next;
    node<T>* nextNode = nullptr;
    tail->next = nullptr; // Break the circle for safe deletion

    while (current != nullptr)
    {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    tail = nullptr;
}

template <class T>
void LinkedList<T>::insertAtHead(T value)
{
    node<T>* nn = new node<T>;
    nn->data = value;
	nn->next = nullptr;
	nn->prev = nullptr;

    if (isEmpty())
    {
        tail = nn;
        tail->next = tail;
        tail->prev = tail; 
    }
    else
    {
        node<T>* head = tail->next;

        nn->next = head;
        nn->prev = tail;
        head->prev = nn;
        tail->next = nn; 
    }
}

template <class T>
void LinkedList<T>::insertAtTail(T value)
{
    node<T>* nn = new node<T>;
    nn->data = value;

    if (isEmpty())
    {
        tail = nn;
        tail->next = tail;
        tail->prev = tail;
    }
    else
    {
        node<T>* head = tail->next;

        nn->next = head;
        nn->prev = tail;
        head->prev = nn;
        tail->next = nn;

        tail = nn;
    }
}

template <class T>
int LinkedList<T>::searchByValue(T value)
{
    if (isEmpty())
        return -1;

    node<T>* temp = tail->next;
    int position = 0;

    while (true)
    {
        if (temp->data == value)
            return position;

        temp = temp->next;
        position++;

        if (temp == tail->next)
            break;
    }
    return -1;
}

template <class T>
void LinkedList<T>::display()
{
    if (isEmpty())
        cout << "Linked List is empty! nothing to show." << endl;
    else
    {
        node<T>* temp = tail->next;
        cout << "--- Forward Display ---" << endl;
        while (true)
        {
            cout << "data: " << temp->data << endl;
            temp = temp->next;

            if (temp == tail->next)
                break;
        }
    }
}

template <class T>
void LinkedList<T>::displayReverse()
{
    if (isEmpty())
    {
        cout << "Linked List is empty! nothing to show." << endl;
        return;
    }

    node<T>* temp = tail;
    cout << "Reverse Display" << endl;
    while (true)
    {
        cout << "data: " << temp->data << endl;
        temp = temp->prev;

        if (temp == tail)
            break;
    }
}

template <class T>
bool LinkedList<T>::isEmpty()
{
    return tail == nullptr;
}

template <class T>
T LinkedList<T>::deleteFromHead()
{
    if (isEmpty())
    {
        cout << "List is empty! nothing to remove." << endl;
        return T();
    }

    T value = tail->next->data;

    if (tail->next == tail) // case 01: Only one node in the list
    {
        delete tail;
        tail = nullptr;
    }
    else // case 02: Multiple nodes
    {
        node<T>* head = tail->next;
        node<T>* newHead = head->next;

        tail->next = newHead;
        newHead->prev = tail;

        delete head;
    }
    return value;
}

template <class T>
T LinkedList<T>::deleteFromTail()
{
    if (isEmpty())
    {
        cout << "List is empty! nothing to remove." << endl;
        return T();
    }

    T value = tail->data;

    if (tail->next == tail) // case 01: Only one node in the list
    {
        delete tail;
        tail = nullptr;
    }
    else // case 02: Multiple nodes
    {
        node<T>* head = tail->next;
        node<T>* newTail = tail->prev;

        newTail->next = head;
        head->prev = newTail;

        delete tail;
        tail = newTail; // Update tail pointer
    }
    return value;
}

template <class T>
bool LinkedList<T>::deleteByValue(T value)
{
    if (isEmpty())
        return false;

    node<T>* head = tail->next;

    // Case 1: The value is at the Head
    if (head->data == value)
    {
        deleteFromHead();
        return true;
    }

    // Case 2: The value is at the Tail
    if (tail->data == value)
    {
        deleteFromTail();
        return true;
    }

    // Case 3: Search within the middle nodes
    node<T>* temp = head->next;

    while (temp != tail)
    {
        if (temp->data == value)
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            delete temp;
            return true;
        }
        temp = temp->next;
    }

    cout << "Value " << value << " not found." << endl;
    return false;
}