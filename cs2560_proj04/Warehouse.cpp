#include <iostream>
#include <string>
#include "Book.h"
#include "HardcoverBook.h"
#include "PaperbackBook.h"
#include "Warehouse.h"
using namespace std;

// Constructor & destructor
Warehouse::Warehouse() : books(new LinkedList<Book>) { }

Warehouse::~Warehouse() {
    // delete linked list
    if (this->books != nullptr) {
        delete this->books;
        books = nullptr;
    }
}

/** 
 * @param is the input stream 
 * @param warehouse the warehouse object reference 
 * @return the input stream 
 */
istream& operator>>(istream &is, Warehouse *warehouse) {
    if (warehouse->books->getLength() >= 35) {
        cerr << "Too many books! Max is 35." << endl;
        is.setstate(ios::failbit);
        return is;
    }

    Book* book = warehouse->createBook_(is); // creates book

    if (book == nullptr) {
        cerr << "Error: corrupted book caught." << endl;
        is.setstate(ios::failbit);
        return is;
    }

    // adds book to linked list
    // size increments automatically
    warehouse->books->add(book);

    return is;
}

/**
 * @param os the output stream 
 * @param warehouse the warehouse object reference 
 * @return the output stream 
 */ 
ostream& operator<<(ostream &os, const Warehouse *warehouse) {
    warehouse->list();

    return os;
}

/** 
 * @param isbn the ISBN number to search for 
 * @return pointer to the Book object, if found. Otherwise, return NULL 
 */
Book* Warehouse::find(string isbn) const {
    Book* tempBook = new HardcoverBook();
    tempBook->setIsbn(isbn);

    tempBook = this->books->findNode(tempBook);

    if (tempBook != nullptr)
        return tempBook;
    
    // book not found
    return nullptr;
}

/** 
 * Prints the inventory of the Warehouse (i.e. list all the books)
 */ 
void Warehouse::list() const {
    this->books->display();
}

/**
 *  "Record from the input data stream and creates an instance of 
 *   HardcoverBook or PaperbackBook depending on the data read"
 * 
 *  @param is the input stream
 *  @return newly created book pointer
 */
Book* Warehouse::createBook_(istream& is) {
    // create book
    string line;
    
    string title; 
    string authors[Book::MAX_AUTHORS]; 
    short authorCount;
    string publisher;
    short yearPublished;
    bool hardcover;
    float price;
    string isbn;
    long copies;


    // title
    getline(is, line); title = line;
    // author count
    getline(is, line);
    if (!isdigit(line[0])) {
        cout << "Error: rendering author count." << std::endl;
        is.setstate(ios::failbit);
        return nullptr;
    }
    authorCount = (short) stoi(line);
    // authors
    for (int index = 0; index < authorCount; ++index) {
        getline(is, line);  authors[index] = line; 
    }
    // publisher
    getline(is, line); publisher = line;
    // year published
    getline(is, line);
    if (!isdigit(line[0])) {
        cout << "Error: rendering publisher." << std::endl;
        is.setstate(ios::failbit);
        return nullptr;
    }
    yearPublished = (short) stoi(line);

    // cover type
    getline(is, line); 
    if (!isdigit(line[0])) {
        cout << "Error: rendering cover type." << std::endl;
        is.setstate(ios::failbit);
        return nullptr;
    }
    (line == "0" || line == "1") ? (hardcover = (line == "1")): hardcover = false;

    // price
    getline(is, line);
    if (!isdigit(line[0])) {
        cout << "Error: rendering price." << std::endl;
        is.setstate(ios::failbit);
        return nullptr;
    }
    price = stof(line);
    // isbn
    getline(is, line); isbn = line;
    // copies
    getline(is, line);
    if (!isdigit(line[0])) {
        cout << "Error: rendering copies." << std::endl;
        is.setstate(ios::failbit);
        return nullptr;
    }
    copies = stol(line);

    // create temp book as hardcover
    Book* tempBook;

    if (hardcover) tempBook = new HardcoverBook();
    else tempBook = new PaperbackBook();

    // add to tempBook
    tempBook->setTitle(title);
    tempBook->setAuthorCount(authorCount);
    tempBook->setAuthors(authors);
    tempBook->setPublisher(publisher);
    tempBook->setYearPublished(yearPublished);
    tempBook->setHardcover(hardcover);
    tempBook->setPrice(price);
    tempBook->setIsbn(isbn);
    tempBook->setCopies(copies);
    
    // return book object
    return tempBook;
}