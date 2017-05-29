#include "TEmployee.h"

TEmployee::TEmployee(string name, TAddress address, TDate birthday, int CustomerNr, int EmployeeNr, vector<TLoan*> LoanList)
            : TPerson(name, address, birthday), TCustomer(CustomerNr, LoanList)
{
    this->EmployeeNr = EmployeeNr;
}

TEmployee::~TEmployee()
{
    //dtor
}
