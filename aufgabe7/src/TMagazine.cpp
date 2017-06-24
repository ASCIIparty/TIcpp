#include "TMagazine.h"
#include <stdio.h>
#include <fstream>
#include <cstdlib>

TMagazine::TMagazine(string title, string signature, TLocation location, int FSK, status stat, string author, int Pages, string Designer)
            : TPrintedMedium(title, signature, location, FSK, stat, author, Pages)
{
    this->Designer = Designer;
}

TMagazine::TMagazine()
{

}

TMagazine::~TMagazine()
{
    printf("Das Magazin %s wurde geloescht.\n", getTitle().c_str());
}


void TMagazine::print()
{
    printf("Designer:        %s\n", getDesigner().c_str());
    printf("Anz. Seiten:     %d\n", TPrintedMedium::getPages());
    printf("Titel:           %s\n", TPrintedMedium::getTitle().c_str());
    printf("Signatur:        %s\n", getSignature().c_str());
    printf("Ort:             ");
    location.print();
    printf("FSK:             freigegeben ab %d Jahren\n",TMedium::getFSK());
    printf("Status:          %s", TMedium::getStatus());
};

string TMagazine::getDesigner()
{
    return Designer;
}

string TMagazine::parseLine(string line, pos *position)
{
    string value;
    position->startpos=line.find("<");
    position->endpos=line.find(">");
    value=line.substr(position->startpos+1,position->endpos-position->startpos-1);
    position->startpos=line.find(value);
    position->endpos=line.find(value,  position->startpos+1);
    return value;
}

void TMagazine::load( ifstream &file)
{   TMedium::stat=verfuegbar;
    string line;
    string value;
    pos position;
    TMedium::stat=verfuegbar;
    getline(file,line);
    value=parseLine(line,&position);

    while((line.find("</Magazine>") == -1))
    {
        if(!value.compare("Designer"))
        {
             this->Designer=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
        }
        else if(!value.compare("Pages"))
        {
            this->Pages=atoi(line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3).c_str());
        }
        else if(!value.compare("Title"))
        {
            this->titel=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
        }
         else if(!value.compare("Title"))
        {
            this->titel=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
        }
        else if(!value.compare("Signatur"))
        {
            this->signatur=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
        }
        if(!value.compare("Location"))
        {
            this->location.load(file);

        }
        if(!value.compare("FSK")){
            string sub_value=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
            TMedium::FSK=atoi(sub_value.c_str());
        }
        getline (file,line);
        value=parseLine(line,&position);
    }

}

