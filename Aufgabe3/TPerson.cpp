#include "TPerson.h"
#include "../aufgabe1/tdate.h"
#include "../aufgabe2/taddress.h"
#include <string>

using namespace std;

TPerson::TPerson(string n , TAddress a, TDate b)
{
    name = n;
    address = a;
    birthday = b;
}

void TPerson::print()
{
    printf("%s\n", getName().c_str());
    address.print();
    printf("* ");
    birthday.print();
}
string TPerson::getName()
{
    return name;
}

TAddress TPerson::getAddress()
{
   return this->address;
}

TDate TPerson::getBirthday()
{
    return birthday;
}

void TPerson::setName(string n)
{
    name = n;
}

void TPerson::setAddress(TAddress a)
{
    address = a;
}

void TPerson::setBirthday(TDate b)
{
    birthday = b;
}
