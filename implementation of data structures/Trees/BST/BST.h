
// This header file contains the generic implementation of the Binary Search Tree (BST) 
// class template. It defines the structure of the tree nodes and the BST class with its 
// member functions for insertion, deletion, searching, traversals, and other utility 
// functions. The implementation includes private helper functions for recursive operations 
// on the tree.

#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

// GENERIC NODE----------------
template <typename T>
struct Node
{
    T data;
    Node* leftChild;
    Node* rightChild;
};

// GENERIC CLASS---------------
template <typename T>
class BST
{
private:
    Node<T>* root;

    void destroyTree(Node<T>* currentNode);
    void inorderHelper(Node<T>* p);
    void preorderHelper(Node<T>* p);
    void postorderHelper(Node<T>* p);
    int getHeightHelper(Node<T>* p);
    int countNodesHelper(Node<T>* p);
    int countLeavesHelper(Node<T>* p);

public:
    BST();
    ~BST();

    void insert(T value);
    bool deleteByValue(T key);
    bool isEmpty();
    bool search(T value);
    void displayInorder();
    void displayPreorder();
    void displayPostorder();

    int getHeight();
    int countNodes();
    int countLeaves();
    T findMin();
    T findMax();
};

// PRIVATE HELPER FUNCTIONS IMPLEMENTATION -------------------

template <typename T>
void BST<T>::destroyTree(Node<T>* currentNode)
{
    if (currentNode == nullptr) return;

    destroyTree(currentNode->leftChild);
    destroyTree(currentNode->rightChild);

    delete currentNode;
}

template <typename T>
void BST<T>::inorderHelper(Node<T>* p)
{
    if (p != nullptr)
    {
        inorderHelper(p->leftChild);
        cout << p->data << " "; // Changed from endl to space so it prints on a single line matching main expectations
        inorderHelper(p->rightChild);
    }
}

template <typename T>
void BST<T>::preorderHelper(Node<T>* p)
{
    if (p != nullptr)
    {
        cout << p->data << " ";
        preorderHelper(p->leftChild);
        preorderHelper(p->rightChild);
    }
}

template <typename T>
void BST<T>::postorderHelper(Node<T>* p)
{
    if (p != nullptr)
    {
        postorderHelper(p->leftChild);
        postorderHelper(p->rightChild);
        cout << p->data << " ";
    }
}

template <typename T>
int BST<T>::getHeightHelper(Node<T>* p)
{
    if (p == nullptr)
        return -1;

    int leftHeight = getHeightHelper(p->leftChild);
    int rightHeight = getHeightHelper(p->rightChild);

    return 1 + max(leftHeight, rightHeight);
}

template <typename T>
int BST<T>::countNodesHelper(Node<T>* p)
{
    if (p == nullptr)
        return 0;

    return 1 + countNodesHelper(p->leftChild) + countNodesHelper(p->rightChild);
}

template <typename T>
int BST<T>::countLeavesHelper(Node<T>* p)
{
    if (p == nullptr)
        return 0;

    if (p->leftChild == nullptr && p->rightChild == nullptr)
        return 1;

    return countLeavesHelper(p->leftChild) + countLeavesHelper(p->rightChild);
}

// PUBLIC FUNCTIONS IMPLEMENTATION --------------------

template <typename T>
BST<T>::BST() { root = nullptr; }

template <typename T>
BST<T>::~BST()
{
    destroyTree(root);
    root = nullptr;
}

template <typename T>
void BST<T>::insert(T value)
{
    Node<T>* nn = new Node<T>;
    nn->data = value;
    nn->leftChild = nullptr;
    nn->rightChild = nullptr;

    if (root == nullptr)
        root = nn;
    else
    {
        Node<T>* p = root;
        while (true)
        {
            if (value < p->data)
            {
                if (p->leftChild == nullptr)
                {
                    p->leftChild = nn;
                    break;
                }
                p = p->leftChild;
            }
            else
            {
                if (p->rightChild == nullptr)
                {
                    p->rightChild = nn;
                    break;
                }
                p = p->rightChild;
            }
        }
    }
}

template <typename T>
bool BST<T>::deleteByValue(T key)
{
    Node<T>* current = root;
    Node<T>* parent = nullptr;

    while (current != nullptr && current->data != key)
    {
        parent = current;
        if (key < current->data)
            current = current->leftChild;
        else
            current = current->rightChild;
    }

    if (current == nullptr)
        return false;

    if (current->leftChild != nullptr && current->rightChild != nullptr)
    {
        Node<T>* successorParent = current;
        Node<T>* successor = current->rightChild;

        while (successor->leftChild != nullptr)
        {
            successorParent = successor;
            successor = successor->leftChild;
        }

        current->data = successor->data;

        parent = successorParent;
        current = successor;
    }

    Node<T>* child = (current->leftChild != nullptr) ? current->leftChild : current->rightChild;

    if (parent == nullptr)
        root = child;
    else if (current == parent->leftChild)
        parent->leftChild = child;
    else
        parent->rightChild = child;

    delete current;
    return true; // Added missing return value statement from original logic 
}

template <typename T>
bool BST<T>::isEmpty() { return root == nullptr; }

template <typename T>
bool BST<T>::search(T value)
{
    Node<T>* current = root;

    while (current != nullptr)
    {
        if (value == current->data)
            return true;
        else if (value < current->data)
            current = current->leftChild;
        else
            current = current->rightChild;
    }

    return false;
}

template <typename T>
void BST<T>::displayInorder()
{
    if (root == nullptr)
        cout << "Tree is empty" << endl;
    else {
        inorderHelper(root);
        cout << endl;
    }
}

template <typename T>
void BST<T>::displayPreorder()
{
    if (root == nullptr)
        cout << "Tree is empty" << endl;
    else {
        preorderHelper(root);
        cout << endl;
    }
}

template <typename T>
void BST<T>::displayPostorder()
{
    if (root == nullptr)
        cout << "Tree is empty" << endl;
    else {
        postorderHelper(root);
        cout << endl;
    }
}

template <typename T>
int BST<T>::getHeight() { return getHeightHelper(root); }

template <typename T>
int BST<T>::countNodes() { return countNodesHelper(root); }

template <typename T>
int BST<T>::countLeaves() { return countLeavesHelper(root); }

template <typename T>
T BST<T>::findMin()
{
    if (isEmpty())
    {
        cout << "Tree is empty!" << endl;
        return T(); // Returns default value of type T if empty
    }

    Node<T>* current = root;
    while (current->leftChild != nullptr)
        current = current->leftChild;

    return current->data;
}

template <typename T>
T BST<T>::findMax()
{
    if (isEmpty())
    {
        cout << "Tree is empty!" << endl;
        return T(); // Returns default value of type T if empty
    }

    Node<T>* current = root;
    while (current->rightChild != nullptr)
        current = current->rightChild;

    return current->data;
}