#include "TLoan.h"
#include "TLibrary.h"
#include "TEmployee.h"
#include "TCustomer.h"

using namespace std;

class TLibraryPool  {
public:
    typedef struct {
        int startpos;
        int endpos;
    } pos;
private:
    string Name;
    TEmployee *Chairman;
    vector<TLibrary *> LibraryList;
    vector<TCustomer *> Customers;
    vector<TLoan *> LoanList;
    string parseLine(string line, pos * position);
public:

    TLibraryPool(string Name, TEmployee *Chairman);
    TLibraryPool(char * filename);
    ~TLibraryPool();
    void add(TCustomer * Customer);
    void add(TLibrary * Library);
    TEmployee *get_Chairman();
    void set_Chairman(TEmployee Chairman);
    vector<TCustomer*>  get_Customers();
    vector<TLibrary*>  get_LibraryList();
    void print();
    void load( ifstream& file);
    TCustomer * findCustomerByID( TLoan * loan);
};
