
// this file contains only the imlementation of the function

...
void LinkedList::reverseIterative() 
{
    // Edge case: if list is empty or has only one node, no reversal needed
    if (head == nullptr || head->next == nullptr) 
    {
        return;
    }

    Node* prev = nullptr;
    Node* current = head;
    Node* nextNode = nullptr;

    while (current != nullptr) 
    {
        // 1. Save the rest of the list before flipping the link
        nextNode = current->next;

        // 2. Flip the arrow to point backward
        current->next = prev;

        // 3. Move the pointer positions forward for the next loop
        prev = current;
        current = nextNode;
    }

    // 4. Update the class's internal head pointer to the new front node
    head = prev;
}
....