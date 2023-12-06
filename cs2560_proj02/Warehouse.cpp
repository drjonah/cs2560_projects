
#include <iostream>
#include <string>
#include "Warehouse.h"
#include "Book.h"
using namespace std;

Warehouse::Warehouse() : bookCount(0) { }

/** 
 * @param is the input stream 
 * @param warehouse the warehouse object reference 
 * @return the input stream 
 */
istream& operator >> (istream& is, Warehouse& warehouse) {
    if (warehouse.bookCount >= warehouse.MAX_BOOKS) {
        cerr << "Too many books!" << endl;
        is.setstate(ios::failbit);
        return is;
    }

    Book book; // temp book object
    // is >> book; // reads book object

    if (!(is >> book)) {
        cerr << "Error: corrupted book caught." << endl;
        is.setstate(ios::failbit);
        return is;
    }

    warehouse.books[warehouse.bookCount] = book; // adds book object
    ++warehouse.bookCount; // increments total

    warehouse.sort_();

    return is;
}

/**
 * @param os the output stream 
 * @param warehouse the warehouse object reference 
 * @return the output stream 
 */ 
ostream& operator << (ostream& os, const Warehouse& warehouse) {
    warehouse.list();
    return os;
}

// /**
//  * @param isbn the ISBN number to search for 
//  * @param book reference to the matched book object, if found 
//  * @return true if found.
//  */ 
bool Warehouse::find(string isbn, Book& book) const {
    for (int index = 0; index < this->bookCount; index++) {
        if (this->books[index].getIsbn() == isbn) {
            book = books[index];
            return true;
        }
    }
    return false;
}

/** 
 * Prints the inventory of the Warehouse (i.e. list all the books)
 */ 
void Warehouse::list() const {
    for (int index = 0; index < this->bookCount; index++) cout << this->books[index] << endl;
}

/** 
 * Sort books by author last name
 * Used: selection sort
 * 
 * Errors with sorting indicate extra space @ end of last name
 */ 
void Warehouse::sort_() {
    for (int index = 0; index < this->bookCount - 1; ++index) {
        int minIndex = index;

        for (int temp_index = index + 1; temp_index < this->bookCount; ++temp_index) {
            string curr = this->books[temp_index].getAuthors()[0];
            curr = curr.substr(curr.find_last_of(' '));

            string comp = this->books[minIndex].getAuthors()[0];
            comp = comp.substr(comp.find_last_of(' '));

            if (curr.compare(comp) < 0) {
                minIndex = temp_index;
            }
        }

        // Swap the books in the books array
        if (minIndex != index) {
            Book temp = this->books[index];
            this->books[index] = this->books[minIndex];
            this->books[minIndex] = temp;
        }
    }
}