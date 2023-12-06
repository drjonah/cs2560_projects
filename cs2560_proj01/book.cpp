
// File: book.cpp
// Author: Jonah Lysne
// Date: Oct 18, 2023 (due)
// Description: This file handles books read from file.

#include "book.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * Reads file and stores data in Book object.
 *
 * @param filename Path to file to read.
 * @param books List of Book objects.
 * @return Total number of books read and stored.
 */
int read(string filename, Book books[]) {
    ifstream file;
    file.open(filename); // open file

    if (!file.is_open()) {
        cerr << "Error: file does not exist or cannot open file." << endl;
        return -1;
    }

    int book_count = 0, line_count = 1;
    short author_count;
    string check_line, line;

    while (file >> check_line) {
        // checks to see if book bound is met
        if (book_count >= MAX_BOOKS) {
            cerr << "Max books reached, returning first 35!" << endl;
            break;
        }

        Book& book = books[book_count]; // fetches book object

        // title
        getline(file, line);
        book.title = check_line + line;

        // author count
        getline(file, line);
        // check to see if it can be converted
        if (!isdigit(line[0])) {
            cerr << "Error: author count corrupted file. (" << line_count << ")" << endl;
            return -1;
        }
        author_count = (short) stoi(line);

        // authors
        for(int index = 0; index < author_count; index++) {
            getline(file, line);
            book.authors[index] = line;
        }
        book.authorCount = author_count;

        // publisher
        getline(file, line);
        book.publisher = line;

        // year published
        getline(file, line);
        // check to see if it can be converted
        if (!isdigit(line[0])) {
            cerr << "Error: year corrupted file. (" << line_count << ")" << endl;
            return -1;
        }
        book.yearPublish = (short) stoi(line);

        // hardcover or softcover
        getline(file, line);
        // check to see if it can be converted
        if (!isdigit(line[0])) {
            cerr << "Error: cover corrupted file. (" << line_count << ")" << endl;
            return -1;
        }
        (line == "0" || line == "1") ? book.hardcover = (line == "1") : book.hardcover = false;

        // price
        getline(file, line);
        // check to see if it can be converted
        if (!isdigit(line[0])) {
            cerr << "Error: price corrupted file. (" << line_count << ")" << endl;
            return -1;
        }
        book.price = stof(line);

        // ISBN
        getline(file, line);
        book.isbn = line;

        // copies
        getline(file, line);
        // check to see if it can be converted
        if (!isdigit(line[0])) {
            cerr << "Error: copies corrupted file. (" << line_count << ")" << endl;
            return -1;
        }
        book.copies = stol(line);

        ++book_count;
    }

    file.close(); // close file

    return book_count;
}

/**
 * Iterates through books to find a book by its id (ISBN).
 *
 * @param id Target id (IDBN) of book.
 * @param books List of Book objects.
 * @param length Number of books in books object.
 * @return Index where book is found.
 */
int find(string id, Book books[], int length) {
    for (int index = 0; index < length; index++)
        if (books[index].isbn == id) return index;
    return -1;
}
