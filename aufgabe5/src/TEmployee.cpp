#include "TEmployee.h"

TEmployee::TEmployee(string name, TAddress address, TDate birthday, int CustomerNr, int EmployeeNr) : TPerson(name, address, birthday), TCustomer(CustomerNr)
{
    this->EmployeeNr = EmployeeNr;
}

TEmployee::~TEmployee()
{
    //dtor
}
