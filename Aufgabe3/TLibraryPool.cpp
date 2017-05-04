#include <iostream>
#include<vector>
#include "TLibraryPool.h"
using namespace std;

TLibraryPool::TLibraryPool(string Name, TPerson * Chairman)
{   //vector<TLibrary > List;
  //LibraryList=List;
    this->Chairman=Chairman;
    this->Name=Name;


}

TLibraryPool::~TLibraryPool()
{
    cout<<"deleting"<<endl;
}
void TLibraryPool::add(TPerson * Customer)
{
    Customers.push_back(Customer);
}

void TLibraryPool::add(TLibrary * Library)
{
    LibraryList.push_back((Library));
}
TPerson *  TLibraryPool::get_Chairman()
{
    return this->Chairman;

}
void  TLibraryPool::set_Chairman(TPerson Chairman)
{
    *(this->Chairman)=Chairman;

}
vector<TPerson*>  TLibraryPool::get_Customers()
{
    return Customers;
}
/*vector <TLibrary > *  TLibraryPool::LibraryList get_LibraryList()
{
    return this->LibraryList;
}*/
void TLibraryPool::print(){
   cout<<"\n"<<this->Name<<endl;
    cout<<"Leitung "<<this->Chairman->getName()<<endl;
    this->Chairman->getAddress().print();
    printf("Zum Buechereiverband gehoeren %d Filialen:\n", LibraryList.size() );
    for ( int i=0;i<LibraryList.size();i++ ){
        printf("\n");
        LibraryList.at(i)->print();


    }
    printf("\nDer Buechereiverband hat %d Kunden:\n",Customers.size());
     for ( int i=0;i<Customers.size();i++ ){
        printf("\n");
        (Customers.at(i))->print();


    }

}
