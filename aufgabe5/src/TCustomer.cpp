#include "TCustomer.h"

TCustomer::TCustomer(string name, TAddress address, TDate birthday, int CustomerNr, vector<TLoan*> LoanList)
            : TPerson(name, address, birthday)
{
    this->CustomerNr = CustomerNr;
    this->LoanList = LoanList;
}

TCustomer::TCustomer(int CustomerNr, vector<TLoan*> LoanList)
{
    this->CustomerNr = CustomerNr;
    this->LoanList = LoanList;

}

TCustomer::~TCustomer()
{
    //dtor
}
