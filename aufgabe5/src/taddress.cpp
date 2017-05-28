#include <iostream>
#include <fstream>
#include <string>
#include<cstdlib>
#include "taddress.h"

using namespace std;
TAddress::TAddress()
{ }

TAddress::TAddress(string Street, string Number, string Zipcode, string Town)
{
    this->Street=Street;
    this->Number=Number;
    this->Zipcode=Zipcode;
    this->Town=Town;
}
void TAddress::set_Street(string Street)
{
    this->Street=Street;
}
void TAddress::set_Number(string Number)
{
    this->Number=Number;
}
void TAddress::set_Zipcode(string Zipcode)
{
    this->Zipcode=Zipcode;
}
void TAddress::set_Town(string Town)
{
    this->Town=Town;
}

string TAddress::get_Street()
{
    return Street;
}
string TAddress::get_Number()
{
    return Number;
}
string TAddress::get_Zipcode()
{
    return Zipcode;
}

string TAddress::get_Town()
{
    return Town;
}
void TAddress::print()
{
     cout << Street <<" "<<Number<<"\n"<<Zipcode<<" "<<Town<< endl;
}
string TAddress:: parseLine(string line, pos * position)
{
    string value;
    position->startpos=line.find("<");
    position->endpos=line.find(">");
    value=line.substr(position->startpos+1,position->endpos-position->startpos-1);
    position->startpos=line.find(value);
    position->endpos=line.find(value,  position->startpos+1);
    return value;

}
void TAddress::load( ifstream& file)
 {   string value;
     string line;
     pos position;
     getline (file,line);
     value=parseLine(line,&position);
     string sub_value;
     while((line.find("</Address>")==-1))
    {
        if(!value.compare("Street"))
        {
          sub_value=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
          this->Street=sub_value;
        }
       else if(!value.compare("Town"))
       {
            this->Town=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
       }
       else if(!value.compare("Number"))
       {
           sub_value=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
           this->Number=atoi(sub_value.c_str());
       }
       else if(!value.compare("Zipcode"))
        {
             this->Zipcode=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);

        }


     getline (file,line);
     value=parseLine(line,&position);

     }

     //cout<<Street<<"street"<<endl;
 }

