

// this header file contains the generic code of doubly linked list 
// using head and tail pointer

#pragma once
#include <iostream>
using namespace std;

template <class T>
struct node {
    T data;
    node<T>* next;
    node<T>* prev;
};

template <class T>
class LinkedList
{
private:
    node<T>* head;          // pointer points to the first node
    node<T>* tail;          // pointer points to the last node

public:

    // ---------- essential functions ---------------
    LinkedList();                   // default constructor
    ~LinkedList();                  // destructor
    void insertAtHead(T value);     // adds element at the start of the list
    void insertAtTail(T value);     // adds element at the end of the list
    T deleteFromHead();             // removes value from the start of the list
    T deleteFromTail();             // removes value from the end of the list
    void display();                 // displays linked list
    bool isEmpty();                 // check is linked list empty

    // ---------- other functions --------------------
    bool insertAtPosition(T value, int index);     // insert new node at the given index
    bool updateAtPosition(T value, int index);     // update the values at the given index
    int searchByValue(T value);                    // return the index of the given element
    bool deleteByValue(T value);                   // deletes the nodes of given element
    bool deleteFromPosition(int index);            // delets the node from the given index
};

// --- Function Definitions ---

template <class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    if (isEmpty())
        return;

    node<T>* current = head;
    node<T>* nextNode = nullptr;

    while (current != nullptr)
    {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
    tail = nullptr;
}

template <class T>
void LinkedList<T>::insertAtHead(T value)
{
    node<T>* nn = new node<T>;
    nn->next = nullptr;
    nn->prev = nullptr;
    nn->data = value;

    if (isEmpty())
    {
        head = nn;
        tail = nn;
    }
    else
    {
        nn->next = head;
        head->prev = nn;
        head = nn;
    }
}

template <class T>
void LinkedList<T>::insertAtTail(T value)
{
    node<T>* nn = new node<T>;
    nn->next = nullptr;
    nn->prev = nullptr;
    nn->data = value;

    if (isEmpty())
    {
        head = nn;
        tail = nn;
    }
    else
    {
        tail->next = nn;
        nn->prev = tail;
        tail = nn;
    }
}

template <class T>
bool LinkedList<T>::insertAtPosition(T value, int index)
{
    if (isEmpty() && index != 0)
    {
        cout << "List is empty! operation terminated." << endl;
        return false;
    }

    if (index == 0)
    {
        insertAtHead(value);
        return true;
    }

    node<T>* temp = head;
    node<T>* prev = nullptr;
    int pos = 0;
    bool done = false;

    node<T>* nn = new node<T>;
    nn->data = value;
    nn->next = nullptr;
    nn->prev = nullptr;

    while (temp != nullptr)
    {
        if (pos == index)
        {
            nn->next = temp;
            prev->next = nn;
            nn->prev = prev;
            temp->prev = nn;
            done = true;
            break;
        }
        prev = temp;
        temp = temp->next;
        pos++;
    }

    if (!done && pos == index)
    {
        insertAtTail(value);
        done = true;
    }

    if (!done)
    {
        cout << "Index out of bounds!" << endl;
        delete nn;
    }

    return done;
}

template <class T>
bool LinkedList<T>::updateAtPosition(T value, int index)
{
    if (isEmpty())
    {
        cout << "List is empty! operation terminated." << endl;
        return false;
    }
    else
    {
        node<T>* temp = head;
        int pos = 0;
        bool done = false;

        while (temp != nullptr)
        {
            if (pos == index)
            {
                temp->data = value;
                done = true;
                break;
            }
            else
            {
                temp = temp->next;
                pos++;
            }
        }
        return done;
    }
}

template <class T>
int LinkedList<T>::searchByValue(T value)
{
    if (isEmpty()) return -1;

    node<T>* temp = head;
    int position = 0;
    while (temp != nullptr)
    {
        if (temp->data == value)
            return position;
        else
        {
            temp = temp->next;
            position++;
        }
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
        node<T>* temp = head;
        while (temp != nullptr)
        {
            cout << "data: " << temp->data << endl;
            temp = temp->next;
        }
    }
}

template <class T>
bool LinkedList<T>::isEmpty()
{
    return tail == nullptr && head == nullptr;
}

template <class T>
T LinkedList<T>::deleteFromHead()
{
    if (isEmpty())
    {
        cout << "List is empty! nothing to remove." << endl;
        return T();
    }
    else
    {
        node<T>* temp = head;
        head = head->next;

        if (head == nullptr)
            tail = nullptr;
        else
            head->prev = nullptr;

        T value = temp->data;
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
    else
    {
        node<T>* temp = tail;
        tail = tail->prev;

        if (tail == nullptr)
            head = nullptr;
        else
            tail->next = nullptr;

        T value = temp->data;
        delete temp;
        temp = nullptr;
        return value;
    }
}

template <class T>
bool LinkedList<T>::deleteFromPosition(int index)
{
    if (isEmpty())
    {
        cout << "List is empty! operation terminated." << endl;
        return false;
    }
    else
    {
        node<T>* temp = head;
        int pos = 0;
        bool done = false;


        while (temp != nullptr)
        {
            if (pos == index)
            {
                if (index == 0)
                {
                    deleteFromHead();
                    return true;
                }

                temp->prev->next = temp->next;
                if (temp->next != nullptr)
                    temp->next->prev = temp->prev;
                else
                    tail = temp->prev;
                
                temp->next = nullptr;
                temp->prev = nullptr;
                delete temp;
                temp = nullptr;
                done = true;
                break;
            }
            temp = temp->next;
            pos++;
        }
        return done;
    }
}

template <class T>
bool LinkedList<T>::deleteByValue(T value)
{
    if (isEmpty()) return false;

    node<T>* temp = head;

    while (temp != nullptr)
    {
        if (temp->data == value)
        {
            if (temp == head)       // deleting from head
            {
                deleteFromHead();
                return true;
            }
            if (temp == tail)       // deleting from tail
            {
                deleteFromTail();
                return true;
            }

            // deleting from middle
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            temp->next = nullptr;
            temp->prev = nullptr;
            delete temp;
            temp = nullptr;
            return true;
        }
        temp = temp->next;
    }
    return false;
}


