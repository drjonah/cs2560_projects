
#include <iostream>
#include <string>
#include "Warehouse.h"
#include "Book.h"
using namespace std;

// Extra headers
Book* mergeSort_(Book* head);
Book* merge_(Book* left, Book* right);
Book* getMiddle_(Book* head);

// Constructor
Warehouse::Warehouse() : bookCount(0) { }

/** 
 * @param is the input stream 
 * @param warehouse the warehouse object reference 
 * @return the input stream 
 */
istream& operator >> (istream& is, Warehouse* warehouse) {
    if (warehouse->bookCount >= 35) {
        cerr << "Too many books! Max is 35." << endl;
        is.setstate(ios::failbit);
        return is;
    }

    Book* book = new Book(); // temp book object

    if (!(is >> book)) {
        cerr << "Error: corrupted book caught." << endl;
        is.setstate(ios::failbit);
        return is;
    }

    book->setNext(warehouse->head); // adds to linked list
    warehouse->head = book; // adds book object
    ++warehouse->bookCount; // increments total

    warehouse->sort_(); // sorts warehouse

    return is;
}

/**
 * @param os the output stream 
 * @param warehouse the warehouse object reference 
 * @return the output stream 
 */ 
ostream& operator << (ostream& os, const Warehouse* warehouse) {
    warehouse->list();
    return os;
}

/** 
 * @param isbn the ISBN number to search for 
 * @return pointer to the Book object, if found. Otherwise, return NULL 
 */
Book* Warehouse::find(string isbn) const {
    Book* bookHead = this->head;

    while (bookHead != nullptr) {
        if (bookHead->getIsbn() == isbn) return bookHead;
        bookHead = bookHead->getNext();
    }
    
    // book not found
    return nullptr;
}

/** 
 * Prints the inventory of the Warehouse (i.e. list all the books)
 */ 
void Warehouse::list() const {
    Book* bookHead = this->head;

    while (bookHead != nullptr) {
        cout << bookHead << endl;
        bookHead = bookHead->getNext();
    }
}

/** 
 * Sort books by ISBN
 * Used: merge sort
 */
void Warehouse::sort_() {
    Book* newHead = mergeSort_(this->head);
    this->head = newHead;
}

// Extra methods
// Sorting methods
Book* mergeSort_(Book* head) {
    if (head == nullptr || head->getNext() == nullptr) return head;

    Book* middle = getMiddle_(head);
    Book* nextMiddle = middle->getNext();
    middle->setNext(nullptr);

    Book* left = mergeSort_(head);
    Book* right = mergeSort_(nextMiddle);

    return merge_(left, right);
}

Book* merge_(Book* left, Book* right) {
    Book* dummy = new Book();
    Book* current = dummy;

    while (left != nullptr && right != nullptr) {
        if (left->getIsbn() < right->getIsbn()) {
            current->setNext(left);
            left = left->getNext();
        }
        else {
            current->setNext(right);
            right = right->getNext();
        }
        current = current->getNext();
    }

    if (left != nullptr) current->setNext(left);
    else current->setNext(right);

    Book* result = dummy->getNext();
    delete dummy;
    return result;
}


Book* getMiddle_(Book* head) {
    if (head == nullptr || head->getNext() == nullptr) return head;

    Book* slow = head;
    Book* fast = head->getNext();

    while (fast != nullptr && fast->getNext() != nullptr) {
        slow = slow->getNext();
        fast = fast->getNext()->getNext();
    }

    return slow;
}