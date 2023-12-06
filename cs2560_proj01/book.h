
// File: book.h
// Author: Professor T. Haung
// Date: Oct 9, 2023 (assigned)
// Description: This file is the headerfile for book.cpp

#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

const int MAX_AUTHORS = 20;
const int MAX_BOOKS = 35;

struct Book {
    string title;
    string authors[MAX_AUTHORS];
    short authorCount;
    string publisher;
    short yearPublish;
    bool hardcover;
    float price;
    string isbn;
    long copies;
};

int read(string filename, Book books[]);

int find(string id, Book books[], int length);

#endif /* BOOK_H */
