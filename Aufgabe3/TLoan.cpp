
TLoan::TLoan( TMedium * Medium,TPerson * Customer,TDate LoanDate,TDate Expiration)
{
    this->Medium=Medium;
    this->Customer=Customer;
    this->LoanDate=LoanDate;
    this->Expiration=Expiration;
}
TLoan::~TLoan()
{
    cout<<"deletes"<<endl;
}
TPerson * TLoan::get_customer(){
    return this->TPerson;
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

