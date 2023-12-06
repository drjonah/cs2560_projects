
#ifndef BOOK_H 
#define BOOK_H

#include <iostream>
#include <string> 
using namespace std;

class Book {
    
    /** 
     * @param is the input stream 
     * @param book the book object to be filled 
     * @return the input stream 
     */
    friend istream& operator >> (istream& is, Book* book);

    /** 
     * @param os the output stream
     * @param book the book object reference 
     * @return the output stream 
     */
    friend ostream& operator << (ostream& os, const Book* book);

    public:
        static const int MAX_AUTHORS = 35;

        Book();

        Book(string title, string authors[], int authorCount, string publisher, short yearPublish, bool hardcover, float price, string isbn, long copies);

        void setTitle(string title); string getTitle() const;
        void setAuthor(string author, int position); void setAuthors(string authors[]); const string* getAuthors() const;
        void setAuthorCount(int authorCount); int getAuthorCount() const;
        void setPublisher(string publisher); string getPublisher() const;
        void setYearPublished(short yearPublish); short getYearPublished() const;
        void setHardcover(bool hardcover); bool getHardcover() const;
        void setPrice(float price); float getPrice() const;
        void setIsbn(string isbn); string getIsbn() const;
        void setCopies(long copies); long getCopies() const;

        void setNext(Book* next); Book* getNext() const;

    private:
        string title; 
        string authors[Book::MAX_AUTHORS]; 
        int authorCount;
        string publisher;
        short yearPublished;
        bool hardcover;
        float price;
        string isbn;
        long copies;

        Book* next;
};

#endif /* BOOK_H */