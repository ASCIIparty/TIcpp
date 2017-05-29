#include "TDVD.h"

TDVD::TDVD(string titel , string signatur, TLocation location, int FSK, status stat, string Actor, TTime PlayingTime) : TMedium(titel,  signatur,  location,  FSK,  stat)
{
    this->Actor = Actor;
    this->PlayingTime = PlayingTime;
}

TDVD::~TDVD()
{
    //dtor
}
