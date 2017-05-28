#include "TBook.h"

TBook::TBook(string t, string s, TLocation l, int f, status stat, int Pages, string author) : TPrintedMedium(t, s, l, f, stat, Pages)
{
    this->author = author;
}

TBook::~TBook()
{
    //dtor
}
