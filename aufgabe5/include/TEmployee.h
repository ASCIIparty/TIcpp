#ifndef TEMPLOYEE_H
#define TEMPLOYEE_H

#include <TPerson.h>
#include <TCustomer.h>

class TEmployee : virtual public TPerson, public TCustomer
{
        string EmployeeNr;
    public:
        TEmployee(string name, TAddress address, TDate birthday, string CustomerNr, string EmployeeNr, vector<TLoan*> LoanList);
        TEmployee();
        virtual ~TEmployee();
        string parseLine(string line, pos * position);
        void load( ifstream &file);
        string getEmployeeNr();
        void print();

};

#endif // TEMPLOYEE_H
