#include "TLibrary.h"

TLibrary::TLibrary(string n, TAddress a, TPerson *m)
{
    name = n;
    address = a;
    manager = m;


}
TLibrary::TLibrary(){}

string TLibrary::getName()
{   return name;    }

vector<TMedium * >  TLibrary::getMediumList()
{   return this->mediumList;  }

void TLibrary::add(TMedium * medium)
{ mediumList.push_back(medium); }
void TLibrary::print()
{
    //cout<<endl;
    cout<<"Buecherei Filiale "<<name<<endl;
    address.print();
    printf("FilialLeiter: ");
    manager->print();
    printf("Es stehen %d Medien zur Verfuegung:\n\n",mediumList.size());
    for(int i = 0;i<mediumList.size();i++){
        printf("\n");
        printf("Medium Nr. %d\n",i+1);
        (mediumList.at(i))->print();
         printf("\n");
    }
}
TLibrary::~TLibrary()
{   printf("TLibrary object %s deleted", name.c_str()); }


string  TLibrary:: parseLine(string line, pos * position)
{
    string value;
    position->startpos=line.find("<");
    position->endpos=line.find(">");
    value=line.substr(position->startpos+1,position->endpos-position->startpos-1);
    position->startpos=line.find(value);
    position->endpos=line.find(value,  position->startpos+1);
    return value;

}
void TLibrary::load( ifstream& file)
{
    string line;
    string value;
    pos position;
    getline (file,line);
    value=parseLine(line,&position);
    this->name=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
    //cout<<name<<endl;
    getline (file,line);
    value=parseLine(line,&position);
    //cout<<value<<"=Library??"<<endl;
    while((line.find("</Library")==-1))
    {
        if(!value.compare("Address"))
        {   //cout<<value<<"=Adress??"<<endl;
          this->address.load(file);
         // cout<<"adress"<<endl;

        }

         else if(!value.compare("Medium"))
        {    //cout<<value<<"=medium??"<<endl;
            while(!value.compare("Medium")){
                //cout<<value<<endl;
                TMedium * medium = new TMedium();
                medium->load(file);
                mediumList.push_back(medium);
                getline (file,line);
                value=parseLine(line,&position);
                //cout<<"ENDE"<<value<<endl;

            }
            continue;

        }
        else if(!value.compare("Manager"))
        {   //cout<<value<<"MAnager??"<<endl;
            getline (file,line);
            //cout<<line<<endl;
            manager= new TPerson();
            manager->load(file);

            getline (file,line); //</manager
            //cout<<value<<"</MAnager>??"<<endl;
        }
        getline (file,line);

        value=parseLine(line,&position);


    }


}


