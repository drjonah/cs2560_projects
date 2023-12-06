#include <iostream>
#include <string> 
#include <iomanip>
#include "Book.h"
using namespace std;

// Constructor
Book::Book() : Book("", nullptr, 0, "", 0, false, 0.0, "", 0) { }

Book::Book(string title, string authors[], int authorCount, string publisher, short yearPublish, bool hardcover, float price, string isbn, long copies) {
    this->setTitle(title);
    
    this->setAuthorCount(authorCount);
    this->setAuthors(authors); // second to fill authors count first

    this->setPublisher(publisher);
    this->setYearPublished(yearPublish);

    this->setPrice(price);
    this->setIsbn(isbn);
    this->setCopies(copies);
}

Book::~Book() { }

/** 
 * @param os the output stream
 * @param book the book object reference 
 * @return the output stream 
 */
ostream& operator << (ostream& os, const Book* book) {

    os << "Title: " << book->getTitle() << endl;

    string authors = *book->getAuthors();
    for (int index = 0; index < book->getAuthorCount(); index++)
        os << "Author: " << book->getAuthors()[index] << endl;
    
    os << "Publisher: " << book->getPublisher() << endl;
    os << "Year: " << book->getYearPublished() << endl;

    os << "Cover: " << book->getCoverType() << endl;

    os << "Price: $" << fixed << setprecision(2) << book->getPrice() << endl;
    os << "ISBN: " << book->getIsbn() << endl;
    os << "Copies: " << book->getCopies() << endl;

    return os;
}

/** 
 * @param book1 book 1 to compare
 * @param book2 book 2 to compare
 * @return boolean if the book's ISBN are equal
 */
bool operator == (const Book& book1, const Book& book2) {
    if (book1.getIsbn().compare(book2.getIsbn()) == 0)
        return true;

    return false;
}

// getter and setter methods
void Book::setTitle(string title) { this->title=title; }
string Book::getTitle() const { return this->title; }

void Book::setAuthor(string author, int position) { this->authors[position] = author; }
void Book::setAuthors(string authors[]) { for (int i = 0; i < getAuthorCount(); i++) this->authors[i] = authors[i]; }
const string* Book::getAuthors() const { return this->authors; }

void Book::setAuthorCount(short authorCount) { this->authorCount=authorCount; }
short Book::getAuthorCount() const { return this->authorCount; }

void Book::setPublisher(string publisher) { this->publisher=publisher; }
string Book::getPublisher() const { return this->publisher; }

void Book::setYearPublished(short yearPublish) { this->yearPublished=yearPublish; }
short Book::getYearPublished() const { return this->yearPublished; }

void Book::setHardcover(bool hardcover) { this->hardcover=hardcover; }
bool Book::getHardcover() const { return this->hardcover; }

void Book::setPrice(float price) { this->price=price; }
float Book::getPrice() const { return this->price; }

void Book::setIsbn(string isbn) { this->isbn=isbn; }
string Book::getIsbn() const { return this->isbn; }

void Book::setCopies(long copies) { this->copies=copies; }
long Book::getCopies() const { return this->copies; }