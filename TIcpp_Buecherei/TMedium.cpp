#include "TMedium.h"

TMedium::TMedium(string t, string s, TLocation l, int f)
{
    titel = t;
    signatur = s;
    location = l;
    FSK = f;
};

string TMedium::getStatus() //soll den Status im Klartext – also als String zurückgeben
{   return statusNames[status]; }

void TMedium::print()
{
    printf("%s\n", getTitle().c_str());
    printf("%s\n", getSignature().c_str());
    location.print();
    printf("freigegeben ab %d Jahren\n", getFSK());
};

int TMedium::getFSK()
{   return FSK; };

string TMedium::getSignature()
{   return signatur; }

string TMedium::getTitle()
{   return titel; };

TMedium::~TMedium()
{ printf("TMedium object %s - %s deleted\n", titel.c_str(), signatur.c_str()); };