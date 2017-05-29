#ifndef TEMPLOYEE_H
#define TEMPLOYEE_H

#include <TPerson.h>
#include <TCustomer.h>


class TEmployee : virtual public TPerson, virtual public TCustomer
{
    public:
        TEmployee(string name, TAddress address, TDate birthday, int CustomerNr, int EmployeeNr, vector<TLoan*> LoanList);
        virtual ~TEmployee();

    private:
        int EmployeeNr;
};

#endif // TEMPLOYEE_H
