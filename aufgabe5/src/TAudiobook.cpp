#include "TAudiobook.h"
#include "TBook.h"
#include "TDVD.h"
#include "ttime.h"


TAudiobook::TAudiobook(string title, string signature, TLocation location, int FSK, status stat, int Pages, string author, string Actors, TTime PlayingTime, int countCDs)
            : TBook(title, signature, location, FSK, stat, Pages, author), TDVD(titel , signatur, location, FSK, stat, Actor, PlayingTime)
{
    this->countCDs = countCDs;
}

TAudiobook::~TAudiobook()
{
    //dtor
}
