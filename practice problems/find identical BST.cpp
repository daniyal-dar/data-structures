
// Note* this file contains the implementation of the functions only not the BST header file

...
template <typename T>
bool BST<T>::isIdentical(const BST<T>& otherTree)
{
    // Start the recursive structure and data check from both roots
    return isIdenticalHelper(this->root, otherTree.root);
}

template <typename T>
bool BST<T>::isIdenticalHelper(Node<T>* root1, Node<T>* root2)
{
    // Case 1: Both nodes are null (reached the leaf ends together) -> structurally identical so far
    if (root1 == nullptr && root2 == nullptr)
        return true;

    // Case 2: One node is null and the other is not -> structural mismatch
    if (root1 == nullptr || root2 == nullptr)
        return false;

    // Case 3: Both nodes have data -> check if current data matches, 
    // and recursively check both left and right subtrees
    return (root1->data == root2->data) && 
           isIdenticalHelper(root1->leftChild, root2->leftChild) && 
           isIdenticalHelper(root1->rightChild, root2->rightChild);
}
....