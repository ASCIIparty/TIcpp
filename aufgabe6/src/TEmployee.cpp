#include "TEmployee.h"

/*TEmployee::TEmployee(string name, TAddress address, TDate birthday, string CustomerNr, string EmployeeNr, vector<TLoan*> LoanList)
            : TPerson(name, address, birthday), TCustomer(CustomerNr, LoanList)
{
    this->EmployeeNr = EmployeeNr;
}
*/
TEmployee::TEmployee() {}

TEmployee::~TEmployee()
{
    printf("Der Angestellte %s wurde geloescht.\n", getName().c_str());

}

void TEmployee::print()
{
    printf("%s (Kundenr.: / Personalnr.: %s)\n", getName().c_str(), getEmployeeNr().c_str());
    address.print();
    printf("* ");
    birthday.print();
}

string TEmployee::getEmployeeNr()
{
    return EmployeeNr;
}

string TEmployee:: parseLine(string line, pos * position)
{
    string value;
    position->startpos=line.find("<");
    position->endpos=line.find(">");
    value=line.substr(position->startpos+1,position->endpos-position->startpos-1);
    position->startpos=line.find(value);
    position->endpos=line.find(value,  position->startpos+1);
    return value;

}

void TEmployee::load( ifstream &file)
{
    string line;
    string value;
    pos position;
    getline (file,line);
    value=parseLine(line,&position);
    this->name=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
    getline (file,line);
    value=parseLine(line,&position);
    while((line.find("</Employee>")==-1)){

         if(!value.compare("Birthday"))
        {
          getline (file,line);
          this->birthday.load(file);
          getline (file,line); //</Birthday>
          //cout<<line<<"</Birtday>??"<<endl;
        }
        else if(!value.compare("EmployeeNr"))
        {
          this->EmployeeNr = line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
        }
        else if(!value.compare("Address"))
        {
          address.load(file);
        }
        getline (file,line);
        value=parseLine(line,&position);
    }
 }
