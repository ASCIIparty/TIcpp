#ifndef TCUSTOMER_H
#define TCUSTOMER_H

#include <TPerson.h>
#include "TLoan.h"


class TCustomer : virtual public TPerson
{
        int CustomerNr;
        vector<TLoan*> LoanList;
    public:
        TCustomer(string name, TAddress address, TDate birthday, int CustomerNr, vector<TLoan*> LoanList);
        TCustomer(int CustomerNr, vector<TLoan*> LoanList);
        virtual ~TCustomer();

};

#endif // TCUSTOMER_H
