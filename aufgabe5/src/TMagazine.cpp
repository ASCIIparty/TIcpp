#include "TMagazine.h"

TMagazine::TMagazine(string t, string s, TLocation l, int f, status stat, int Pages, string Designer) : TPrintedMedium(t, s, l, f, stat, Pages)
{
    this->Designer = Designer;
}

TMagazine::~TMagazine()
{
    //dtor
}
