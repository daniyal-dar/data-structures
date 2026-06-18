

// this file only contains the function implementation 

...
void heapifyUpRecursive(int index) {
    // Base Case: Root has no parent
    if (index <= 1) {
        return;
    }

    int parentIndex = index / 2; // 1-based index formula

    // If the current node violates the Max-Heap property
    if (heap[index] > heap[parentIndex]) {
        swap(heap[index], heap[parentIndex]);
        
        // Recursive Call: Follow the element up to its new position
        heapifyUpRecursive(parentIndex);
    }
}
....