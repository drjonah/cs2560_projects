
#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

class Warehouse {

    /** 
     * @param is the input stream 
     * @param warehouse the warehouse object reference 
     * @return the input stream 
     */
    friend istream& operator >> (istream& is, Warehouse& warehouse);

    /**
     * @param os the output stream 
     * @param warehouse the warehouse object reference 
     * @return the output stream 
     */ 
    friend ostream& operator << (ostream& os, const Warehouse& warehouse);

    public:
        static const int MAX_BOOKS = 35;

        Warehouse();

        /**
         * @param isbn the ISBN number to search for 
         * @param book reference to the matched book object, if found 
         * @return true if found.
         */ 
        bool find (string isbn, Book& book) const;

        /** 
         * Prints the inventory of the Warehouse (i.e. list all the books)
         */ 
        void list () const;

    private: /* extra credit */ 
        void sort_();

    private:
        Book books[Warehouse::MAX_BOOKS];
        int bookCount;
};

#endif /* WAREHOUSE_H */