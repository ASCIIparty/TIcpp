
TLibraryPool:: TLibraryPool(TPerson * Chairman, vector<TLibrary > *LibraryList, vector<TPerson> * Customers, vector<TLoan> * LoanList)
{
    this->Chairman=Chairman;
    this->LibraryList= LibraryList;
    this->Customers=Customers;
    this->LoanList=LoanList;
}
TLibraryPool::~TLibraryPool()
{
    cout<<"deleting"<<endl;
}
void TLibraryPool::add(TPerson  Customer)
{
    *(this->Customers).push_back(Customer);
}

void TLibraryPool::add(TLibrary  Library)
{
    *(this->LibraryList).push_back(Library);
}
TPerson *  TLibraryPool::get_Chairman()
{
    return this->Chairman;

}
void  TLibraryPool::set_Chairman(TPerson Chairman)
{
    *(this->chairman)=Chairman;

}
vector<TPerson> *  TLibraryPool::get_Customers()
{
    return this->Customers;
}
vector <TLibrary > *  TLibraryPool::LibraryList get_LibraryList()
{
    return this->LibraryList;
}
