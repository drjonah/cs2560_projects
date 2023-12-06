#ifndef BOOK_H 
#define BOOK_H

#include <iostream>
#include <string> 
using namespace std;

class Book {
    
    /** 
     * @param os the output stream
     * @param book the book object reference 
     * @return the output stream 
     */
    friend ostream& operator << (ostream& os, const Book* book);

    /** 
     * @param book1 book 1 to compare
     * @param book2 book 2 to compare
     * @return boolean if the book's ISBN are equal
     */
    friend bool operator == (const Book& book1, const Book& book2);

    public:
        static const int MAX_AUTHORS = 35;

        Book();
        Book(string title, string authors[], int authorCount, string publisher, short yearPublish, bool hardcover, float price, string isbn, long copies);
        virtual ~Book();

        void setTitle(string title); string getTitle() const;
        void setAuthor(string author, int position); void setAuthors(string authors[]); const string* getAuthors() const;
        void setAuthorCount(short authorCount); short getAuthorCount() const;
        void setPublisher(string publisher); string getPublisher() const;
        void setYearPublished(short yearPublish); short getYearPublished() const;
        void setHardcover(bool hardcover); bool getHardcover() const;
        void setPrice(float price); float getPrice() const;
        void setIsbn(string isbn); string getIsbn() const;
        void setCopies(long copies); long getCopies() const;
    
    protected:
        virtual string getCoverType() const = 0; // pure virtual

    private:
        string title; 
        string authors[Book::MAX_AUTHORS]; 
        short authorCount;
        string publisher;
        short yearPublished;
        bool hardcover;
        float price;
        string isbn;
        long copies;
};

#endif /* BOOK_H */