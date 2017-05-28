#include "TCustomer.h"

TCustomer::TCustomer(string name, TAddress address, TDate birthday, int CustomerNr) : TPerson(name, address, birthday)
{
    this->CustomerNr = CustomerNr;
}

TCustomer::TCustomer(int CustomerNr)
{
    this->CustomerNr = CustomerNr;
}

TCustomer::~TCustomer()
{
    //dtor
}
