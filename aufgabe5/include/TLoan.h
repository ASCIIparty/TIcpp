#ifndef TLOAN_H
#define TLOAN_H

#include "TPerson.h"
#include "TMedium.h"
#include <TCustomer.h>
#include "tdate.h"


using namespace std;

class TLoan{
protected:
    TMedium * Medium;
    // * customer;
    TPerson * Customer;
 TCustomer * cust;
    string Signaur;
    string CustomerNr;
    TDate LoanDate;

    TDate Expiration;
public:
    typedef struct {
        int startpos;
        int endpos;
      } pos;
    //TLoan( TMedium * Medium, TCustomer * Customer,TDate LoanDate,TDate Expiration);
    ~TLoan();
    TLoan();
    TPerson *get_customer();
    TDate get_LoanDate();
    TDate get_Expiration();
    void set_Expiration(TDate LoanDate);
    void load( ifstream &file);
    string parseLine(string line, pos * position);
    string get_CustomerNr();
    void set_Customer(TPerson* customer);
    void print();
};
#endif // TLOAN_H
