
class TLibraryPool  {

private:
    string Name;
    TPerson * Chairman;
    vector<TLibrary > *LibraryList;
    vector<TPerson> * Customers;
    vector<TLoan> * LoanList;
public:
    TLibraryPool(TPerson * Chairman, vector<TLibrary > *LibraryList, vector<TPerson> * Customers, vector<TLoan> * LoanList);
    ~TLibraryPool();
    void add(TPerson  Customer);
    void add(TLibrary  Library);
    TPerson * get_Chairman();
    void set_Chairman(TPerson Chairman);
    vector<TPerson> * get_Customers();
    vector<TLibrary > *LibraryList get_LibraryList();
};
