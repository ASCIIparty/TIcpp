#include "TDVD.h"

TDVD::TDVD(string t, string s, TLocation l, int f, status stat, string Actor, TTime Playtime) : TMedium( t,  s,  l,  f,  stat)
{
    this->Actor = Actor;
    this->Playtime = Playtime;
}

TDVD::~TDVD()
{
    //dtor
}
