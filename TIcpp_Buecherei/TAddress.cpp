#include "TAddress.h"
#include <string>

using namespace std;


TAddress::TAddress()
{

}

TAddress::TAddress(string s, string n, string z, string t)
{
    street = s;
    number = n;
    zipcode = z;
    town = t;
}


void TAddress::print()
{
    printf("%s %s\n", getStreet().c_str(), getNumber().c_str());
    printf("%s %s\n", getZipcode().c_str(), getTown().c_str());
}

string TAddress::getStreet()
{
    return street;
}

string TAddress::getNumber()
{
    return number;
}

string TAddress::getZipcode()
{
    return zipcode;
}

string TAddress::getTown()
{
    return town;
}

void TAddress::setStreet(string s)
{
    street = s;
}

void TAddress::setNumber(string n)
{
    number = n;
}

void TAddress::setZipcode(string z)
{
    zipcode = z;
}

void TAddress::setTown(string t)
{
    town = t;
}

TAddress::~TAddress() {
    // TODO Auto-generated destructor stub
}

