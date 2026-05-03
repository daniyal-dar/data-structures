


// this header file contains the implementation of the linked (circular LL) list using 
// tail pointer only


#pragma once
#include<iostream>
using namespace std;

template<class T>
struct node
{
	T data;
	node<T>* next;
};

template<class T>
class LinkedList
{
private:
	node<T>*  tail;     // pointer points to the last node of the linked list

public:

    // ---------- essential functions ---------------
    LinkedList();                    // default constructor
    ~LinkedList();                   // destructor
    void insertAtHead(T value);      // adds element at the start of the list
    void insertAtTail(T value);      // adds element at te end of the list
    T deleteFromHead();              // removes element from the start of the list 
    T deleteFromTail();              // removes element from the end of the list
    void display();                  // displays the list
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
    tail->next = nullptr;

    while (current!=nullptr)
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
    nn->next = nullptr;
    nn->data = value;

    if (isEmpty())
    {
        tail = nn;
        tail->next = tail;
    }
    else
    {
        nn->next = tail->next;
        tail->next = nn;
    }
}

template <class T>
void LinkedList<T>::insertAtTail(T value)
{
    node<T>* nn = new node<T>;
    nn->next = nullptr;
    nn->data = value;

    if (isEmpty())
    {
        tail = nn;
        tail->next = tail;
    }
    else
    {
        nn->next = tail->next;
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
        else
        {
            temp = temp->next;
            position++;
        }

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
    else if (tail->next == tail)
    {
        T value = tail->data;
        delete tail;
        tail = nullptr;
        return value;
    }
    else
    {
        node<T>* temp = tail->next;
        T value = temp->data;

        tail->next = temp->next;
        
        delete temp;
        temp = nullptr;
        return value;
    }
}

template <class T>
T LinkedList<T>::deleteFromTail()
{
    if (isEmpty())
    {
        cout << "List is empty! nothing to remove." << endl;
        return T();
    }
    else if (tail->next == tail)
    {
        T value = tail->data;
        delete tail;
        tail = nullptr;
        return value;
    }
    else
    {
        node<T>* temp = tail->next;
        while (temp->next != tail) 
            temp = temp->next;

        T value = tail->data;
        temp->next = tail->next; // New tail points to head
        delete tail;             // Delete old tail
        tail = temp;             // Update the class tail pointer
        return value;
    }
}



template <class T>
bool LinkedList<T>::deleteByValue(T value)
{
    node<T>* temp = tail->next;
    node<T>* prev = nullptr;

    if (isEmpty())
        return false;

    if (temp->data == value)
    {
        deleteFromHead();
        return true;
    }

    while (true)
    {
        if (temp->data == value)
        {
            prev->next = temp->next;
            if (temp == tail)       // last node of the linked list
                tail = prev;

            delete temp;
            return true;
        }
        prev = temp;
        temp = temp->next;
        
        if (temp->next == tail->next)
            break;
    }

    cout << "Value " << value << " not found." << endl;
    return false;
}


