#include "TAudiobook.h"
#include "TBook.h"
#include "TDVD.h"
#include "ttime.h"

TAudiobook::TAudiobook(string t, string s, TLocation l, int f, status stat, int Pages, string author,
                    string Actor, TTime Playtime, int countCDs) : TBook(t, s, l, f, stat, Pages, author), TDVD(Actor, Playtime)
{
    this->countCDs = countCDs;
}

TAudiobook::~TAudiobook()
{
    //dtor
}
