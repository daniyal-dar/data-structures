#pragma once
#include <iostream>
using namespace std;


enum colour { RED, BLACK };

struct node {
    int data;                  // Data/Key value
    colour colour;             // Node colour
    node* leftChild;           // Left child pointer
    node* rightChild;          // Right child pointer
};


class RBT {
private:
    node* root;                                     // Root pointer of the Red-Black Tree

    // Private helper functions
    node* getParent(node* current);                // Returns parent of given node
    node* getParent(node* p, node* child);         // Searches parent dynamically from a root pointer
    void destroyTree(node* current);               // Recursively deletes all nodes
    void preorderHelper(node* current);            // Preorder traversal helper (Root, Left, Right)
    void postorderHelper(node* current);           // Postorder traversal helper (Left, Right, Root)
    void inorderHelper(node* current);             // Inorder traversal helper (Left, Root, Right)
    void recolor(node* current);                   // Changes colours to fix Red-Black properties
    void restructure(node* current);               // Performs rotations and colour changes for balancing

    // Additional RBT helper functions
    node* createNode(int value);                   // creates node
    void leftRotate(node* current);                // Left rotation around given node
    void rightRotate(node* current);               // Right rotation around given node
    void fixInsert(node* current);                 // Fixes violations after insertion
    void fixDelete(node* x, node* xParent, bool xIsLeftChild); // Fixes violations after deletion
    node* findNode(node* p, int value);            // Internal recursive search helper
    node* findNode(int value);                     // Returns node with specified value
    node* getUncle(node* current);                 // Returns uncle of given node
    node* getSibling(node* current);               // Returns sibling of given node
    void transplant(node* u, node* v);             // Replaces subtree u with subtree v
    node* getMinimum(node* current);               // Returns node with minimum value in subtree
    void deleteNode(node* current);                // Removes specific node from tree

    // Utility helpers mapped from reference logic
    colour getColour(node* p);                     // Safely reads colour handling null pointers
    void setColour(node* p, colour c);             // Safely updates a node's colour
    node* getGrandParent(node* child);             // Safely determines grandparent node
    node* insertHelper(node* p, int value, node*& inserted); // Performs binary tree insertion

public:
    // Constructor & Destructor
    RBT();                                          // Initializes empty Red-Black Tree
    ~RBT();                                         // Cleans up all nodes and frees memory

    // Public operations
    bool isEmpty();                                 // Checks if tree is empty
    void insert(int value);                         // Inserts value into tree
    void deleteValue(int value);                    // Deletes value from tree
    bool search(int value);                         // Searches for value in tree
    void displayInorder();                          // Displays tree inorder (sorted order)
    void displayPreorder();                         // Displays tree preorder
    void displayPostorder();                        // Displays tree postorder
};



// Constructor
RBT::RBT() {
    root = nullptr;
}

// Destructor
RBT::~RBT() {
    destroyTree(root);
}

// Safely reads colour handling null pointers
colour RBT::getColour(node* p) {
    if (p == nullptr) {
        return BLACK;
    }
    return p->colour;
}

// Safely updates a node's colour
void RBT::setColour(node* p, colour c) {
    if (p != nullptr) {
        p->colour = c;
    }
}

// Recursively deletes all nodes
void RBT::destroyTree(node* current) {
    if (current == nullptr) {
        return;
    }
    destroyTree(current->leftChild);
    destroyTree(current->rightChild);
    delete current;
}

// Preorder traversal helper (Root, Left, Right)
void RBT::preorderHelper(node* current) {
    if (current == nullptr) {
        return;
    }
    cout << current->data << "(" << (current->colour == RED ? "R" : "B") << ") ";
    preorderHelper(current->leftChild);
    preorderHelper(current->rightChild);
}

// Postorder traversal helper (Left, Right, Root)
void RBT::postorderHelper(node* current) {
    if (current == nullptr) {
        return;
    }
    postorderHelper(current->leftChild);
    postorderHelper(current->rightChild);
    cout << current->data << "(" << (current->colour == RED ? "R" : "B") << ") ";
}

// Inorder traversal helper (Left, Root, Right)
void RBT::inorderHelper(node* current) {
    if (current == nullptr) {
        return;
    }
    inorderHelper(current->leftChild);
    cout << current->data << "(" << (current->colour == RED ? "R" : "B") << ") ";
    inorderHelper(current->rightChild);
}

// Searches parent dynamically from a root pointer
node* RBT::getParent(node* p, node* child) {
    if (p == nullptr || child == nullptr) {
        return nullptr;
    }
    if (p->leftChild == child || p->rightChild == child) {
        return p;
    }
    node* leftSearch = getParent(p->leftChild, child);
    if (leftSearch != nullptr) {
        return leftSearch;
    }
    return getParent(p->rightChild, child);
}

// Returns parent of given node
node* RBT::getParent(node* current) {
    return getParent(root, current);
}

