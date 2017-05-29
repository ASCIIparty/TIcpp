#include "TBook.h"

TBook::TBook(string title, string signature, TLocation location, int FSK, status stat, int Pages, string author)
        : TPrintedMedium( title, signature, location, FSK, stat, author, Pages)
{
    this->author = author;
}

TBook::TBook(string author)
{
    this->author = author;
}

TBook::~TBook()
{
    //dtor
}
