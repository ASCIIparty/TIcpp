#include <iostream>
#include <fstream>
#include<vector>
#include "TLibraryPool.h"
using namespace std;


TLibraryPool::TLibraryPool(string Name, TEmployee *Chairman)
{
    this->Chairman=Chairman;
    this->Name=Name;
}

string TLibraryPool::parseLine(string line, pos *position)
{
    string value;
    position->startpos=line.find("<");
    position->endpos=line.find(">");
    value=line.substr(position->startpos+1,position->endpos-position->startpos-1);
    position->startpos=line.find(value);
    position->endpos=line.find(value,  position->startpos+1);
    return value;
}

TLibraryPool::TLibraryPool(char *filename)
{
    ifstream myfile (filename);
    string line;
    string value;
    pos position;
    string tag;

    if (myfile.is_open())
    {
        cout << "Datei geoeffnet ..." << endl;
        getline (myfile,line);
        tag = parseLine(line, &position);
        while((line.find("</LibraryPool>")==-1)){
            if(!tag.compare("Name"))
            {

                this->Name=line.substr(position.startpos+tag.size()+1,position.endpos-position.startpos-tag.size()-3);
            }
            else if(!tag.compare("Chairman"))
            {
              getline (myfile,line);
              Chairman = new TEmployee();
              Chairman->load(myfile);
              getline (myfile,line);
              //cout <<line<<"CHAIRMAN???"<<endl; // </chairman>
            }
            else if(!tag.compare("Library"))
            {

               //  cout<<tag<<"=Library?"<<endl;

                 TLibrary * library= new TLibrary();
                 library->load(myfile);
                 this->linkedList.push_back(library);
                 //LibraryList.push_back(library);

            }
            else if(!tag.compare("Employee"))
            {
                    getline (myfile,line);
                   TEmployee *person = new TEmployee();
                   person->load(myfile);
                   Customers.push_back(person);
                   getline (myfile,line);
                   //getline (myfile,line);

            }
            else if(!tag.compare("Customer"))
            {
           // getline (myfile,line);

                   TCustomer *person = new TCustomer();
                   person->load(myfile);
                   Customers.push_back(person);
                   //getline (myfile,line);
                   //getline (myfile,line);


            }
            else if(!tag.compare("Loan"))
            {
           // getline (myfile,line);

                   TLoan *loan = new TLoan();
                   loan->load(myfile);
                   findCustomerByID(loan);
                   findMediumBySignature(loan);
                    LoanList.push_back(loan);
                   //getline (myfile,line);
                   //getline (myfile,line);


            }
            getline (myfile,line);
            tag = parseLine(line, &position);

        }

    }
    else {
            cout << "Unable to open file";
            myfile.close();
    }
}
TCustomer * TLibraryPool::findCustomerByID( TLoan * loan){
     for(int i= 0; i<Customers.size();i++)
    {   TCustomer * customer = Customers.at(i);

        string ID= loan->get_CustomerNr();
        if (ID.compare(customer->getCustomerNr())==0){
                loan->set_Customer(customer);
                customer->add(loan);
            return customer;
        }
    }
    return NULL;

}
TMedium * TLibraryPool::findMediumBySignature( TLoan * loan){
    TList<TLibrary *>:: Iterator it;
    for( it= linkedList.begin();it!=linkedList.end();++it)
    {   TLibrary * library = *it;//=linkedList.pop_back();
        vector<TMedium *> medien = library->getMediumList();
        for(int i= 0; i<medien.size();i++)
        {
            TMedium* medium= medien.at(i);
            string ID= medium->getSignature();

            if (ID.compare(loan->get_signatur())==0){
                loan->set_Medium(medium);
                medium->setStatus(3);
            return medium;
            }
    }    }
    return NULL;

}
void TLibraryPool::add(TCustomer *Customer)
{
    Customers.push_back(Customer);
}

void TLibraryPool::add(TLibrary *Library)
{
    LibraryList.push_back((Library));
}

TEmployee * TLibraryPool::get_Chairman()
{
    return this->Chairman;
}

void  TLibraryPool::set_Chairman(TEmployee Chairman)
{
    *(this->Chairman)=Chairman;

}

vector<TCustomer*> TLibraryPool::get_Customers()
{
    return Customers;
}

void TLibraryPool::print()
{
    cout<< "\n" << this->Name <<endl;
    cout<<"Leitung "<< this->Chairman->getName() << endl;
    this->Chairman->getAddress().print();
    printf("Zum Buechereiverband gehoeren %d Filialen:\n", linkedList.size());
    TList<TLibrary *>:: Iterator it;
    for ( it=linkedList.begin();it!=linkedList.end(); ++it ){
        printf("\n");
        (*it)->print();
    }
    printf("\nDer Buechereiverband hat %d Kunden:\n",Customers.size());
    for ( int i=0;i<Customers.size();i++ ){
        printf("\n");
        (Customers.at(i))->print();
        vector <TLoan *> Loanvect=Customers.at(i)->get_LoanList();
         for ( int j=0;j<Loanvect.size();j++ ){
            printf("\n");
             Loanvect.at(j)->print();
                printf("\n");
         }


    }
    printf("\nFolgende Ausleihen (%i Stueck):\n", LoanList.size());
    for ( int i=0;i<LoanList.size();i++ ){
        printf("\n");
        (LoanList.at(i))->print();
        printf("\n\n");
    }
}
TLibraryPool::~TLibraryPool()
{
    TList<TLibrary *>:: Iterator it;
    for(it=linkedList.begin(); it!=linkedList.end();++it)
    {   TLibrary * lib= *it;
        cout << "delete Buecherei " << lib->getName() << endl;
        delete lib;
    }
    for(int i= 0; i<Customers.size();i++)
    {   TPerson * customer = Customers.at(i);
        delete customer;
    }
    vector<TLoan *>::iterator anotherit;
    for(  anotherit=LoanList.begin();  anotherit!=LoanList.end(); anotherit++)
    {   TLoan * loan = * anotherit;
        cout << "delete loan " << endl;
        delete loan;
    }
    delete Chairman;
}
