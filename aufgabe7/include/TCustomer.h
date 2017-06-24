#ifndef TCUSTOMER_H
#define TCUSTOMER_H
#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>
#include "TPerson.h"
#include "TLoan.h"

class TLoan;

using namespace std;

class TCustomer : virtual public TPerson
{  protected:
        string CustomerNr;
        vector <TLoan*> LoanList;

    public:
      //TCustomer(string name, TAddress address, TDate birthday, string CustomerNr, vector<TLoan *> LoanList);
       //TCustomer(string CustomerNr, vector<TLoan *> LoanList);
        TCustomer();
        virtual ~TCustomer();
        string parseLine(string line, pos *position);
        void load( ifstream &file);
        void print();
        string getCustomerNr();
        void add(TLoan * loan);
        vector <TLoan*> get_LoanList();
};
#endif //TLOAH_H
