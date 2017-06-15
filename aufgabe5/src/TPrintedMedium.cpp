#include "TPrintedMedium.h"
#include <fstream>
#include <cstdlib>

TPrintedMedium::TPrintedMedium(string title, string signature, TLocation location, int FSK, status stat, string author, int Pages)
                : TMedium(title,  signatur,  location,  FSK,  stat)
{
    this->Pages = Pages;
}

TPrintedMedium::TPrintedMedium(int Pages)
{
    this->Pages = Pages;
}

int TPrintedMedium::getPages()
{
    return Pages;
}

TPrintedMedium::TPrintedMedium()
{
    //ctor
}

TPrintedMedium::~TPrintedMedium()
{
    printf("Das PrintedMedium %s wurde geloescht.\n", getTitle().c_str());
}
