/**
 * @brief Deletes a target node from a singly linked list in O(1) time complexity.
 * 
 * @note This is a standalone helper function. It assumes the address of the target 
 *       node is retrieved externally (e.g., via a pre-implemented `getNode()` method).
 * 
 * @constraints This approach relies on "identity theft" (copying the next node's data).
 *              Therefore, it CANNOT be used if the target node is the tail of the list.
 */

// The O(1) Deletion Function
void deleteNode(Node* nodeToDelete) 
{
    // 1. Safety check: Since it's not the tail, nodeToDelete->next exists
    if (nodeToDelete == nullptr || nodeToDelete->next == nullptr) { return; }

    // 2. Store the pointer to the next node temporarily
    Node* temp = nodeToDelete->next;

    // 3. Copy the data from the next node to the current node
    nodeToDelete->data = temp->data;

    // 4. Link the current node to the node after 'temp'
    nodeToDelete->next = temp->next;

    // 5. Delete the physical memory of the old next node
    delete temp;
}