
#include <iostream>
#include <string> 
#include <iomanip>
#include "Book.h"
using namespace std;

// Extra headers
void logError(string type, string line);

// Constructor
Book::Book() : Book("", nullptr, 0, "", 0, false, 0.0, "", 0) { }

Book::Book(string title, string authors[], int authorCount, string publisher, short yearPublish, bool hardcover, float price, string isbn, long copies) {
    this->setTitle(title);
    
    this->setAuthorCount(authorCount);
    this->setAuthors(authors); // second to fill authors count first

    this->setPublisher(publisher);
    this->setYearPublished(yearPublish);
    this->setHardcover(hardcover);
    this->setPrice(price);
    this->setIsbn(isbn);
    this->setCopies(copies);

    this->setNext(nullptr);
}

/** 
 * @param is the input stream 
 * @param book the book object to be filled 
 * @return the input stream 
 */
istream& operator >> (istream& is, Book* book) {
    
    string line;
    // title
    getline(is, line); book->setTitle(line);
    // author count
    getline(is, line);
    if (!isdigit(line[0])) {
        logError("author count", line);
        is.setstate(ios::failbit);
        return is;
    }
    book->setAuthorCount((short) stoi(line));
    // authors
    for (int index = 0; index < book->getAuthorCount(); ++index) {
        getline(is, line);  book->setAuthor(line, index); 
    }
    // publisher
    getline(is, line); book->setPublisher(line);
    // year published
    getline(is, line);
    if (!isdigit(line[0])) {
        logError("year", line);
        is.setstate(ios::failbit);
        return is;
    }
    book->setYearPublished((short) stoi(line));
    // cover type
    getline(is, line); 
    if (!isdigit(line[0])) {
        logError("cover", line);
        is.setstate(ios::failbit);
        return is;
    }
    (line == "0" || line == "1") ? book->setHardcover(line == "1") : book->setHardcover(false);
    // price
    getline(is, line);
    if (!isdigit(line[0])) {
        logError("price", line);
        is.setstate(ios::failbit);
        return is;
    }
    book->setPrice(stof(line));
    // isbn
    getline(is, line); book->setIsbn(line);
    // copies
    getline(is, line);
    if (!isdigit(line[0])) {
        logError("copies", line);
        is.setstate(ios::failbit);
        return is;
    }
    book->setCopies(stol(line));

    return is;
}

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

    (book->getHardcover()) ? os << "Cover: Hardcover" << endl : os << "Cover: Paperback" << endl;

    os << "Price: $" << fixed << setprecision(2) << book->getPrice() << endl;
    os << "ISBN: " << book->getIsbn() << endl;
    os << "Copies: " << book->getCopies() << endl;

    return os;
}

void Book::setTitle(string title) { this->title=title; }
string Book::getTitle() const { return this->title; }

void Book::setAuthor(string author, int position) { this->authors[position] = author; }
void Book::setAuthors(string authors[]) { for (int i = 0; i < getAuthorCount(); i++) this->authors[i] = authors[i]; }
const string* Book::getAuthors() const { return this->authors; }

void Book::setAuthorCount(int authorCount) { this->authorCount=authorCount; }
int Book::getAuthorCount() const { return this->authorCount; }

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

void Book::setNext(Book* next) { this->next=next; }
Book* Book::getNext() const { return this->next; }

// Extra methods
void logError(string type, string line) {
    if (line.length() == 0)
        cerr << "Error: " << type << " corrupted file. [content=BLANK FIELD]" << endl;
    else
        cerr << "Error: " << type << " corrupted file. [content=" << line << "]" << endl;
}