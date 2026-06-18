#pragma once
#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    int isbn;
    string title;

public:
    // Constructors
    Book() : isbn(0), title("") {}
    Book(int i, string t) : isbn(i), title(t) {}

    // Getters
    int getIsbn() const { return isbn; }
    string getTitle() const { return title; }

    // 1. Less-than operator overload: Used by BST to decide left/right placement
    bool operator<(const Book& other) const {
        return this->isbn < other.isbn;
    }

    // 2. Equality operator overload: Used by BST and LinkedList for searching/deleting
    bool operator==(const Book& other) const {
        return this->isbn == other.isbn;
    }
};

// 3. Stream insertion operator overload: Placed outside the class so std::cout can access it
inline ostream& operator<<(ostream& os, const Book& book) {
    os << "[" << book.getIsbn() << ": " << book.getTitle() << "]";
    return os;
}