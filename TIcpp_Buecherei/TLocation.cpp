#include <cstdio>
#include <string>

#include "TLocation.h"

using namespace std;


TLocation::TLocation()
{
    section = "Büro";
    rack = "Fach zum Einsortieren";
}

TLocation::TLocation(string s, string r)
{
    section = s;
    rack = r;
}

void TLocation::print()
{
    printf("Abt.: %s; Regal: %s", getSection().c_str(), getRack().c_str());
}

string TLocation::getSection()
{
    return section;
}

string TLocation::getRack()
{
    return rack;
}

TLocation::~TLocation()
{
    // TODO Auto-generated destructor stub
}
