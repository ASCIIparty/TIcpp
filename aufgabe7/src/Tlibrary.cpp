#include "TLibrary.h"

TLibrary::TLibrary(string n, TAddress a, TEmployee *m)
{
    name = n;
    address = a;
    manager = m;
}

TLibrary::TLibrary(){}

TLibrary::~TLibrary()
{
    for(TMedium *medium : mediumList)
    {
        delete medium;
    }

    delete manager;

    printf("Die Bibliothek %s wurde geloescht.\n", getName().c_str());

}

string TLibrary::getName()
{   return name;    }

vector<TMedium *>  TLibrary::getMediumList()
{   return this->mediumList;  }

void TLibrary::add(TMedium *medium)
{
    mediumList.push_back(medium);
}

void TLibrary::print()
{
    cout<<"Buecherei Filiale "<<name<<endl;
    address.print();
    printf("FilialLeiter: ");
    manager->print();
    printf("Es stehen %d Medien zur Verfuegung:\n\n",mediumList.size());
    for(int i = 0; i<mediumList.size(); i++){
        printf("\n");
        printf("Medium Nr. %d\n",i+1);
        (mediumList.at(i))->print();
         printf("\n");
    }
}


string  TLibrary:: parseLine(string line, pos *position)
{
    string value;
    position->startpos=line.find("<");
    position->endpos=line.find(">");
    value=line.substr(position->startpos+1,position->endpos-position->startpos-1);
    position->startpos=line.find(value);
    position->endpos=line.find(value,  position->startpos+1);
    return value;
}

void TLibrary::load( ifstream &file)
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
    while((line.find("</Library")==-1))
    {
        if(!value.compare("Address"))
        {
            this->address.load(file);
        }
        else if(!value.compare("Book"))
        {
            while(!value.compare("Book")){

                TBook *book = new TBook();
                book->load(file);
                mediumList.push_back(book);
                getline (file,line);
                value=parseLine(line,&position);
            }
            continue;
        }
        else if(!value.compare("Magazine"))
        {
            while(!value.compare("Magazine")){
                cout<< "MAGAZINE? "<<endl;
                TMagazine *magazine = new TMagazine();
                magazine->load(file);
                mediumList.push_back(magazine);
                getline (file,line);
                value=parseLine(line,&position);
            }
            continue;
        }
        else if(!value.compare("DVD"))
        {
            while(!value.compare("DVD")){
                cout<< "DVD" <<endl;
                TDVD *dvd = new TDVD();
                dvd->load(file);
                mediumList.push_back(dvd);
                getline(file,line);
                value=parseLine(line,&position);
            }
            continue;
        }
        else if(!value.compare("CD"))
        {
            while(!value.compare("CD")){

                TCD *cd = new TCD();
                cd->load(file);
                mediumList.push_back(cd);
                getline (file,line);
                value=parseLine(line,&position);
            }
            continue;
        }
        else if(!value.compare("Audiobook"))
        {
            while(!value.compare("Audiobook")){

                TAudiobook *Audiobook = new TAudiobook();
                Audiobook->load(file);
                mediumList.push_back(Audiobook);
                getline (file,line);
                value=parseLine(line,&position);
            }
            continue;
        }

        else if(!value.compare("Manager"))
        {
            getline (file,line);
            manager= new TEmployee();
            manager->load(file);
            getline (file,line); //</manager
        }
        getline (file,line);
        value=parseLine(line,&position);
    }
}


