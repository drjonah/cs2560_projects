#include <iostream>
#include "HardcoverBook.h"
using namespace std;

HardcoverBook::HardcoverBook() : Book() { }

HardcoverBook::~HardcoverBook() { }

string HardcoverBook::getCoverType() const { return "Hardcover"; }