
// Note* this file contains the implementation of the functions only not the BST header file

...
template <typename T>
void BST<T>::insert(T value)
{
    // Pass root by reference to the helper so it can modify the tree structure
    insertHelper(root, value);
}

template <typename T>
void BST<T>::insertHelper(Node<T>*& p, T value)
{
    // Case 1: Found an empty spot, create the new node here
    if (p == nullptr)
    {
        p = new Node<T>;
        p->data = value;
        p->leftChild = nullptr;
        p->rightChild = nullptr;
    }
    // Case 2: Value is smaller, go to the left subtree
    else if (value < p->data)
    {
        insertHelper(p->leftChild, value);
    }
    // Case 3: Value is greater, go to the right subtree
    else if (value > p->data)
    {
        insertHelper(p->rightChild, value);
    }
    // Case 4: Value is equal (duplicate) -> Do nothing, as duplicates aren't allowed
}
....