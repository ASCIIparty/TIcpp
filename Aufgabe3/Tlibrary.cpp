#include "TLibrary.h"

TLibrary::TLibrary(string n, TAddress a, TPerson *m, vector<TMedium> *mL)
{
    name = n;
    address = a;
    manager = m;
    mediumList = mL;
}

string TLibrary::getName()
{   return name;    }

vector<TMedium> TLibrary::getMediumList()
{   return *mediumList;  }

void TLibrary::add(TMedium medium)
{   getMediumList().push_back(medium); }

TLibrary::~TLibrary()
{   printf("TLibrary object %s deleted", name.c_str()); }
