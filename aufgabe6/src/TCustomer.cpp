#include "TCustomer.h"

using namespace std;


/*TCustomer::TCustomer(string name, TAddress address, TDate birthday, string CustomerNr, vector<TLoan*> LoanList)
            : TPerson(name, address, birthday)
{
    this->CustomerNr = CustomerNr;
    this->LoanList = LoanList;
}*/

/*TCustomer::TCustomer(string CustomerNr, vector<TLoan *> LoanList)
{
    this->CustomerNr = CustomerNr;
    this->LoanList = LoanList;
}
*/
TCustomer::TCustomer() {}

TCustomer::~TCustomer()
{
    printf("Der Kunde %s wurde geloescht.\n", getName().c_str());

}

void TCustomer::print()
{
    printf("%s (Kundenr.: %s / Personalnr.:)\n", getName().c_str(), getCustomerNr().c_str());
    address.print();
    printf("* ");
    birthday.print();
}

string TCustomer::getCustomerNr()
{
    return CustomerNr;
}

string TCustomer::parseLine(string line, pos *position)
{
    string value;
    position->startpos=line.find("<");
    position->endpos=line.find(">");
    value=line.substr(position->startpos+1,position->endpos-position->startpos-1);
    position->startpos=line.find(value);
    position->endpos=line.find(value,  position->startpos+1);
    return value;
}
void TCustomer::add(TLoan * loan){
    this->LoanList.push_back(loan);
}
void  TLoan::set_Customer(TCustomer * customer){
this->Customer=customer;

}
 vector <TLoan*> TCustomer::get_LoanList(){
 return this->LoanList;
 }
void TCustomer::load( ifstream &file){
    string line;
    string value;
    pos position;
    getline (file,line);
    value=parseLine(line,&position);
    this->name = line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
    getline (file,line);
    value=parseLine(line,&position);
    this->CustomerNr = atoi(line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3).c_str());
    while((line.find("</Customer>")==-1))
        {
            if(!value.compare("Name"))
            {
                this->name = line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
            }
            if(!value.compare("CustomerNr"))
            {
                //cout << "XXXXXXXX" << line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3).c_str() << endl;
                this->CustomerNr = line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
            }
            if(!value.compare("Birthday"))
            {
                getline (file,line);
                this->birthday.load(file);
                getline (file,line); //</Birthday>
            }
            if(!value.compare("Address"))
            {
                address.load(file);
            }
            getline (file,line);
            value=parseLine(line,&position);
        }
 }
