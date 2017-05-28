#include "TCD.h"

TCD::TCD(string t, string s, TLocation l, int f, status stat, int Tracks, string Artist) :  TMedium( t,  s,  l,  f,  stat)
{
    this->Tracks = Tracks;
    this -> Artist = Artist;
}

TCD::~TCD()
{
    //dtor
}
