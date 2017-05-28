#include "TPrintedMedium.h"

TPrintedMedium::TPrintedMedium(string t, string s, TLocation l, int f, status stat, int Pages) : TMedium( t,  s,  l,  f,  stat)
{
    this->Pages = Pages;
}

TPrintedMedium::~TPrintedMedium()
{
    //dtor
}