// Safely determines grandparent node
node* RBT::getGrandParent(node* child) {
    node* parent = getParent(child);
    if (parent == nullptr) {
        return nullptr;
    }
    return getParent(parent);
}

// Returns uncle of given node
node* RBT::getUncle(node* current) {
    node* parent = getParent(current);
    node* grandParent = getGrandParent(current);
    if (parent == nullptr || grandParent == nullptr) {
        return nullptr;
    }
    if (parent == grandParent->leftChild) {
        return grandParent->rightChild;
    }
    else {
        return grandParent->leftChild;
    }
}

// Returns sibling of given node
node* RBT::getSibling(node* current) {
    node* parent = getParent(current);
    if (parent == nullptr) {
        return nullptr;
    }
    if (current == parent->leftChild) {
        return parent->rightChild;
    }
    else {
        return parent->leftChild;
    }
}

// creates node
node* RBT::createNode(int value) {
    node* nn = new node;
    nn->data = value;
    nn->colour = RED;
    nn->leftChild = nullptr;
    nn->rightChild = nullptr;
    return nn;
}

// Left rotation around given node
void RBT::leftRotate(node* current) {
    if (current == nullptr || current->rightChild == nullptr) {
        return;
    }
    node* y = current->rightChild;
    node* parent = getParent(current);
    current->rightChild = y->leftChild;
    y->leftChild = current;
    if (parent == nullptr) {
        root = y;
    }
    else if (parent->leftChild == current) {
        parent->leftChild = y;
    }
    else {
        parent->rightChild = y;
    }
}

// Right rotation around given node
void RBT::rightRotate(node* current) {
    if (current == nullptr || current->leftChild == nullptr) {
        return;
    }
    node* y = current->leftChild;
    node* parent = getParent(current);
    current->leftChild = y->rightChild;
    y->rightChild = current;
    if (parent == nullptr) {
        root = y;
    }
    else if (parent->leftChild == current) {
        parent->leftChild = y;
    }
    else {
        parent->rightChild = y;
    }
}

// Changes colours to fix Red-Black properties
void RBT::recolor(node* current) {
    node* parent = getParent(current);
    node* grandParent = getParent(parent);
    node* uncle = getUncle(current);
    setColour(parent, BLACK);
    setColour(uncle, BLACK);
    setColour(grandParent, RED);
}

// Performs rotations and colour changes for balancing
void RBT::restructure(node* current) {
    node* parent = getParent(current);
    node* grandParent = getParent(parent);
    if (parent == grandParent->leftChild) {
        if (current == parent->rightChild) {
            leftRotate(parent);
            current = parent;
            parent = getParent(current);
        }
        setColour(parent, BLACK);
        setColour(grandParent, RED);
        rightRotate(grandParent);
    }
    else {
        if (current == parent->leftChild) {
            rightRotate(parent);
            current = parent;
            parent = getParent(current);
        }
        setColour(parent, BLACK);
        setColour(grandParent, RED);
        leftRotate(grandParent);
    }
}

// Fixes violations after insertion
void RBT::fixInsert(node* current) {
    while (current != root && getColour(getParent(current)) == RED) {
        node* parent = getParent(current);
        node* grandParent = getParent(parent);
        if (grandParent == nullptr) {
            break;
        }
        node* uncle = getUncle(current);
        if (getColour(uncle) == RED) {
            recolor(current);
            current = grandParent;
        }
        else {
            restructure(current);
            break;
        }
    }
    setColour(root, BLACK);
}

// Replaces subtree u with subtree v
void RBT::transplant(node* u, node* v) {
    node* parent = getParent(u);
    if (parent == nullptr) {
        root = v;
    }
    else if (parent->leftChild == u) {
        parent->leftChild = v;
    }
    else {
        parent->rightChild = v;
    }
}

// Returns node with minimum value in subtree
node* RBT::getMinimum(node* current) {
    if (current == nullptr) {
        return nullptr;
    }
    while (current->leftChild != nullptr) {
        current = current->leftChild;
    }
    return current;
}

