
#pragma once
#include <cstdlib>
#include <vector>
//#include "TLoan.h"


using namespace std;


class TCustomer : virtual public TPerson
{  protected:
        string CustomerNr;
      //TLoan* LoanList;

    public:
      //TCustomer(string name, TAddress address, TDate birthday, string CustomerNr, vector<TLoan *> LoanList);
       //TCustomer(string CustomerNr, vector<TLoan *> LoanList);
        TCustomer();
        virtual ~TCustomer();
        string parseLine(string line, pos *position);
        void load( ifstream &file);
        void print();
        string getCustomerNr();
        //void add(TLoan * loan);
};
