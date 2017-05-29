#include "TMagazine.h"

TMagazine::TMagazine(string title, string signature, TLocation location, int FSK, status stat, string author, int Pages, string Designer)
            : TPrintedMedium(title, signature, location, FSK, stat, author, Pages)
{
    this->Designer = Designer;
}

TMagazine::~TMagazine()
{
    //dtor
}
