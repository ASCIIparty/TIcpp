#include <iostream>
#include <string>
#include "../aufgabe1/tdate.h"
#include "taddress.h"
#include "tperson.h"
using namespace std;


TPerson::TPerson(string Name, TAddress Adress, TDate Birthday)
{
    this->Name=Name;
    this->Birthday=Birthday;
    this->Adress=Adress;
}
void TPerson::set_Name(string Name)
{
    this->Name=Name;

}
void TPerson::set_Birthday(TDate Birthday)
{
    this->Birthday=Birthday;
}
void TPerson::set_Adresse(TAddress Adress)
{
    this->Adress=Adress;
}
string TPerson::get_Name()
{
    return Name;
}
TDate TPerson::get_Birthday()
{
    return Birthday;
}
TAddress TPerson::get_Address()
{
    return Adress;
}
void TPerson::print()
{
     cout << Name << endl;
     Adress.print();
     Birthday.print();
}
