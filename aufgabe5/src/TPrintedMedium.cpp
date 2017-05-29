#include "TPrintedMedium.h"

TPrintedMedium::TPrintedMedium(string title, string signature, TLocation location, int FSK, status stat, string author, int Pages)
                : TMedium(title,  signatur,  location,  FSK,  stat)
{
    this->Pages = Pages;
}

TPrintedMedium::TPrintedMedium(int Pages)
{
    this->Pages = Pages;
}

TPrintedMedium::TPrintedMedium()
{

}

TPrintedMedium::~TPrintedMedium()
{
    //dtor
}