// Fixes violations after deletion
void RBT::fixDelete(node* x, node* xParent, bool xIsLeftChild) {
    while (x != root && getColour(x) == BLACK) {
        if (xParent == nullptr) {
            break;
        }
        bool isLeft = (x != nullptr) ? (xParent->leftChild == x) : xIsLeftChild;
        if (isLeft) {
            node* sibling = xParent->rightChild;
            if (getColour(sibling) == RED) {
                setColour(sibling, BLACK);
                setColour(xParent, RED);
                leftRotate(xParent);
                sibling = xParent->rightChild;
            }
            if (getColour(sibling == nullptr ? nullptr : sibling->leftChild) == BLACK &&
                getColour(sibling == nullptr ? nullptr : sibling->rightChild) == BLACK) {
                setColour(sibling, RED);
                x = xParent;
                xParent = getParent(x);
                if (xParent != nullptr) {
                    xIsLeftChild = (xParent->leftChild == x);
                }
            }
            else {
                if (getColour(sibling == nullptr ? nullptr : sibling->rightChild) == BLACK) {
                    setColour(sibling == nullptr ? nullptr : sibling->leftChild, BLACK);
                    setColour(sibling, RED);
                    rightRotate(sibling);
                    sibling = xParent->rightChild;
                }
                setColour(sibling, getColour(xParent));
                setColour(xParent, BLACK);
                setColour(sibling == nullptr ? nullptr : sibling->rightChild, BLACK);
                leftRotate(xParent);
                x = root;
                xParent = nullptr;
            }
        }
        else {
            node* sibling = xParent->leftChild;
            if (getColour(sibling) == RED) {
                setColour(sibling, BLACK);
                setColour(xParent, RED);
                rightRotate(xParent);
                sibling = xParent->leftChild;
            }
            if (getColour(sibling == nullptr ? nullptr : sibling->leftChild) == BLACK &&
                getColour(sibling == nullptr ? nullptr : sibling->rightChild) == BLACK) {
                setColour(sibling, RED);
                x = xParent;
                xParent = getParent(x);
                if (xParent != nullptr) {
                    xIsLeftChild = (xParent->leftChild == x);
                }
            }
            else {
                if (getColour(sibling == nullptr ? nullptr : sibling->leftChild) == BLACK) {
                    setColour(sibling == nullptr ? nullptr : sibling->rightChild, BLACK);
                    setColour(sibling, RED);
                    leftRotate(sibling);
                    sibling = xParent->leftChild;
                }
                setColour(sibling, getColour(xParent));
                setColour(xParent, BLACK);
                setColour(sibling == nullptr ? nullptr : sibling->leftChild, BLACK);
                rightRotate(xParent);
                x = root;
                xParent = nullptr;
            }
        }
    }
    setColour(x, BLACK);
}

// Removes specific node from tree
void RBT::deleteNode(node* z) {
    if (z == nullptr) {
        return;
    }
    node* y = z;
    node* x = nullptr;
    node* xParent = nullptr;
    bool xIsLeftChild = false;
    colour yOriginalColour = y->colour;

    if (z->leftChild == nullptr) {
        x = z->rightChild;
        xParent = getParent(z);
        if (xParent != nullptr) {
            xIsLeftChild = (xParent->leftChild == z);
        }
        transplant(z, z->rightChild);
    }
    else if (z->rightChild == nullptr) {
        x = z->leftChild;
        xParent = getParent(z);
        if (xParent != nullptr) {
            xIsLeftChild = (xParent->leftChild == z);
        }
        transplant(z, z->leftChild);
    }
    else {
        y = getMinimum(z->rightChild);
        yOriginalColour = y->colour;
        x = y->rightChild;
        node* yParent = getParent(y);
        if (yParent == z) {
            xParent = y;
            xIsLeftChild = false;
        }
        else {
            xParent = yParent;
            if (yParent != nullptr) {
                xIsLeftChild = (yParent->leftChild == y);
            }
            transplant(y, y->rightChild);
            y->rightChild = z->rightChild;
        }
        transplant(z, y);
        y->leftChild = z->leftChild;
        y->colour = z->colour;
    }
    delete z;
    if (yOriginalColour == BLACK) {
        fixDelete(x, xParent, xIsLeftChild);
    }
    if (root != nullptr) {
        root->colour = BLACK;
    }
}

// Internal recursive search helper
node* RBT::findNode(node* p, int value) {
    if (p == nullptr) {
        return nullptr;
    }
    if (value == p->data) {
        return p;
    }
    else if (value < p->data) {
        return findNode(p->leftChild, value);
    }
    else {
        return findNode(p->rightChild, value);
    }
}

// Returns node with specified value
node* RBT::findNode(int value) {
    return findNode(root, value);
}

// Performs binary tree insertion
node* RBT::insertHelper(node* p, int value, node*& inserted) {
    if (p == nullptr) {
        inserted = createNode(value);
        return inserted;
    }
    if (value < p->data) {
        p->leftChild = insertHelper(p->leftChild, value, inserted);
    }
    else {
        p->rightChild = insertHelper(p->rightChild, value, inserted);
    }
    return p;
}

// Checks if tree is empty
bool RBT::isEmpty() {
    return root == nullptr;
}

// Inserts value into tree
void RBT::insert(int value) {
    node* inserted = nullptr;
    root = insertHelper(root, value, inserted);
    fixInsert(inserted);
}

// Deletes value from tree
void RBT::deleteValue(int value) {
    node* z = findNode(value);
    if (z != nullptr) {
        deleteNode(z);
    }
}

// Searches for value in tree
bool RBT::search(int value) {
    return findNode(value) != nullptr;
}

// Displays tree inorder (sorted order)
void RBT::displayInorder() {
    inorderHelper(root);
    cout << endl;
}

// Displays tree preorder
void RBT::displayPreorder() {
    preorderHelper(root);
    cout << endl;
}

// Displays tree postorder
void RBT::displayPostorder() {
    postorderHelper(root);
    cout << endl;
}