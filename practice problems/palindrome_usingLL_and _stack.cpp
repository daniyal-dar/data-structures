/**
 * @brief Checks if a head-pointer-only Linked List contains a palindrome sequence.
 * 
 * @note This is a global function implemented in main. Because the underlying Linked List 
 *       is a head-only implementation, it natively behaves exactly like a stack (LIFO: 
 *       Last-In, First-Out) when using head operations. 
 * 
 * @param list Reference to the LinkedList object (will be consumed/destroyed).
 * @param s Reference to the auxiliary Stack object.
 * @param n Total number of single-digit elements in the list.
 * 
 * @return true if the original sequence was a palindrome, false otherwise.
 * 
 * @warning DESTRUCTIVE OPERATION: The original linked list is fully consumed and emptied
 *          by design upon completion of this function.
 */
bool isPalindromeDestructive(LinkedList& list, Stack& s, int n) 
{
    // Edge cases: An empty list or single digit is inherently a palindrome
    if (n <= 1) return true;

    // 1. Copy the first half into the stack by consuming the LL
    for (int i = 0; i < n / 2; i++) 
        s.push(list.deleteFromHead());

    // 2. Handle odd sizes by dropping the middle element entirely
    if (n % 2 != 0)
        list.deleteFromHead();

    // 3. Pop from stack and match against the remaining data consumed from the head
    bool isPalin = true;
    
    for (int i = 0; i < n / 2; i++) 
    {
        int stackVal = s.pop();
        int listVal = list.deleteFromHead();
        
        // If a mismatch is found, mark it, but do NOT break out early.
        // We must finish the loop to completely destroy and deallocate the rest of the list.
        if (stackVal != listVal) 
            isPalin = false;
    }

    return isPalin;
}