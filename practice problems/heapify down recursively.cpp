
// this file only contains the function implementation
...
void heapifyDownRecursive(int index, int heapSize) {
    int leftChild = 2 * index;       // 1-based index formula
    int rightChild = 2 * index + 1;   // 1-based index formula
    int largest = index;

    // Check if left child exists and is larger than current largest
    if (leftChild <= heapSize && heap[leftChild] > heap[largest]) {
        largest = leftChild;
    }

    // Check if right child exists and is larger than current largest
    if (rightChild <= heapSize && heap[rightChild] > heap[largest]) {
        largest = rightChild;
    }

    // If a child is larger, a swap is needed
    if (largest != index) {
        swap(heap[index], heap[largest]);
        
        // Recursive Call: Follow the element down into the subtree
        heapifyDownRecursive(largest, heapSize);
    }
}
....