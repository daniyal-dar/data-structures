/*********************************************************************************************
* 
* Imagine a library system where each book is stored in a Binary Search Tree (BST) using its ISBN 
* number as the unique key. The BST allows fast searching, insertion, and deletion of books, but when 
* it comes to creating a sorted catalog of all books, a linked list is more efficient for sequential traversal.
* Your task is to convert the BST into a sorted singly linked list using recursion. The conversion should 
* maintain the natural ascending order of ISBNs, which can be achieved by performing an inorder traversal of 
* the BST. Each visited node should be inserted into the linked list in the same order
* Detailed Requirements:
* 1. Input: A BST where each node contains:
*         o	ISBN (integer key)
*         o	Title (string for book title)
*         o	Left and right pointers
* 2. Output: A singly linked list where each node contains:
*         o	ISBN
*         o	Title
*         o	Pointer to the next node
* 3. Operations to Implement:
*         o	Insert books into the BST by ISBN.
*         o	Perform an inorder traversal to process nodes in sorted order.
*         o	Recursively convert the BST into a sorted singly linked list.
*         o	Print the linked list to show the catalog.
* 
*********************************************************************************************/


#include <iostream>
#include "Book.h"
#include "catalogconvertor.h"

using namespace std;

// Note* "BST.h" and "linkedList-singly" are prelinked in this code but not added in the solution
// to compile this code you need to download the header file seperately from the implementation section
// [same repo] and place it in the same root folder


int main() 
{
    BST<Book> libraryTree;

    // Inserting books into the BST out of order using the Class constructor
    libraryTree.insert(Book(97803, "The Hobbit"));
    libraryTree.insert(Book(97801, "Introduction to Algorithms"));
    libraryTree.insert(Book(97805, "Clean Code"));
    libraryTree.insert(Book(97802, "Design Patterns"));
    libraryTree.insert(Book(97804, "The Pragmatic Programmer"));

    cout << "BST Inorder Traversal (Verifying BST sorting):" << endl;
    libraryTree.displayInorder();
    cout << "------------------------------------------------" << endl;

    // Create our target catalog container
    LinkedList<Book> catalogList;

    // Convert the collections
    convertViaDestruction(libraryTree, catalogList);

    cout << "Final Sorted Linked List Catalog:" << endl;
    catalogList.display();

    return 0;
}