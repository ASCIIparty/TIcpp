#include "TLoan.h"

TLoan::TLoan( TMedium *Medium, TPerson *Customer, TDate LoanDate, TDate Expiration)
{
    this->Medium=Medium;
    this->Customer=Customer;
    this->LoanDate=LoanDate;
    this->Expiration=Expiration;
}
TLoan::~TLoan() {}

TPerson *TLoan::get_customer(){
    return this->Customer;
}
TDate TLoan::get_LoanDate()
{
  return this->LoanDate;

}
 TDate TLoan::get_Expiration()
 {
   return this->Expiration;
 }
void TLoan::set_Expiration(TDate Expiration)
{
    this->Expiration=Expiration;
}
