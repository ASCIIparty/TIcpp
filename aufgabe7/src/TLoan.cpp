#include <cstdio>
#include<iostream>
#include<cstdlib>
#include<vector>
#include "TLoan.h"

using namespace std;


/*TLoan::TLoan( TMedium *Medium, TPerson *Customer, TDate LoanDate, TDate Expiration)
{
    this->Medium=Medium;
    this->Customer=Customer;
    this->LoanDate=LoanDate;
    this->Expiration=Expiration;
}*/
TLoan::~TLoan() {}
TLoan::TLoan(){}

TPerson *TLoan::get_customer(){
    return this->Customer;
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
string TLoan::get_CustomerNr(){
    return this->CustomerNr;

}
string  TLoan::get_signatur(){
    return this->Signatur;
 }
 void  TLoan::set_Medium(TMedium * medium){
    this->Medium=medium;
 }

void TLoan::print()
{
    printf("Ausleihen:\n");
    printf("Aus vom ");
    this->LoanDate.print();
    printf("Rueckgabe bis spaetestens ");
    this->Expiration.print();
    printf("\n");
    this->Medium->print();
    printf("\nausgelehen von %s",this->Customer->getName().c_str());
}
 string  TLoan::parseLine(string line, pos * position)
 {

    string value;
    position->startpos=line.find("<");
    position->endpos=line.find(">");
    value=line.substr(position->startpos+1,position->endpos-position->startpos-1);
    position->startpos=line.find(value);
    position->endpos=line.find(value,  position->startpos+1);
    return value;
}
  void TLoan::load( ifstream &file){
    string line;
    string value;
    string tag;
    pos position;
     getline (file,line);
     tag = parseLine(line, &position);
     while(line.find("</Loan>")==-1){
        if(!tag.compare("Signatur")){
            this->Signatur=line.substr(position.startpos+tag.size()+1,position.endpos-position.startpos-tag.size()-3);

        }
        else if(!tag.compare("CustomerNr")){
            this->CustomerNr=line.substr(position.startpos+tag.size()+1,position.endpos-position.startpos-tag.size()-3);

        }
        else if(!tag.compare("LoanDate")){
            getline (file,line);
            LoanDate.load(file);
            getline (file,line);
        }
        else if(!tag.compare("LoanDays")){
                int numbers=atoi(line.substr(position.startpos+tag.size()+1,position.endpos-position.startpos-tag.size()-3).c_str());
                this->Expiration=LoanDate+numbers;
        }
        getline (file,line);
        tag = parseLine(line, &position);
    }
  }
