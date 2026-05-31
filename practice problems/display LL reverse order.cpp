


// Description: Contains a recursive function to display a singly linked list 
//              in reverse order using only the head pointer.
//
// Scenario: Given a pointer to the head of a singly linked list, the function 
//           recursively traverses to the end node. As the recursive call stack 
//           unwinds from the tail back to the head, it prints the node values, 
//           effectively displaying the list in reverse order.

// Important Notice : The source code provided herein is restricted to the specific function 
// implementations requested.It is not designed to compile independently.To ensure proper compilation 
// and execution, developers must refactor these functions into template functions and embed them 
// within the existing LinkedList class available in the project repository.

void displayReverse()
{
    if(isEmpty())
		cout << "List is empty" << endl;
    else
		displayReverseRecursive(head);
}

void displayReverseRecursive(node* head) 
{
    // Base Case: If the current node is null, we reached the end of the list
    if (head == nullptr) 
        return;

    // Recursive Step: Pass the next node to the stack first
    displayReverseRecursive(head->next);

    // Print the current node's data as the stack unwinds
    cout << head->data << " ";
}



