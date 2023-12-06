#ifndef PAPERBACKBOOK_H 
#define PAPERBACKBOOK_H 

#include "Book.h"

class PaperbackBook : public Book {

    public:
        PaperbackBook();
        virtual ~PaperbackBook();

    protected:
        virtual string getCoverType() const;

};

#endif