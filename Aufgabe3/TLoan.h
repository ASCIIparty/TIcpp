#include "TMedium.h"
#include "../aufgabe1/tdate.h"
#include "TPerson.h"
class TLoan{

private:
    TMedium * Medium;
    TPerson * Customer;
    TDate LoanDate;
    TDate Expiration;
public:
    TLoan( TMedium * Medium,TPerson * Customer,TDate LoanDate,TDate Expiration);
    ~TLoan();
    TPerson * get_customer();
    TDate get_LoanDate();
    TDate get_Expiration();
    void set_Expiration(TDate LoanDate);

};
