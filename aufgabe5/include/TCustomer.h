#ifndef TCUSTOMER_H
#define TCUSTOMER_H

#include <vector>
#include "TPerson.h"
#include "TLoan.h"
#include <cstdlib>

using namespace std;


class TCustomer : virtual public TPerson
{
        string CustomerNr;
        vector<TLoan *> LoanList;
    public:
        TCustomer(string name, TAddress address, TDate birthday, string CustomerNr, vector<TLoan *> LoanList);
        TCustomer(string CustomerNr, vector<TLoan *> LoanList);
        TCustomer();
        virtual ~TCustomer();
        string parseLine(string line, pos *position);
        void load( ifstream &file);
        void print();
        string getCustomerNr();
};

#endif // TCUSTOMER_H
