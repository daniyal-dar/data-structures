
// Note* this file contains the implementation of the functions only not the BST header file

...
template <typename T>
bool BST<T>::search(T value)
{
    // Start the recursive check from the root
    return searchHelper(root, value);
}

template <typename T>
bool BST<T>::searchHelper(Node<T>* p, T value)
{
    // Case 1: Base case - tree is empty or we hit the end without finding it
    if (p == nullptr)
        return false;

    // Case 2: Base case - value found!
    if (value == p->data)
        return true;
    
    // Case 3: Value is smaller, search the left subtree recursively
    if (value < p->data)
        return searchHelper(p->leftChild, value);
    
    // Case 4: Value is greater, search the right subtree recursively
    return searchHelper(p->rightChild, value);
}
....