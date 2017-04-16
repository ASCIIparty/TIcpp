#include <cstdio>
#include <string>

#include "tlocation.h"


TLocation::TLocation()
{
	section = "Büro";
	rack = "Fach zum Einsortieren";
}

TLocation::TLocation(std::string s, std::string r)
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

