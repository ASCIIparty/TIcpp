#ifndef TLOAN_H
#define TLOAN_H

#include "TPerson.h"
#include "TMedium.h"
#include "TCustomer.h"
#include "tdate.h"

class TCustomer;
using namespace std;

class TLoan{
private:
    TMedium * Medium;
    // * customer;
    TCustomer * Customer;
    string Signatur;
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
    void set_Customer(TCustomer* customer);
    string get_signatur();
    void set_Medium(TMedium * medium);
    void print();
};
#endif // TLOAN_H
