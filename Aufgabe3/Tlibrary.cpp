#include "TLibrary.h"

TLibrary::TLibrary(string n, TAddress a, TPerson *m)
{
    name = n;
    address = a;
    manager = m;
    mediumList = new vector<TMedium>;

}

string TLibrary::getName()
{   return name;    }

vector<TMedium>  * TLibrary::getMediumList()
{   return this->mediumList;  }

void TLibrary::add(TMedium * medium)
{ (*this->mediumList).push_back(*medium); }
void TLibrary::print()
{
    cout<<endl;
    cout<<"Buecherei Filiale "<<name<<endl;
    address.print();
    printf("FilialLeiter: ");
    manager->print();
    printf("Es stehen %d Medien zur Verfuegung:\n\n",(*this->mediumList).size());
    for(int i = 0;i<(*this->mediumList).size();i++){
        printf("\n");
        printf("Medium Nr. %d\n",i+1);
        (mediumList->at(i)).print();
         printf("\n");
    }
}
TLibrary::~TLibrary()
{   printf("TLibrary object %s deleted", name.c_str()); }

