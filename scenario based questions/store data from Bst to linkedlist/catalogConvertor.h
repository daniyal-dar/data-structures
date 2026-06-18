#pragma once
#include "BST.h"
#include "linkedList-singly.h"
#include "Book.h"

inline void convertViaDestruction(BST<Book>& tree, LinkedList<Book>& list) {
    while (!tree.isEmpty()) {
        Book minBook = tree.findMin();
        list.insertAtTail(minBook);
        tree.deleteByValue(minBook); // Removes from tree so the next findMin() grabs the next sorted book
    }
}
