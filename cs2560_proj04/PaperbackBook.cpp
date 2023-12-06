#include <iostream>
#include "PaperbackBook.h"
using namespace std;

PaperbackBook::PaperbackBook() : Book() { }

PaperbackBook::~PaperbackBook() { }

string PaperbackBook::getCoverType() const { return "Paperback"; }