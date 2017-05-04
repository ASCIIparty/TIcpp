#include <iostream>
#include<vector>
#include "TLibraryPool.h"
using namespace std;

TLibraryPool::TLibraryPool(string Name, TPerson * Chairman)
{   //vector<TLibrary > List;
  //LibraryList=List;
    this->Chairman=Chairman;
    this->Name=Name;
    LibraryList = new vector<TLibrary >;
    Customers=new vector<TPerson >;

}
TLibraryPool:: TLibraryPool( vector<TLibrary > *LibraryList, vector<TPerson> * Customers, vector<TLoan> * LoanList)
{

    this->LibraryList= LibraryList;
    this->Customers=Customers;
    this->LoanList=LoanList;
}
TLibraryPool::~TLibraryPool()
{
    cout<<"deleting"<<endl;
}
void TLibraryPool::add(TPerson * Customer)
{
    (*this->Customers).push_back(*Customer);
}

void TLibraryPool::add(TLibrary * Library)
{
    (*this->LibraryList).push_back((*Library));
}
TPerson *  TLibraryPool::get_Chairman()
{
    return this->Chairman;

}
void  TLibraryPool::set_Chairman(TPerson Chairman)
{
    *(this->Chairman)=Chairman;

}
vector<TPerson> *  TLibraryPool::get_Customers()
{
    return this->Customers;
}
/*vector <TLibrary > *  TLibraryPool::LibraryList get_LibraryList()
{
    return this->LibraryList;
}*/
void TLibraryPool::print(){
   cout<<"\n"<<this->Name<<endl;
    cout<<"Leitung "<<this->Chairman->getName()<<endl;
    this->Chairman->getAddress().print();
    printf("Zum Buechereiverband gehoeren %d Filialen:\n", (*this->LibraryList).size() );
    for ( int i=0;i<(*this->LibraryList).size();i++ ){
        printf("\n");
        (LibraryList->at(i)).print();


    }
    printf("\nDer Buechereiverband hat %d Kunden:\n",(*this->Customers).size());
     for ( int i=0;i<(*this->Customers).size();i++ ){
        printf("\n");
        (Customers->at(i)).print();


    }

}
