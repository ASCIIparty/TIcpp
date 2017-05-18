#include "TPerson.h"
#include "../aufgabe1/tdate.h"
#include "../aufgabe2/taddress.h"
#include <string>
#include<cstdlib>

using namespace std;

TPerson::TPerson(string n , TAddress a, TDate b)
{
    name = n;
    address = a;
    birthday = b;
}
TPerson::TPerson(){}

void TPerson::print()
{
    printf("%s\n", getName().c_str());
    address.print();
    printf("* ");
    birthday.print();
}
string TPerson::getName()
{
    return name;
}

TAddress TPerson::getAddress()
{
   return this->address;
}

TDate TPerson::getBirthday()
{
    return birthday;
}

void TPerson::setName(string n)
{
    name = n;
}

void TPerson::setAddress(TAddress a)
{
    address = a;
}

void TPerson::setBirthday(TDate b)
{
    birthday = b;
}
string  TPerson:: parseLine(string line, pos * position)
{
    string value;
    position->startpos=line.find("<");
    position->endpos=line.find(">");
    value=line.substr(position->startpos+1,position->endpos-position->startpos-1);
    position->startpos=line.find(value);
    position->endpos=line.find(value,  position->startpos+1);
    return value;

}
 void TPerson::load( ifstream& file){
    string line;
    string value;
    pos position;
    getline (file,line);
    value=parseLine(line,&position);
    this->name=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
    getline (file,line);
    value=parseLine(line,&position);
    while((line.find("</Person>")==-1)){

         if(!value.compare("Birthday"))
        {
          getline (file,line);
          this->birthday.load(file);
          getline (file,line); //</Birthday>
          //cout<<line<<"</Birtday>??"<<endl;
        }
        else if(!value.compare("Address"))
        {
          address.load(file);

        }
        getline (file,line);
        value=parseLine(line,&position);
    }



 }
