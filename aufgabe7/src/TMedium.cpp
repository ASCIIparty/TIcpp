#include <stdio.h>
#include <fstream>
#include <cstdlib>
#include "TMedium.h"


TMedium::TMedium(string title, string signatur, TLocation location, int FSK, status stat):location(location)
{
    this->titel = title;
    this->signatur = signatur;
    this->FSK = FSK;
    this->stat=stat;
};

TMedium::TMedium(){}

char *TMedium::getStatus() //soll den Status im Klartext – also als String zurückgeben
{
    switch(stat)
    {
        case verfuegbar:    return "verfuegbar";break;
        case ausgeliehen:   return "ausgeliehen";break;
        case bestellt:      return "bestellt";break;
        case reserviert:    return "reserviert";break;
    }
}


void TMedium::setStatus(int i)
{
     switch(i)
    {
        case 1:     stat= verfuegbar;break;
        case 2:     stat=  ausgeliehen;break;
        case 3:     stat=  bestellt; break;
        case 4:     stat=  reserviert;break;
    }
 }

void TMedium::print()
{
    printf("Titel:          %s\n", getTitle().c_str());
    printf("Signatur:       %s\n",getSignature().c_str());
    printf("Ort:            ");
    location.print();
    printf("FSK:            freigegeben ab %d Jahren\n",getFSK());
    printf("Status:         %s", getStatus());
};

int TMedium::getFSK()
{   return FSK; };

string TMedium::getSignature()
{   return signatur; }

string TMedium::getTitle()
{   return titel; };

TMedium::~TMedium()
{
    printf("Das Medium %s wurde geloescht.\n", getTitle().c_str());
};

string TMedium:: parseLine(string line, pos * position)
{
    string value;
    position->startpos=line.find("<");
    position->endpos=line.find(">");
    value=line.substr(position->startpos+1,position->endpos-position->startpos-1);
    position->startpos=line.find(value);
    position->endpos=line.find(value,  position->startpos+1);
    return value;
}

void TMedium::load( ifstream& file)
{
    string line;
    string value;
    pos position;
    getline (file,line);
    value=parseLine(line,&position);
    this->titel=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
    getline (file,line);
   // cout<<titel<<endl;;
    value=parseLine(line,&position);
    this->signatur=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
    getline (file,line);

    value=parseLine(line,&position);
    if(!value.compare("Location"))
     {

          this->location.load(file);
     }
     getline (file,line);
    value=parseLine(line,&position);
    string sub_value=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
    this->FSK=atoi(sub_value.c_str());
    //cout<<FSK<<endl;
    getline (file,line);
    value=parseLine(line,&position);
    sub_value =line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
    setStatus(atoi(sub_value.c_str()));
    getline (file,line);
    //cout<<line<<"</medium>"<<endl;
}
