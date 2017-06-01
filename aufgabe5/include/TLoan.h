#pragma once
#include "TPerson.h"
#include "TMedium.h"
#include "tdate.h"

class TLoan{
    TMedium *Medium;
    TPerson *Customer;
    TDate LoanDate;
    TDate Expiration;
public:
    TLoan( TMedium * Medium, TPerson *Customer,TDate LoanDate,TDate Expiration);
    ~TLoan();
    TPerson *get_customer();
    TDate get_LoanDate();
    TDate get_Expiration();
    void set_Expiration(TDate LoanDate);
    void load( ifstream &file);
};

