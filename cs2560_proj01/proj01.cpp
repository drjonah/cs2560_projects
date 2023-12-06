
// File: book.h
// Author: Jonah Lysne
// Date: Oct 18, 2023 (due)
// Description: Main file to read / search books.

#include "book.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void display_book(Book book); // display book function definition

int main(int argc, char *argv[]) {
    if (argc <= 1 || argc > 4) {
        // invalid parameter input 
        cerr << "Invalid program parameters:" << endl;
        cout << "    ./proj01 <input file> list" << endl;
        cout << "    ./proj01 <input file> find <id>" << endl;
        return -1;
    }

    string filename = argv[1], command = argv[2], id; // format input
    Book books[MAX_BOOKS]; // book objects
    int book_count = 0, book_index; // number of books

    // ./proj01 <input file> list
    if (argc == 3 && command == "list") {
        book_count = read(filename, books);
        if (book_count == -1) return -1;

        for (int index = 0; index < book_count; index++)
            display_book(books[index]);
    }

    // ./proj01 <input file> find <id>
    else if (argc == 4 && command == "find") {
        id = argv[3];

        book_count = read(filename, books);
        if (book_count == -1) return -1;
        
        book_index = find(id, books, book_count);
        if (book_index != -1) {
            cout << "\nISBN: " << id << " -- FOUND" << endl;
            display_book(books[book_index]);
        }
        else {
            cerr << "\nISBN: " << argv[3] << " -- NOT FOUND" << endl;
            return -1;
        }
    }
    else {
        cerr << "Error: invalid command" << endl;
        return -1;
    }

    return 0;
}

/**
 * Displays a book object to the user.
 * 
 * @param book Book objects.
 * @return Void.
 */
void display_book(Book book) {
    cout << "Title: " << book.title << endl;
    
    for (int index = 0; index < book.authorCount; index++)
        cout << "Author: " << book.authors[index] << endl;
    
    cout << "Publisher: " << book.publisher << endl;
    cout << "Year: " << book.yearPublish << endl;

    (book.hardcover) ? cout << "Cover: " << "Hardcover" << endl : cout << "Cover: " << "Paperback" << endl;

    cout << "Price: $" << fixed << setprecision(2) << book.price << endl;
    cout << "ISBN: " << book.isbn << endl;
    cout << "Copies: " << book.copies << "\n" << endl;
}